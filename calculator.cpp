#include "calculator.h"
#include <stack>
#include <queue>
#include <sstream>
#include <cctype>
#include <cmath>
#include <map>
#include <iostream>
#include <stdexcept>
#include <random>

using namespace std;

double applyOperator(char op, double a, double b) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b == 0 ? throw runtime_error("Division by zero") : a / b;
        default: throw runtime_error("Unknown operator");
    }
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

queue<string> toPostfix(const string& expr) {
   stack<char> ops;
   queue<string> output;
   stringstream number;

    for (size_t i = 0; i < expr.length(); ++i) {
        char token = expr[i];

        if (isspace(token)) continue;

        if (isdigit(token) || token == '.') {
            number << token;
            if (i == expr.length() - 1 || !isdigit(expr[i+1]) && expr[i+1] != '.') {
                output.push(number.str());
                number.str("");
                number.clear();
            }
        } else if (token == '(') {
            ops.push(token);
        } else if (token == ')') {
            while (!ops.empty() && ops.top() != '(') {
                output.push(string(1, ops.top()));
                ops.pop();
            }
            if (!ops.empty()) ops.pop(); 
        } else if (isOperator(token)) {
            while (!ops.empty() && precedence(ops.top()) >= precedence(token)) {
                output.push(string(1, ops.top()));
                ops.pop();
            }
            ops.push(token);
        }
    }

    while (!ops.empty()) {
        output.push(string(1, ops.top()));
        ops.pop();
    }

    return output;
}

double evaluatePostfix(queue<string> postfix) {
   stack<double> values;

    while (!postfix.empty()) {
        string token = postfix.front();
        postfix.pop();

        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            values.push(stod(token));
        } else if (isOperator(token[0])) {
            double b = values.top(); values.pop();
            double a = values.top(); values.pop();
            values.push(applyOperator(token[0], a, b));
        }
    }

    return values.top();
}

double evaluateExpression(const string& expr) {
    return evaluatePostfix(toPostfix(expr));
}

