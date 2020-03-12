// author: Von Reid, Ronald Hunt

#include <iostream>
#include <fstream>         // used for file stuff
#include <cassert>         // used for assert() in void testDriver()
#include <string.h>        // used for memcpy(), mostly in the array-altering functions i.e. swap(), reverse(), etc.
#define sendl endl << endl // creats a 'super endl' (pretty much) const string var for me to reduce redundant endl usage

using std::cin;  // user input
using std::cout; // message output
using std::endl; // my professor recommends endl over \n but I can't remember why lol
using std::string;
// MIGHT use this
// using std::fstream;  // combo of ofstream and ifstream: creates, reads, and writes to files——but stack overflow peeps mostly recommend only using this for only both read and right, not one or the other
using std::ifstream; // reads from files
using std::ofstream; // creates and writes to files

// global cosnt variables
const unsigned short int globalConstArraySubscr = 2; // recurring subscript in the arrays dealt with in this program
const char globalConstArray[globalConstArraySubscr] = {'a', 'b'};

// global variables
char globalArray[globalConstArraySubscr];

// main functions
char copy(int *, int *, int); // turns one array into another with recursion, rather than using redundant loops to do it; VERY convenient yo
void swap(char[]);            // takes in two characters (by reference) and exchanges the contents of the two arguments.
void reverse(char[], int);    // takes in a character array and a size, n, and then reverses the first n characters of the array

// file functions
void saveFile(string, char, int); // takes file, writes char array values until int size value gets reached, then saves to new file
void loadFile(string, char, int); // takes file, reads until end of file is reached, then return characters that were read

// QA functions
void testDriver(); // for running tests
void reverseTests(int, int, char[]);

int main()
{
    // run tests on some stuff; incomplete for now
    testDriver();

    // index char values for the char array below
    char iZero = 'y', iOne = 'z';
    /*
        *FIRST I NEED TO GET PERMANENT DEFAULT VALUES FOR iZero AND iOne*
    */
    char mainArray[globalConstArraySubscr] = {iZero, iOne};

    // set globalArray values to the same as mainArray[]
    memcpy(globalArray, mainArray, sizeof((mainArray)));
    assert(globalArray[0] == mainArray[0] && globalArray[1] == mainArray[1]); // test the same values with each other

    //  swap mainArray values and spit them into globalArray values
    swap(mainArray);
    assert(globalArray[0] == mainArray[1] && globalArray[1] == mainArray[0]); // test the swapped values with the original values

    // reverse mainArray values and spit them into globalArray values
    reverse(mainArray, globalConstArraySubscr);
    assert(globalArray[0] == mainArray[1]);

    // globalArray will have the mainArray values
    if ((globalArray[0] == iOne && globalArray[1] == iZero) || (mainArray[0] == iZero && mainArray[1] == iOne))
    {
        cout << "mainArray has been successfully swapped." << endl;
        cout << globalArray[0] << endl;
        cout << globalArray[1] << endl;
    }
    else
    {
        cout << "**mainArray has NOT been successfully swapped.**" << endl;
        assert(false); // flag for bug
    }

    return 0; // close program
}

void swap(char charArray[])
{
    // create the swapped array
    char charSwapArray[2] = {charArray[1], charArray[0]};

    // create some consts;
    char i1 = charArray[0];
    char i2 = charArray[1];

    const char indexOne = i1;
    const char indexTwo = i2;

    // reset the globalArray for this function
    memcpy(globalArray, charSwapArray, sizeof((charSwapArray)));

    // assertions to ensure that memcpy() successfully made globalArray become charArray
    assert(globalArray[0] == charSwapArray[0]);
    assert(globalArray[1] == charSwapArray[1]);
    // assertions to ensure that globalArray[] is the opposite of charSwapArray[]
    assert(globalArray[0] == charArray[1]);
    assert(globalArray[1] == charArray[0]);
}

void reverse(char charArray[], int n)
{
    int i = 0, decrement = n - 1; // decrement will count down to opposing cells
    while (i <= n)
    {
        globalArray[i] = charArray[decrement];
        decrement--;
        i++;
        if (i == n)
        {
            break;
        }
    }
}

void saveFile(string fileName, char, int)
{
    // saveFile() stuff
}

void loadFile(string fileName, char, int)
{
    // loadFile() stuff
}

void testDriver()
{
    // dumb lab questions; pay no attention
    //assert(3 + 5 == 8);                   // dumb stupid assert requirement for question 2 :P
    //cout << "All tests passed." << sendl; // again, dumb question 2

    // reset globalArray to clean new value
    memcpy(globalArray, globalConstArray, sizeof((globalConstArray)));

    // swap() test
    char testArray[globalConstArraySubscr] = {'a', 'b'};
    swap(testArray);
    // now globalArray will have testArray's swapped values, so these assertions should be true
    assert(globalArray[0] == testArray[1]);
    assert(globalArray[1] == testArray[0]);

    // reset globalArray to clean new value
    memcpy(globalArray, globalConstArray, sizeof((globalConstArray)));

    short unsigned int t, t2, i = 0;

    // 3 different tests on reverse()
    while (i < 3)
    {
        if (i == 0)
        {
            t = 3;
            t2 = t - 1;
            char reverseArray[t] = {'a', 'b', 'c'};
            reverse(reverseArray, t);
            reverseTests(t, t2, reverseArray);
        }
        else if (i == 1)
        {
            t = 4;
            t2 = t - 1;
            char reverseArray[t] = {'a', 'b', 'c', 'd'};
            reverse(reverseArray, t);
            reverseTests(t, t2, reverseArray);
        }
        else if (i == 2)
        {
            t = 10;
            t2 = t - 1;
            char reverseArray[t] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
            reverse(reverseArray, t);
            reverseTests(t, t2, reverseArray);
        }
        else
        {
            cout << "oof, reverse() testing in testDriver failed" << endl;
            assert(false);
        }
        i++;
    }
}

void reverseTests(int maxNum, int decrement, char reverseTestArray[])
{
    for (int index = 0; index < maxNum; index++)
    {
        assert(reverseTestArray[index] == globalArray[decrement]);
        decrement--;
        if (decrement < 0)
        {
            break;
        }
    }
}