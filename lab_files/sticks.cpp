// author: Von Reid, Garrett Record
// does a thing
#include <iostream>
// I don't care about the std:: stuff--this is way easier
using namespace std;

int main () {
    int sticksTaken, numSticksLeft, turnsTaken = 0, currentPlayer;
    if (turnsTaken )
    /*
    if turnsTaken is odd, currentPlayer is an even number
    if turnsTaken is even, currentPlayer is an odd number
    i.e. if turnsTaken == 3, currentPlayer == 2
    */
    currentPlayer = (turnsTaken % 2) + 1;
    while (numSticksLeft > 0) {
        numSticksLeft = 20;
        cout << currentPlayer << ", how many sticks would you like to take?\n";
        cin >> sticksTaken;
        numSticksLeft = numSticksLeft - sticksTaken;
        cout << "Sticks left: " << numSticksLeft << endl;
    }
    return 0;
}