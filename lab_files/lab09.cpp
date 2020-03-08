// author: Von Reid

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool checkIfPrime;

bool isPrime(int);

int main()
{
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