    #include "lexer.h"
#include <cctype>
#include <cstdlib>

Lexer::Lexer(const string &input) : text(input), pos(0) {}

Token Lexer::getNextToken() {
    while (pos < text.size() && isspace(text[pos])) pos++;

    if (pos >= text.size())
        return {END, 0};

    char current = text[pos];

    if (isdigit(current)) {
        string num;
        while (pos < text.size() && (isdigit(text[pos]) || text[pos] == '.')) {
            num += text[pos++];
        }
        return {NUMBER, stod(num)};
    }

    pos++;
    switch (current) {
        case '+': return {PLUS, 0};
        case '-': return {MINUS, 0};
        case '*': return {MUL, 0};
        case '/': return {DIV, 0};
        default:  return {INVALID, 0};
    }
}
