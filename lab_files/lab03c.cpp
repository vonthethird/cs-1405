// author: Von Reid, Garrett Record, and Ronald Hunt -- cs-1405 lab
// User will enter interger for a, b, c, and d then the program will calculate
#include <iostream> 
using namespace std; 

int main(){
    int a, b, c, d;
    cout << "Using a, b, c and d, we will solve for x, y, and z.\n";
    cout << "Enter the value of a\n";
    cin >> a;
    cout << "Enter the value of b\n";
    cin >> b;
    cout << "Enter the value of c\n";
    cin >> c;
    cout << "Enter the value of d\n";
    cin >> d;
    // x = b^2 - 4ac
    int x = b * b - 4 * a * c;
    // y = (a^2 + c^2) / d^2
    int y = (a * a + c * c) / (d * d);
    // z = d^3 - 2c^2 + 3b - a
    int z = (d * d * d) - (2 * c * c) + (3 * b) - a;
    cout << "\nx = " << x << ",\n y = " << y << ",\n z = " << z;
 }