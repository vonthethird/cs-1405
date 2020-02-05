// 02-05-2020
// We did this in class to demo setw() and setprecision()

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setprecision;
using std::setw;

int main() {
    double a1 = 503.2377234278949;
    double b1 = 234.34;
    double a2 = 2.23;
    double b2 = 123.3;
    cout << setw(10) << "a" << " " << setw(6) << "b" << endl;
    cout << setw(10) << setprecision(20) << a1 << " " << setw(3) << b1 << endl;
    cout << setw(10) << setprecision(3) << a2 << " " << setw(3) << b2 << endl;
    return 0;
}