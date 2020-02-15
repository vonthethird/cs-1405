// author: Von Reid

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int n = 1, inpNum, fibNum1 = 0, fibNum2 = 1, fibSeqOp = 0, charQuant = 0;
std::string userChar = " ";

int displayChar1()
{
    charQuant = fibNum1 - 1;
    while (charQuant <= fibNum1)
    {
        cout << userChar;
        charQuant++;
    }
}
int displayChar2()
{
    charQuant = fibNum2 - 1;
    while (charQuant <= fibNum2)
    {
        cout << userChar;
        charQuant++;
    }
}
int displayCharSeqOp()
{
    charQuant = fibSeqOp - 1;
    while (charQuant <= fibSeqOp)
    {
        cout << userChar;
        charQuant++;
    }
}

int main()
{
    do
    {
        if (n != 1)
        {
            cout << "E";
        }
        else
        {
            cout << "Hello, please e";
        }
        inpNum = 0;
        cout << "nter a number between 1 and 12." << endl;
        cin >> inpNum;
        while (inpNum < 0 || inpNum > 12)
        {
            cout << endl
                 << "That's not a valid number between 1 and 12. (or enter 0 to exit)" << endl;
            cout << "Enter a number between 1 and 12." << endl;
            cin >> inpNum;
        }
        while (userChar == " ")
        {
            cout << "Enter a character to use for display" << endl;
            cin >> userChar;
        }
        cout << "Here's the sequence generated from the given number:" << endl;

        // doing this prints the first two terms, it's how fibonnacn works
        if (n == 1)
        {
            displayChar1();
            cout << fibNum1 << endl;
            //continue;
        }
        if (n == 2)
        {
            displayChar2();
            cout << fibNum2 << endl;
            //continue;
        }

        // fibSeqOp (sequence output) is just the classic fibonnacn formula:
        // x(n) = x(n-1) + x(n-2)
        fibSeqOp = fibNum1 + fibNum2;

        fibNum1 = fibNum2;
        fibNum2 = fibSeqOp;

        displayCharSeqOp();
        cout << fibSeqOp << endl;
        n++;
    } while (inpNum != 0);

    return 0;
}