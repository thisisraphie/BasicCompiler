#include "parser.h"
#include <cstdlib>

Parser::Parser(Lexer lex) : lexer(lex) {
    current = lexer.getNextToken();
}

void Parser::eat(TokenType type) {
    if (current.type == type)
        current = lexer.getNextToken();
    else {
        cerr << "Syntax error!" << endl;
        exit(1);
    }
}

double Parser::factor() {
    double value = current.value;
    eat(NUMBER);
    return value;
}

double Parser::term() {
    double result = factor();
    while (current.type == MUL || current.type == DIV) {
        if (current.type == MUL) {
            eat(MUL);
            result *= factor();
        } else {
            eat(DIV);
            result /= factor();
        }
    }
    return result;
}

double Parser::expr() {
    double result = term();
    while (current.type == PLUS || current.type == MINUS) {
        if (current.type == PLUS) {
            eat(PLUS);
            result += term();
        } else {
            eat(MINUS);
            result -= term();
        }
    }
    return result;
}

double Parser::statement() {
    if (current.type == PRINT) {
        eat(PRINT);

        if (current.type == STRING) {
            cout << current.text << endl;
            eat(STRING);
            if (current.type == END) eat(END);
            return 0;
        } else {
            double value = expr();
            cout << value << endl;
            if (current.type == END) eat(END);
            return value;
        }

    } else {
        double value = expr();
        if (current.type == END) eat(END);
        return value;
    }
}


double Parser::parse() {
    return statement();
}
