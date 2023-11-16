/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const ATTACHED_MODIFIERS = [
        "bold",
        "italic",
        // TODO: add more
    ],
    VERBATIM_ATTACHED_MODIFIERS = [
        "verbatim",
        // TODO: add more
    ],
    PREC = {
        standard_attached_modifier: 1,
        free_form_standard_attached_modifier: 2,
        verbatim_attached_modifier: 3,
        free_form_verbatim_attached_modifier: 4,
    },
    word = /[\p{L}\p{N}]+/,
    whitespace = /\p{Zs}+/,
    newline = choice("\n", "\r", "\r\n");

module.exports = grammar({
    name: "norgtest",
    extras: ($) => [$._preceding_whitespace],
    inline: (_) => [],
    externals: ($) => [
        $._preceding_whitespace,
        // NOTE: EOF is handled by external scanner because it can be 0 or NUL
        $._eof,
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
        // NOTE: and these are for NOT making ERROR with unclosed
        // attached_modifier_extensions
        // unclosed attached_modifier_extensions should not be ERROR because
        // otherwise, parser will fallback to pure punctuations
        [$.bold],
        [$.italic],
    ],
    precedences: () => [],
    rules: {
        document: ($) =>
            repeat(
                choice(
                    $.paragraph,
                    $.test_heading,
                    // TODO: add more
                    newline,
                ),
            ),
        word: (_) => word,
        ws: (_) => prec(-1, whitespace),
        soft_break: (_) => seq(optional(whitespace), newline),
        paragraph: ($) =>
            prec.right(
                1,
                seq(
                    $._non_ws,
                    choice(
                        prec(-1, alias($.soft_break, "_paragraph_break")),
                        $._eof,
                    ),
                ),
            ),
        test_heading: ($) => seq(token(prec(10, "* ")), $.word),
        punc: ($) =>
            choice(
                token(prec(2, seq("*", repeat1(prec(9, "*"))))),
                token(prec(2, seq("/", repeat1(prec(9, "/"))))),
                token(prec(2, seq("`", repeat1(prec(9, "`"))))),
                "*",
                "/",
                "`",
                ".",
                ":",
                $._close_conflict,
                // NOTE: only `(` can be parsed as punctuation and not `{`, `[`
                "(",
                ")",
                "|",
                "}",
                "]",
                token(/[^\{\[\n\r\p{Z}\p{L}\p{N}]/),
            ),
        link_modifier: (_) => prec.dynamic(1, ":"),
        verbatim_open: (_) => "`",
        verbatim: ($) =>
            prec.dynamic(
                2,
                seq($.verbatim_open, $._verbatim_non_ws, $.verbatim_close),
            ),
        _verbatim_non_ws: ($) =>
            prec.right(
                choice(
                    $.word,
                    $.punc,
                    alias("[", $.punc),
                    alias("{", $.punc),
                    prec.left(seq($._verbatim_non_ws, $._verbatim_non_ws)),
                    prec.left(
                        seq($._verbatim_non_ws, $.ws, $._verbatim_non_ws),
                    ),
                    prec.left(
                        seq(
                            $._verbatim_non_ws,
                            $.soft_break,
                            $._verbatim_non_ws,
                        ),
                    ),
                ),
            ),
        ...gen_attached_modifier("bold", "*"),
        ...gen_attached_modifier("italic", "/"),
        attached_modifier_extension: ($) =>
            seq(
                "(",
                optional(whitespace),
                $.attr_pair,
                repeat(
                    seq(
                        optional(whitespace),
                        "|",
                        optional(whitespace),
                        $.attr_pair,
                    ),
                ),
                optional(whitespace),
                ")",
            ),
        attr_pair: ($) =>
            seq(
                field("key", $.word),
                optional(whitespace),
                ":",
                optional(whitespace),
                field("val", $.word),
            ),
        link_description: ($) =>
            seq(
                "[",
                optional(whitespace),
                $._non_ws,
                optional(whitespace),
                prec(1, "]"),
            ),
        _link_location: ($) =>
            seq(
                "{",
                field(
                    "location",
                    choice(
                        // seq(
                        //     $.file_loc,
                        //     optional(
                        //         choice(
                        //             // TODO:
                        //         )
                        //     )
                        // ),
                        $.uri_link,
                    ),
                ),
                prec(1, "}"),
            ),
        uri_link: (_) =>
            token(seq(/[^\}\n\r]+/, repeat(seq(newline, /[^\}\n\r]+/)))),
        file_loc: (_) => seq(token(prec(1, ":")), /[^:\S]+/, ":"),
        anchor: ($) =>
            prec.right(
                seq(
                    field("description", $.link_description),
                    optional($._link_location),
                ),
            ),
        link: ($) =>
            prec.right(
                seq(
                    $._link_location,
                    optional(field("description", $.link_description)),
                ),
            ),
        // NOTE: put _non_ws on bottom of list to give lowest precedence by symbol
        // e.g. case: /word /word/
        // two paragraphs have same max/sum precedence level,
        // but one starting with italic should be prioritized.
        _non_ws: ($) =>
            choice(
                seq($.word, optional(alias($._open_conflict, $.punc))),
                $.punc,
                seq(
                    optional(seq($.word, $.link_modifier)),
                    choice(
                        ...ATTACHED_MODIFIERS.map((t) => $[t]),
                        ...VERBATIM_ATTACHED_MODIFIERS.map((t) => $[t]),
                    ),
                    optional(seq($.link_modifier, $._lookahead_word)),
                ),
                $.anchor,
                $.link,
                prec.left(seq($._non_ws, $._non_ws)),
                prec.left(seq($._non_ws, $.ws, $._non_ws)),
                prec.left(seq($._non_ws, $.soft_break, $._non_ws)),
            ),
    },
});

/**
 * @param {string} type
 * @param {string} mod
 */
function gen_attached_modifier(type, mod) {
    /**
     * @type {RuleBuilders<string, string>}
     */
    let rules = {};
    rules[type + "_open"] = (_) => mod;
    rules["_" + type + "_non_ws"] = ($) =>
        choice(
            seq($.word, optional(alias($._open_conflict, $.punc))),
            $.punc,
            seq(
                optional(seq($.word, $.link_modifier)),
                choice(
                    ...ATTACHED_MODIFIERS.filter((t) => t != type).map(
                        (t) => $[t],
                    ),
                    ...VERBATIM_ATTACHED_MODIFIERS.filter((t) => t != type).map(
                        (t) => $[t],
                    ),
                ),
                // NOTE: use zero-length token here to ensure lookahead is word without actually consuming it
                optional(seq($.link_modifier, $._lookahead_word)),
            ),
            prec.left(
                seq($["_" + type + "_non_ws"], $["_" + type + "_non_ws"]),
            ),
            prec.left(
                seq($["_" + type + "_non_ws"], $.ws, $["_" + type + "_non_ws"]),
            ),
            prec.left(
                seq(
                    $["_" + type + "_non_ws"],
                    $.soft_break,
                    $["_" + type + "_non_ws"],
                ),
            ),
        );
    rules[type] = ($) =>
        prec.dynamic(
            PREC.standard_attached_modifier,
            seq(
                $[type + "_open"],
                $["_" + type + "_non_ws"],
                $[type + "_close"],
                optional($.attached_modifier_extension),
            ),
        );
    return rules;
}
