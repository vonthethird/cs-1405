// author: Von Reid

/*
    *WARNING*
    
    THIS FILE DOESN'T WORK 100% YET
    The calculations and functions in this program work 98%, however.
    There's also a mess of comments everywhere, but I'll clean it up soon.
    I'm almost done guys lol just give me a lil bit     yeeeet
*/

/*
use this eventually tho boi

if (std::string(typeid(input_variable).name()) == typeid(chosen_type).name())
 {
      // input_variable is of type chosen_type
 }
*/

#include <iostream>
#include <fstream> // used for file stuff
#include <cassert> // used for assert()

using std::cin;  // user input
using std::cout; // message output
using std::endl; // my professor recommends endl over \n but I can't remember why lol
using std::string;
/////// yo remember to resort these more logically at some point, but the formatter auto-sorts them by alphabetical order for some reason *big shrug* lolol
//using std::fstream;  // combo of ofstream and ifstream: creates, reads, and writes to files——but stack overflow peeps mostly recommend only using this for only both read and right, not one or the other
using std::ifstream; // reads from files
using std::ofstream; // creates and writes to files

// global const variables -- NEVER CHANGE THESE
const bool assertFalse = false;            // only for a constant static value to stick in my false assertion flags
const unsigned short int MAX_SIZE = 10000; // won't go higher than that, according to assignment standards

// global variables for return statements
// checkIfPrime gets passed from isPrime() to collectPrimeNumbers(), defaults globally as false unless isPrime() switches it to true
bool checkIfPrime = false;
bool testsPassed = false;          // testsPassed defaults at false, but switches to true when/if the initial testDrive() test in main() returns true to successfully/securely/solidly indicate passed tests
unsigned int primeArray[MAX_SIZE]; // store prime numbers here

// prime number handling (algorithm) functions
bool collectPrimeNumbers(bool, unsigned short int, const unsigned short int); // collects the amount of prime numbers you tell it to, and prints them out if it's not used for a test
bool isPrime(int);                                                            // the number you pass into isPrime() is how many prime numbers you want, and isPrime() will run through every number starting with 2 until it gets the amount of prime numbers you need

// file functions
void createFile(string);                                // can create any file, passes in the file name and does it (simply for refactoring and to break it up into a smaller function)
void storeToMainFile(string, const unsigned short int); // store main() prime numbers here
void readMainFile(string, const unsigned short int);    // reads and prints prime numbers from the main() .txt file
void fileBuffer(string);                                // buffer the file to make sure to get rid of old data

// QA functions
bool testDriver();       // runs a bunch of tests on isPrime() to ensure that there won't be any bugs or errors (QA)
void testFile(bool);     // optional saved test file for test results, currently flagged off
void bugMessage(string); // just for the sake of making bug messages easier to flag

int main()
{

    // run some tests yo
    /*testDriver();
    if (testsPassed == false) // bug report if there's a weird bug somehow *shrug*
    {
        bugMessage("Oof, there's a bug in testDriver()! Global var 'testsPassed' returned false.");
        assert(assertFalse); // closes the program and identifies this line number (the line below the bug report, so it'll make debugging easier)
    }*/
    testsPassed = true; // TEMPORARILY here but will delete after I get tests working again

    char newList = 'n'; // gives newList a default value at first to avoid (unlikely but potential) weird lacking-initialized-value bugs
    do                  // executes the program, then the user can choose to either make a new list of prime numbers or exit the program with newList value
    {

        switch (newList) // determines first part of greeting by whether it's the first time the program is running or if the user is running it after listing prime numbers at least once
        {
        case 'n':
            cout << "Hello! "; // greeting to user
            break;
        case 'y':
            cout << endl; // extra line for clean line usage ;)
            break;
        }
        cout << "Please enter how many prime numbers you would like to print out (anything from 0 to " << MAX_SIZE << ")." << endl;
        unsigned short int inputQuant = 0; // "Quant" meaning "Quantity," for the quantity of prime numbers
        cin >> inputQuant;
        while (inputQuant < 0 || inputQuant > MAX_SIZE)
        {
            cout << "You must enter anything ranging from 0 to " << MAX_SIZE << "." << endl;
            cin >> inputQuant;
        }
        const unsigned short int userInput = inputQuant; // save this value to use it at the end of main()
        // the below function should always return true in main(), so assert() is a safety blanket
        assert(collectPrimeNumbers(testsPassed, inputQuant, userInput)); // by this point, the testsPassed value SHOULD be true, and I will always have it set to true by this line

        cout << endl
             << "Those are all of the first " << userInput << " positive sequential prime numbers greater than 0." << endl;

        // prompt to start over program
        cout << endl
             << "Would you like to list more prime numbers?" << endl
             << "Enter [y]es or [n]o." << endl;
        cin >> newList;
        cout << newList << endl; //
        while (newList != 'y' && newList != 'n')
        {
            cout << "That's not a valid option! Enter [y]es or [n]o." << endl;
            cin >> newList;
        }
    } while (newList == 'y');

    // close program
    return 0;
}

