#ifndef LEXER_H
#define LEXER_H

#include <string>
using namespace std;

enum TokenType {
    NUMBER, PLUS, MINUS, MUL, DIV, PRINT, STRING, SEMICOLON, END, INVALID
};

struct Token {
    TokenType type;
    double value; // used if type == NUMBER 
    std::string text; // used if type == STRING
};

class Lexer {
    string text;
    size_t pos;
public:
    Lexer(const string &input);
    Token getNextToken();
};

#endif
