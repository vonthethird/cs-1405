// author: Von Reid

#include <iostream>
#include <cassert>
#include <assert.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int isClose(float, float);
float inToCm(float);
float ydToM(float);
float miToKm(float);
void testDriver();
int floatInp(string);
float floatOutp(float, string);

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

float inToCm(float in)
{
    float const cmConversion = 2.54;
    cm = in * cmConversion;
    return cm;
}

float ydToM(float yd)
{
    float const mConversion = 0.9144;
    m = yd * mConversion;
    return m;
}

float miToKm(float mi)
{
    float const kmConversion = 1.609344;
    km = mi * kmConversion;
    return km;
}

void testDriver()
{
    assert(isClose(4.9999999, 5));
    // this assertion fails, so that tells us that isClose() works properly.
    // assert(isClose(40000, 5));

    float cm1 = inToCm(2), cm2 = 2 * 2.54;
    float m1 = ydToM(2), m2 = 2 * 0.9144;
    float km1 = miToKm(2), km2 = 2 * 1.609344;
    assert(isClose(cm1, cm2));
    assert(isClose(m1, m2));
    assert(isClose(km1, km2));
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