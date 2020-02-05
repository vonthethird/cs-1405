/* you may wonder why this file exists in ~/extra_projects AND in ~/lab_files
this is because I added functionality for players to enter in names, which was a lot of extra work. check it out yo

author: Von Reid
this is a game of sticks, where players select 1-3 and the player who picks the last one loses. */
#include <iostream>
using namespace std;

int main()
{
    int sticksTaken, numSticksLeft, turnsTaken = 0, currentPlayerInt;
    cout << "How many sticks are you starting with?\n";
    cin >> numSticksLeft;

    // Let's give Player 1 and Player 2 names (this is extra work)
    string player1, player2, currentPlayerStr;
    cout << "\nPlayer 1, please enter your name:\n";
    cin >> player1;
    cout << "Player 2, please enter your name:\n";
    cin >> player2;

    while (numSticksLeft > 0)
    {
        /*
        if turnsTaken is odd, currentPlayerInt is an even number
        if turnsTaken is even, currentPlayerInt is an odd number
        i.e. if turnsTaken == 3, currentPlayerInt == 2
        */
        currentPlayerInt = (turnsTaken % 2) + 1;
        if (currentPlayerInt == 1)
        {
            currentPlayerStr = player1;
        }
        else if (currentPlayerInt == 2)
        {
            currentPlayerStr = player2;
        }

        cout << endl
             << currentPlayerStr << ", how many sticks would you like to take?\n";
        cout << "(please only take 1, 2, or 3)\n";
        cin >> sticksTaken;
        // prevents user(s) from entering more than 3 sticks
        while (sticksTaken > 3 || sticksTaken < 1)
        {
            cout << "\n***REEEEEE YOU STUPID IDIOT!!! YOU ENTERED IN " << sticksTaken << " STICKS!***\n>>>>>You must only enter 1, 2, or 3 sticks.<<<<<\n***If you violate this rule again, you will be hunted down by Jeff Bezos and he will sell you on Amazon.***\n\n"
                 << currentPlayerStr << ", how many sticks would you like to take?\n";
            cin >> sticksTaken;
        }
        numSticksLeft = numSticksLeft - sticksTaken;

        if (numSticksLeft > 0)
        {
            cout << "\n>>>Sticks left: " << numSticksLeft << endl;
        }
        // increment the number of turns taken so currentPlayerInt can have a correct value
        turnsTaken++;
    }

    // the last person to take sticks is the loser, so the winner's Player number is the opposite of currentPlayerInt
    int winnerInt = currentPlayerInt % 2 + 1;
    // now we gotta convert winnerInt into a string so it displays the player's name instead of the number
    string winnerStr;
    if (winnerInt == 1)
    {
        winnerStr = player1;
    }
    else if (winnerInt == 2)
    {
        winnerStr = player2;
    }
    cout << "\n>>>>>>>>>>>>\n"
         << winnerStr << " won!\n<<<<<<<<<<<<\n\n";

    return 0;
}