// author: Von Reid

/*

1. displayBoard()
    a. display the tic-tac-toe board depending on the character(s) entered.
    b. */ 
    void displayBoard(char, char, char, char, char, char, char, char, char); /*
    c. it will use getInput() to determine which letters have been entered

2. hasWinner()
    a. it will check for 3-in-a-row to determine if the game has been won yet
    b. */
    bool hasWinner(char, char, char, char, char, char, char, char, char); /*
    c. if getInput() has any of the 3-letter combinations entered, then it will return true

3. getInput()
    a. gathers the user inputs to select cell(s) on the board
    b. */
    char getInput(int, char, char, char, char, char, char, char, char, char); /*
    c. make the user enter a letter, then pass it on to other functions.

*/