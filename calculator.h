#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

using namespace std;

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(double a, double b);
int factorial(int n);
int gcd(int a, int b);
int lcm(int a, int b);
int randomInRange(int min, int max);
double evaluateExpression(const string& expr); 
#endif
