#include "tree_sitter/parser.h"
#include <cwctype>
#include <iostream>
#include <unordered_map>

using namespace std;

enum TokenType: char {
    PRE_WHITESPACE,
    END_OF_FILE,
    OPEN_CONFLICT,
    CLOSE_CONFLICT,
    LOOKAHEAD_WORD,
    BOLD_CLOSE,
    ITALIC_CLOSE,
    UNDERLINE_CLOSE,
    VERBATIM_CLOSE,
    COMMENT_CLOSE,
    FREE_BOLD_CLOSE,
    FREE_ITALIC_CLOSE,
    FREE_UNDERLINE_CLOSE,
    FREE_VERBATIM_CLOSE,
    FREE_COMMENT_CLOSE,
};

struct Scanner {
    TSLexer* lexer;
    std::unordered_map<int32_t, TokenType> attached_modifiers;
    Scanner() {
        attached_modifiers['*'] = BOLD_CLOSE;
        attached_modifiers['/'] = ITALIC_CLOSE;
        attached_modifiers['_'] = UNDERLINE_CLOSE;
        attached_modifiers['`'] = VERBATIM_CLOSE;
        attached_modifiers['%'] = COMMENT_CLOSE;
    }
    bool scan(const bool *valid_symbols) {
        if (lexer->eof(lexer) && valid_symbols[END_OF_FILE]) {
            lexer->result_symbol = END_OF_FILE;
            lexer->mark_end(lexer);
            return true;
        }
        if (lexer->get_column(lexer) == 0) {
            if (iswblank(lexer->lookahead)) {
                while (iswblank(lexer->lookahead)) 
                    advance();
                lexer->result_symbol = PRE_WHITESPACE;
                lexer->mark_end(lexer);
                return true;
            }
        }
        // zero-length token
        if (valid_symbols[LOOKAHEAD_WORD]) {
            if (!iswpunct(lexer->lookahead) && !iswspace(lexer->lookahead) && !lexer->eof(lexer)) {
                lexer->result_symbol = LOOKAHEAD_WORD;
                lexer->mark_end(lexer);
                return true;
            }
        }
        bool is_free_close = false;
        if (lexer->lookahead == '|') {
            advance();
            is_free_close = true;
        }
        std::unordered_map<int32_t, TokenType>::iterator iter = attached_modifiers.find(lexer->lookahead);
        if (iter != attached_modifiers.end()) {
            const int token_char = iter->first;
            const TokenType token_type = iter->second;
            advance();
            lexer->mark_end(lexer);
            if (lexer->lookahead == token_char) {
                // repeated modifiers are handled by grammar.js
                return false;
            }
            if(valid_symbols[token_type] || valid_symbols[token_type + (FREE_BOLD_CLOSE - BOLD_CLOSE)]) {
                // *_close is valid
                if(iswspace(lexer->lookahead) || iswpunct(lexer->lookahead) || lexer->eof(lexer)) {
                    lexer->result_symbol = token_type;
                    if (is_free_close) {
                        lexer->result_symbol += (FREE_BOLD_CLOSE - BOLD_CLOSE);
                    }
                    // check if FREE_*_CLOSE is valid
                    if (!valid_symbols[lexer->result_symbol])
                        return false;
                    return true;
                } else {
                    lexer->result_symbol = CLOSE_CONFLICT;
                    return true;
                }
            } else if(valid_symbols[OPEN_CONFLICT]) {
                // *_close isn't valid
                // haven't opened bold/or bold_open was parsed as punctuation
                lexer->result_symbol = OPEN_CONFLICT;
                return true;
            } else {
                // TODO: when is this case..?
                return false;
            }
        }
        return false;
    }

    void skip() { lexer->advance(lexer, true); }
    void advance() { lexer->advance(lexer, false); }
};

extern "C" {
    void *tree_sitter_norgtest_external_scanner_create() { return new Scanner(); }

    void tree_sitter_norgtest_external_scanner_destroy(void *payload) {
        delete static_cast<Scanner * >(payload);
    }

    bool tree_sitter_norgtest_external_scanner_scan(void *payload, TSLexer *lexer, const bool *valid_symbols) {
        Scanner *scanner = static_cast<Scanner*>(payload);
        scanner->lexer = lexer;
        return scanner->scan(valid_symbols);
    }

    unsigned tree_sitter_norgtest_external_scanner_serialize(void *payload, char *buffer) {
        Scanner* scanner = static_cast<Scanner*>(payload);
        size_t total_size = 0;
        return total_size;
    }

    void tree_sitter_norgtest_external_scanner_deserialize(void *payload, const char *buffer, unsigned length) {
    }
}

