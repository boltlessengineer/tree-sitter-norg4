/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const newline = choice("\n", "\r", "\r\n");
const newline_or_eof = choice("\n", "\r", "\r\n", "\0");

const ATTACHED_MODIFIERS = [
    "bold",
    "italic",

    "verbatim",
];

const PREC = {
    standard_attached_modifier: 1,
    free_form_standard_attached_modifier: 2,
    verbatim_attached_modifier: 3,
    free_form_verbatim_attached_modifier: 4,
}

module.exports = grammar({
    name: 'norgtest',
    extras: (_) => [],
    inline: ($) => [
    ],
    externals: ($) => [
        $._paragraph_break,
        $._open_conflict,
        $._close_conflict,
        $._lookahead_word,
        $.bold_close,
        $.italic_close,
        $.verbatim_close,
    ],
    conflicts: ($) => [
        [$.punc, $.bold_open],
        [$.punc, $.italic_open],
        [$.punc, $.verbatim_open],
        // NOTE: these conflicts are here to solve link_modifier cases
        // as link modifier needs more than 1 lookahead(followed by completed markup or not,)
        // link_modifier and punctuation should be treated as conflict cases
        [$._non_ws],
        [$._bold_non_ws],
        [$._italic_non_ws],
    ],
    precedences: ($) => [],
    rules: {
        document: ($) => repeat(
            choice(
                $.paragraph,
                newline_or_eof
            )
        ),
        word: (_) => 'word',
        // TODO: repeated whitespace/eol
        // regex pattern for ws+eol and ws+
        // external scanner for preceding whitespace (to match code blocks)
        // ㄴthis will allow preceding whitespace inside attached modifiers
        ws: (_) => ' ',
        paragraph: ($) => prec.right(1, seq(
            $._non_ws,
            $._paragraph_break,
        )),
        punc: ($) => choice(
            token(prec(2, seq("*", repeat1(prec(9,"*"))))),
            token(prec(2, seq("/", repeat1(prec(9,"/"))))),
            token(prec(2, seq("`", repeat1(prec(9,"`"))))),
            "*",
            "/",
            "`",
            ".",
            ":",
            $._close_conflict,
        ),
        link_modifier: (_) => prec.dynamic(1, ":"),
        verbatim_open: (_) => "`",
        verbatim: ($) => prec.dynamic(2, seq(
            $.verbatim_open,
            $._verbatim_non_ws,
            $.verbatim_close
        )),
        _verbatim_non_ws: ($) => prec.right(choice(
            $.word,
            $.punc,
            prec.left(seq($._verbatim_non_ws, $._verbatim_non_ws)),
            prec.left(seq($._verbatim_non_ws, $.ws, $._verbatim_non_ws)),
        )),
        ...gen_attached_modifier("bold", "*"),
        ...gen_attached_modifier("italic", "/"),
        // NOTE: put _non_ws on bottom of list to give lowest precedence by symbol
        // e.g. case: /word /word/
        // two paragraphs have same max/sum precedence level,
        // but one starting with italic should be prioritized.
        _non_ws: ($) => choice(
            seq($.word, optional(alias($._open_conflict, $.punc))),
            $.punc,
            seq(
                optional(seq($.word, $.link_modifier)),
                choice(
                    $.bold,
                    $.italic,
                    $.verbatim,
                ),
                optional(seq($.link_modifier, $._lookahead_word)),
            ),
            prec.left(seq($._non_ws, $._non_ws)),
            prec.left(seq($._non_ws, $.ws, $._non_ws)),
            prec.left(seq($._non_ws, newline, $._non_ws)),
        ),
    },
});

/**
 * @param {string} type
 * @param {string} mod
 */
function gen_attached_modifier(type, mod) {
    let rules = {};
    rules[type + "_open"] = (_) => mod;
    rules["_" + type + "_non_ws"] = ($) => choice(
        seq($.word, optional(alias($._open_conflict, $.punc))),
        $.punc,
        seq(
            optional(seq($.word, $.link_modifier)),
            choice(
                ...ATTACHED_MODIFIERS
                    .filter(t => t != type)
                    .map(t => $[t]),
            ),
            // NOTE: use zero-length token here to ensure lookahead is word while not actually consuming it
            optional(seq($.link_modifier, $._lookahead_word)),
        ),
        prec.left(seq($["_" + type + "_non_ws"], $["_" + type + "_non_ws"])),
        prec.left(seq($["_" + type + "_non_ws"], $.ws, $["_" + type + "_non_ws"])),
        prec.left(seq($["_" + type + "_non_ws"], newline, $["_" + type + "_non_ws"])),
    );
    rules[type] = ($) => prec.dynamic(PREC.standard_attached_modifier, seq(
        $[type + "_open"],
        $["_" + type + "_non_ws"],
        $[type + "_close"],
    ))
    return rules;
}
