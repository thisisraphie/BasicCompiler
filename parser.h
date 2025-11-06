#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

class Parser {
    Lexer lexer;
    Token current;

    void eat(TokenType type);
    double factor();
    double term();
    double expr();

public:
    Parser(Lexer lex);
    double parse();
};

#endif
