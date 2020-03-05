// author: Von Reid

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int turnsTaken, curPlayer, winPlayer;
char userCell, userChar, a = 'a', b = 'b', c = 'c', d = 'd', e = 'e', f = 'f', g = 'g', h = 'h', i = 'i';
const int MAX_TURNS = 9;
bool threeInARow;
// displays the tic-tac-toe board depending on the letter(s) entered
void displayBoard();

// determines who the winner is based which cells have been entered
bool hasWinner(bool);

// gathers the user inputs to select cell(s) on the board
char getInput(char, char, char, char, char, char, char, char, char, char);

int main()
{
    for (turnsTaken = 0; turnsTaken < MAX_TURNS; turnsTaken++)
    {
        curPlayer = (turnsTaken % 2) + 1;
        cout << endl;
        cout << "Current Board:" << endl;
        displayBoard();
        getInput(curPlayer, a, b, c, d, e, f, g, h, i);
        hasWinner(threeInARow);
        if (threeInARow == true)
        {
            break;
        }
    }
    displayBoard();
    if (threeInARow == true)
    {
        cout << "Player " << winPlayer << " won!" << endl;
    }
    else
    {
        cout << "Looks like a draw. Oof. Better start over bro." << endl;
    }
}

void displayBoard()
{
    cout << endl
         << " " << a << " | " << b << " | " << c << endl
         << "---+---+---" << endl
         << " " << d << " | " << e << " | " << f << endl
         << "---+---+---" << endl
         << " " << g << " | " << h << " | " << i << endl
         << endl;
}

bool hasWinner(bool)
{
    bool threeX = ((a == 'X' && d == 'X' && g == 'X') || (b == 'X' && e == 'X' && h == 'X') || (c == 'X' && f == 'X' && i == 'X') || (a == 'X' && b == 'X' && c == 'X') || (d == 'X' && e == 'X' && f == 'X') || (g == 'X' && h == 'X' && i == 'X') || (a == 'X' && e == 'X' && i == 'X') || (c == 'X' && e == 'X' && g == 'X'));
    bool threeO = ((a == 'O' && d == 'O' && g == 'O') || (b == 'O' && e == 'O' && h == 'O') || (c == 'O' && f == 'O' && i == 'O') || (a == 'O' && b == 'O' && c == 'O') || (d == 'O' && e == 'O' && f == 'O') || (g == 'O' && h == 'O' && i == 'O') || (a == 'O' && e == 'O' && i == 'O') || (c == 'O' && e == 'O' && g == 'O'));
    //if ((a && d && g) == userChar || (b && e && h) == userChar || (c && f && i) == userChar || (a && b && c) == userChar || (d && e && f) == userChar || (g && h && i) == userChar || (a && e && i) == userChar || (c && e && g) == userChar)
    if (threeX == true)
    {
        threeInARow = true;
        winPlayer = 1;
    }
    else if (threeO == true)
    {
        threeInARow = true;
        winPlayer = 2;
    }
    else
    {
        threeInARow = false;
    }
    return threeInARow;
}

char getInput(char, char, char, char, char, char, char, char, char, char)
{
    cout << "Player " << curPlayer << ", which cell would you like to enter?" << endl;
    cin >> userCell;
    switch (curPlayer)
    {
    case 1:
        userChar = 'X';
        break;
    case 2:
        userChar = 'O';
        break;
    }
    switch (userCell)
    {
    case 'a':
        a = userChar;
        break;
    case 'b':
        b = userChar;
        break;
    case 'c':
        c = userChar;
        break;
    case 'd':
        d = userChar;
        break;
    case 'e':
        e = userChar;
        break;
    case 'f':
        f = userChar;
        break;
    case 'g':
        g = userChar;
        break;
    case 'h':
        h = userChar;
        break;
    case 'i':
        i = userChar;
        break;
    }
    //return userCell;
}