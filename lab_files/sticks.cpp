// author: Von Reid, Garrett Record
// does a thing
#include <iostream>
// I don't care about the std:: stuff--this is way easier
using namespace std;

int main()
{
    int sticksTaken, numSticksLeft = 20, turnsTaken = 0, currentPlayer;

    while (numSticksLeft > 0)
    {
        /*
        if turnsTaken is odd, currentPlayer is an even number
        if turnsTaken is even, currentPlayer is an odd number
        i.e. if turnsTaken == 3, currentPlayer == 2
        */
        currentPlayer = (turnsTaken % 2) + 1;
        cout << "Player " << currentPlayer << ", how many sticks would you like to take?\n";
        cin >> sticksTaken;
        numSticksLeft = numSticksLeft - sticksTaken;

        if (numSticksLeft > 0)
        {
            cout << "Sticks left: " << numSticksLeft << endl;
        }
        // increment the number of turns taken so currentPlayer can have a correct value
        turnsTaken++;
    }

    // the last person to take sticks is the loser, so the winner's Player number is the opposite of currentPlayer
    int winner = currentPlayer % 2 + 1;
    cout << "Player " << winner << " won!\n";

    return 0;
}