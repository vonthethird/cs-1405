// author: Von Reid

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int primeList;

int isPrime(const int, int);

int main()
{
    int userInput;
    cout << "Hello! Please enter how many prime numbers you would like to print out (starting from 1)." << endl;
    cin >> userInput;
    // I have to turn userInput into a const because arrays require const variables
    const int inputQuant = userInput; // "Quant" meaning "Quantity," for the quantity of prime numbers
    int primeList[inputQuant];
    isPrime(inputQuant, primeList[inputQuant]);
    for (int index = 0; index < inputQuant; index++)
    {
        cout << primeList << endl;
    }
    cout << endl
         << "Those are all of the first " << inputQuant << " prime numbers." << endl;

    return 0;
}

// primeQuant is the same variable as inputQuant, just named differently for the different use in the functions.
// i.e. main() uses it as user input, isPrime() uses it as the quantity of prime numbers to know how many of them to print out.
int isPrime(const int primeQuant, int primeList[primeQuant])
{
    int num = 1;
    bool checkIfPrime;

    for (num; num < primeQuant; num++)
    {
        for (int i = 2; i <= num / 2; ++i)
        {
            if (num % i == 0)
            {
                checkIfPrime = false;
                break;
            }
            else // this else only exists because checkIfPrime doesn't have an initialized `true` value
            {
                checkIfPrime = true;
            }
        }
        if (checkIfPrime == true)
        {
            num >> primeList;
        }
    }

    return primeList;
}