#include "lexer.h"
#include <cctype>
#include <cstdlib>
using namespace std;

Lexer::Lexer(const string &input) : text(input), pos(0) {}

Token Lexer::getNextToken() {
    while (pos < text.size() && (isspace(text[pos]) || text[pos] == '\r')) pos++;

    if (pos >= text.size()) return {END, 0};

    char current = text[pos];

    // Numbers
    if (isdigit(current)) {
        string num;
        while (pos < text.size() && (isdigit(text[pos]) || text[pos] == '.')) {
            num += text[pos++];
        }
        return {NUMBER, stod(num)};
    }

    // Keywords: print
    if (isalpha(current)) {
        string word;
        while (pos < text.size() && isalpha(text[pos])) {
            word += text[pos++];
        }
        if (word == "print") return {PRINT, 0};
        return {INVALID, 0};
    }

    // for strings
    if (current == '"') {
        pos++; // skip opening quote
        string str;
        while (pos < text.size() && text[pos] != '"') {
            str += text[pos++];
        }
        if (pos < text.size()) pos++; // skip closing quote
        return {STRING, 0, str};
    }

    // Operators
    pos++;
    switch (current) {
        case '+': return {PLUS, 0};
        case '-': return {MINUS, 0};
        case '*': return {MUL, 0};
        case '/': return {DIV, 0};
        default: return {INVALID, 0};
    }
}
