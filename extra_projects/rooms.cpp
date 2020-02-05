#include <iostream>

using std::cin;
using std::cout;
using std::endl;

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