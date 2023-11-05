const newline = choice("\n", "\r", "\r\n");
const newline_or_eof = choice("\n", "\r", "\r\n", "\0");

const ATTACHED_MODIFIERS = [
    "bold",
    "italic",

    "verbatim",
];

const PREC_STANDARD_ATTACHED_MODIFIER = 1;

module.exports = grammar({
    name: 'norgtest',
    extras: (_) => [],
    inline: ($) => [
    ],
    externals: ($) => [
        $._paragraph_break,
        $._open_conflict,
        $._close_conflict,
        $.bold_close,
        $.italic_close,
        $.verbatim_close,
    ],
    conflicts: ($) => [
        [$.punc, $.bold_open],
        [$.punc, $.italic_open],
        [$.punc, $.verbatim_open],
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
        _non_ws: ($) => prec.right(choice(
            seq($.word, optional(alias($._open_conflict, $.punc))),
            $.punc,
            seq(
                optional(seq($.word, $.link_modifier)),
                choice(
                    $.bold,
                    $.italic,
                    $.verbatim,
                ),
                optional(seq($.link_modifier, $.word)),
            ),
            prec.left(seq($._non_ws, $._non_ws)),
            prec.left(seq($._non_ws, $.ws, $._non_ws)),
            prec.left(seq($._non_ws, $._newline_non_ws)),
        )),
        _newline_non_ws: ($) => prec.left(seq(newline, $._non_ws))
    },
});

function gen_attached_modifier(type, mod) {
    let rules = {};
    rules[type + "_open"] = (_) => mod;
    rules["_" + type + "_non_ws"] = ($) => prec.right(choice(
        $.word,
        $.punc,
        seq(
            optional(seq($.word, $.link_modifier)),
            choice(
                ...ATTACHED_MODIFIERS
                    .filter(t => t != type)
                    .map(t => $[t]),
            ),
            optional(seq($.link_modifier, $.word)),
        ),
        prec.left(seq($._italic_non_ws, $._italic_non_ws)),
        prec.left(seq($._italic_non_ws, $.ws, $._italic_non_ws)),
    ));
    rules[type] = ($) => prec.dynamic(PREC_STANDARD_ATTACHED_MODIFIER, seq(
        $[type + "_open"],
        $["_" + type + "_non_ws"],
        $[type + "_close"],
    ))
    return rules;
}
