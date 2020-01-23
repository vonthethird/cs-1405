// author: Von Reid, Garrett Record, and Ronald Hunt -- cs-1405 lab
// this program will calculate the miles per gallon that a car gets.
#include <iostream>
using namespace std;

int gallons, miles;

int main() {
    // user greeting
    cout << "I will calculate your car's mileage based off of the number gallons and miles traveled that you give me.\n";
    cout << "Enter the number of gallons your car used on your last trip:\n";
    cin >> gallons;
    cout << "Enter the number of miles your car drove on your last trip:\n";
    cin >> miles;
    // miles per gallon just divides the gallons from the miles, which is literally the definition of it
    int MpG = miles / gallons;
    cout << "Your car gets " << MpG << " miles per gallon\n";
}