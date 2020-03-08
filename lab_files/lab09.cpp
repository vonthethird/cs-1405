// author: Von Reid

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool checkIfPrime;

bool isPrime(int);

int main()
{
    int inputQuant; // "Quant" meaning "Quantity," for the quantity of prime numbers
    cout << "Hello! Please enter how many prime numbers you would like to print out (starting from 1)." << endl;
    cin >> inputQuant;
    int primeList[inputQuant];

    for (int num = 1; num <= inputQuant; num++)
    {
        isPrime(num);
        if (checkIfPrime == true)
        {
            cout << num << endl;
        }
    }
    cout << endl
         << "Those are all of the first " << inputQuant << " prime numbers." << endl;

    return 0;
}

// primeQuant is the same variable as inputQuant, just named differently for the different use in the functions.
// i.e. main() uses it as user input, isPrime() uses it as the quantity of prime numbers to know how many of them to print out.
bool isPrime(int testNum)
{
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