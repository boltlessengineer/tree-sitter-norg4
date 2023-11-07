#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 121
#define LARGE_STATE_COUNT 15
#define SYMBOL_COUNT 45
#define ALIAS_COUNT 0
#define TOKEN_COUNT 26
#define EXTERNAL_TOKEN_COUNT 7
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 4

enum ts_symbol_identifiers {
  anon_sym_LF = 1,
  anon_sym_CR = 2,
  anon_sym_CR_LF = 3,
  anon_sym_NULL = 4,
  sym_word = 5,
  aux_sym_ws_token1 = 6,
  aux_sym_punc_token1 = 7,
  aux_sym_punc_token2 = 8,
  aux_sym_punc_token3 = 9,
  anon_sym_STAR = 10,
  anon_sym_SLASH = 11,
  anon_sym_BQUOTE = 12,
  anon_sym_DOT = 13,
  anon_sym_COLON = 14,
  anon_sym_LPAREN = 15,
  anon_sym_RPAREN = 16,
  anon_sym_PIPE = 17,
  aux_sym_punc_token4 = 18,
  sym__paragraph_break = 19,
  sym__open_conflict = 20,
  sym__close_conflict = 21,
  sym__lookahead_word = 22,
  sym_bold_close = 23,
  sym_italic_close = 24,
  sym_verbatim_close = 25,
  sym_document = 26,
  sym_ws = 27,
  sym_paragraph = 28,
  sym_punc = 29,
  sym_link_modifier = 30,
  sym_verbatim_open = 31,
  sym_verbatim = 32,
  sym__verbatim_non_ws = 33,
  sym_bold_open = 34,
  sym__bold_non_ws = 35,
  sym_bold = 36,
  sym_italic_open = 37,
  sym__italic_non_ws = 38,
  sym_italic = 39,
  sym_attached_modifier_extension = 40,
  sym_attr_pair = 41,
  sym__non_ws = 42,
  aux_sym_document_repeat1 = 43,
  aux_sym_attached_modifier_extension_repeat1 = 44,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_LF] = "\n",
  [anon_sym_CR] = "\r",
  [anon_sym_CR_LF] = "\r\n",
  [anon_sym_NULL] = "\0",
  [sym_word] = "word",
  [aux_sym_ws_token1] = "ws_token1",
  [aux_sym_punc_token1] = "punc_token1",
  [aux_sym_punc_token2] = "punc_token2",
  [aux_sym_punc_token3] = "punc_token3",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_BQUOTE] = "`",
  [anon_sym_DOT] = ".",
  [anon_sym_COLON] = ":",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_PIPE] = "|",
  [aux_sym_punc_token4] = "punc_token4",
  [sym__paragraph_break] = "_paragraph_break",
  [sym__open_conflict] = "punc",
  [sym__close_conflict] = "_close_conflict",
  [sym__lookahead_word] = "_lookahead_word",
  [sym_bold_close] = "bold_close",
  [sym_italic_close] = "italic_close",
  [sym_verbatim_close] = "verbatim_close",
  [sym_document] = "document",
  [sym_ws] = "ws",
  [sym_paragraph] = "paragraph",
  [sym_punc] = "punc",
  [sym_link_modifier] = "link_modifier",
  [sym_verbatim_open] = "verbatim_open",
  [sym_verbatim] = "verbatim",
  [sym__verbatim_non_ws] = "_verbatim_non_ws",
  [sym_bold_open] = "bold_open",
  [sym__bold_non_ws] = "_bold_non_ws",
  [sym_bold] = "bold",
  [sym_italic_open] = "italic_open",
  [sym__italic_non_ws] = "_italic_non_ws",
  [sym_italic] = "italic",
  [sym_attached_modifier_extension] = "attached_modifier_extension",
  [sym_attr_pair] = "attr_pair",
  [sym__non_ws] = "_non_ws",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_attached_modifier_extension_repeat1] = "attached_modifier_extension_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_CR] = anon_sym_CR,
  [anon_sym_CR_LF] = anon_sym_CR_LF,
  [anon_sym_NULL] = anon_sym_NULL,
  [sym_word] = sym_word,
  [aux_sym_ws_token1] = aux_sym_ws_token1,
  [aux_sym_punc_token1] = aux_sym_punc_token1,
  [aux_sym_punc_token2] = aux_sym_punc_token2,
  [aux_sym_punc_token3] = aux_sym_punc_token3,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_BQUOTE] = anon_sym_BQUOTE,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [aux_sym_punc_token4] = aux_sym_punc_token4,
  [sym__paragraph_break] = sym__paragraph_break,
  [sym__open_conflict] = sym_punc,
  [sym__close_conflict] = sym__close_conflict,
  [sym__lookahead_word] = sym__lookahead_word,
  [sym_bold_close] = sym_bold_close,
  [sym_italic_close] = sym_italic_close,
  [sym_verbatim_close] = sym_verbatim_close,
  [sym_document] = sym_document,
  [sym_ws] = sym_ws,
  [sym_paragraph] = sym_paragraph,
  [sym_punc] = sym_punc,
  [sym_link_modifier] = sym_link_modifier,
  [sym_verbatim_open] = sym_verbatim_open,
  [sym_verbatim] = sym_verbatim,
  [sym__verbatim_non_ws] = sym__verbatim_non_ws,
  [sym_bold_open] = sym_bold_open,
  [sym__bold_non_ws] = sym__bold_non_ws,
  [sym_bold] = sym_bold,
  [sym_italic_open] = sym_italic_open,
  [sym__italic_non_ws] = sym__italic_non_ws,
  [sym_italic] = sym_italic,
  [sym_attached_modifier_extension] = sym_attached_modifier_extension,
  [sym_attr_pair] = sym_attr_pair,
  [sym__non_ws] = sym__non_ws,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_attached_modifier_extension_repeat1] = aux_sym_attached_modifier_extension_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CR_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_NULL] = {
    .visible = true,
    .named = false,
  },
  [sym_word] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_ws_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_punc_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_punc_token2] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_punc_token3] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_punc_token4] = {
    .visible = false,
    .named = false,
  },
  [sym__paragraph_break] = {
    .visible = false,
    .named = true,
  },
  [sym__open_conflict] = {
    .visible = true,
    .named = true,
  },
  [sym__close_conflict] = {
    .visible = false,
    .named = true,
  },
  [sym__lookahead_word] = {
    .visible = false,
    .named = true,
  },
  [sym_bold_close] = {
    .visible = true,
    .named = true,
  },
  [sym_italic_close] = {
    .visible = true,
    .named = true,
  },
  [sym_verbatim_close] = {
    .visible = true,
    .named = true,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym_ws] = {
    .visible = true,
    .named = true,
  },
  [sym_paragraph] = {
    .visible = true,
    .named = true,
  },
  [sym_punc] = {
    .visible = true,
    .named = true,
  },
  [sym_link_modifier] = {
    .visible = true,
    .named = true,
  },
  [sym_verbatim_open] = {
    .visible = true,
    .named = true,
  },
  [sym_verbatim] = {
    .visible = true,
    .named = true,
  },
  [sym__verbatim_non_ws] = {
    .visible = false,
    .named = true,
  },
  [sym_bold_open] = {
    .visible = true,
    .named = true,
  },
  [sym__bold_non_ws] = {
    .visible = false,
    .named = true,
  },
  [sym_bold] = {
    .visible = true,
    .named = true,
  },
  [sym_italic_open] = {
    .visible = true,
    .named = true,
  },
  [sym__italic_non_ws] = {
    .visible = false,
    .named = true,
  },
  [sym_italic] = {
    .visible = true,
    .named = true,
  },
  [sym_attached_modifier_extension] = {
    .visible = true,
    .named = true,
  },
  [sym_attr_pair] = {
    .visible = true,
    .named = true,
  },
  [sym__non_ws] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_attached_modifier_extension_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_key = 1,
  field_val = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_key] = "key",
  [field_val] = "val",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 2},
  [3] = {.index = 4, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_key, 0},
    {field_val, 2},
  [2] =
    {field_key, 0},
    {field_val, 3},
  [4] =
    {field_key, 0},
    {field_val, 4},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 8,
  [13] = 11,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 25,
  [28] = 28,
  [29] = 22,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 35,
  [37] = 34,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 39,
  [47] = 44,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 40,
  [53] = 53,
  [54] = 54,
  [55] = 39,
  [56] = 43,
  [57] = 35,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 40,
  [62] = 62,
  [63] = 53,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 41,
  [68] = 68,
  [69] = 69,
  [70] = 34,
  [71] = 71,
  [72] = 71,
  [73] = 71,
  [74] = 40,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 89,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
};

