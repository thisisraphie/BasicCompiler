#include <iostream>
#include <string>
#include "lexer.h"
#include "parser.h"

using namespace std;

int main() {
    string input;
    getline(cin, input);

    Lexer lexer(input);
    Parser parser(lexer);

    double result = parser.parse();

    return 0;
}
    