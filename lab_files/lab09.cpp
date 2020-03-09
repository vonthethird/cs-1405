// author: Von Reid

#include <iostream>
#include <cassert>

using std::cin;
using std::cout;
using std::endl;

bool checkIfPrime;

bool isPrime(int); // the number you pass into isPrime() is how many prime numbers you want, and isPrime() will run through every number starting with 2 until it gets the amount of prime numbers you need
void testDriver(); // runs a bunch of tests on isPrime() to ensure that there won't be any bugs or errors (QA)

int main()
{
    testDriver(); // I need to rewrite how isPrime() works, because it's hard to test with it being a bool function

    int primeQuant = 0, inputQuant; // "Quant" meaning "Quantity," for the quantity of prime numbers
    cout << "Hello! Please enter how many prime numbers you would like to print out (starting from 1)." << endl;
    cin >> inputQuant;

    for (int num = 0; num <= 9999999999999; num++) // num tests every number from 0 to the big 999... number, until the amount of listed prime numbers matches the value of inputQuant
    {
        isPrime(num);
        if (checkIfPrime == true)
        {
            cout << num << endl;
            primeQuant++; // tracks how many prime numbers get listed
        }
        if (primeQuant == inputQuant)
        {
            break;
        }
    }

    cout << endl
         << "Those are all of the first " << inputQuant << " prime numbers." << endl;

    return 0;
}

bool isPrime(int testNum)
{
    if (testNum == 2 || testNum == 3) // I can't effing figure out why the for() won't accept 2 or 3, so I put this here for now to get around it
    {
        checkIfPrime = true;
        return checkIfPrime;
    }
    for (int i = 2; i <= testNum / 2; ++i)
    {
        if (testNum % i == 0)
        {
            checkIfPrime = false;
            break;
        }
        else // this else only exists because checkIfPrime doesn't have an initialized `true` value
        {
            checkIfPrime = true;
        }
    }

    return checkIfPrime;
}

void testDriver()
{
    assert(isPrime(1));
    assert(isPrime(5));
    assert(isPrime(10));
    assert(isPrime(20));
    assert(isPrime(50));
    assert(isPrime(100));
}