static inline bool aux_sym_punc_token4_character_set_1(int32_t c) {
  return (c < 6688
    ? (c < 3046
      ? (c < 2392
        ? (c < 1376
          ? (c < 748
            ? (c < 185
              ? (c < 'a'
                ? (c < '0'
                  ? c == 0
                  : (c <= '9' || (c >= 'A' && c <= 'Z')))
                : (c <= 'z' || (c < 178
                  ? c == 170
                  : (c <= 179 || c == 181))))
              : (c <= 186 || (c < 248
                ? (c < 192
                  ? (c >= 188 && c <= 190)
                  : (c <= 214 || (c >= 216 && c <= 246)))
                : (c <= 705 || (c < 736
                  ? (c >= 710 && c <= 721)
                  : c <= 740)))))
            : (c <= 748 || (c < 908
              ? (c < 890
                ? (c < 880
                  ? c == 750
                  : (c <= 884 || (c >= 886 && c <= 887)))
                : (c <= 893 || (c < 902
                  ? c == 895
                  : (c <= 902 || (c >= 904 && c <= 906)))))
              : (c <= 908 || (c < 1162
                ? (c < 931
                  ? (c >= 910 && c <= 929)
                  : (c <= 1013 || (c >= 1015 && c <= 1153)))
                : (c <= 1327 || (c < 1369
                  ? (c >= 1329 && c <= 1366)
                  : c <= 1369)))))))
          : (c <= 1416 || (c < 1984
            ? (c < 1765
              ? (c < 1632
                ? (c < 1519
                  ? (c >= 1488 && c <= 1514)
                  : (c <= 1522 || (c >= 1568 && c <= 1610)))
                : (c <= 1641 || (c < 1649
                  ? (c >= 1646 && c <= 1647)
                  : (c <= 1747 || c == 1749))))
              : (c <= 1766 || (c < 1810
                ? (c < 1791
                  ? (c >= 1774 && c <= 1788)
                  : (c <= 1791 || c == 1808))
                : (c <= 1839 || (c < 1969
                  ? (c >= 1869 && c <= 1957)
                  : c <= 1969)))))
            : (c <= 2026 || (c < 2144
              ? (c < 2074
                ? (c < 2042
                  ? (c >= 2036 && c <= 2037)
                  : (c <= 2042 || (c >= 2048 && c <= 2069)))
                : (c <= 2074 || (c < 2088
                  ? c == 2084
                  : (c <= 2088 || (c >= 2112 && c <= 2136)))))
              : (c <= 2154 || (c < 2308
                ? (c < 2185
                  ? (c >= 2160 && c <= 2183)
                  : (c <= 2190 || (c >= 2208 && c <= 2249)))
                : (c <= 2361 || (c < 2384
                  ? c == 2365
                  : c <= 2384)))))))))
        : (c <= 2401 || (c < 2730
          ? (c < 2556
            ? (c < 2486
              ? (c < 2447
                ? (c < 2417
                  ? (c >= 2406 && c <= 2415)
                  : (c <= 2432 || (c >= 2437 && c <= 2444)))
                : (c <= 2448 || (c < 2474
                  ? (c >= 2451 && c <= 2472)
                  : (c <= 2480 || c == 2482))))
              : (c <= 2489 || (c < 2527
                ? (c < 2510
                  ? c == 2493
                  : (c <= 2510 || (c >= 2524 && c <= 2525)))
                : (c <= 2529 || (c < 2548
                  ? (c >= 2534 && c <= 2545)
                  : c <= 2553)))))
            : (c <= 2556 || (c < 2649
              ? (c < 2602
                ? (c < 2575
                  ? (c >= 2565 && c <= 2570)
                  : (c <= 2576 || (c >= 2579 && c <= 2600)))
                : (c <= 2608 || (c < 2613
                  ? (c >= 2610 && c <= 2611)
                  : (c <= 2614 || (c >= 2616 && c <= 2617)))))
              : (c <= 2652 || (c < 2693
                ? (c < 2662
                  ? c == 2654
                  : (c <= 2671 || (c >= 2674 && c <= 2676)))
                : (c <= 2701 || (c < 2707
                  ? (c >= 2703 && c <= 2705)
                  : c <= 2728)))))))
          : (c <= 2736 || (c < 2908
            ? (c < 2821
              ? (c < 2768
                ? (c < 2741
                  ? (c >= 2738 && c <= 2739)
                  : (c <= 2745 || c == 2749))
                : (c <= 2768 || (c < 2790
                  ? (c >= 2784 && c <= 2785)
                  : (c <= 2799 || c == 2809))))
              : (c <= 2828 || (c < 2866
                ? (c < 2835
                  ? (c >= 2831 && c <= 2832)
                  : (c <= 2856 || (c >= 2858 && c <= 2864)))
                : (c <= 2867 || (c < 2877
                  ? (c >= 2869 && c <= 2873)
                  : c <= 2877)))))
            : (c <= 2909 || (c < 2969
              ? (c < 2947
                ? (c < 2918
                  ? (c >= 2911 && c <= 2913)
                  : (c <= 2927 || (c >= 2929 && c <= 2935)))
                : (c <= 2947 || (c < 2958
                  ? (c >= 2949 && c <= 2954)
                  : (c <= 2960 || (c >= 2962 && c <= 2965)))))
              : (c <= 2970 || (c < 2984
                ? (c < 2974
                  ? c == 2972
                  : (c <= 2975 || (c >= 2979 && c <= 2980)))
                : (c <= 2986 || (c < 3024
                  ? (c >= 2990 && c <= 3001)
                  : c <= 3024)))))))))))
      : (c <= 3058 || (c < 4176
        ? (c < 3450
          ? (c < 3242
            ? (c < 3168
              ? (c < 3114
                ? (c < 3086
                  ? (c >= 3077 && c <= 3084)
                  : (c <= 3088 || (c >= 3090 && c <= 3112)))
                : (c <= 3129 || (c < 3160
                  ? c == 3133
                  : (c <= 3162 || c == 3165))))
              : (c <= 3169 || (c < 3205
                ? (c < 3192
                  ? (c >= 3174 && c <= 3183)
                  : (c <= 3198 || c == 3200))
                : (c <= 3212 || (c < 3218
                  ? (c >= 3214 && c <= 3216)
                  : c <= 3240)))))
            : (c <= 3251 || (c < 3342
              ? (c < 3296
                ? (c < 3261
                  ? (c >= 3253 && c <= 3257)
                  : (c <= 3261 || (c >= 3293 && c <= 3294)))
                : (c <= 3297 || (c < 3313
                  ? (c >= 3302 && c <= 3311)
                  : (c <= 3314 || (c >= 3332 && c <= 3340)))))
              : (c <= 3344 || (c < 3412
                ? (c < 3389
                  ? (c >= 3346 && c <= 3386)
                  : (c <= 3389 || c == 3406))
                : (c <= 3414 || (c < 3430
                  ? (c >= 3416 && c <= 3425)
                  : c <= 3448)))))))
          : (c <= 3455 || (c < 3749
            ? (c < 3634
              ? (c < 3517
                ? (c < 3482
                  ? (c >= 3461 && c <= 3478)
                  : (c <= 3505 || (c >= 3507 && c <= 3515)))
                : (c <= 3517 || (c < 3558
                  ? (c >= 3520 && c <= 3526)
                  : (c <= 3567 || (c >= 3585 && c <= 3632)))))
              : (c <= 3635 || (c < 3716
                ? (c < 3664
                  ? (c >= 3648 && c <= 3654)
                  : (c <= 3673 || (c >= 3713 && c <= 3714)))
                : (c <= 3716 || (c < 3724
                  ? (c >= 3718 && c <= 3722)
                  : c <= 3747)))))
            : (c <= 3749 || (c < 3840
              ? (c < 3776
                ? (c < 3762
                  ? (c >= 3751 && c <= 3760)
                  : (c <= 3763 || c == 3773))
                : (c <= 3780 || (c < 3792
                  ? c == 3782
                  : (c <= 3801 || (c >= 3804 && c <= 3807)))))
              : (c <= 3840 || (c < 3976
                ? (c < 3904
                  ? (c >= 3872 && c <= 3891)
                  : (c <= 3911 || (c >= 3913 && c <= 3948)))
                : (c <= 3980 || (c < 4159
                  ? (c >= 4096 && c <= 4138)
                  : c <= 4169)))))))))
        : (c <= 4181 || (c < 5024
          ? (c < 4696
            ? (c < 4256
              ? (c < 4206
                ? (c < 4193
                  ? (c >= 4186 && c <= 4189)
                  : (c <= 4193 || (c >= 4197 && c <= 4198)))
                : (c <= 4208 || (c < 4238
                  ? (c >= 4213 && c <= 4225)
                  : (c <= 4238 || (c >= 4240 && c <= 4249)))))
              : (c <= 4293 || (c < 4348
                ? (c < 4301
                  ? c == 4295
                  : (c <= 4301 || (c >= 4304 && c <= 4346)))
                : (c <= 4680 || (c < 4688
                  ? (c >= 4682 && c <= 4685)
                  : c <= 4694)))))
            : (c <= 4696 || (c < 4802
              ? (c < 4752
                ? (c < 4704
                  ? (c >= 4698 && c <= 4701)
                  : (c <= 4744 || (c >= 4746 && c <= 4749)))
                : (c <= 4784 || (c < 4792
                  ? (c >= 4786 && c <= 4789)
                  : (c <= 4798 || c == 4800))))
              : (c <= 4805 || (c < 4888
                ? (c < 4824
                  ? (c >= 4808 && c <= 4822)
                  : (c <= 4880 || (c >= 4882 && c <= 4885)))
                : (c <= 4954 || (c < 4992
                  ? (c >= 4969 && c <= 4988)
                  : c <= 5007)))))))
          : (c <= 5109 || (c < 6128
            ? (c < 5952
              ? (c < 5792
                ? (c < 5121
                  ? (c >= 5112 && c <= 5117)
                  : (c <= 5740 || (c >= 5743 && c <= 5786)))
                : (c <= 5866 || (c < 5888
                  ? (c >= 5870 && c <= 5880)
                  : (c <= 5905 || (c >= 5919 && c <= 5937)))))
              : (c <= 5969 || (c < 6103
                ? (c < 5998
                  ? (c >= 5984 && c <= 5996)
                  : (c <= 6000 || (c >= 6016 && c <= 6067)))
                : (c <= 6103 || (c < 6112
                  ? c == 6108
                  : c <= 6121)))))
            : (c <= 6137 || (c < 6400
              ? (c < 6279
                ? (c < 6176
                  ? (c >= 6160 && c <= 6169)
                  : (c <= 6264 || (c >= 6272 && c <= 6276)))
                : (c <= 6312 || (c < 6320
                  ? c == 6314
                  : c <= 6389)))
              : (c <= 6430 || (c < 6576
                ? (c < 6512
                  ? (c >= 6470 && c <= 6509)
                  : (c <= 6516 || (c >= 6528 && c <= 6571)))
                : (c <= 6601 || (c < 6656
                  ? (c >= 6608 && c <= 6618)
                  : c <= 6678)))))))))))))
    : (c <= 6740 || (c < 43138
      ? (c < 10102
        ? (c < 8118
          ? (c < 7401
            ? (c < 7086
              ? (c < 6917
                ? (c < 6800
                  ? (c >= 6784 && c <= 6793)
                  : (c <= 6809 || c == 6823))
                : (c <= 6963 || (c < 6992
                  ? (c >= 6981 && c <= 6988)
                  : (c <= 7001 || (c >= 7043 && c <= 7072)))))
              : (c <= 7141 || (c < 7296
                ? (c < 7232
                  ? (c >= 7168 && c <= 7203)
                  : (c <= 7241 || (c >= 7245 && c <= 7293)))
                : (c <= 7304 || (c < 7357
                  ? (c >= 7312 && c <= 7354)
                  : c <= 7359)))))
            : (c <= 7404 || (c < 8008
              ? (c < 7424
                ? (c < 7413
                  ? (c >= 7406 && c <= 7411)
                  : (c <= 7414 || c == 7418))
                : (c <= 7615 || (c < 7960
                  ? (c >= 7680 && c <= 7957)
                  : (c <= 7965 || (c >= 7968 && c <= 8005)))))
              : (c <= 8013 || (c < 8029
                ? (c < 8025
                  ? (c >= 8016 && c <= 8023)
                  : (c <= 8025 || c == 8027))
                : (c <= 8029 || (c < 8064
                  ? (c >= 8031 && c <= 8061)
                  : c <= 8116)))))))
          : (c <= 8124 || (c < 8455
            ? (c < 8182
              ? (c < 8144
                ? (c < 8130
                  ? c == 8126
                  : (c <= 8132 || (c >= 8134 && c <= 8140)))
                : (c <= 8147 || (c < 8160
                  ? (c >= 8150 && c <= 8155)
                  : (c <= 8172 || (c >= 8178 && c <= 8180)))))
              : (c <= 8188 || (c < 8319
                ? (c < 8304
                  ? (c >= 8232 && c <= 8233)
                  : (c <= 8305 || (c >= 8308 && c <= 8313)))
                : (c <= 8329 || (c < 8450
                  ? (c >= 8336 && c <= 8348)
                  : c <= 8450)))))
            : (c <= 8455 || (c < 8495
              ? (c < 8484
                ? (c < 8469
                  ? (c >= 8458 && c <= 8467)
                  : (c <= 8469 || (c >= 8473 && c <= 8477)))
                : (c <= 8484 || (c < 8488
                  ? c == 8486
                  : (c <= 8488 || (c >= 8490 && c <= 8493)))))
              : (c <= 8505 || (c < 8528
                ? (c < 8517
                  ? (c >= 8508 && c <= 8511)
                  : (c <= 8521 || c == 8526))
                : (c <= 8585 || (c < 9450
                  ? (c >= 9312 && c <= 9371)
                  : c <= 9471)))))))))
        : (c <= 10131 || (c < 12690
          ? (c < 11712
            ? (c < 11568
              ? (c < 11517
                ? (c < 11499
                  ? (c >= 11264 && c <= 11492)
                  : (c <= 11502 || (c >= 11506 && c <= 11507)))
                : (c <= 11517 || (c < 11559
                  ? (c >= 11520 && c <= 11557)
                  : (c <= 11559 || c == 11565))))
              : (c <= 11623 || (c < 11688
                ? (c < 11648
                  ? c == 11631
                  : (c <= 11670 || (c >= 11680 && c <= 11686)))
                : (c <= 11694 || (c < 11704
                  ? (c >= 11696 && c <= 11702)
                  : c <= 11710)))))
            : (c <= 11718 || (c < 12344
              ? (c < 11823
                ? (c < 11728
                  ? (c >= 11720 && c <= 11726)
                  : (c <= 11734 || (c >= 11736 && c <= 11742)))
                : (c <= 11823 || (c < 12321
                  ? (c >= 12293 && c <= 12295)
                  : (c <= 12329 || (c >= 12337 && c <= 12341)))))
              : (c <= 12348 || (c < 12540
                ? (c < 12445
                  ? (c >= 12353 && c <= 12438)
                  : (c <= 12447 || (c >= 12449 && c <= 12538)))
                : (c <= 12543 || (c < 12593
                  ? (c >= 12549 && c <= 12591)
                  : c <= 12686)))))))
          : (c <= 12693 || (c < 42560
            ? (c < 13312
              ? (c < 12872
                ? (c < 12784
                  ? (c >= 12704 && c <= 12735)
                  : (c <= 12799 || (c >= 12832 && c <= 12841)))
                : (c <= 12879 || (c < 12928
                  ? (c >= 12881 && c <= 12895)
                  : (c <= 12937 || (c >= 12977 && c <= 12991)))))
              : (c <= 13312 || (c < 42192
                ? (c < 19968
                  ? c == 19903
                  : (c <= 19968 || (c >= 40959 && c <= 42124)))
                : (c <= 42237 || (c < 42512
                  ? (c >= 42240 && c <= 42508)
                  : c <= 42539)))))
            : (c <= 42606 || (c < 42965
              ? (c < 42786
                ? (c < 42656
                  ? (c >= 42623 && c <= 42653)
                  : (c <= 42735 || (c >= 42775 && c <= 42783)))
                : (c <= 42888 || (c < 42960
                  ? (c >= 42891 && c <= 42954)
                  : (c <= 42961 || c == 42963))))
              : (c <= 42969 || (c < 43020
                ? (c < 43011
                  ? (c >= 42994 && c <= 43009)
                  : (c <= 43013 || (c >= 43015 && c <= 43018)))
                : (c <= 43042 || (c < 43072
                  ? (c >= 43056 && c <= 43061)
                  : c <= 43123)))))))))))
      : (c <= 43187 || (c < 65345
        ? (c < 43808
          ? (c < 43600
            ? (c < 43396
              ? (c < 43261
                ? (c < 43250
                  ? (c >= 43216 && c <= 43225)
                  : (c <= 43255 || c == 43259))
                : (c <= 43262 || (c < 43312
                  ? (c >= 43264 && c <= 43301)
                  : (c <= 43334 || (c >= 43360 && c <= 43388)))))
              : (c <= 43442 || (c < 43520
                ? (c < 43488
                  ? (c >= 43471 && c <= 43481)
                  : (c <= 43492 || (c >= 43494 && c <= 43518)))
                : (c <= 43560 || (c < 43588
                  ? (c >= 43584 && c <= 43586)
                  : c <= 43595)))))
            : (c <= 43609 || (c < 43714
              ? (c < 43697
                ? (c < 43642
                  ? (c >= 43616 && c <= 43638)
                  : (c <= 43642 || (c >= 43646 && c <= 43695)))
                : (c <= 43697 || (c < 43705
                  ? (c >= 43701 && c <= 43702)
                  : (c <= 43709 || c == 43712))))
              : (c <= 43714 || (c < 43777
                ? (c < 43744
                  ? (c >= 43739 && c <= 43741)
                  : (c <= 43754 || (c >= 43762 && c <= 43764)))
                : (c <= 43782 || (c < 43793
                  ? (c >= 43785 && c <= 43790)
                  : c <= 43798)))))))
          : (c <= 43814 || (c < 64287
            ? (c < 55216
              ? (c < 43888
                ? (c < 43824
                  ? (c >= 43816 && c <= 43822)
                  : (c <= 43866 || (c >= 43868 && c <= 43881)))
                : (c <= 44002 || (c < 44032
                  ? (c >= 44016 && c <= 44025)
                  : (c <= 44032 || c == 55203))))
              : (c <= 55238 || (c < 64256
                ? (c < 63744
                  ? (c >= 55243 && c <= 55291)
                  : (c <= 64109 || (c >= 64112 && c <= 64217)))
                : (c <= 64262 || (c < 64285
                  ? (c >= 64275 && c <= 64279)
                  : c <= 64285)))))
            : (c <= 64296 || (c < 64848
              ? (c < 64320
                ? (c < 64312
                  ? (c >= 64298 && c <= 64310)
                  : (c <= 64316 || c == 64318))
                : (c <= 64321 || (c < 64326
                  ? (c >= 64323 && c <= 64324)
                  : (c <= 64433 || (c >= 64467 && c <= 64829)))))
              : (c <= 64911 || (c < 65142
                ? (c < 65008
                  ? (c >= 64914 && c <= 64967)
                  : (c <= 65019 || (c >= 65136 && c <= 65140)))
                : (c <= 65276 || (c < 65313
                  ? (c >= 65296 && c <= 65305)
                  : c <= 65338)))))))))
        : (c <= 65370 || (c < 66816
          ? (c < 65930
            ? (c < 65576
              ? (c < 65490
                ? (c < 65474
                  ? (c >= 65382 && c <= 65470)
                  : (c <= 65479 || (c >= 65482 && c <= 65487)))
                : (c <= 65495 || (c < 65536
                  ? (c >= 65498 && c <= 65500)
                  : (c <= 65547 || (c >= 65549 && c <= 65574)))))
              : (c <= 65594 || (c < 65664
                ? (c < 65599
                  ? (c >= 65596 && c <= 65597)
                  : (c <= 65613 || (c >= 65616 && c <= 65629)))
                : (c <= 65786 || (c < 65856
                  ? (c >= 65799 && c <= 65843)
                  : c <= 65912)))))
            : (c <= 65931 || (c < 66464
              ? (c < 66304
                ? (c < 66208
                  ? (c >= 66176 && c <= 66204)
                  : (c <= 66256 || (c >= 66273 && c <= 66299)))
                : (c <= 66339 || (c < 66384
                  ? (c >= 66349 && c <= 66378)
                  : (c <= 66421 || (c >= 66432 && c <= 66461)))))
              : (c <= 66499 || (c < 66720
                ? (c < 66513
                  ? (c >= 66504 && c <= 66511)
                  : (c <= 66517 || (c >= 66560 && c <= 66717)))
                : (c <= 66729 || (c < 66776
                  ? (c >= 66736 && c <= 66771)
                  : c <= 66811)))))))
          : (c <= 66855 || (c < 67506
            ? (c < 66995
              ? (c < 66956
                ? (c < 66928
                  ? (c >= 66864 && c <= 66915)
                  : (c <= 66938 || (c >= 66940 && c <= 66954)))
                : (c <= 66962 || (c < 66967
                  ? (c >= 66964 && c <= 66965)
                  : (c <= 66977 || (c >= 66979 && c <= 66993)))))
              : (c <= 67001 || (c < 67424
                ? (c < 67072
                  ? (c >= 67003 && c <= 67004)
                  : (c <= 67382 || (c >= 67392 && c <= 67413)))
                : (c <= 67431 || (c < 67463
                  ? (c >= 67456 && c <= 67461)
                  : c <= 67504)))))
            : (c <= 67514 || (c < 67672
              ? (c < 67639
                ? (c < 67592
                  ? (c >= 67584 && c <= 67589)
                  : (c <= 67592 || (c >= 67594 && c <= 67637)))
                : (c <= 67640 || (c < 67647
                  ? c == 67644
                  : c <= 67669)))
              : (c <= 67702 || (c < 67828
                ? (c < 67751
                  ? (c >= 67705 && c <= 67742)
                  : (c <= 67759 || (c >= 67808 && c <= 67826)))
                : (c <= 67829 || (c < 67872
                  ? (c >= 67835 && c <= 67867)
                  : c <= 67883)))))))))))))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  switch (state) {
    case 0:
      if (eof) ADVANCE(6);
      if (!eof && lookahead == 0) ADVANCE(10);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '\r') ADVANCE(8);
      if (lookahead == '(') ADVANCE(24);
      if (lookahead == ')') ADVANCE(25);
      if (lookahead == '*') ADVANCE(17);
      if (lookahead == '.') ADVANCE(22);
      if (lookahead == '/') ADVANCE(19);
      if (lookahead == ':') ADVANCE(23);
      if (lookahead == '`') ADVANCE(21);
      if (lookahead == 'w') ADVANCE(4);
      if (lookahead == '|') ADVANCE(26);
      if (lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(12);
      if (!aux_sym_punc_token4_character_set_1(lookahead)) ADVANCE(27);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '\r') ADVANCE(8);
      if (lookahead == '(') ADVANCE(24);
      if (lookahead == ')') ADVANCE(25);
      if (lookahead == '*') ADVANCE(17);
      if (lookahead == '.') ADVANCE(22);
      if (lookahead == '/') ADVANCE(19);
      if (lookahead == ':') ADVANCE(23);
      if (lookahead == '`') ADVANCE(21);
      if (lookahead == 'w') ADVANCE(4);
      if (lookahead == '|') ADVANCE(26);
      if (lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(12);
      if (!aux_sym_punc_token4_character_set_1(lookahead)) ADVANCE(27);
      END_STATE();
    case 2:
      if (lookahead == '*') ADVANCE(16);
      if (lookahead == '/') ADVANCE(18);
      if (lookahead == '`') ADVANCE(20);
      END_STATE();
    case 3:
      if (lookahead == 'd') ADVANCE(11);
      END_STATE();
    case 4:
      if (lookahead == 'o') ADVANCE(5);
      END_STATE();
    case 5:
      if (lookahead == 'r') ADVANCE(3);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_LF);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_CR);
      if (lookahead == '\n') ADVANCE(9);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_CR_LF);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_NULL);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_word);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(aux_sym_ws_token1);
      if (lookahead == ' ' ||
          lookahead == 160 ||
          lookahead == 5760 ||
          (8192 <= lookahead && lookahead <= 8202) ||
          lookahead == 8239 ||
          lookahead == 8287 ||
          lookahead == 12288) ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(aux_sym_punc_token1);
      if (lookahead == '*') ADVANCE(13);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(aux_sym_punc_token2);
      if (lookahead == '/') ADVANCE(14);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(aux_sym_punc_token3);
      if (lookahead == '`') ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(13);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '/') ADVANCE(14);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_BQUOTE);
      if (lookahead == '`') ADVANCE(15);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(aux_sym_punc_token4);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0, .external_lex_state = 1},
  [1] = {.lex_state = 0, .external_lex_state = 2},
  [2] = {.lex_state = 0, .external_lex_state = 2},
  [3] = {.lex_state = 0, .external_lex_state = 2},
  [4] = {.lex_state = 1, .external_lex_state = 3},
  [5] = {.lex_state = 1, .external_lex_state = 3},
  [6] = {.lex_state = 1, .external_lex_state = 3},
  [7] = {.lex_state = 1, .external_lex_state = 4},
  [8] = {.lex_state = 1, .external_lex_state = 4},
  [9] = {.lex_state = 1, .external_lex_state = 4},
  [10] = {.lex_state = 1, .external_lex_state = 5},
  [11] = {.lex_state = 1, .external_lex_state = 5},
  [12] = {.lex_state = 1, .external_lex_state = 4},
  [13] = {.lex_state = 1, .external_lex_state = 5},
  [14] = {.lex_state = 1, .external_lex_state = 5},
  [15] = {.lex_state = 1, .external_lex_state = 2},
  [16] = {.lex_state = 1, .external_lex_state = 6},
  [17] = {.lex_state = 1, .external_lex_state = 7},
  [18] = {.lex_state = 1, .external_lex_state = 8},
  [19] = {.lex_state = 1, .external_lex_state = 3},
  [20] = {.lex_state = 1, .external_lex_state = 3},
  [21] = {.lex_state = 1, .external_lex_state = 2},
  [22] = {.lex_state = 1, .external_lex_state = 2},
  [23] = {.lex_state = 1, .external_lex_state = 3},
  [24] = {.lex_state = 1, .external_lex_state = 5},
  [25] = {.lex_state = 1, .external_lex_state = 2},
  [26] = {.lex_state = 1, .external_lex_state = 4},
  [27] = {.lex_state = 1, .external_lex_state = 2},
  [28] = {.lex_state = 1, .external_lex_state = 2},
  [29] = {.lex_state = 1, .external_lex_state = 2},
  [30] = {.lex_state = 1, .external_lex_state = 3},
  [31] = {.lex_state = 1, .external_lex_state = 5},
  [32] = {.lex_state = 1, .external_lex_state = 4},
  [33] = {.lex_state = 1, .external_lex_state = 5},
  [34] = {.lex_state = 1, .external_lex_state = 4},
  [35] = {.lex_state = 1, .external_lex_state = 5},
  [36] = {.lex_state = 1, .external_lex_state = 3},
  [37] = {.lex_state = 1, .external_lex_state = 5},
  [38] = {.lex_state = 1, .external_lex_state = 9},
  [39] = {.lex_state = 1, .external_lex_state = 9},
  [40] = {.lex_state = 1, .external_lex_state = 3},
  [41] = {.lex_state = 1, .external_lex_state = 5},
  [42] = {.lex_state = 1, .external_lex_state = 3},
  [43] = {.lex_state = 1, .external_lex_state = 4},
  [44] = {.lex_state = 1, .external_lex_state = 4},
  [45] = {.lex_state = 1, .external_lex_state = 3},
  [46] = {.lex_state = 1, .external_lex_state = 9},
  [47] = {.lex_state = 1, .external_lex_state = 3},
  [48] = {.lex_state = 1, .external_lex_state = 4},
  [49] = {.lex_state = 0, .external_lex_state = 2},
  [50] = {.lex_state = 1, .external_lex_state = 4},
  [51] = {.lex_state = 1, .external_lex_state = 5},
  [52] = {.lex_state = 1, .external_lex_state = 4},
  [53] = {.lex_state = 1, .external_lex_state = 3},
  [54] = {.lex_state = 1, .external_lex_state = 3},
  [55] = {.lex_state = 1, .external_lex_state = 9},
  [56] = {.lex_state = 1, .external_lex_state = 3},
  [57] = {.lex_state = 1, .external_lex_state = 4},
  [58] = {.lex_state = 1, .external_lex_state = 3},
  [59] = {.lex_state = 1, .external_lex_state = 9},
  [60] = {.lex_state = 1, .external_lex_state = 3},
  [61] = {.lex_state = 1, .external_lex_state = 5},
  [62] = {.lex_state = 1, .external_lex_state = 3},
  [63] = {.lex_state = 1, .external_lex_state = 5},
  [64] = {.lex_state = 1, .external_lex_state = 3},
  [65] = {.lex_state = 1, .external_lex_state = 3},
  [66] = {.lex_state = 1, .external_lex_state = 3},
  [67] = {.lex_state = 1, .external_lex_state = 3},
  [68] = {.lex_state = 1, .external_lex_state = 5},
  [69] = {.lex_state = 1, .external_lex_state = 4},
  [70] = {.lex_state = 1, .external_lex_state = 3},
  [71] = {.lex_state = 1, .external_lex_state = 2},
  [72] = {.lex_state = 1, .external_lex_state = 2},
  [73] = {.lex_state = 1, .external_lex_state = 2},
  [74] = {.lex_state = 1, .external_lex_state = 9},
  [75] = {.lex_state = 1, .external_lex_state = 2},
  [76] = {.lex_state = 1, .external_lex_state = 2},
  [77] = {.lex_state = 1, .external_lex_state = 2},
  [78] = {.lex_state = 1, .external_lex_state = 2},
  [79] = {.lex_state = 1, .external_lex_state = 2},
  [80] = {.lex_state = 2},
  [81] = {.lex_state = 2},
  [82] = {.lex_state = 2},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 2},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0, .external_lex_state = 10},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0, .external_lex_state = 10},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0, .external_lex_state = 10},
  [113] = {.lex_state = 0, .external_lex_state = 10},
  [114] = {.lex_state = 0, .external_lex_state = 10},
  [115] = {.lex_state = 0, .external_lex_state = 10},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 0, .external_lex_state = 10},
  [118] = {.lex_state = 0, .external_lex_state = 10},
  [119] = {.lex_state = 0, .external_lex_state = 10},
  [120] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_LF] = ACTIONS(1),
    [anon_sym_CR] = ACTIONS(1),
    [anon_sym_CR_LF] = ACTIONS(1),
    [anon_sym_NULL] = ACTIONS(1),
    [sym_word] = ACTIONS(1),
    [aux_sym_ws_token1] = ACTIONS(1),
    [aux_sym_punc_token1] = ACTIONS(1),
    [aux_sym_punc_token2] = ACTIONS(1),
    [aux_sym_punc_token3] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_BQUOTE] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [aux_sym_punc_token4] = ACTIONS(1),
    [sym__paragraph_break] = ACTIONS(1),
    [sym__open_conflict] = ACTIONS(1),
    [sym__close_conflict] = ACTIONS(1),
    [sym__lookahead_word] = ACTIONS(1),
    [sym_bold_close] = ACTIONS(1),
    [sym_italic_close] = ACTIONS(1),
    [sym_verbatim_close] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(108),
    [sym_paragraph] = STATE(3),
    [sym_punc] = STATE(5),
    [sym_verbatim_open] = STATE(72),
    [sym_verbatim] = STATE(20),
    [sym_bold_open] = STATE(29),
    [sym_bold] = STATE(20),
    [sym_italic_open] = STATE(27),
    [sym_italic] = STATE(20),
    [sym__non_ws] = STATE(5),
    [aux_sym_document_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LF] = ACTIONS(5),
    [anon_sym_CR] = ACTIONS(7),
    [anon_sym_CR_LF] = ACTIONS(5),
    [anon_sym_NULL] = ACTIONS(5),
    [sym_word] = ACTIONS(9),
    [aux_sym_punc_token1] = ACTIONS(11),
    [aux_sym_punc_token2] = ACTIONS(11),
    [aux_sym_punc_token3] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_DOT] = ACTIONS(11),
    [anon_sym_COLON] = ACTIONS(11),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_RPAREN] = ACTIONS(11),
    [anon_sym_PIPE] = ACTIONS(11),
    [aux_sym_punc_token4] = ACTIONS(19),
    [sym__close_conflict] = ACTIONS(11),
  },
  [2] = {
    [sym_paragraph] = STATE(2),
    [sym_punc] = STATE(5),
    [sym_verbatim_open] = STATE(72),
    [sym_verbatim] = STATE(20),
    [sym_bold_open] = STATE(29),
    [sym_bold] = STATE(20),
    [sym_italic_open] = STATE(27),
    [sym_italic] = STATE(20),
    [sym__non_ws] = STATE(5),
    [aux_sym_document_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(21),
    [anon_sym_LF] = ACTIONS(23),
    [anon_sym_CR] = ACTIONS(26),
    [anon_sym_CR_LF] = ACTIONS(23),
    [anon_sym_NULL] = ACTIONS(23),
    [sym_word] = ACTIONS(29),
    [aux_sym_punc_token1] = ACTIONS(32),
    [aux_sym_punc_token2] = ACTIONS(32),
    [aux_sym_punc_token3] = ACTIONS(32),
    [anon_sym_STAR] = ACTIONS(35),
    [anon_sym_SLASH] = ACTIONS(38),
    [anon_sym_BQUOTE] = ACTIONS(41),
    [anon_sym_DOT] = ACTIONS(32),
    [anon_sym_COLON] = ACTIONS(32),
    [anon_sym_LPAREN] = ACTIONS(32),
    [anon_sym_RPAREN] = ACTIONS(32),
    [anon_sym_PIPE] = ACTIONS(32),
    [aux_sym_punc_token4] = ACTIONS(44),
    [sym__close_conflict] = ACTIONS(32),
  },
  [3] = {
    [sym_paragraph] = STATE(2),
    [sym_punc] = STATE(5),
    [sym_verbatim_open] = STATE(72),
    [sym_verbatim] = STATE(20),
    [sym_bold_open] = STATE(29),
    [sym_bold] = STATE(20),
    [sym_italic_open] = STATE(27),
    [sym_italic] = STATE(20),
    [sym__non_ws] = STATE(5),
    [aux_sym_document_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(47),
    [anon_sym_LF] = ACTIONS(49),
    [anon_sym_CR] = ACTIONS(51),
    [anon_sym_CR_LF] = ACTIONS(49),
    [anon_sym_NULL] = ACTIONS(49),
    [sym_word] = ACTIONS(9),
    [aux_sym_punc_token1] = ACTIONS(11),
    [aux_sym_punc_token2] = ACTIONS(11),
    [aux_sym_punc_token3] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_DOT] = ACTIONS(11),
    [anon_sym_COLON] = ACTIONS(11),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_RPAREN] = ACTIONS(11),
    [anon_sym_PIPE] = ACTIONS(11),
    [aux_sym_punc_token4] = ACTIONS(19),
    [sym__close_conflict] = ACTIONS(11),
  },
  [4] = {
    [sym_ws] = STATE(15),
    [sym_punc] = STATE(4),
    [sym_verbatim_open] = STATE(72),
    [sym_verbatim] = STATE(20),
    [sym_bold_open] = STATE(29),
    [sym_bold] = STATE(20),
    [sym_italic_open] = STATE(27),
    [sym_italic] = STATE(20),
    [sym__non_ws] = STATE(4),
    [anon_sym_LF] = ACTIONS(53),
    [anon_sym_CR] = ACTIONS(55),
    [anon_sym_CR_LF] = ACTIONS(53),
    [sym_word] = ACTIONS(53),
    [aux_sym_ws_token1] = ACTIONS(53),
    [aux_sym_punc_token1] = ACTIONS(53),
    [aux_sym_punc_token2] = ACTIONS(53),
    [aux_sym_punc_token3] = ACTIONS(53),
    [anon_sym_STAR] = ACTIONS(55),
    [anon_sym_SLASH] = ACTIONS(55),
    [anon_sym_BQUOTE] = ACTIONS(55),
    [anon_sym_DOT] = ACTIONS(53),
    [anon_sym_COLON] = ACTIONS(53),
    [anon_sym_LPAREN] = ACTIONS(53),
    [anon_sym_RPAREN] = ACTIONS(53),
    [anon_sym_PIPE] = ACTIONS(53),
    [aux_sym_punc_token4] = ACTIONS(55),
    [sym__paragraph_break] = ACTIONS(53),
    [sym__close_conflict] = ACTIONS(53),
  },
  [5] = {
    [sym_ws] = STATE(15),
    [sym_punc] = STATE(4),
    [sym_verbatim_open] = STATE(72),
    [sym_verbatim] = STATE(20),
    [sym_bold_open] = STATE(29),
    [sym_bold] = STATE(20),
    [sym_italic_open] = STATE(27),
    [sym_italic] = STATE(20),
    [sym__non_ws] = STATE(4),
    [anon_sym_LF] = ACTIONS(57),
    [anon_sym_CR] = ACTIONS(59),
    [anon_sym_CR_LF] = ACTIONS(57),
    [sym_word] = ACTIONS(9),
    [aux_sym_ws_token1] = ACTIONS(61),
    [aux_sym_punc_token1] = ACTIONS(11),
    [aux_sym_punc_token2] = ACTIONS(11),
    [aux_sym_punc_token3] = ACTIONS(11),
    [anon_sym_STAR] = ACTIONS(13),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_BQUOTE] = ACTIONS(17),
    [anon_sym_DOT] = ACTIONS(11),
    [anon_sym_COLON] = ACTIONS(11),
    [anon_sym_LPAREN] = ACTIONS(11),
    [anon_sym_RPAREN] = ACTIONS(11),
    [anon_sym_PIPE] = ACTIONS(11),
    [aux_sym_punc_token4] = ACTIONS(19),
    [sym__paragraph_break] = ACTIONS(63),
    [sym__close_conflict] = ACTIONS(11),
  },
  [6] = {
    [sym_ws] = STATE(15),
    [sym_punc] = STATE(4),
    [sym_verbatim_open] = STATE(72),
    [sym_verbatim] = STATE(20),
    [sym_bold_open] = STATE(29),
    [sym_bold] = STATE(20),
    [sym_italic_open] = STATE(27),
    [sym_italic] = STATE(20),
    [sym__non_ws] = STATE(4),
    [anon_sym_LF] = ACTIONS(65),
    [anon_sym_CR] = ACTIONS(67),
    [anon_sym_CR_LF] = ACTIONS(65),
    [sym_word] = ACTIONS(65),
    [aux_sym_ws_token1] = ACTIONS(65),
    [aux_sym_punc_token1] = ACTIONS(65),
    [aux_sym_punc_token2] = ACTIONS(65),
    [aux_sym_punc_token3] = ACTIONS(65),
    [anon_sym_STAR] = ACTIONS(67),
    [anon_sym_SLASH] = ACTIONS(67),
    [anon_sym_BQUOTE] = ACTIONS(67),
    [anon_sym_DOT] = ACTIONS(65),
    [anon_sym_COLON] = ACTIONS(65),
    [anon_sym_LPAREN] = ACTIONS(65),
    [anon_sym_RPAREN] = ACTIONS(65),
    [anon_sym_PIPE] = ACTIONS(65),
    [aux_sym_punc_token4] = ACTIONS(67),
    [sym__paragraph_break] = ACTIONS(65),
    [sym__close_conflict] = ACTIONS(65),
  },
  [7] = {
    [sym_ws] = STATE(21),
    [sym_punc] = STATE(7),
    [sym_verbatim_open] = STATE(71),
    [sym_verbatim] = STATE(26),
    [sym_bold_open] = STATE(22),
    [sym_bold] = STATE(26),
    [sym__italic_non_ws] = STATE(7),
    [anon_sym_LF] = ACTIONS(69),
    [anon_sym_CR] = ACTIONS(71),
    [anon_sym_CR_LF] = ACTIONS(69),
    [sym_word] = ACTIONS(69),
    [aux_sym_ws_token1] = ACTIONS(69),
    [aux_sym_punc_token1] = ACTIONS(69),
    [aux_sym_punc_token2] = ACTIONS(69),
    [aux_sym_punc_token3] = ACTIONS(69),
    [anon_sym_STAR] = ACTIONS(71),
    [anon_sym_SLASH] = ACTIONS(71),
    [anon_sym_BQUOTE] = ACTIONS(71),
    [anon_sym_DOT] = ACTIONS(69),
    [anon_sym_COLON] = ACTIONS(69),
    [anon_sym_LPAREN] = ACTIONS(69),
    [anon_sym_RPAREN] = ACTIONS(69),
    [anon_sym_PIPE] = ACTIONS(69),
    [aux_sym_punc_token4] = ACTIONS(71),
    [sym__close_conflict] = ACTIONS(69),
    [sym_italic_close] = ACTIONS(69),
  },
  [8] = {
    [sym_ws] = STATE(21),
    [sym_punc] = STATE(7),
    [sym_verbatim_open] = STATE(71),
    [sym_verbatim] = STATE(26),
    [sym_bold_open] = STATE(22),
    [sym_bold] = STATE(26),
    [sym__italic_non_ws] = STATE(7),
    [anon_sym_LF] = ACTIONS(73),
    [anon_sym_CR] = ACTIONS(75),
    [anon_sym_CR_LF] = ACTIONS(73),
    [sym_word] = ACTIONS(77),
    [aux_sym_ws_token1] = ACTIONS(61),
    [aux_sym_punc_token1] = ACTIONS(79),
    [aux_sym_punc_token2] = ACTIONS(79),
    [aux_sym_punc_token3] = ACTIONS(79),
    [anon_sym_STAR] = ACTIONS(81),
    [anon_sym_SLASH] = ACTIONS(83),
    [anon_sym_BQUOTE] = ACTIONS(85),
    [anon_sym_DOT] = ACTIONS(79),
    [anon_sym_COLON] = ACTIONS(79),
    [anon_sym_LPAREN] = ACTIONS(79),
    [anon_sym_RPAREN] = ACTIONS(79),
    [anon_sym_PIPE] = ACTIONS(79),
    [aux_sym_punc_token4] = ACTIONS(83),
    [sym__close_conflict] = ACTIONS(79),
    [sym_italic_close] = ACTIONS(87),
  },
  [9] = {
    [sym_ws] = STATE(21),
    [sym_punc] = STATE(7),
    [sym_verbatim_open] = STATE(71),
    [sym_verbatim] = STATE(26),
    [sym_bold_open] = STATE(22),
    [sym_bold] = STATE(26),
    [sym__italic_non_ws] = STATE(7),
    [anon_sym_LF] = ACTIONS(89),
    [anon_sym_CR] = ACTIONS(91),
    [anon_sym_CR_LF] = ACTIONS(89),
    [sym_word] = ACTIONS(89),
    [aux_sym_ws_token1] = ACTIONS(89),
    [aux_sym_punc_token1] = ACTIONS(89),
    [aux_sym_punc_token2] = ACTIONS(89),
    [aux_sym_punc_token3] = ACTIONS(89),
    [anon_sym_STAR] = ACTIONS(91),
    [anon_sym_SLASH] = ACTIONS(91),
    [anon_sym_BQUOTE] = ACTIONS(91),
    [anon_sym_DOT] = ACTIONS(89),
    [anon_sym_COLON] = ACTIONS(89),
    [anon_sym_LPAREN] = ACTIONS(89),
    [anon_sym_RPAREN] = ACTIONS(89),
    [anon_sym_PIPE] = ACTIONS(89),
    [aux_sym_punc_token4] = ACTIONS(91),
    [sym__close_conflict] = ACTIONS(89),
    [sym_italic_close] = ACTIONS(89),
  },
  [10] = {
    [sym_ws] = STATE(28),
    [sym_punc] = STATE(14),
    [sym_verbatim_open] = STATE(73),
    [sym_verbatim] = STATE(24),
    [sym__bold_non_ws] = STATE(14),
    [sym_italic_open] = STATE(25),
    [sym_italic] = STATE(24),
    [anon_sym_LF] = ACTIONS(93),
    [anon_sym_CR] = ACTIONS(95),
    [anon_sym_CR_LF] = ACTIONS(93),
    [sym_word] = ACTIONS(93),
    [aux_sym_ws_token1] = ACTIONS(93),
    [aux_sym_punc_token1] = ACTIONS(93),
    [aux_sym_punc_token2] = ACTIONS(93),
    [aux_sym_punc_token3] = ACTIONS(93),
    [anon_sym_STAR] = ACTIONS(95),
    [anon_sym_SLASH] = ACTIONS(95),
    [anon_sym_BQUOTE] = ACTIONS(95),
    [anon_sym_DOT] = ACTIONS(93),
    [anon_sym_COLON] = ACTIONS(93),
    [anon_sym_LPAREN] = ACTIONS(93),
    [anon_sym_RPAREN] = ACTIONS(93),
    [anon_sym_PIPE] = ACTIONS(93),
    [aux_sym_punc_token4] = ACTIONS(95),
    [sym__close_conflict] = ACTIONS(93),
    [sym_bold_close] = ACTIONS(93),
  },
  [11] = {
    [sym_ws] = STATE(28),
    [sym_punc] = STATE(14),
    [sym_verbatim_open] = STATE(73),
    [sym_verbatim] = STATE(24),
    [sym__bold_non_ws] = STATE(14),
    [sym_italic_open] = STATE(25),
    [sym_italic] = STATE(24),
    [anon_sym_LF] = ACTIONS(97),
    [anon_sym_CR] = ACTIONS(99),
    [anon_sym_CR_LF] = ACTIONS(97),
    [sym_word] = ACTIONS(101),
    [aux_sym_ws_token1] = ACTIONS(61),
    [aux_sym_punc_token1] = ACTIONS(103),
    [aux_sym_punc_token2] = ACTIONS(103),
    [aux_sym_punc_token3] = ACTIONS(103),
    [anon_sym_STAR] = ACTIONS(105),
    [anon_sym_SLASH] = ACTIONS(107),
    [anon_sym_BQUOTE] = ACTIONS(109),
    [anon_sym_DOT] = ACTIONS(103),
    [anon_sym_COLON] = ACTIONS(103),
    [anon_sym_LPAREN] = ACTIONS(103),
    [anon_sym_RPAREN] = ACTIONS(103),
    [anon_sym_PIPE] = ACTIONS(103),
    [aux_sym_punc_token4] = ACTIONS(105),
    [sym__close_conflict] = ACTIONS(103),
    [sym_bold_close] = ACTIONS(111),
  },
  [12] = {
    [sym_ws] = STATE(21),
    [sym_punc] = STATE(7),
    [sym_verbatim_open] = STATE(71),
    [sym_verbatim] = STATE(26),
    [sym_bold_open] = STATE(22),
    [sym_bold] = STATE(26),
    [sym__italic_non_ws] = STATE(7),
    [anon_sym_LF] = ACTIONS(73),
    [anon_sym_CR] = ACTIONS(75),
    [anon_sym_CR_LF] = ACTIONS(73),
    [sym_word] = ACTIONS(77),
    [aux_sym_ws_token1] = ACTIONS(61),
    [aux_sym_punc_token1] = ACTIONS(79),
    [aux_sym_punc_token2] = ACTIONS(79),
    [aux_sym_punc_token3] = ACTIONS(79),
    [anon_sym_STAR] = ACTIONS(81),
    [anon_sym_SLASH] = ACTIONS(83),
    [anon_sym_BQUOTE] = ACTIONS(85),
    [anon_sym_DOT] = ACTIONS(79),
    [anon_sym_COLON] = ACTIONS(79),
    [anon_sym_LPAREN] = ACTIONS(79),
    [anon_sym_RPAREN] = ACTIONS(79),
    [anon_sym_PIPE] = ACTIONS(79),
    [aux_sym_punc_token4] = ACTIONS(83),
    [sym__close_conflict] = ACTIONS(79),
    [sym_italic_close] = ACTIONS(113),
  },
  [13] = {
    [sym_ws] = STATE(28),
    [sym_punc] = STATE(14),
    [sym_verbatim_open] = STATE(73),
    [sym_verbatim] = STATE(24),
    [sym__bold_non_ws] = STATE(14),
    [sym_italic_open] = STATE(25),
    [sym_italic] = STATE(24),
    [anon_sym_LF] = ACTIONS(97),
    [anon_sym_CR] = ACTIONS(99),
    [anon_sym_CR_LF] = ACTIONS(97),
    [sym_word] = ACTIONS(101),
    [aux_sym_ws_token1] = ACTIONS(61),
    [aux_sym_punc_token1] = ACTIONS(103),
    [aux_sym_punc_token2] = ACTIONS(103),
    [aux_sym_punc_token3] = ACTIONS(103),
    [anon_sym_STAR] = ACTIONS(105),
    [anon_sym_SLASH] = ACTIONS(107),
    [anon_sym_BQUOTE] = ACTIONS(109),
    [anon_sym_DOT] = ACTIONS(103),
    [anon_sym_COLON] = ACTIONS(103),
    [anon_sym_LPAREN] = ACTIONS(103),
    [anon_sym_RPAREN] = ACTIONS(103),
    [anon_sym_PIPE] = ACTIONS(103),
    [aux_sym_punc_token4] = ACTIONS(105),
    [sym__close_conflict] = ACTIONS(103),
    [sym_bold_close] = ACTIONS(115),
  },
  [14] = {
    [sym_ws] = STATE(28),
    [sym_punc] = STATE(14),
    [sym_verbatim_open] = STATE(73),
    [sym_verbatim] = STATE(24),
    [sym__bold_non_ws] = STATE(14),
    [sym_italic_open] = STATE(25),
    [sym_italic] = STATE(24),
    [anon_sym_LF] = ACTIONS(117),
    [anon_sym_CR] = ACTIONS(119),
    [anon_sym_CR_LF] = ACTIONS(117),
    [sym_word] = ACTIONS(117),
    [aux_sym_ws_token1] = ACTIONS(117),
    [aux_sym_punc_token1] = ACTIONS(117),
    [aux_sym_punc_token2] = ACTIONS(117),
    [aux_sym_punc_token3] = ACTIONS(117),
    [anon_sym_STAR] = ACTIONS(119),
    [anon_sym_SLASH] = ACTIONS(119),
    [anon_sym_BQUOTE] = ACTIONS(119),
    [anon_sym_DOT] = ACTIONS(117),
    [anon_sym_COLON] = ACTIONS(117),
    [anon_sym_LPAREN] = ACTIONS(117),
    [anon_sym_RPAREN] = ACTIONS(117),
    [anon_sym_PIPE] = ACTIONS(117),
    [aux_sym_punc_token4] = ACTIONS(119),
    [sym__close_conflict] = ACTIONS(117),
    [sym_bold_close] = ACTIONS(117),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(9), 1,
      sym_word,
    ACTIONS(13), 1,
      anon_sym_STAR,
    ACTIONS(15), 1,
      anon_sym_SLASH,
    ACTIONS(17), 1,
      anon_sym_BQUOTE,
    ACTIONS(19), 1,
      aux_sym_punc_token4,
    STATE(27), 1,
      sym_italic_open,
    STATE(29), 1,
      sym_bold_open,
    STATE(72), 1,
      sym_verbatim_open,
    STATE(6), 2,
      sym_punc,
      sym__non_ws,
    STATE(20), 3,
      sym_verbatim,
      sym_bold,
      sym_italic,
    ACTIONS(11), 9,
      sym__close_conflict,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [45] = 5,
    ACTIONS(125), 1,
      anon_sym_COLON,
    ACTIONS(128), 1,
      sym__open_conflict,
    STATE(81), 1,
      sym_link_modifier,
    ACTIONS(123), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(121), 13,
      sym__close_conflict,
      sym_italic_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [77] = 5,
    ACTIONS(134), 1,
      anon_sym_COLON,
    ACTIONS(137), 1,
      sym__open_conflict,
    STATE(80), 1,
      sym_link_modifier,
    ACTIONS(132), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(130), 13,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [109] = 5,
    ACTIONS(143), 1,
      anon_sym_COLON,
    ACTIONS(146), 1,
      sym__open_conflict,
    STATE(82), 1,
      sym_link_modifier,
    ACTIONS(141), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(139), 13,
      sym__close_conflict,
      sym_bold_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [141] = 6,
    ACTIONS(148), 1,
      anon_sym_COLON,
    ACTIONS(151), 1,
      anon_sym_LPAREN,
    STATE(30), 1,
      sym_attached_modifier_extension,
    STATE(112), 1,
      sym_link_modifier,
    ACTIONS(67), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(65), 12,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [175] = 6,
    ACTIONS(154), 1,
      anon_sym_COLON,
    ACTIONS(157), 1,
      anon_sym_LPAREN,
    STATE(23), 1,
      sym_attached_modifier_extension,
    STATE(118), 1,
      sym_link_modifier,
    ACTIONS(132), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(130), 12,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [209] = 9,
    ACTIONS(77), 1,
      sym_word,
    ACTIONS(81), 1,
      anon_sym_STAR,
    ACTIONS(85), 1,
      anon_sym_BQUOTE,
    STATE(22), 1,
      sym_bold_open,
    STATE(71), 1,
      sym_verbatim_open,
    ACTIONS(83), 2,
      anon_sym_SLASH,
      aux_sym_punc_token4,
    STATE(9), 2,
      sym_punc,
      sym__italic_non_ws,
    STATE(26), 2,
      sym_verbatim,
      sym_bold,
    ACTIONS(79), 9,
      sym__close_conflict,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [248] = 9,
    ACTIONS(101), 1,
      sym_word,
    ACTIONS(107), 1,
      anon_sym_SLASH,
    ACTIONS(109), 1,
      anon_sym_BQUOTE,
    STATE(25), 1,
      sym_italic_open,
    STATE(73), 1,
      sym_verbatim_open,
    ACTIONS(105), 2,
      anon_sym_STAR,
      aux_sym_punc_token4,
    STATE(11), 2,
      sym_punc,
      sym__bold_non_ws,
    STATE(24), 2,
      sym_verbatim,
      sym_italic,
    ACTIONS(103), 9,
      sym__close_conflict,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [287] = 4,
    ACTIONS(160), 1,
      anon_sym_COLON,
    STATE(115), 1,
      sym_link_modifier,
    ACTIONS(55), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(53), 13,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [316] = 4,
    ACTIONS(163), 1,
      anon_sym_COLON,
    STATE(114), 1,
      sym_link_modifier,
    ACTIONS(141), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(139), 13,
      sym__close_conflict,
      sym_bold_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [345] = 9,
    ACTIONS(77), 1,
      sym_word,
    ACTIONS(81), 1,
      anon_sym_STAR,
    ACTIONS(85), 1,
      anon_sym_BQUOTE,
    STATE(22), 1,
      sym_bold_open,
    STATE(71), 1,
      sym_verbatim_open,
    ACTIONS(83), 2,
      anon_sym_SLASH,
      aux_sym_punc_token4,
    STATE(8), 2,
      sym_punc,
      sym__italic_non_ws,
    STATE(26), 2,
      sym_verbatim,
      sym_bold,
    ACTIONS(79), 9,
      sym__close_conflict,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [384] = 4,
    ACTIONS(166), 1,
      anon_sym_COLON,
    STATE(113), 1,
      sym_link_modifier,
    ACTIONS(123), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(121), 13,
      sym__close_conflict,
      sym_italic_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [413] = 9,
    ACTIONS(77), 1,
      sym_word,
    ACTIONS(81), 1,
      anon_sym_STAR,
    ACTIONS(85), 1,
      anon_sym_BQUOTE,
    STATE(22), 1,
      sym_bold_open,
    STATE(71), 1,
      sym_verbatim_open,
    ACTIONS(83), 2,
      anon_sym_SLASH,
      aux_sym_punc_token4,
    STATE(12), 2,
      sym_punc,
      sym__italic_non_ws,
    STATE(26), 2,
      sym_verbatim,
      sym_bold,
    ACTIONS(79), 9,
      sym__close_conflict,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [452] = 9,
    ACTIONS(101), 1,
      sym_word,
    ACTIONS(107), 1,
      anon_sym_SLASH,
    ACTIONS(109), 1,
      anon_sym_BQUOTE,
    STATE(25), 1,
      sym_italic_open,
    STATE(73), 1,
      sym_verbatim_open,
    ACTIONS(105), 2,
      anon_sym_STAR,
      aux_sym_punc_token4,
    STATE(10), 2,
      sym_punc,
      sym__bold_non_ws,
    STATE(24), 2,
      sym_verbatim,
      sym_italic,
    ACTIONS(103), 9,
      sym__close_conflict,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [491] = 9,
    ACTIONS(101), 1,
      sym_word,
    ACTIONS(107), 1,
      anon_sym_SLASH,
    ACTIONS(109), 1,
      anon_sym_BQUOTE,
    STATE(25), 1,
      sym_italic_open,
    STATE(73), 1,
      sym_verbatim_open,
    ACTIONS(105), 2,
      anon_sym_STAR,
      aux_sym_punc_token4,
    STATE(13), 2,
      sym_punc,
      sym__bold_non_ws,
    STATE(24), 2,
      sym_verbatim,
      sym_italic,
    ACTIONS(103), 9,
      sym__close_conflict,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [530] = 4,
    ACTIONS(173), 1,
      anon_sym_COLON,
    STATE(119), 1,
      sym_link_modifier,
    ACTIONS(171), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(169), 13,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [559] = 4,
    ACTIONS(176), 1,
      anon_sym_COLON,
    STATE(117), 1,
      sym_link_modifier,
    ACTIONS(95), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(93), 13,
      sym__close_conflict,
      sym_bold_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [588] = 4,
    ACTIONS(179), 1,
      anon_sym_COLON,
    STATE(109), 1,
      sym_link_modifier,
    ACTIONS(91), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(89), 13,
      sym__close_conflict,
      sym_italic_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [617] = 2,
    ACTIONS(119), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(117), 14,
      sym__close_conflict,
      sym_bold_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [641] = 4,
    ACTIONS(184), 1,
      anon_sym_CR,
    ACTIONS(182), 4,
      sym_italic_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      aux_sym_ws_token1,
    ACTIONS(189), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(186), 10,
      sym__close_conflict,
      sym_word,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [669] = 2,
    ACTIONS(194), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(192), 14,
      sym__close_conflict,
      sym_bold_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [693] = 2,
    ACTIONS(194), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(192), 14,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [717] = 4,
    ACTIONS(184), 1,
      anon_sym_CR,
    ACTIONS(182), 4,
      sym_bold_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      aux_sym_ws_token1,
    ACTIONS(189), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(186), 10,
      sym__close_conflict,
      sym_word,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [745] = 4,
    STATE(75), 1,
      sym_ws,
    STATE(38), 2,
      sym_punc,
      sym__verbatim_non_ws,
    ACTIONS(198), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(196), 12,
      sym__close_conflict,
      sym_verbatim_close,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [773] = 7,
    ACTIONS(61), 1,
      aux_sym_ws_token1,
    ACTIONS(200), 1,
      sym_word,
    ACTIONS(206), 1,
      sym_verbatim_close,
    STATE(75), 1,
      sym_ws,
    STATE(38), 2,
      sym_punc,
      sym__verbatim_non_ws,
    ACTIONS(204), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(202), 9,
      sym__close_conflict,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [807] = 2,
    ACTIONS(184), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(182), 14,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [831] = 4,
    ACTIONS(184), 1,
      anon_sym_CR,
    ACTIONS(182), 4,
      sym_bold_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      aux_sym_ws_token1,
    ACTIONS(211), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(208), 10,
      sym__close_conflict,
      sym_word,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [859] = 2,
    ACTIONS(67), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(65), 14,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [883] = 4,
    ACTIONS(184), 1,
      anon_sym_CR,
    ACTIONS(182), 4,
      sym_italic_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      aux_sym_ws_token1,
    ACTIONS(217), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(214), 10,
      sym__close_conflict,
      sym_word,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [911] = 2,
    ACTIONS(222), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(220), 14,
      sym__close_conflict,
      sym_italic_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [935] = 2,
    ACTIONS(226), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(224), 14,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [959] = 7,
    ACTIONS(61), 1,
      aux_sym_ws_token1,
    ACTIONS(200), 1,
      sym_word,
    ACTIONS(228), 1,
      sym_verbatim_close,
    STATE(75), 1,
      sym_ws,
    STATE(38), 2,
      sym_punc,
      sym__verbatim_non_ws,
    ACTIONS(204), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(202), 9,
      sym__close_conflict,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [993] = 2,
    ACTIONS(222), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(220), 14,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1017] = 2,
    ACTIONS(232), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(230), 14,
      sym__close_conflict,
      sym_italic_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1041] = 2,
    ACTIONS(236), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(234), 14,
      sym__close_conflict,
      ts_builtin_sym_end,
      anon_sym_LF,
      anon_sym_CR_LF,
      anon_sym_NULL,
      sym_word,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1065] = 2,
    ACTIONS(71), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(69), 14,
      sym__close_conflict,
      sym_italic_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1089] = 2,
    ACTIONS(240), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(238), 14,
      sym__close_conflict,
      sym_bold_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1113] = 2,
    ACTIONS(184), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(182), 14,
      sym__close_conflict,
      sym_italic_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1137] = 2,
    ACTIONS(244), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(242), 14,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1161] = 2,
    ACTIONS(248), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(246), 14,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1185] = 7,
    ACTIONS(61), 1,
      aux_sym_ws_token1,
    ACTIONS(200), 1,
      sym_word,
    ACTIONS(250), 1,
      sym_verbatim_close,
    STATE(75), 1,
      sym_ws,
    STATE(38), 2,
      sym_punc,
      sym__verbatim_non_ws,
    ACTIONS(204), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(202), 9,
      sym__close_conflict,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1219] = 4,
    ACTIONS(184), 1,
      anon_sym_CR,
    ACTIONS(182), 4,
      sym__paragraph_break,
      anon_sym_LF,
      anon_sym_CR_LF,
      aux_sym_ws_token1,
    ACTIONS(217), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(214), 10,
      sym__close_conflict,
      sym_word,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1247] = 2,
    ACTIONS(194), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(192), 14,
      sym__close_conflict,
      sym_italic_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1271] = 2,
    ACTIONS(55), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(53), 14,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1295] = 4,
    STATE(75), 1,
      sym_ws,
    STATE(38), 2,
      sym_punc,
      sym__verbatim_non_ws,
    ACTIONS(254), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(252), 12,
      sym__close_conflict,
      sym_verbatim_close,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1323] = 2,
    ACTIONS(258), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(256), 14,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1347] = 2,
    ACTIONS(184), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(182), 14,
      sym__close_conflict,
      sym_bold_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1371] = 2,
    ACTIONS(262), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(260), 14,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1395] = 2,
    ACTIONS(244), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(242), 14,
      sym__close_conflict,
      sym_bold_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1419] = 2,
    ACTIONS(266), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(264), 14,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1443] = 2,
    ACTIONS(270), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(268), 14,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1467] = 2,
    ACTIONS(171), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(169), 14,
      sym__paragraph_break,
      sym__close_conflict,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1491] = 4,
    ACTIONS(184), 1,
      anon_sym_CR,
    ACTIONS(182), 4,
      sym__paragraph_break,
      anon_sym_LF,
      anon_sym_CR_LF,
      aux_sym_ws_token1,
    ACTIONS(211), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(208), 10,
      sym__close_conflict,
      sym_word,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1519] = 2,
    ACTIONS(95), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(93), 14,
      sym__close_conflict,
      sym_bold_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1543] = 2,
    ACTIONS(91), 5,
      anon_sym_CR,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(89), 14,
      sym__close_conflict,
      sym_italic_close,
      anon_sym_LF,
      anon_sym_CR_LF,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1567] = 4,
    ACTIONS(184), 1,
      anon_sym_CR,
    ACTIONS(182), 4,
      sym__paragraph_break,
      anon_sym_LF,
      anon_sym_CR_LF,
      aux_sym_ws_token1,
    ACTIONS(189), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(186), 10,
      sym__close_conflict,
      sym_word,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1595] = 4,
    ACTIONS(272), 1,
      sym_word,
    STATE(39), 2,
      sym_punc,
      sym__verbatim_non_ws,
    ACTIONS(204), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(202), 9,
      sym__close_conflict,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1620] = 4,
    ACTIONS(274), 1,
      sym_word,
    STATE(55), 2,
      sym_punc,
      sym__verbatim_non_ws,
    ACTIONS(204), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(202), 9,
      sym__close_conflict,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1645] = 4,
    ACTIONS(276), 1,
      sym_word,
    STATE(46), 2,
      sym_punc,
      sym__verbatim_non_ws,
    ACTIONS(204), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(202), 9,
      sym__close_conflict,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1670] = 2,
    ACTIONS(184), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(182), 12,
      sym__close_conflict,
      sym_verbatim_close,
      sym_word,
      aux_sym_ws_token1,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1691] = 4,
    ACTIONS(278), 1,
      sym_word,
    STATE(59), 2,
      sym_punc,
      sym__verbatim_non_ws,
    ACTIONS(204), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(202), 9,
      sym__close_conflict,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1716] = 2,
    ACTIONS(282), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(280), 10,
      sym__close_conflict,
      sym_word,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1735] = 2,
    ACTIONS(286), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(284), 10,
      sym__close_conflict,
      sym_word,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1754] = 2,
    ACTIONS(290), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(288), 10,
      sym__close_conflict,
      sym_word,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1773] = 2,
    ACTIONS(294), 4,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
      aux_sym_punc_token4,
    ACTIONS(292), 10,
      sym__close_conflict,
      sym_word,
      aux_sym_punc_token1,
      aux_sym_punc_token2,
      aux_sym_punc_token3,
      anon_sym_DOT,
      anon_sym_COLON,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1792] = 7,
    ACTIONS(296), 1,
      anon_sym_STAR,
    ACTIONS(298), 1,
      anon_sym_SLASH,
    ACTIONS(300), 1,
      anon_sym_BQUOTE,
    STATE(27), 1,
      sym_italic_open,
    STATE(29), 1,
      sym_bold_open,
    STATE(72), 1,
      sym_verbatim_open,
    STATE(19), 3,
      sym_verbatim,
      sym_bold,
      sym_italic,
  [1816] = 5,
    ACTIONS(296), 1,
      anon_sym_STAR,
    ACTIONS(300), 1,
      anon_sym_BQUOTE,
    STATE(22), 1,
      sym_bold_open,
    STATE(71), 1,
      sym_verbatim_open,
    STATE(32), 2,
      sym_verbatim,
      sym_bold,
  [1833] = 5,
    ACTIONS(298), 1,
      anon_sym_SLASH,
    ACTIONS(300), 1,
      anon_sym_BQUOTE,
    STATE(25), 1,
      sym_italic_open,
    STATE(73), 1,
      sym_verbatim_open,
    STATE(31), 2,
      sym_verbatim,
      sym_italic,
  [1850] = 4,
    ACTIONS(302), 1,
      aux_sym_ws_token1,
    ACTIONS(304), 1,
      anon_sym_RPAREN,
    ACTIONS(306), 1,
      anon_sym_PIPE,
    STATE(86), 1,
      aux_sym_attached_modifier_extension_repeat1,
  [1863] = 4,
    ACTIONS(302), 1,
      aux_sym_ws_token1,
    ACTIONS(304), 1,
      anon_sym_RPAREN,
    ACTIONS(306), 1,
      anon_sym_PIPE,
    STATE(85), 1,
      aux_sym_attached_modifier_extension_repeat1,
  [1876] = 4,
    ACTIONS(306), 1,
      anon_sym_PIPE,
    ACTIONS(308), 1,
      aux_sym_ws_token1,
    ACTIONS(310), 1,
      anon_sym_RPAREN,
    STATE(86), 1,
      aux_sym_attached_modifier_extension_repeat1,
  [1889] = 4,
    ACTIONS(312), 1,
      aux_sym_ws_token1,
    ACTIONS(315), 1,
      anon_sym_RPAREN,
    ACTIONS(317), 1,
      anon_sym_PIPE,
    STATE(86), 1,
      aux_sym_attached_modifier_extension_repeat1,
  [1902] = 4,
    ACTIONS(306), 1,
      anon_sym_PIPE,
    ACTIONS(320), 1,
      aux_sym_ws_token1,
    ACTIONS(322), 1,
      anon_sym_RPAREN,
    STATE(83), 1,
      aux_sym_attached_modifier_extension_repeat1,
  [1915] = 1,
    ACTIONS(324), 3,
      aux_sym_ws_token1,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1921] = 1,
    ACTIONS(326), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_BQUOTE,
  [1927] = 1,
    ACTIONS(328), 3,
      aux_sym_ws_token1,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1933] = 3,
    ACTIONS(330), 1,
      sym_word,
    ACTIONS(332), 1,
      aux_sym_ws_token1,
    STATE(87), 1,
      sym_attr_pair,
  [1943] = 3,
    ACTIONS(330), 1,
      sym_word,
    ACTIONS(334), 1,
      aux_sym_ws_token1,
    STATE(96), 1,
      sym_attr_pair,
  [1953] = 1,
    ACTIONS(336), 3,
      aux_sym_ws_token1,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1959] = 3,
    ACTIONS(330), 1,
      sym_word,
    ACTIONS(338), 1,
      aux_sym_ws_token1,
    STATE(90), 1,
      sym_attr_pair,
  [1969] = 1,
    ACTIONS(340), 3,
      aux_sym_ws_token1,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1975] = 1,
    ACTIONS(315), 3,
      aux_sym_ws_token1,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1981] = 1,
    ACTIONS(342), 3,
      aux_sym_ws_token1,
      anon_sym_RPAREN,
      anon_sym_PIPE,
  [1987] = 2,
    ACTIONS(344), 1,
      sym_word,
    ACTIONS(346), 1,
      aux_sym_ws_token1,
  [1994] = 2,
    ACTIONS(310), 1,
      anon_sym_RPAREN,
    ACTIONS(348), 1,
      anon_sym_PIPE,
  [2001] = 2,
    ACTIONS(348), 1,
      anon_sym_PIPE,
    ACTIONS(350), 1,
      anon_sym_RPAREN,
  [2008] = 2,
    ACTIONS(330), 1,
      sym_word,
    STATE(95), 1,
      sym_attr_pair,
  [2015] = 2,
    ACTIONS(352), 1,
      aux_sym_ws_token1,
    ACTIONS(354), 1,
      anon_sym_COLON,
  [2022] = 2,
    ACTIONS(330), 1,
      sym_word,
    STATE(90), 1,
      sym_attr_pair,
  [2029] = 2,
    ACTIONS(356), 1,
      sym_word,
    ACTIONS(358), 1,
      aux_sym_ws_token1,
  [2036] = 2,
    ACTIONS(330), 1,
      sym_word,
    STATE(84), 1,
      sym_attr_pair,
  [2043] = 2,
    ACTIONS(304), 1,
      anon_sym_RPAREN,
    ACTIONS(348), 1,
      anon_sym_PIPE,
  [2050] = 1,
    ACTIONS(326), 1,
      sym__lookahead_word,
  [2054] = 1,
    ACTIONS(360), 1,
      ts_builtin_sym_end,
  [2058] = 1,
    ACTIONS(362), 1,
      sym__lookahead_word,
  [2062] = 1,
    ACTIONS(356), 1,
      sym_word,
  [2066] = 1,
    ACTIONS(364), 1,
      anon_sym_COLON,
  [2070] = 1,
    ACTIONS(366), 1,
      sym__lookahead_word,
  [2074] = 1,
    ACTIONS(368), 1,
      sym__lookahead_word,
  [2078] = 1,
    ACTIONS(370), 1,
      sym__lookahead_word,
  [2082] = 1,
    ACTIONS(372), 1,
      sym__lookahead_word,
  [2086] = 1,
    ACTIONS(374), 1,
      sym_word,
  [2090] = 1,
    ACTIONS(376), 1,
      sym__lookahead_word,
  [2094] = 1,
    ACTIONS(378), 1,
      sym__lookahead_word,
  [2098] = 1,
    ACTIONS(380), 1,
      sym__lookahead_word,
  [2102] = 1,
    ACTIONS(348), 1,
      anon_sym_PIPE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(15)] = 0,
  [SMALL_STATE(16)] = 45,
  [SMALL_STATE(17)] = 77,
  [SMALL_STATE(18)] = 109,
  [SMALL_STATE(19)] = 141,
  [SMALL_STATE(20)] = 175,
  [SMALL_STATE(21)] = 209,
  [SMALL_STATE(22)] = 248,
  [SMALL_STATE(23)] = 287,
  [SMALL_STATE(24)] = 316,
  [SMALL_STATE(25)] = 345,
  [SMALL_STATE(26)] = 384,
  [SMALL_STATE(27)] = 413,
  [SMALL_STATE(28)] = 452,
  [SMALL_STATE(29)] = 491,
  [SMALL_STATE(30)] = 530,
  [SMALL_STATE(31)] = 559,
  [SMALL_STATE(32)] = 588,
  [SMALL_STATE(33)] = 617,
  [SMALL_STATE(34)] = 641,
  [SMALL_STATE(35)] = 669,
  [SMALL_STATE(36)] = 693,
  [SMALL_STATE(37)] = 717,
  [SMALL_STATE(38)] = 745,
  [SMALL_STATE(39)] = 773,
  [SMALL_STATE(40)] = 807,
  [SMALL_STATE(41)] = 831,
  [SMALL_STATE(42)] = 859,
  [SMALL_STATE(43)] = 883,
  [SMALL_STATE(44)] = 911,
  [SMALL_STATE(45)] = 935,
  [SMALL_STATE(46)] = 959,
  [SMALL_STATE(47)] = 993,
  [SMALL_STATE(48)] = 1017,
  [SMALL_STATE(49)] = 1041,
  [SMALL_STATE(50)] = 1065,
  [SMALL_STATE(51)] = 1089,
  [SMALL_STATE(52)] = 1113,
  [SMALL_STATE(53)] = 1137,
  [SMALL_STATE(54)] = 1161,
  [SMALL_STATE(55)] = 1185,
  [SMALL_STATE(56)] = 1219,
  [SMALL_STATE(57)] = 1247,
  [SMALL_STATE(58)] = 1271,
  [SMALL_STATE(59)] = 1295,
  [SMALL_STATE(60)] = 1323,
  [SMALL_STATE(61)] = 1347,
  [SMALL_STATE(62)] = 1371,
  [SMALL_STATE(63)] = 1395,
  [SMALL_STATE(64)] = 1419,
  [SMALL_STATE(65)] = 1443,
  [SMALL_STATE(66)] = 1467,
  [SMALL_STATE(67)] = 1491,
  [SMALL_STATE(68)] = 1519,
  [SMALL_STATE(69)] = 1543,
  [SMALL_STATE(70)] = 1567,
  [SMALL_STATE(71)] = 1595,
  [SMALL_STATE(72)] = 1620,
  [SMALL_STATE(73)] = 1645,
  [SMALL_STATE(74)] = 1670,
  [SMALL_STATE(75)] = 1691,
  [SMALL_STATE(76)] = 1716,
  [SMALL_STATE(77)] = 1735,
  [SMALL_STATE(78)] = 1754,
  [SMALL_STATE(79)] = 1773,
  [SMALL_STATE(80)] = 1792,
  [SMALL_STATE(81)] = 1816,
  [SMALL_STATE(82)] = 1833,
  [SMALL_STATE(83)] = 1850,
  [SMALL_STATE(84)] = 1863,
  [SMALL_STATE(85)] = 1876,
  [SMALL_STATE(86)] = 1889,
  [SMALL_STATE(87)] = 1902,
  [SMALL_STATE(88)] = 1915,
  [SMALL_STATE(89)] = 1921,
  [SMALL_STATE(90)] = 1927,
  [SMALL_STATE(91)] = 1933,
  [SMALL_STATE(92)] = 1943,
  [SMALL_STATE(93)] = 1953,
  [SMALL_STATE(94)] = 1959,
  [SMALL_STATE(95)] = 1969,
  [SMALL_STATE(96)] = 1975,
  [SMALL_STATE(97)] = 1981,
  [SMALL_STATE(98)] = 1987,
  [SMALL_STATE(99)] = 1994,
  [SMALL_STATE(100)] = 2001,
  [SMALL_STATE(101)] = 2008,
  [SMALL_STATE(102)] = 2015,
  [SMALL_STATE(103)] = 2022,
  [SMALL_STATE(104)] = 2029,
  [SMALL_STATE(105)] = 2036,
  [SMALL_STATE(106)] = 2043,
  [SMALL_STATE(107)] = 2050,
  [SMALL_STATE(108)] = 2054,
  [SMALL_STATE(109)] = 2058,
  [SMALL_STATE(110)] = 2062,
  [SMALL_STATE(111)] = 2066,
  [SMALL_STATE(112)] = 2070,
  [SMALL_STATE(113)] = 2074,
  [SMALL_STATE(114)] = 2078,
  [SMALL_STATE(115)] = 2082,
  [SMALL_STATE(116)] = 2086,
  [SMALL_STATE(117)] = 2090,
  [SMALL_STATE(118)] = 2094,
  [SMALL_STATE(119)] = 2098,
  [SMALL_STATE(120)] = 2102,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(67),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(40),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(2),
  [26] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(2),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(17),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(40),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(56),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(67),
  [41] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(70),
  [44] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2), SHIFT_REPEAT(40),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__non_ws, 2),
  [55] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__non_ws, 2),
  [57] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__non_ws, 3),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__non_ws, 3),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__italic_non_ws, 2),
  [71] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__italic_non_ws, 2),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__italic_non_ws, 3),
  [91] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__italic_non_ws, 3),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_non_ws, 3),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_non_ws, 3),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(41),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_non_ws, 2),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_non_ws, 2),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__italic_non_ws, 1),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__italic_non_ws, 1),
  [125] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym__italic_non_ws, 1), SHIFT(89),
  [128] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__non_ws, 1),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__non_ws, 1),
  [134] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym__non_ws, 1), SHIFT(89),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_non_ws, 1),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_non_ws, 1),
  [143] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym__bold_non_ws, 1), SHIFT(89),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [148] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym__non_ws, 3), SHIFT(107),
  [151] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym__non_ws, 3), SHIFT(91),
  [154] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym__non_ws, 1), SHIFT(107),
  [157] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym__non_ws, 1), SHIFT(91),
  [160] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym__non_ws, 2), SHIFT(107),
  [163] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym__bold_non_ws, 1), SHIFT(107),
  [166] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym__italic_non_ws, 1), SHIFT(107),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__non_ws, 4),
  [171] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__non_ws, 4),
  [173] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym__non_ws, 4), SHIFT(107),
  [176] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym__bold_non_ws, 3), SHIFT(107),
  [179] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym__italic_non_ws, 3), SHIFT(107),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_punc, 1),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_punc, 1),
  [186] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_punc, 1), REDUCE(sym_verbatim_open, 1),
  [189] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_punc, 1), REDUCE(sym_verbatim_open, 1),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_verbatim, 3, .dynamic_precedence = 2),
  [194] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_verbatim, 3, .dynamic_precedence = 2),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__verbatim_non_ws, 2),
  [198] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__verbatim_non_ws, 2),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [204] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [206] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [208] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_punc, 1), REDUCE(sym_italic_open, 1),
  [211] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_punc, 1), REDUCE(sym_italic_open, 1),
  [214] = {.entry = {.count = 2, .reusable = true}}, REDUCE(sym_punc, 1), REDUCE(sym_bold_open, 1),
  [217] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_punc, 1), REDUCE(sym_bold_open, 1),
  [220] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bold, 3, .dynamic_precedence = 1),
  [222] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bold, 3, .dynamic_precedence = 1),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attached_modifier_extension, 6),
  [226] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attached_modifier_extension, 6),
  [228] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__italic_non_ws, 5),
  [232] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__italic_non_ws, 5),
  [234] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_paragraph, 2),
  [236] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_paragraph, 2),
  [238] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__bold_non_ws, 5),
  [240] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__bold_non_ws, 5),
  [242] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_italic, 3, .dynamic_precedence = 1),
  [244] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_italic, 3, .dynamic_precedence = 1),
  [246] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attached_modifier_extension, 5),
  [248] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attached_modifier_extension, 5),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [252] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__verbatim_non_ws, 3),
  [254] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__verbatim_non_ws, 3),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__non_ws, 6),
  [258] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__non_ws, 6),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attached_modifier_extension, 4),
  [262] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attached_modifier_extension, 4),
  [264] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attached_modifier_extension, 3),
  [266] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_attached_modifier_extension, 3),
  [268] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__non_ws, 5),
  [270] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__non_ws, 5),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [280] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_italic_open, 1),
  [282] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_italic_open, 1),
  [284] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ws, 1),
  [286] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_ws, 1),
  [288] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_bold_open, 1),
  [290] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_bold_open, 1),
  [292] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_verbatim_open, 1),
  [294] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_verbatim_open, 1),
  [296] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [298] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [300] = {.entry = {.count = 1, .reusable = true}}, SHIFT(79),
  [302] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [304] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [306] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [308] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [310] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [312] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attached_modifier_extension_repeat1, 2), SHIFT_REPEAT(120),
  [315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_attached_modifier_extension_repeat1, 2),
  [317] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_attached_modifier_extension_repeat1, 2), SHIFT_REPEAT(92),
  [320] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [322] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [324] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attr_pair, 4, .production_id = 2),
  [326] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_link_modifier, 1, .dynamic_precedence = 1),
  [328] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_attached_modifier_extension_repeat1, 3),
  [330] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [332] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [334] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [336] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attr_pair, 5, .production_id = 3),
  [338] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [340] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_attached_modifier_extension_repeat1, 4),
  [342] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_attr_pair, 3, .production_id = 1),
  [344] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [346] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [348] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [350] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [352] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [354] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [356] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [358] = {.entry = {.count = 1, .reusable = true}}, SHIFT(116),
  [360] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [362] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [364] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [366] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [368] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [370] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [372] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [374] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [376] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [378] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [380] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
};

