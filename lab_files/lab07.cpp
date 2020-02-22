// author: Von Reid

#include <iostream>
#include <cassert>
#include <assert.h>

using std::cin;
using std::cout;
using std::endl;

int isClose(double, double);
int inchToCm(double);
int yardToM(double);
int mileToKm(double);
void testDriver();
int floatBoi(float); // wonder why this isn't surrounded by the other int functions? cuz I'm ordering these by the order they come up in the lab, not the data types.

double close1 = 4.9999999;
double close2 = 5;

int main()
{
    testDriver();

    return 0;
}

int isClose(double num1, double num2)
{
    double difference, greaterNum, smallerNum;

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
        return true;
    }
    else
    {
        return false;
    }
}

int inchToCm(double inch)
{
    double const cmConversion = 2.54;
    double cm = inch * cmConversion;
}

int yardToM(double yard)
{
    double const mConversion = 0.9144;
    double m = yard * mConversion;
}

int mileToKm(double mile)
{
    double const kmConversion = 1.609344;
    double km = mile * kmConversion;
}

void testDriver()
{
    assert(isClose(close1, close2));
    // this assertion fails, so that tells us that isClose() works properly.
    // assert(isClose(40000, 5));

    /* honestly, I have no idea how to do 3b, I started to do this but it's not working like it's supposed to.
    double cm1 = inchToCm(close1), cm2 = inchToCm(close2), m1 = yardToM(close1), m2 = yardToM(close2), km1 = mileToKm(close1), km2 = mileToKm(close2);
    assert(isClose(cm1, cm2));
    assert(isClose(m1, m2));
    assert(isClose(km1, km2)); */
}

int floatBoi(float usrFloat) {
    cout << "Please enter a number." << endl;
    cin >> usrFloat;
    return usrFloat;
}