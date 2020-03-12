// author: Von Reid, Ronald Hunt

#include <iostream>
#include <fstream>         // used for file stuff
#include <cassert>         // used for assert()
#include <string.h>
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
const unsigned short int globalArraySub = 2; // recurring subscript in the arrays dealt with in this program

// global variables
char globalArray[globalArraySub] = {'a', 'b'};

// main functions
char copy(int *, int *, int); // turns one array into another with recursion, rather than using redundant loops to do it; VERY convenient yo
char swap(char[]);            // takes in two characters (by reference) and exchanges the contents of the two arguments.

// QA functions
void testDriver(); // for running tests

int main()
{
    // run tests on some stuff; incomplete for now
    testDriver();

    // index char values for the char array below
    char iZero, iOne;
    /*
        *FIRST I NEED TO GET PERMANENT DEFAULT VALUES FOR iZero AND iOne*
    */
    char mainArray[globalArraySub] = {iZero, iOne};
    swap(mainArray);

    return 0; // close program
}

void testDriver()
{
    // dumb lab questions; pay no attention
    assert(3 + 5 == 8);                   // dumb stupid assert requirement for question 2 :P
    cout << "All tests passed." << sendl; // again, dumb question 2

    // reset globalArray to default value
    globalArray[0] = 'a';
    globalArray[1] = 'b';

    // real tests
    char testChar[globalArraySub] = {'a', 'b'};
    //assert(swap(testChar) == globalArray) // not working yet lol
}

char swap(char charArray[])
{
    // create the swapped array
    char charSwapArray[2] = {charArray[1], charArray[0]};

    // create some consts;
    char i1 = charArray[0];
    char i2 = charArray[1];

    const char indexOne = i1;
    const char indexTwo = i2;


    // reset the globalArray for this function
    //1st try -- fail      globalArray = charSwapArray;
    //2nd try -- fail      copy(globalArray[0], globalArray[1], 2); // oof won't work lol
    memcpy(globalArray, charArray, globalArraySub);
}

// array copy shortcut; VERY CONVENIENT——copies one array into another
char copy(int *a, int *b, int b_size)
{
    const char returnChar = 'a';

    if (b_size == 0) return returnChar;
    *a = *b;
    copy(++a, ++b, b_size - 1);
}