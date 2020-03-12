// author: Von Reid

/*
    *WARNING*
    
    THIS FILE DOESN'T WORK 100% YET
    The calculations and functions in this program work 98%, however.
    There's also a mess of comments everywhere, but I'll clean it up soon.
    I'm almost done guys lol just give me a lil bit     yeeeet
*/

#include <iostream>
#include <sstream>
#include <cassert> // used for assert()
#include <fstream> // file stuff

using std::cin;  // user input
using std::cout; // message output
using std::endl; // my professor recommends endl over \n but I can't remember why lol
using std::string;
/////// yo remember to resort these more logically at some point, but the formatter auto-sorts them by alphabetical order for some reason *big shrug* lolol
using std::fstream;  // combo of ofstream and ifstream: creates, reads, and writes to files——but stack overflow peeps mostly recommend only using this for only both read and right, not one or the other
using std::ifstream; // reads from files
using std::ofstream; // creates and writes to files

bool checkIfPrime = false, testBoi = false;
const unsigned short int MAX_SIZE = 10000; // won't go higher than that, according to assignment standards
unsigned int primeArray[MAX_SIZE];         // store prime numbers here

// prime number handling (algorithm) functions
bool isPrime(int);                                             // the number you pass into isPrime() is how many prime numbers you want, and isPrime() will run through every number starting with 2 until it gets the amount of prime numbers you need
bool collectPrimeNumbers(int, bool, const unsigned short int); // collects the amount of prime numbers you tell it to, and prints them out if it's not used for a test

// file functions
void storeToMainFile(string, const unsigned short int); // store main() prime numbers here
void readMainFile(string, const unsigned short int);    // reads and prints prime numbers from the main() .txt file
void testFile(bool);                                    // optional saved test file for test results, currently flagged off
void fileBuffer(string);                                // buffer the file to make sure to get rid of old data

// QA functions
bool testDriver();       // runs a bunch of tests on isPrime() to ensure that there won't be any bugs or errors (QA)
void bugMessage(string); // just for the sake of making bug messages easier to flag

int main()
{

    // run some tests yo
    /*testDriver();
    if (testBoi == false) // bug report if there's a weird bug somehow *shrug*
    {
        bugMessage("Oof, there's a bug in testDriver()! Global var 'testBoi' returned false.");
        assert(false); // closes the program and identifies this line number (the line below the bug report, so it'll make debugging easier)
    }*/

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
        collectPrimeNumbers(inputQuant, true, userInput);

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

bool collectPrimeNumbers(int primeQuant, bool ismainFile, const unsigned short int constPrimeQuant)
{
    unsigned short int primeArrayIndex = 0; // knows where to store the prime number in the text file

    for (unsigned short int num = 2; num <= MAX_SIZE; num++) // num tests every number from 0 to the MAX_SIZE constant var——until the amount of listed prime numbers matches the value of inputQuant
    {
        isPrime(num);
        if (checkIfPrime == true)
        {
            //primeArray[primeArrayIndex].push_back(num);
            primeArray[primeArrayIndex] = num;

            primeArrayIndex++; // moves on to the next prime number slot in the array
            primeQuant--;      // tracks how many prime numbers get listed by deducting until it reaches 0
        }
        if (primeQuant == 0)
        {
            // stops running through every number less than closeToInfinity and moves on to the end of isPrime()
            break;
        }
    }
    if (primeQuant != 0) // triggers bug report in case primeQuant doesn't reach 0 somehow
    {
        bugMessage("error with primeQuant not reducing to 0 in collectPrimeNumbers()");
        assert(false); // closes the program and identifies this line number (the line below the bug report, so it'll make debugging easier)
    }

    if (ismainFile == true)
    {
        const string primeFileName = "lab_files/lab09_project/prime_numbers.txt";

        // stores the array numbers to the main() .txt file
        storeToMainFile(primeFileName, constPrimeQuant);
        // prints file to display the main() prime numbers
        readMainFile(primeFileName, constPrimeQuant);
    }
    else // for tests only
    {
        // If I want to save a test file to check the test results, I can change the mainFile bool *dank extra test code file* #justcuzican
        testFile(true);
    }

    return true; // only for assertion tests in the testDriver() function, but useless for when it's used in main()
}

bool isPrime(int testNum)
{
    checkIfPrime = true; // sets default value each time isPrime() gets used, so it will always be true unless the algorithm in the for() loop below makes it false

    if (testNum == 2 || testNum == 3) // I can't effing figure out why the for() won't accept 2 or 3, so I put this here for now to get around it
    {
        return checkIfPrime;
    }

    // tests if the number is a prime number or not.
    for (unsigned short int eachNum = 2; eachNum <= testNum / 2; ++eachNum)
    {
        if (testNum % eachNum == 0)
        {
            checkIfPrime = false;
            break;
        }
    }

    return checkIfPrime;
}

void storeToMainFile(const string primeFileName, const unsigned short int maxInput)
{
    // store main() prime numbers here

    ofstream primeFile(primeFileName);
    //random shit to eventually delete
    //std::stringstream primeData;
    //string primeData[constPrimeQuant];
    //primeData << primeArray;
    //cout << primeData << endl;;
    //cout << primeArray << endl;
    //  fileBuffer(primeFileName);  FIX THIS LATER
    //primeData >> primeFile;
    for (unsigned short int store = 0; store < maxInput; store++)
    {
        //cout << primeArray[i] << endl; ////

        //primeArray[i] >> primeData[i];
        primeFile << primeArray[store] << endl;
    }
    primeFile.close();
}

void readMainFile(const string mainFileName, const unsigned short int maxNum)
{
    string line, mainArrayStr[maxNum];
    ifstream mainPrimeFile;
    mainPrimeFile.open(mainFileName);
    // Output the prime numbers from the file
    unsigned short int slot = 0;
    while (getline(mainPrimeFile, line))
    {
        mainArrayStr[slot] = line;
        slot++;
    }
    mainPrimeFile.close(); ////

    /*for (int index = 0; index < maxNum; i++)
        {
            primeFile << primeArray[index]; // keep printing the array numbers from the ifstream mainPrimeFile
        }*/

    //cout << line;
    // if (mainPrimeFile.is_open())
    // {
    //string mainArray[maxNum];
    //unsigned int mainArray[maxNum];
    for (slot = 0; slot < maxNum; slot++)
    {
        //mainPrimeFile >> mainArray[slot];
        cout << mainArrayStr[slot] << endl;
    }

    // mainPrimeFile.close(); // close the file
    // }
    /*else
    {
        bugMessage("File-opening malfunction; check readMainFile()");
        mainPrimeFile.close(); // attempt to close
        assert(false);
    }*/
}

bool testDriver()
{
    bool passTest = true;
    const unsigned short int testNum = 859; // 6661 is the 859th prime number
    // tests every prime number up until 6661 (the 859th prime number, when you count 2 as the 1st)
    assert(collectPrimeNumbers(859, false, testNum) == passTest);

    /* testBoi ensures that testDriver() was executed to the end with no bugs.
       Pretty unnecessary, because the assert() stuff above will end the program and return an error if any of the assertions fail.
       But testBoi adds extra, extremely-solid QA to the program, so sue me. */
    testBoi = true;

    return testBoi;
}

void testFile(bool saveTestFile)
{
    if (saveTestFile == true)
    {
        string testFileName = "lab_files/lab09_project/test_driver.txt";
        ofstream testFile(testFileName);
        fileBuffer(testFileName);
        std::stringstream testData;
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