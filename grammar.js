/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

const ATTACHED_MODIFIERS = [
        "bold",
        "italic",
        "underline",
        "strikethrough",
        "spoiler",
        "superscript",
        "subscript",
    ],
    VERBATIM_ATTACHED_MODIFIERS = ["verbatim", "comment", "math", "macro"],
    PREC = {
        standard_attached_modifier: 1,
        free_form_standard_attached_modifier: 2,
        verbatim_attached_modifier: 3,
        free_form_verbatim_attached_modifier: 4,
        structural_detached_modifier: 5,
    },
    word = /[\p{L}\p{N}]+/,
    whitespace = /\p{Zs}+/,
    newline = choice("\n", "\r", "\r\n");

const d_alias = process.env.NORG_BUILD
    ? alias
    : (/** @type {RuleOrLiteral} */ rule, /** @type {string} */ _name) => rule;

module.exports = grammar({
    name: "norg4",
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
        $.underline_close,
        $.strikethrough_close,
        $.spoiler_close,
        $.superscript_close,
        $.subscript_close,
        $.verbatim_close,
        $.comment_close,
        $.math_close,
        $.macro_close,
        $.free_bold_close,
        $.free_italic_close,
        $.free_underline_close,
        $.free_strikethrough_close,
        $.free_spoiler_close,
        $.free_superscript_close,
        $.free_subscript_close,
        $.free_verbatim_close,
        $.free_comment_close,
        $.free_math_close,
        $.free_macro_close,
    ],
    conflicts: ($) => [
        ...ATTACHED_MODIFIERS.map((t) => [$.punc, $[t + "_open"]]),
        ...VERBATIM_ATTACHED_MODIFIERS.map((t) => [$.punc, $[t + "_open"]]),
        [$.punc, $._free_open],

        // NOTE: these conflicts are here to solve link_modifier cases
        // as link modifier needs more than 1 lookahead(followed by completed markup or not,)
        // link_modifier and punctuation should be treated as conflict cases
        [$._non_ws],
        [$._title],
        ...ATTACHED_MODIFIERS.map((t) => [$["_" + t + "_non_ws"]]),

        // HACK: and these are for NOT making ERROR with unclosed
        // attached_modifier_extensions
        // unclosed attached_modifier_extensions should not be ERROR because
        // otherwise, parser will fallback to pure punctuations
        ...ATTACHED_MODIFIERS.map((t) => [$[t]]),
        ...ATTACHED_MODIFIERS.map((t) => [$["free_" + t]]),
        ...VERBATIM_ATTACHED_MODIFIERS.map((t) => [$[t]]),
        ...VERBATIM_ATTACHED_MODIFIERS.map((t) => [$["free_" + t]]),
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
        escape_sequence: ($) =>
            seq(
                token(prec(9, "\\")),
                alias(token(prec(9, choice(/./, newline))), $.escape_char),
            ),
        paragraph: ($) =>
            prec.right(
                1,
                seq(
                    $._non_ws,
                    choice(
                        prec(-1, alias($.soft_break, "_paragraph_break")),
                        alias($._eof, "_paragraph_break"),
                    ),
                ),
            ),
        test_heading: ($) =>
            prec.dynamic(
                PREC.structural_detached_modifier,
                seq(
                    token(prec(10, "* ")),
                    alias(prec.right($._title), $.title),
                ),
            ),
        punc: ($) =>
            choice(
                token(prec(2, seq("*", repeat1("*")))),
                token(prec(2, seq("/", repeat1("/")))),
                token(prec(2, seq("-", repeat1("-")))),
                token(prec(2, seq("!", repeat1("!")))),
                token(prec(2, seq("^", repeat1("^")))),
                token(prec(2, seq(",", repeat1(",")))),
                token(prec(2, seq("`", repeat1("`")))),
                token(prec(2, seq("%", repeat1("%")))),
                token(prec(2, seq("$", repeat1("$")))),
                token(prec(2, seq("&", repeat1("&")))),
                "*",
                "/",
                "_",
                "-",
                "!",
                "^",
                ",",
                "`",
                "%",
                "$",
                "&",
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
        link_modifier: (_) =>
            prec.dynamic(PREC.standard_attached_modifier, ":"),
        _free_open: (_) => "|",
        ...gen_verbatim_attached_modifier("verbatim", "`"),
        ...gen_verbatim_attached_modifier("comment", "%"),
        ...gen_verbatim_attached_modifier("math", "$"),
        ...gen_verbatim_attached_modifier("macro", "&"),
        ...gen_attached_modifier("bold", "*"),
        ...gen_attached_modifier("italic", "/"),
        ...gen_attached_modifier("underline", "_"),
        ...gen_attached_modifier("strikethrough", "-"),
        ...gen_attached_modifier("spoiler", "!"),
        ...gen_attached_modifier("superscript", "^"),
        ...gen_attached_modifier("subscript", ","),
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
        _title: ($) =>
            choice(
                seq($.word, optional(alias($._open_conflict, $.punc))),
                $.punc,
                $.escape_sequence,
                seq(
                    optional(seq($.word, $.link_modifier)),
                    choice(
                        ...ATTACHED_MODIFIERS.map((t) => $[t]),
                        ...ATTACHED_MODIFIERS.map((t) => $["free_" + t]),
                        ...VERBATIM_ATTACHED_MODIFIERS.map((t) => $[t]),
                        ...VERBATIM_ATTACHED_MODIFIERS.map(
                            (t) => $["free_" + t],
                        ),
                    ),
                    optional(seq($.link_modifier, $._lookahead_word)),
                ),
                $.anchor,
                $.link,
                prec.left(seq($._title, $._title)),
                prec.left(seq($._title, $.ws, $._title)),
            ),
        _non_ws: ($) =>
            choice(
                seq($.word, optional(alias($._open_conflict, $.punc))),
                $.punc,
                $.escape_sequence,
                // TODO: wrap this seq(...) as _link_mod_wrap and make it conflict with punc or _non_ws
                seq(
                    optional(seq($.word, $.link_modifier)),
                    choice(
                        ...ATTACHED_MODIFIERS.map((t) => $[t]),
                        ...ATTACHED_MODIFIERS.map((t) => $["free_" + t]),
                        ...VERBATIM_ATTACHED_MODIFIERS.map((t) => $[t]),
                        ...VERBATIM_ATTACHED_MODIFIERS.map(
                            (t) => $["free_" + t],
                        ),
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
    const other_attached_modfiers = ATTACHED_MODIFIERS.filter((t) => t != type);
    let rules = gen_free_attached_modifier(type);
    // NOTE: give precedence level on *_open to give higher prefer
    // level to stack with *_open even attached modifier is not completed yet
    rules[type + "_open"] = (_) =>
        prec.dynamic(PREC.standard_attached_modifier, mod);
    rules["_" + type + "_non_ws"] = ($) =>
        choice(
            seq($.word, optional(alias($._open_conflict, $.punc))),
            $.punc,
            $.escape_sequence,
            seq(
                optional(seq($.word, $.link_modifier)),
                choice(
                    ...other_attached_modfiers.map((t) => $[t]),
                    ...other_attached_modfiers.map((t) => $["free_" + t]),
                    ...VERBATIM_ATTACHED_MODIFIERS.map((t) => $[t]),
                    ...VERBATIM_ATTACHED_MODIFIERS.map((t) => $["free_" + t]),
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
        seq(
            d_alias($[type + "_open"], "_open"),
            $["_" + type + "_non_ws"],
            d_alias($[type + "_close"], "_close"),
            optional(field("extension", $.attached_modifier_extension)),
        );
    return rules;
}

/**
 * @param {string} type
 */
function gen_free_attached_modifier(type) {
    const other_attached_modfiers = ATTACHED_MODIFIERS.filter((t) => t != type);
    /**
     * @type {RuleBuilders<string, string>}
     */
    let rules = {};
    rules["free_" + type + "_open"] = ($) =>
        prec.dynamic(
            PREC.free_form_standard_attached_modifier,
            seq(alias($[type + "_open"], "open"), $._free_open),
        );
    rules["_free_" + type + "_inline"] = ($) =>
        prec.right(
            repeat1(
                choice(
                    seq($.word, optional(alias($._open_conflict, $.punc))),
                    $.ws,
                    $.punc,
                    ...other_attached_modfiers.map((t) => $[t]),
                    ...other_attached_modfiers.map((t) => $["free_" + t]),
                    ...VERBATIM_ATTACHED_MODIFIERS.map((t) => $[t]),
                    ...VERBATIM_ATTACHED_MODIFIERS.map((t) => $["free_" + t]),
                ),
            ),
        );
    rules["free_" + type] = ($) =>
        seq(
            d_alias($["free_" + type + "_open"], "_open"),
            choice(
                $.soft_break,
                seq(
                    optional($.soft_break),
                    $["_free_" + type + "_inline"],
                    repeat(seq($.soft_break, $["_free_" + type + "_inline"])),
                    optional($.soft_break),
                ),
            ),
            d_alias($["free_" + type + "_close"], "_close"),
            optional($.attached_modifier_extension),
        );
    return rules;
}

/**
 * @param {string} type
 * @param {string} mod
 */
function gen_verbatim_attached_modifier(type, mod) {
    let rules = gen_free_verbatim_attached_modifier(type);
    // NOTE: give precedence level on verbatim_open to give higher prefer
    // level to stack with verbatim_open even verbatim is not completed yet
    rules[type + "_open"] = (_) =>
        prec.dynamic(PREC.verbatim_attached_modifier, mod);
    const _non_ws = "_" + type + "_non_ws";
    rules[type] = ($) =>
        seq(
            d_alias($[type + "_open"], "_open"),
            $[_non_ws],
            d_alias($[type + "_close"], "_close"),
            optional($.attached_modifier_extension),
        );
    rules[_non_ws] = ($) =>
        prec.right(
            choice(
                seq($.word, optional(alias($._open_conflict, $.punc))),
                $.punc,
                $.escape_sequence,
                alias("[", $.punc),
                alias("{", $.punc),
                prec.left(seq($[_non_ws], $[_non_ws])),
                prec.left(seq($[_non_ws], $.ws, $[_non_ws])),
                prec.left(seq($[_non_ws], $.soft_break, $[_non_ws])),
            ),
        );
    return rules;
}

/**
 * @param {string} type
 */
function gen_free_verbatim_attached_modifier(type) {
    /**
     * @type {RuleBuilders<string, string>}
     */
    let rules = {};
    rules["free_" + type + "_open"] = ($) =>
        prec.dynamic(
            PREC.free_form_verbatim_attached_modifier,
            seq(alias($[type + "_open"], "open"), $._free_open),
        );
    rules["_free_" + type + "_inline"] = ($) =>
        prec.right(
            repeat1(
                choice(
                    seq($.word, optional(alias($._open_conflict, $.punc))),
                    $.ws,
                    $.punc,
                ),
            ),
        );
    rules["free_" + type] = ($) =>
        seq(
            d_alias($["free_" + type + "_open"], "_open"),
            choice(
                $.soft_break,
                seq(
                    optional($.soft_break),
                    $["_free_" + type + "_inline"],
                    repeat(seq($.soft_break, $["_free_" + type + "_inline"])),
                    optional($.soft_break),
                ),
            ),
            d_alias($["free_" + type + "_close"], "_close"),
            optional($.attached_modifier_extension),
        );
    return rules;
}
