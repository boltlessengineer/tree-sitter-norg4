const newline_or_eof = choice("\n", "\r", "\r\n", "\0");
const plus = 0;
module.exports = grammar({
    name: 'norgtest',
    extras: (_) => [],
    inline: ($) => [
        // punctuation
        // $._non_ws,
    ],
    externals: ($) => [
        $._italic_close,
    ],
    conflicts: ($) => [
        // [$._non_ws],
        // [$._non_ws, $.italic],
        [$.punc, $.italic_open]
    ],
    precedences: ($) => [
    ],
    rules: {
        document: ($) => repeat1($.paragraph),
        word: ($) => 'word',
        paragraph: ($) => (seq(
            choice(
                $._non_ws,
                // $._ws,
            ),
            (newline_or_eof),
        )),
        punc: ($) => choice(
            token(prec(3, seq("/", repeat1(prec(9,"/"))))),
            '/',
            '.',
        ),
        _non_ws: ($) => prec.right(0,
            choice(
                $.word,
                $.punc,
                $.italic,
                // token(prec(9, seq('/', "word"))),
                seq($._non_ws, $._non_ws),
                seq($._non_ws, $._ws, $._non_ws),
                // prec(1, seq($._non_ws, '/', $.word)),
            )
        ),
        _ws: (_) => " ",
        _italic_non_ws: ($) => prec.right(0, choice(
            $.word,
            $.punc,
            // token(prec(9, seq('/', "word"))),
            seq($._italic_non_ws, $._italic_non_ws),
            seq($._italic_non_ws, $._ws, $._italic_non_ws),
        )),
        italic_open: (_) => '/',
        italic: ($) => prec.dynamic(1, seq(
            $.italic_open,
            // $._italic_non_ws,
            $._non_ws,
            alias($._italic_close, $.close),
            // '/'
        ))
    },
});