enum ts_external_scanner_symbol_identifiers {
  ts_external_token__paragraph_break = 0,
  ts_external_token__open_conflict = 1,
  ts_external_token__close_conflict = 2,
  ts_external_token__lookahead_word = 3,
  ts_external_token_bold_close = 4,
  ts_external_token_italic_close = 5,
  ts_external_token_verbatim_close = 6,
};

static const TSSymbol ts_external_scanner_symbol_map[EXTERNAL_TOKEN_COUNT] = {
  [ts_external_token__paragraph_break] = sym__paragraph_break,
  [ts_external_token__open_conflict] = sym__open_conflict,
  [ts_external_token__close_conflict] = sym__close_conflict,
  [ts_external_token__lookahead_word] = sym__lookahead_word,
  [ts_external_token_bold_close] = sym_bold_close,
  [ts_external_token_italic_close] = sym_italic_close,
  [ts_external_token_verbatim_close] = sym_verbatim_close,
};

static const bool ts_external_scanner_states[11][EXTERNAL_TOKEN_COUNT] = {
  [1] = {
    [ts_external_token__paragraph_break] = true,
    [ts_external_token__open_conflict] = true,
    [ts_external_token__close_conflict] = true,
    [ts_external_token__lookahead_word] = true,
    [ts_external_token_bold_close] = true,
    [ts_external_token_italic_close] = true,
    [ts_external_token_verbatim_close] = true,
  },
  [2] = {
    [ts_external_token__close_conflict] = true,
  },
  [3] = {
    [ts_external_token__paragraph_break] = true,
    [ts_external_token__close_conflict] = true,
  },
  [4] = {
    [ts_external_token__close_conflict] = true,
    [ts_external_token_italic_close] = true,
  },
  [5] = {
    [ts_external_token__close_conflict] = true,
    [ts_external_token_bold_close] = true,
  },
  [6] = {
    [ts_external_token__open_conflict] = true,
    [ts_external_token__close_conflict] = true,
    [ts_external_token_italic_close] = true,
  },
  [7] = {
    [ts_external_token__paragraph_break] = true,
    [ts_external_token__open_conflict] = true,
    [ts_external_token__close_conflict] = true,
  },
  [8] = {
    [ts_external_token__open_conflict] = true,
    [ts_external_token__close_conflict] = true,
    [ts_external_token_bold_close] = true,
  },
  [9] = {
    [ts_external_token__close_conflict] = true,
    [ts_external_token_verbatim_close] = true,
  },
  [10] = {
    [ts_external_token__lookahead_word] = true,
  },
};

#ifdef __cplusplus
extern "C" {
#endif
void *tree_sitter_norgtest_external_scanner_create(void);
void tree_sitter_norgtest_external_scanner_destroy(void *);
bool tree_sitter_norgtest_external_scanner_scan(void *, TSLexer *, const bool *);
unsigned tree_sitter_norgtest_external_scanner_serialize(void *, char *);
void tree_sitter_norgtest_external_scanner_deserialize(void *, const char *, unsigned);

#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_norgtest(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .external_scanner = {
      &ts_external_scanner_states[0][0],
      ts_external_scanner_symbol_map,
      tree_sitter_norgtest_external_scanner_create,
      tree_sitter_norgtest_external_scanner_destroy,
      tree_sitter_norgtest_external_scanner_scan,
      tree_sitter_norgtest_external_scanner_serialize,
      tree_sitter_norgtest_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
