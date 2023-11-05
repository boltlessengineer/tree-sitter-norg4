#include "tree_sitter/parser.h"
#include <cwctype>
#include <iostream>
#include <unordered_map>

using namespace std;

enum TokenType: char {
    PARA_BREAK,
    OPEN_CONFLICT,
    CLOSE_CONFLICT,
    BOLD_CLOSE,
    ITALIC_CLOSE,
    VERBATIM_CLOSE,
};

struct Scanner {
    TSLexer* lexer;
    std::unordered_map<int32_t, TokenType> attached_modifiers;
    Scanner() {
        attached_modifiers['*'] = BOLD_CLOSE;
        attached_modifiers['/'] = ITALIC_CLOSE;
        attached_modifiers['`'] = VERBATIM_CLOSE;
    }
    bool scan(const bool *valid_symbols) {
        if (valid_symbols[PARA_BREAK]) {
            // TODO: more precise paragraph break parsing
            lexer->result_symbol = PARA_BREAK;
            lexer->mark_end(lexer);
            if (lexer->eof(lexer)) return true;
            if (lexer->lookahead == '\n') {
                advance();
                while ((lexer->lookahead == '\n'
                    || lexer->lookahead == '\0')
                    && !lexer->eof(lexer)) {
                    advance();
                }
                lexer->mark_end(lexer);
                return true;
            }
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
            if(valid_symbols[token_type]) {
                if(iswspace(lexer->lookahead) || iswpunct(lexer->lookahead) || lexer->eof(lexer)) {
                    lexer->result_symbol = token_type;
                    return true;
                } else {
                    lexer->result_symbol = CLOSE_CONFLICT;
                    return true;
                }
            } else if(valid_symbols[OPEN_CONFLICT]) {
                if(iswspace(lexer->lookahead) || iswpunct(lexer->lookahead) || lexer->eof(lexer)) {
                    return false;
                } else {
                    lexer->result_symbol = OPEN_CONFLICT;
                    return true;
                }
            } else {
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

