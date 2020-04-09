// author: Von Reid
// this is a game of sticks, where 2 players select 1-3 of the sticks and the player who picks the last one loses.
#include <iostream>

int main()
{
    int sticksTaken, numSticksLeft, turnsTaken = 0, currentPlayerInt;
    std::cout << "Welcome!" << std::endl << "This is a game of sticks, where 2 players select 1-3 of the sticks and the player who picks the last one loses." << std::endl;
    std::cout << "How many sticks are you starting with?\n";
    std::cin >> numSticksLeft;

    // let's give Player 1 and Player 2 names (this is extra work)
    std::string player1, player2, currentPlayerStr;
    std::cout << "\nPlayer 1, please enter your name:\n";
    std::cin >> player1;
    std::cout << "Player 2, please enter your name:\n";
    std::cin >> player2;

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

        std::cout << std::endl
             << currentPlayerStr << ", how many sticks would you like to take?\n";
        std::cout << "(please only take 1, 2, or 3)\n";
        std::cin >> sticksTaken;

        // users can only enter 1-3 sticks, so 4 or higher and 0 are all invalid values to input
        while (sticksTaken > 3 || sticksTaken < 1)
        {
            std::cout << "\n***REEEEEE YOU STUPID IDIOT!!! YOU ENTERED IN " << sticksTaken << " STICKS!***\n>>>>>You must only enter 1, 2, or 3 sticks.<<<<<\n***If you violate this rule again, you will be hunted down by Jeff Bezos and he will sell you on Amazon.***\n\n"
                 << currentPlayerStr << ", how many sticks would you like to take?\n";
            std::cin >> sticksTaken;
        }
        numSticksLeft = numSticksLeft - sticksTaken;

        // as long as there are still sticks left, the user will still be prompted to take some
        if (numSticksLeft > 0)
        {
            std::cout << "\n>>>Sticks left: " << numSticksLeft << std::endl;
        }
        
        // increment the number of turns taken so currentPlayerInt can have a correct value
        turnsTaken++;
    }

    // the last person to take sticks is the loser, so the winner's Player number is the opposite of currentPlayerInt
    int winnerInt = currentPlayerInt % 2 + 1;
    
    // now we gotta convert winnerInt into a string so it displays the player's name instead of the number
    std::string winnerStr;
    if (winnerInt == 1)
    {
        winnerStr = player1;
    }
    else if (winnerInt == 2)
    {
        winnerStr = player2;
    }
    
    std::cout << "\n>>>>>>>>>>>>\n"
         << winnerStr << " won!\n<<<<<<<<<<<<\n\n";

    return 0;
}