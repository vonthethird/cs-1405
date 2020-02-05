#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::setw;

/* We did this in class to demo setw() and setprecision() so I commented it out to use as an example in case we need it as a reference.
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
*/

int promptQuestions()
{
    char promptAnswer;
    cout << "From the 3 options, enter 1 letter:\na, b, or c\n";
    cout << "a) Move North\n"
         << "b) Move East\n"
         << "c) Go to sleep\n";
    cin >> promptAnswer;
    while ((promptAnswer != 'a') && (promptAnswer != 'b') && (promptAnswer != 'c'))
    {
        cout << "\nYou dumb, stupid, incompetent idiot.\nThat's not a valid option. Try again.\n";
        cin >> promptAnswer;
    }
}

int main()
{
    cout << "Hello, welcome to the game!\nYou may or may not survive this, so be careful.\n\n";
    promptQuestions();
}