bool collectPrimeNumbers(bool isMainFile, unsigned short int primeQuant, const unsigned short int constPrimeQuant)
{
    unsigned short int primeArrayIndex = 0; // knows where to store the prime number in the text file

    for (unsigned short int testForPrime = 2; testForPrime <= MAX_SIZE; testForPrime++) // testForPrime tests every number from 0 to the MAX_SIZE constant var——until the amount of listed prime numbers matches the value of inputQuant
    {
        isPrime(testForPrime);
        if (checkIfPrime == true)
        {
            //primeArray[primeArrayIndex].push_back(testForPrime);
            primeArray[primeArrayIndex] = testForPrime;

            primeArrayIndex++; // moves on to the next prime number slot in the array
            primeQuant--;      // tracks how many prime numbers get listed by deducting until it reaches 0
        }
        if (primeArrayIndex > constPrimeQuant) // bug catcher flag
        {
            bugMessage("caught error in collectPrimeNumbers() with primeArrayIndex value becoming greater than constPrimeQuant");
            assert(assertFalse);
            break;
        }
        if (primeQuant < 0 || ((primeQuant > constPrimeQuant) && constPrimeQuant != 0)) // will trigger a bug after breaking the for() loop
        {
            // in the rare case of the for() loop going on longer than expected, I'm cutting off the primeQuant-- decremental loopage at < 0 to break the loop lol
            break;
        }
        else if (primeQuant == 0)
        {
            // stops running through every number less than closeToInfinity and moves on to the end of isPrime()
            break;
        }
    }
    if (primeQuant != 0) // triggers bug report in case primeQuant doesn't reach 0 somehow
    {
        bugMessage("error with primeQuant not reducing to 0 in collectPrimeNumbers()");
        cout << "primeQuant value: " << primeQuant << endl;
        assert(assertFalse); // closes the program and identifies this line number (the line below the bug report, so it'll make debugging easier)
    }
    if (isMainFile == true)
    {
        string mainFileName = "prime_numbers.txt";
        // create the file first
        createFile(mainFileName);
        // stores the array numbers to the main() .txt file
        storeToMainFile(mainFileName, constPrimeQuant);
        // prints file to display the main() prime numbers
        readMainFile(mainFileName, constPrimeQuant);
        return isMainFile;
    }
    else // I can change the isMainFile bool in collectPrimeNumbers to save a test file if I want to view the test results in a .txt *dank extra test code file* #justcuzican
    {
        testFile(assertFalse); // assertFalse is currently switching off the testFile function
        return isMainFile;
    }
}

bool isPrime(int testNum)
{
    checkIfPrime = true; // sets default value each time isPrime() gets used, so it will always be true unless the algorithm in the for() loop below makes it false

    if (testNum == 2 || 3) // I can't effing figure out why the for() won't accept 2 or 3, so I put this here for now to get around it
    {
        return (testNum == 2 || 3); // will be true, so that's fine
    }

    // tests if the number is a prime number or not.
    for (unsigned short int primeTest = 2; primeTest <= testNum / 2; ++primeTest)
    {
        if (testNum % primeTest == 0)
        {
            checkIfPrime = false;
            break;
        }
    }

    return checkIfPrime;
}

