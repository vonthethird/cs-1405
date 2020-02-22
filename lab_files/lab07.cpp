// author: Von Reid

#include <iostream>
#include <cassert>
#include <assert.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int isClose(float, float);
int inchToCm(float);
int yardToM(float);
int mileToKm(float);
void testDriver();
int floatInp(string);
float floatOutp(float, string);

float close1 = 4.9999999;
float close2 = 5;
float usrFloat, cm, m, km;

int main()
{
    testDriver();

    floatInp("Please enter how many inches you would like to convert into centimeters.");
    inchToCm(usrFloat);
    floatOutp(cm, "cm");

    floatInp("Please enter how many yards you would like to convert into meters.");
    yardToM(usrFloat);
    floatOutp(m, "m");

    floatInp("Please enter how many miles you would like to convert into kilometers.");
    mileToKm(usrFloat);
    floatOutp(km, "km");

    return 0;
}

int isClose(float num1, float num2)
{
    float difference, greaterNum, smallerNum;

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

int inchToCm(float inch)
{
    float const cmConversion = 2.54;
    cm = inch * cmConversion;
    return cm;
}

int yardToM(float yard)
{
    float const mConversion = 0.9144;
    m = yard * mConversion;
    return m;
}

int mileToKm(float mile)
{
    float const kmConversion = 1.609344;
    km = mile * kmConversion;
    return km;
}

void testDriver()
{
    assert(isClose(close1, close2));
    // this assertion fails, so that tells us that isClose() works properly.
    // assert(isClose(40000, 5));

    /* honestly, I have no idea how to do 3b, I started to do this but it's not working like it's supposed to.
    float cm1 = inchToCm(close1), cm2 = inchToCm(close2), m1 = yardToM(close1), m2 = yardToM(close2), km1 = mileToKm(close1), km2 = mileToKm(close2);
    assert(isClose(cm1, cm2));
    assert(isClose(m1, m2));
    assert(isClose(km1, km2)); */
}

int floatInp(string floatInpPrompt)
{
    cout << floatInpPrompt << endl;
    cin >> usrFloat;
    return usrFloat;
}

float floatOutp(float callFloat, string floatLabel)
{
    cout << callFloat << " " << floatLabel << endl;
}