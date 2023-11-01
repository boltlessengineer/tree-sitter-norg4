const newline_or_eof = choice("\n", "\r", "\r\n", "\0");
const plus = 0;
module.exports = grammar({
    name: 'norgtest',
    extras: (_) => [],
    inline: ($) => [
    ],
    externals: ($) => [
    ],
    conflicts: ($) => [
        [$.punc, $.bold_open],
        [$.punc, $.italic_open],
        [$.punc, $.verbatim_open],
    ],
    precedences: ($) => [],
    rules: {
        document: ($) => repeat1(
            choice(
                $.paragraph,
                newline_or_eof
            )
        ),
        word: ($) => 'word',
        paragraph: ($) => prec.right(repeat1(
            choice(
                $.punc,
                $.word,
                $.italic,
                $.bold,
                $.verbatim,
            )
        )),
        punc: ($) => choice(
            token(prec(2, seq("*", repeat1(prec(9,"*"))))),
            token(prec(2, seq("/", repeat1(prec(9,"/"))))),
            token(prec(2, seq("`", repeat1(prec(9,"`"))))),
            "*",
            "/",
            "`",
            ".",
        ),
        bold_open: (_) => "*",
        italic_open: (_) => "/",
        verbatim_open: (_) => "`",
        bold_close: (_) => prec(1, "*"),
        italic_close: (_) => prec(1, "/"),
        verbatim_close: (_) => prec(1, "`"),
        bold_inner: ($) => seq(
            prec.dynamic(0, choice(
                seq($.punc, $.punc, $.word, $.punc),
                $.italic,
            )),
            $.bold_close,
        ),
        // NOTE:
        // don't touch this bold(open->inner(...->close)) approach
        // don't even change `bold_inner` to `_bold_inner`
        bold: ($) => prec.dynamic(1, seq(
            alias($.bold_open, $._open),
            repeat1(
                choice(
                    $.word,
                    $.punc,
                    $.italic,
                    $.verbatim,
                )
            ),
            alias($.bold_close, $._close),
        )),
        italic: ($) => prec.dynamic(1, seq(
            alias($.italic_open, $._open),
            repeat1(
                choice(
                    $.word,
                    $.punc,
                    $.bold,
                    $.verbatim,
                )
            ),
            alias($.italic_close, $._close),
        )),
        verbatim: ($) => prec.dynamic(2, seq(
            alias($.verbatim_open, $._open),
            repeat1(
                choice(
                    $.word,
                    $.punc,
                )
            ),
            alias($.verbatim_close, $._close),
        )),
    },
});
