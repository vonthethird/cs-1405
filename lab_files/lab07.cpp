/*
author: Von Reid
this program converts imperial units into metric units.
it also tests that everything works properly (besides the stuff in main()) with the testDriver() function.
*/

#include <iostream>
#include <cassert>
#include <assert.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// this compares 2 numbers to see if one is almost the exact same number as the other
// see testDriver() for more info
bool isClose(float, float);

// these 3 functions will convert units (as stated on line 2)
float inToCm(float);
float ydToM(float);
float miToKm(float);

// this tests the 4 functions above it
void testDriver();

// this inputs the user's entered imperial unit each time you want to convert a unit
int floatInp(string);
void floatOutp(float, string);

// these variables get used in multiple functions, so they MUST be global #sorrynotsorry
float usrFloat, cm, m, km;

int main()
{
    // run a bunch of tests at the beginning to add some solid QA to the functions used in the important code before the important code gets executed
    testDriver();

    // inches to centimeters
    floatInp("Please enter how many inches you would like to convert into centimeters.");
    inToCm(usrFloat);
    floatOutp(cm, "cm");

    // yards to meters
    floatInp("Please enter how many yards you would like to convert into meters.");
    ydToM(usrFloat);
    floatOutp(m, "m");

    // miles to kilometers
    floatInp("Please enter how many miles you would like to convert into kilometers.");
    miToKm(usrFloat);
    floatOutp(km, "km");

    return 0;
}

bool isClose(float num1, float num2)
{
    float difference, greaterNum, smallerNum;

    // determines which number is the biggest and which is the smallest
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
    // if there's more than a 1E-4 difference between the 2 numbers, the assertions in testDriver() will catch it and successfully report that there's a problem
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
    // might as well make this const just for the sake of having squeaky clean code
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
    // this tests if those 2 numbers are APPROXIMATELY the same number
    // it should return true, because 4.9999999 is approximately the same number as 5 (because 0.0000001)
    assert(isClose(4.9999999, 5));

    // this assertion is intended to fail, to test that isClose() returns false when its parameters aren't close together enough--delete the comment slashes below to try it out for yourself.
    // assert(isClose(40000, 5));

    // the [unit]1 and [unit]2 values SHOULD be the exact same numbers, since it's literally the copy-and-pasted math from the unit conversion functions
    float cm1 = inToCm(2), cm2 = 2 * 2.54;
    float m1 = ydToM(2), m2 = 2 * 0.9144;
    float km1 = miToKm(2), km2 = 2 * 1.609344;
    // now we get to make sure that they're approximately the same numbers by testing all 3 unit conversion functions with isClose()
    assert(isClose(cm1, cm2));
    assert(isClose(m1, m2));
    assert(isClose(km1, km2));
}

int floatInp(string floatInpPrompt)
{
    cout << floatInpPrompt << endl;
    cin >> usrFloat;
    // gotta yeet this boi back to main() so the unit conversion functions can use it to convert the value into metric units
    return usrFloat;
}

void floatOutp(float callFloat, string floatLabel)
{
    // displays the value and the unit name
    cout << callFloat << " " << floatLabel << endl;
}