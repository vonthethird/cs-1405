// author: Von Reid

#include <iostream>
#include <cassert> // used for assert()
#include <fstream> // file stuff

using std::cin; // user input
using std::cout; // message output
using std::endl; // my professor recommends endl over \n but I can't remember why lol
using std::string;
using std::ofstream; // creates and writes to files
using std::ifstream; // reads from files
using std::fstream; // combo of ofstream and ifstream: creates, reads, and writes to files——but stack overflow peeps mostly recommend only using this for only both read and right, not one or the other

bool checkIfPrime = false, testBoi = false;

bool isPrime(int);                   // the number you pass into isPrime() is how many prime numbers you want, and isPrime() will run through every number starting with 2 until it gets the amount of prime numbers you need
bool collectPrimeNumbers(int, bool); // collects the amount of prime numbers you tell it to, and prints them out if it's not used for a test
bool testDriver();                   // runs a bunch of tests on isPrime() to ensure that there won't be any bugs or errors (QA)
void bugMessage(string);             // just for the sake of making bug messages easier to flag

int main()
{
    // store prime numbers here
    ofstream createPrimeFile("stored_prime_numbers.txt");
    
    // run some tests yo
    testDriver();
    if (testBoi == false) // bug report if there's a weird bug somehow *shrug*
    {
        bugMessage("Oof, there's a bug in testDriver()! Global var 'testBoi' returned false.");
        assert(false); // closes the program and identifies this line number (the line below the bug report, so it'll make debugging easier)
    }

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
        cout << "Please enter how many prime numbers you would like to print out (anything from 0 to 10000)." << endl;
        int inputQuant = 0; // "Quant" meaning "Quantity," for the quantity of prime numbers
        cin >> inputQuant;
        int userInput = inputQuant; // save this value to use it at the end of main()

        collectPrimeNumbers(inputQuant, true);

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

bool collectPrimeNumbers(int primeQuant, bool printList)
{
    const long int closeEnoughToInfinity = 9999999999999;

    for (int num = 2; num <= closeEnoughToInfinity; num++) // num tests every number from 0 to the prettyMuchToInfinity constant var——until the amount of listed prime numbers matches the value of inputQuant
    {
        isPrime(num);
        if (checkIfPrime == true)
        {
            if (printList == true)
            {
                cout << num << endl;
            }
            primeQuant--; // tracks how many prime numbers get listed by deducting until it reaches 0
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
    for (int i = 2; i <= testNum / 2; ++i)
    {
        if (testNum % i == 0)
        {
            checkIfPrime = false;
            break;
        }
    }

    return checkIfPrime;
}

bool testDriver()
{
    bool passTest = true;

    // tests every prime number up until 6661 (the 859th prime number, when you count 2 as the 1st)
    assert(collectPrimeNumbers(859, false) == passTest);

    /* testBoi ensures that testDriver() was executed to the end with no bugs.
       Pretty unnecessary, because the assert() stuff above will end the program and return an error if any of the assertions fail.
       But testBoi adds extra, extremely-solid QA to the program, so sue me. */
    testBoi = true;

    return testBoi;
}

void bugMessage(string message)
{
    cout << "Bug Report: " << message << endl
         << "If you are a user: contact Von, message him and paste this bug report in the message so he can fix this." << endl
         << "Here's a failed assert() to direct Von to the line of code for this bug:" << endl
         << "(this will be the line of code BELOW the bug)" << endl;
}