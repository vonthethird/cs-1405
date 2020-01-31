// author: Von Reid
// does a thing
#include <iostream>
// I don't care about the std:: stuff--this is way easier
using namespace std;

int main()
{
    int sticksTaken, numSticksLeft, turnsTaken = 0, currentPlayer;
    cout << "How many sticks are you starting with?\n";
    cin >> numSticksLeft;

    while (numSticksLeft > 0)
    {
        /*
        if turnsTaken is odd, currentPlayer is an even number
        if turnsTaken is even, currentPlayer is an odd number
        i.e. if turnsTaken == 3, currentPlayer == 2
        */
        currentPlayer = (turnsTaken % 2) + 1;
        cout << "Player " << currentPlayer << ", how many sticks would you like to take?\n";
        cout << "(please only take 1, 2, or 3)\n";
        cin >> sticksTaken;
        // I had to wrap the if statement inside of the while because it wouldn't continuously loop through the if statement if you kept entering a number > 3
        while (sticksTaken > 3)
        {
            if (sticksTaken > 3)
            {
                cout << "\n***REEEEEE YOU STUPID IDIOT!!! YOU ENTERED IN " << sticksTaken << " STICKS!***\n>>>>>You must only enter 1, 2, or 3 sticks.<<<<<\n***If you violate this rule again, you will be hunted down by Jeff Bezos and he will sell you on Amazon.***\n\nPlayer " << currentPlayer << ", how many sticks would you like to take?\n";
                cin >> sticksTaken;
            }
        }
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