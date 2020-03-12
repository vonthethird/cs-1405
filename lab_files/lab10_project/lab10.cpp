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
const unsigned short int globalArraySubscr = 2; // recurring subscript in the arrays dealt with in this program

// global variables
char globalArray[globalArraySubscr] = {'a', 'b'};

// main functions
char copy(int *, int *, int); // turns one array into another with recursion, rather than using redundant loops to do it; VERY convenient yo
void swap(char[]);            // takes in two characters (by reference) and exchanges the contents of the two arguments.
void reverse(char[]);         // takes in a character array and a size, n, and then reverses the first n characters of the array

// file functions
void saveFile(string, char, int); // takes file, writes char array values until int size value gets reached, then saves to new file
void loadFile(string, char, int); // takes file, reads until end of file is reached, then return characters that were read

// QA functions
void testDriver(); // for running tests

int main()
{
    // run tests on some stuff; incomplete for now
    //testDriver();

    // index char values for the char array below
    char iZero = 'y', iOne = 'z';
    /*
        *FIRST I NEED TO GET PERMANENT DEFAULT VALUES FOR iZero AND iOne*
    */
    char mainArray[globalArraySubscr] = {iZero, iOne};

    // reset globalArray values
    globalArray[0] = iZero;
    globalArray[1] = iOne;

    //  swap mainArray values and spit them into globalArray values
    swap(mainArray);
    // assign new global values to local main values
    mainArray[0] = globalArray[0];
    mainArray[1] = globalArray[1];

    if (mainArray[0] == iOne & mainArray[1] == iZero)
    {
        cout << "mainArray has been successfully swapped." << endl;
        cout << mainArray[0] << endl;
        cout << mainArray[1] << endl;
    }
    else
    {
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
    //1st try -- fail      globalArray = charSwapArray;
    //2nd try -- fail      copy(globalArray[0], globalArray[1], 2); // oof won't work lol
    memcpy(globalArray, charSwapArray, sizeof((charSwapArray)));

    // assertions to ensure that memcpy() successfully made globalArray become charArray
    assert(globalArray[0] == charSwapArray[0]);
    assert(globalArray[1] == charSwapArray[1]);
    // assertions to ensure that globalArray[] is the opposite of charSwapArray[]
    assert(globalArray[0] == charArray[1]);
    assert(globalArray[1] == charArray[0]);
}

void reverse(char charArray[])
{
    // reverse() stuff
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
    assert(3 + 5 == 8);                   // dumb stupid assert requirement for question 2 :P
    cout << "All tests passed." << sendl; // again, dumb question 2

    // reset globalArray to default value
    globalArray[0] = 'a';
    globalArray[1] = 'b';

    // real tests
    char testChar[globalArraySubscr] = {'a', 'b'};
    //assert(swap(testChar) == globalArray) // not working yet lol
}

/*//lol I might actually kill this function *shrug*
// array copy shortcut; VERY CONVENIENT——copies one array into another
char copy(int *a, int *b, int b_size)
{
    const char returnChar = 'a';

    if (b_size == 0)
        return returnChar;
    *a = *b;
    copy(++a, ++b, b_size - 1);
}
*/