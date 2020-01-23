// author: Von Reid, cs-1405 lab
// this program will calculate the average of 5 test scores.
#include <iostream>
using namespace std;

float firstScore, secondScore, thirdScore, fourthScore, fifthScore;

int main() {
    // user greeting
    cout << "Give me 5 test scores and I will calculate the average of them.\n\n";
    cout << "1st score:\n";
    cin >> firstScore;
    cout << "2nd score:\n";
    cin >> secondScore;
    cout << "3rd score:\n";
    cin >> thirdScore;
    cout << "4th score:\n";
    cin >> fourthScore;
    cout << "5th score:\n";
    cin >> fifthScore;
    // divides the total of the scores by 5, because it's the average (mean) of the total
    float averageScore = (firstScore + secondScore + thirdScore + fourthScore + fifthScore) / 5;
    cout << "\nThe average score of the 5 scores you gave me is " << averageScore << ".\n";
}