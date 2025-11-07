#include <iostream>
#include <string>
#include "lexer.h"
#include "parser.h"

using namespace std;

int main() {
    cout << "Enter expression: ";
    string input;
    getline(cin, input);

    Lexer lexer(input);
    Parser parser(lexer);

    double result = parser.parse();
    cout << "Result: " << result << endl;

    parser.parse();

    return 0;
}
    