void storeToMainFile(string primeFileName, const unsigned short int maxInput)
{
    // store main() prime numbers here

    ofstream primeFile(primeFileName);

    //ooooooof ignore this lol                                 fileBuffer(primeFileName);  FIX THIS LATER

    for (unsigned short int store = 0; store < maxInput; store++)
    {
        // stores the array into the file for whatever maxInput is (maxInput traces back to the original inputQuant var in main() yo)
        //primeFile << primeArray[store] << endl;
        cout << primeArray[store] << endl;
    }
    primeFile.close();

    if (primeFile.is_open())
    {
        bugMessage("problem associated with closing the newly-made file");
        cout << "File name: " << primeFileName << endl;
        assert(assertFalse);
    }
}

void readMainFile(string readFileName, const unsigned short int maxNum)
{
    string line, mainArrayStr[maxNum];
    ifstream mainPrimeFile;
    mainPrimeFile.open(readFileName);
    // Output the prime numbers from the file
    unsigned short int slot = 0;
    while (getline(mainPrimeFile, line))
    {
        mainArrayStr[slot] = line;
        slot++;
        if (slot == maxNum)
        {
            break; // just cuz we only need 5 slots in the main array, ya know?
        }
    }
    mainPrimeFile.close();

    if (mainPrimeFile.is_open()) // bug catcher flag
    {
        bugMessage("File-opening malfunction; check readMainFile()");
        mainPrimeFile.close(); // attempt to close
        assert(assertFalse);
    }
    else // print it out tho
    {
        for (slot = 0; slot < maxNum; slot++)
        {
            cout << mainArrayStr[slot] << endl;
        }
    }
}

bool testDriver()
{
    const bool passTest = true;
    const unsigned short int testNum = 859; // 6661 is the 859th prime number

    /*
    collectPrimeNumbers() passed values explained:
        [assertFalse]used static false bool var assertFalse as a way of passing (isMainFile = false) into collectPrimeNumbers(), which actually makes sense cuz isMainFile determines if it should print a text file for these prime nums.
        [testNum]tests every prime number up until 6661 (the 859th prime number, when you count 2 as the 1st)
        [testNum]passes testNum in still as a const int to keep track of the 859
    */
    assert(collectPrimeNumbers(assertFalse, testNum, testNum) != passTest); // collectPrimeNumbers() should return false, so it'll assert as true

    /* testsPassed ensures that testDriver() was executed to the end with no bugs.
       Pretty unnecessary, because the assert() stuff above will end the program and return an error if any of the assertions fail.
       But testsPassed adds extra, extremely-solid QA to the program, so sue me. */
    testsPassed = true;

    return testsPassed;
}

void testFile(bool saveTestFile)
{
    if (saveTestFile == true)
    {
        string testFileName = "test_driver.txt";
        createFile(testFileName);
        ofstream testFile(testFileName);
        //////fileBuffer(testFileName);
        testFile << primeArray;
        testFile.close();
    }
}

void bugMessage(string message)
{
    cout << "Bug Report: " << message << endl
         << "If you are a user: message me (Von) and paste this bug report in the message so I can fix this." << endl
         << "Here's a failed assert() to direct Von to the line of code for this bug:" << endl
         << "(this will be the line of code BELOW the bug)" << endl;
}

void fileBuffer(string bufFileName)
{
    ifstream bufFile(bufFileName);
    char buf[10241];
    bufFile.rdbuf()->pubsetbuf(buf, sizeof buf);
    //bufFile.close(); // close buffed file to keep it clean yo
}

void createFile(string createFileName)
{
    ofstream newFile(createFileName);
    newFile.close();
    if (newFile.is_open())
    {
        bugMessage("problem associated with closing the newly-made file");
        cout << "File name: " << createFileName << endl;
        assert(assertFalse);
    }
}