// Von Reid CS-1400, Chapter 2 Challenge 3 (HWK #5)
// Write a program that will compute the total sales tax on a $95 purchase. Assume the state sales tax is 4 percent, and the county sales tax is 2 percent.
#include <iostream>
using namespace std;

int subTotal = 95;
float stateTaxPer = 0.04;
float countyTaxPer = 0.02;

int main() {
    float stateTaxPrice = subTotal * stateTaxPer;
    float countyTaxPrice = subTotal * countyTaxPer;
    float total = subTotal + stateTaxPrice + countyTaxPrice;
    cout << "The total price of your purchase is " << total << endl;
}