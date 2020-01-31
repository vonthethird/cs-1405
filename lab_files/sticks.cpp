// author: Von Reid, Garrett Record
// does a thing
#include <iostream>
// I don't care about the std:: stuff--this is way easier
using namespace std;

int main () {
    int sticksTaken, numSticksLeft = 20, turnsTaken = 0, currentPlayer;

    while (numSticksLeft > 0) {
    /*
    if turnsTaken is odd, currentPlayer is an even number
    if turnsTaken is even, currentPlayer is an odd number
    i.e. if turnsTaken == 3, currentPlayer == 2
    */
        currentPlayer = (turnsTaken % 2) + 1;
        cout << "Player" << currentPlayer << ", how many sticks would you like to take?\n";
        cin >> sticksTaken;
        numSticksLeft = numSticksLeft - sticksTaken;
        cout << "Sticks left: " << numSticksLeft << endl;
        turnsTaken++;
        cout << "turn: " << turnsTaken << endl;
        }
    return 0;
}