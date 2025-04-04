
#include <iostream>
#include "calculator.h"

using namespace std;

int main() {
    
    cout << "Addition: 5 + 3 = " << add(5, 3) << endl;

    
   cout << "Subtraction: 8 - 2 = " << subtract(8, 2) << endl;

   cout << "Multiplication: 4 * 7 = " << multiply(4, 7) << endl;

   cout << "Division: 20 / 4 = " << divide(20, 4) << endl;
   cout << "Division by zero: " << divide(20, 0) << endl;

  cout << "Factorial of 5 = " << factorial(5) << endl;
  cout << "Factorial of -5 = " << factorial(-5) << endl;

    
   cout << "GCD of 48 and 18 = " << gcd(48, 18) << endl;
   cout << "LCM of 48 and 18 = " << lcm(48, 18) << endl;

   cout << "Random number between 1 and 100 = " << randomInRange(1, 100) << endl;

    return 0;
}
