// author: Von Reid
// CS-1405 Worksheet #6, due 02-14-2020
// Look at my comments to guide you through the code for the assignment's problems

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int enterNumToContinue()
{
    int numberEntered;
    cout << endl
         << "Enter any number to continue." << endl;
    cin >> numberEntered;
}

// 1.
int firstProblem()
{
    // subproblem 1.
    cout << "1.1." << endl;
    for (int i = -10; i <= 10; i++)
    {
        // cout << i << endl;
    }
    cout << "for (int i = -10; i <= 10; i++)" << endl;
    // subproblem 2.
    cout << "1.2." << endl;
    for (int i = 100; i >= 1; i--)
    {
        // cout << i << endl;
    }
    cout << "for (int i = 100; i >= 1; i--)" << endl;
    enterNumToContinue();
}

// 2.
int secondProblem()
{
    /* original loop with a problem:

for (int i = 0; i < 10; i++)
{
    cout << i++;
}

**how to correct**:
make i start at 1 by doing `int i = 1`
then use <= to make it go to 10 exactly
print i without the ++ so it'll simply print out all of 1 to 10 with ease

    corrected loop:         */
    for (int i = 1; i <= 10; i++)
    {
        // commented out only so it won't print when main() is run
        // cout << i;
    }
    cout << "original loop:" << endl
         << "for (int i = 0; i < 10; i++)" << endl
         << "{" << endl
         << "   cout << i++;" << endl
         << "}" << endl
         << endl;
    cout << "make i start at 1 by doing `int i = 1`" << endl;
    cout << "then use <= to make it go to 10 exactly" << endl;
    cout << "print i without the ++ so it'll simply print out all of 1 to 10 with ease" << endl
         << endl;
    cout << "corrected loop:" << endl;
    cout << "for (int i = 1; i <= 10; i++)" << endl;
    cout << "{" << endl;
    cout << "   cout << i;" << endl;
    cout << "}" << endl
         << endl;
    enterNumToContinue();
}

// 3.
int thirdProblem()
{
    /*
    with this:

    for (int i = 0; i < 5; i++) {
    for (int j = 0; j < i; j++)
        cout << ‘*’;
    }

    the output will be 10 *s printed out next to each other
    BUT it needs to be
    cout << "*"
    or else you'll get command line errors :(
    */
    cout << "The output of the code for 3. will be 10 *s printed out next to each other, like this:" << endl;
    for (int i = 0; i < 5; i++) {
    for (int j = 0; j < i; j++)
        cout << "*";
    }
    enterNumToContinue();
}

// 4.
int fourthProblem()
{
    /*
    this loop:

    int m = 12;
    do
    {
        cout << m << endl;
        m = m - 3;
    } while (m > 0);

    will print this:
    12
    9
    6
    3
    */
    cout << "The given loop will print this:" << endl
         << "12" << endl
         << "9" << endl
         << "6" << endl
         << "3" << endl;
    enterNumToContinue();
}

// 5.
int fifthProblem()
{
    // Write a code segment that prompts a user for a value between -20 and 20 inclusive.
    // It should validate the input using a while loop.

    int inputtedNumber = 0;
    while ((inputtedNumber >= -20) && (inputtedNumber <= 20))
    {
        cout << endl
             << "Please enter a value between -20 and 20." << endl;
        cin >> inputtedNumber;
        if ((inputtedNumber >= -20) && (inputtedNumber <= 20))
        {
            cout << "The number " << inputtedNumber << " is indeed in the given range. Good job." << endl;
        }
    }
    cout << endl
         << "The number " << inputtedNumber << " is NOT a valid number in the given range." << endl
         << "Get out of my office." << endl;
    enterNumToContinue();
}

// 6.
int sixthProblem()
{
    /* Convert the following for loop to a while loop:
    for (int i = 0; i < 10; i++)
    cout << i; */
    cout << "I was given a `for` loop, here's the same loop converted into a `while` loop:" << endl;
    cout << "int i = 0;" << endl
         << "while (i < 10)" << endl
         << "{" << endl
         << "   cout << i;" << endl
         << "   i++;" << endl
         << "}" << endl
         << endl;
    cout << "The output of that loop is:" << endl;
    int i = 0;
    while (i < 10)
    {
        cout << i;
        i++;
    }
    cout << endl;
    enterNumToContinue();
}

// executes all 6 problems
int main()
{
    int problemSelected = 1;
    while (problemSelected >= 1 && problemSelected <= 6)
    {
        cout << endl
             << "Enter a number between 1 and 6 to view each problem for this worksheet." << endl
             << "Any other number will exit the program." << endl
             << "1." << endl
             << "2." << endl
             << "3." << endl
             << "4." << endl
             << "5." << endl
             << "6." << endl
             << "7. <exit this program>" << endl << endl;
        cin >> problemSelected;
        cout << endl;
        switch (problemSelected)
        {
        case 1:
            firstProblem();
            break;
        case 2:
            secondProblem();
            break;
        case 3:
            thirdProblem();
            break;
        case 4:
            fourthProblem();
            break;
        case 5:
            fifthProblem();
            break;
        case 6:
            sixthProblem();
            break;
        }
    }
}