// author: Von Reid

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int isClose();

int main()
{
    isClose();

    return 0;
}

int isClose()
{
    double num1, num2, greaterNum, smallerNum, difference;
    cout << "Hello, please enter a number, ANY number." << endl;
    cin >> num1;
    cout << "Now enter another number." << endl;
    cin >> num2;

    if (num1 >= num2)
    {
        greaterNum = num1;
        smallerNum = num2;
    }
    else if (num2 > num1)
    {
        greaterNum = num2;
        smallerNum = num1;
    }

    difference = greaterNum - smallerNum;
    if (difference < 1E-4)
    {
        //figure out what to do with the true/false result after you finish the other problems
        return true;
    }
    else
    {
        return false;
    }
}