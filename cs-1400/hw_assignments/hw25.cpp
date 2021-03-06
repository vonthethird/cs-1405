// author: Von Reid
// this is for the H.W. #25 assignment in CS-1400
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    /*
    7. Because anytime the name of an array is used without brackets and a subscript, it is seen as the array’s beginning memory address. The assignment operator will not work because you cannot change the starting memory address of an array.

    11. By using the same subscript value for each array

    24. subscript

    25. assignment

    26. the array’s beginning memory address
    */

    // 43.
    const int NUM_EMPLOYEES = 10; // number of employees

    int idNums[NUM_EMPLOYEES]; // employee identification numbers

    double weeklyPay[NUM_EMPLOYEES]; // weekly gross pay

    cout << "Enter the identification numbers for " << NUM_EMPLOYEES
         << " employees and their hourly pay rates." << endl;
    for (int index = 0; index < NUM_EMPLOYEES; index++)
    {
        cout << "ID number for employee #" << (index + 1) << ": ";
        cin >> idNums[index];
        cout << "Weekly pay rate for employee #" << (index + 1) << ": ";
        cin >> weeklyPay[index];
    }

    // 45
    const int NUM_COUNTRIES = 12;

    string countryNames[NUM_COUNTRIES];

    int countryPopulation[NUM_COUNTRIES];

    cout << "Enter the names and total population for " << NUM_COUNTRIES
         << " countries." << endl;
    for (int index = 0; index < NUM_COUNTRIES; index++)
    {
        cout << "Name for country #" << (index + 1) << ": ";
        cin >> countryNames[index];
        cout << "Total population number for country #" << (index + 1) << ": ";
        cin >> countryPopulation[index];
    }

    cout << "Here is the population for each country:\n";
    for (int index = 0; index < NUM_COUNTRIES; index++)
    {
        cout << countryNames[index];
        cout << " Population: " << countryPopulation[index] << endl;
    }

    /*
    46. The loop is only executed for 23 elements, while there are 25. So the total will be incorrect.

    64. F

    65. T

    66. F
    */

    return 0;
}