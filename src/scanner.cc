#include "tree_sitter/parser.h"
#include <cwctype>

using namespace std;

enum TokenType: char {
    BOLD_CLOSE,
};

struct Scanner {
    TSLexer* lexer;
    bool scan(const bool *valid_symbols) {
        // return false;
        if(valid_symbols[BOLD_CLOSE] && lexer->lookahead == '/') {
            advance();
            if(iswspace(lexer->lookahead) || iswpunct(lexer->lookahead)) {
                lexer->result_symbol = BOLD_CLOSE;
                return true;
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

