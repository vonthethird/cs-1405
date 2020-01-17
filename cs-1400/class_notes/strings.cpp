#include <iostream>
using namespace std;

// run this program and look at the output of c2
// you won't get a real number output, because c (a string) added to delta (a number) can't have a number sum
int main() {
    char c = '3';
    int n = 3;
    int delta = 13;
    char c2 = c + delta;
    int n2 = n + delta;
    cout << c << endl;
    cout << n << endl;
    cout << c2 << endl;
    cout << n2 << endl;
    return 0;
}