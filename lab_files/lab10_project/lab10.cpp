// author: Von Reid, Ronald Hunt

#include <iostream>
#include <fstream> // used for file stuff
#include <cassert> // used for assert()

using std::cin;  // user input
using std::cout; // message output
using std::endl; // my professor recommends endl over \n but I can't remember why lol
using std::string;
// MIGHT use this
// using std::fstream;  // combo of ofstream and ifstream: creates, reads, and writes to files——but stack overflow peeps mostly recommend only using this for only both read and right, not one or the other
using std::ifstream; // reads from files
using std::ofstream; // creates and writes to files

// main functions
char swap(char); // takes in two characters (by reference) and exchanges the contents of the two arguments.

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
    char mainArray[2] = {iZero, iOne};

    return 0; // close program
}

void testDriver()
{
    assert(3 + 5 == 8); // dumb stupid assert requirement for question 2 :P
    cout << "All tests passed." << endl
         << endl; // again, dumb question 2
}

char swap(char charArray)