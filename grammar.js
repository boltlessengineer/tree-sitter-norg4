const newline_or_eof = choice("\n", "\r", "\r\n", "\0");
const plus = 0;
module.exports = grammar({
    name: 'norgtest',
    extras: (_) => [],
    inline: ($) => [
        // punctuation
        // $._bold_close,
    ],
    conflicts: ($) => [
    ],
    precedences: ($) => [
    ],
    rules: {
        document: ($) => repeat1($.paragraph),
        word: (_) => 'word',
        paragraph: ($) => seq($._para_seg, choice(newline_or_eof, "")),
        _para_seg: ($) =>
            choice(
                $._word_seg,
                $._punc_seg,
                $._ws_seg,
                $._bold_seg,
                // $._italic_seg,
                $._verbatim_seg,
                //...
            ),
        _word_seg: ($) => prec.right(seq(
            $.word,
            optional(choice(
                $._ws_seg,
                $._punc_seg
            ))
        )),
        _punc_seg: ($) =>
            prec.right(seq(
                alias(choice(
                    // punctuations
                    token(prec(3, seq("*", repeat1(prec(9,"*"))))),
                    token(prec(3, seq("/", repeat1(prec(9,"/"))))),
                    token(prec(3, seq("`", repeat1(prec(9,"`"))))),
                    "*",
                    "/",
                    '`',
                    '.',
                ), $.punc),
                optional($._para_seg),
            )),
        _ws_seg: ($) => prec.right(seq(' ', optional($._para_seg))),
        _italic_seg: ($) =>
            seq(
                $.italic,
                optional(choice(
                    $._ws_seg,
                    $._punc_seg,
                    $._bold_seg,
                    $._italic_seg,
                    $._verbatim_seg,
                ))
            ),
        _bold_seg: ($) =>
            seq(
                $.bold,
                optional(choice(
                    $._ws_seg,
                    $._punc_seg,
                    $._bold_seg,
                    // $._italic_seg,
                    $._verbatim_seg,
                ))
            ),
        _verbatim_seg: ($) =>
            seq(
                $.verbatim,
                optional(choice(
                    $._ws_seg,
                    $._punc_seg,
                    $._bold_seg,
                    // $._italic_seg,
                    $._verbatim_seg,
                ))
            ) ,

        _italic_inner: ($) => prec.right(1, choice(
            $._italic_word_seg,
            $._italic_punc_seg,
            seq(
                $.bold,
                choice(
                    $._italic_punc_seg,
                    $._italic_ws_seg,
                    $._italic_close,
                )
            )
        )),
        _italic_close: ($) => choice(
            prec(4, "/"),
            prec(10, seq("/", $._italic_word_seg)),
        ),
        _italic_word_seg: ($) => prec.right(2, seq(
            $.word,
            choice(
                $._italic_ws_seg,
                $._italic_punc_seg,
                $._italic_close,
            )
        )),
        _italic_punc_seg: ($) => prec(2, seq(
            alias(choice(
                token(prec(3, seq("**", repeat(prec(9,"*"))))),
                token(prec(3, seq("//", repeat(prec(9,"/"))))),
                token(prec(3, seq("``", repeat(prec(9,"`"))))),
                "*",
                '/',
                // '`',
                '.',
            ), $.punc),
            choice(
                $._italic_ws_seg,
                $._italic_word_seg,
                $._italic_close,
            )
        )),
        _italic_ws_seg: ($) => seq(
            " ",
            choice(
                $._italic_punc_seg,
                $._italic_word_seg,
            )
        ),
        italic: ($) => seq("/", $._italic_inner),

        _bold_inner: ($) => prec.right(1, choice(
            $._bold_word_seg,
            $._bold_punc_seg,
            // seq(
            //     $.italic,
            //     choice(
            //         $._bold_punc_seg,
            //         $._bold_ws_seg,
            //         $._bold_close,
            //     )
            // ),
            // prec(50, seq('`', $._bold_word_seg)),
            // seq(
            //     $.verbatim,
            //     choice(
            //         $._bold_punc_seg,
            //         $._bold_ws_seg,
            //         $._bold_close,
            //     )
            // ),
        )),
        _bold_close: ($) => choice(
            prec(2, "*"),
            prec(10, seq("*", $._bold_word_seg)),
        ),
        _bold_word_seg: ($) => prec.right(2, seq(
            $.word,
            choice(
                $._bold_ws_seg,
                $._bold_punc_seg,
                $._bold_close,
            )
        )),
        _bold_punc_seg: ($) => prec.right(2, choice(
            seq(
                alias(choice(
                    token(prec(5, seq("**", repeat(prec(9,"*"))))),
                    token(prec(5, seq("//", repeat(prec(9,"/"))))),
                    token(prec(5, seq("``", repeat(prec(9,"`"))))),
                    // "*",
                    '/',
                    '`',
                    '.',
                ), $.punc),
                choice(
                    $._bold_ws_seg,
                    $._bold_punc_seg,
                    $._bold_word_seg,
                    $._bold_close,
                )
            ),
            seq(
                $.verbatim,
                choice(
                    $._bold_ws_seg,
                    $._bold_punc_seg,
                    $._bold_close,
                )
            )
        )),
        _bold_ws_seg: ($) => seq(
            " ",
            choice(
                $._bold_punc_seg,
                $._bold_word_seg,
            )
        ),
        bold: ($) => seq("*", $._bold_inner),

        _verbatim_inner: ($) => prec.right(1+plus, choice(
            $._verbatim_word_seg,
            $._verbatim_punc_seg,
            // $._bold_close,
            // choice(
            //     prec(4, "*"),
            //     prec(10, seq("*", $._bold_word_seg)),
            //     prec(11, seq("*", choice(
            //         $._verbatim_inner,
            //         $._verbatim_ws_seg,
            //     )))
            // )
            // seq(
            //     choice(
            //         $.bold,
            //         $.italic,
            //     ),
            //     choice(
            //         $._verbatim_punc_seg,
            //         $._verbatim_ws_seg,
            //         $._verbatim_close,
            //     )
            // )
        )),
        _verbatim_close: ($) => choice(
            prec(7, "`"),
            prec(10, seq("`", $._verbatim_word_seg)),
        ),
        _verbatim_word_seg: ($) => prec.right(2+plus, seq(
            $.word,
            choice(
                $._verbatim_ws_seg,
                $._verbatim_punc_seg,
                $._verbatim_close,
            )
        )),
        _verbatim_punc_seg: ($) => prec(2+plus, seq(
            alias(choice(
                token(prec(6, seq("**", repeat(prec(9,"*"))))),
                token(prec(6, seq("//", repeat(prec(9,"/"))))),
                token(prec(6, seq("``", repeat(prec(9,"`"))))),
                token("*"),
                "/",
                '`',
                '.',
            ), $.punc),
            choice(
                $._verbatim_ws_seg,
                $._verbatim_word_seg,
                $._verbatim_close,
            )
        )),
        _verbatim_ws_seg: ($) => seq(
            " ",
            choice(
                $._verbatim_inner,
            )
        ),
        verbatim: ($) => seq(prec(1, "`"), $._verbatim_inner),
    },
});
