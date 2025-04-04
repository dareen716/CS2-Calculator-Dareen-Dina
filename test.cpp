#include "calculator.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    string expr;

    cout << "Enter a math expression (e.g. 3 + 4 * (2 - 1) / 5): ";
   getline(cin, expr);

double result = evaluateExpression(expr);
cout << "Expression result: " << result << endl;
   
    return 0;
}
