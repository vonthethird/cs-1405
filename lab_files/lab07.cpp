// author: Von Reid

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int isClose();
int inchToCm(float);
int yardToM(float);
int mileToKm(float);

int main()
{
    /*isClose();
    inchToCm(4.28);
    yardToM(3.2);
    mileToKm(8.9);*/

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

int inchToCm(float inch)
{
    float cm = inch * 2.54;
}

int yardToM(float yard)
{
    float m = yard * 0.9144;
}

int mileToKm(float mile)
{
    float km = mile * 1.60934;
}