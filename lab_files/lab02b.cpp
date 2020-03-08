// author: Von Reid, cs-1405 lab #2b
// this program will calculate the sum, difference, product, quotient, and remainder of 2 integers.
#include <iostream>
using namespace std;

int firstInt, secondInt;

int main() {
    // greeting to user
    cout << "This program will calculate the sum, difference, product, quotient, and remainder of 2 integers.";
    // collect the user input
    cout << "Enter first integer: ";
    cin >> firstInt;
    cout << "Enter second integer: ";
    cin >> secondInt;
    
    // throw the inputs into some equations and spit them out
    // sum will add them together
    int sum = firstInt + secondInt;
    cout << "Sum is............" << sum << endl;
    // diff will subtract the second integer from the first
    int diff = firstInt - secondInt;
    cout << "Difference is....." << diff << endl;
    // prod will multiply them
    int prod = firstInt * secondInt;
    cout << "Product is........" << prod << endl;
    // quot will divide them
    int quot = firstInt / secondInt;
    cout << "Quotient is......." << quot << endl;
    // remain will get the leftover remainder it would get from the division
    int remain = firstInt % secondInt;
    cout << "Remainder is......" << remain << endl;
    
    return 0;
}