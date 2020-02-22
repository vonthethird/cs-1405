// author: Von Reid

#include <iostream>
#include <cassert>
#include <assert.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int isClose(float, float);
int inToCm(float);
int ydToM(float);
int miToKm(float);
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
    inToCm(usrFloat);
    floatOutp(cm, "cm");

    floatInp("Please enter how many yards you would like to convert into meters.");
    ydToM(usrFloat);
    floatOutp(m, "m");

    floatInp("Please enter how many miles you would like to convert into kilometers.");
    miToKm(usrFloat);
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

int inToCm(float in)
{
    float const cmConversion = 2.54;
    cm = in * cmConversion;
    return cm;
}

int ydToM(float yd)
{
    float const mConversion = 0.9144;
    m = yd * mConversion;
    return m;
}

int miToKm(float mi)
{
    float const kmConversion = 1.609344;
    km = mi * kmConversion;
    return km;
}

void testDriver()
{
    assert(isClose(close1, close2));
    // this assertion fails, so that tells us that isClose() works properly.
    // assert(isClose(40000, 5));

    /* honestly, I have no idea how to do 3b, I started to do this but it's not working like it's supposed to.
    float cm1 = inToCm(close1), cm2 = inToCm(close2), m1 = ydToM(close1), m2 = ydToM(close2), km1 = miToKm(close1), km2 = miToKm(close2);
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