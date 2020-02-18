// author: Von Reid

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int n = 1, inpNum, fibNum1 = 0, fibNum2 = 1, fibSeqOp = 0, charQuant = 0;
std::string userChar = " ";

int main()
{
    do
    {
        inpNum = 0; // clear user input
        if (n != 1)
        {
            cout << "E";
        }
        else
        {
            cout << "Hello, how many terms of the sequence would you like to display?" << endl
                 << "Please e";
        }
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
        if (inpNum fibSeqOp> 0)
        {
            for (fibNum1; fibNum1 < 2; fibNum1++)
            {
                cout << userChar;
            }
            cout << fibNum1 << endl;
            //continue;
        }
        if (inpNum > 1)
        {
            for (fibNum2; fibNum2 < 3; fibNum1++)
            {
                cout << userChar;
            }
            cout << fibNum2 << endl;
            //continue;
        }

        for (fibSeqOp = fibNum1 + fibNum2; fibNum1 < fibSeqOp; fibSeqOp++)
        {
            cout << userChar;
        }

        // fibSeqOp (sequence output) is just the classic fibonnacn formula:
        // x(n) = x(n-1) + x(n-2)
        //fibSeqOp = fibNum1 + fibNum2;

        fibNum1 = fibNum2;
        fibNum2 = fibSeqOp;

        cout << fibSeqOp << endl;
        n++;
    } while (inpNum != 0);

    return 0;
}