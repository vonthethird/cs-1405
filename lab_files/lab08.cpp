// author: Von Reid

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

char userCell, userChar, a = 'a', b = 'b', c = 'c', d = 'd', e = 'e', f = 'f', g = 'g', h = 'h', i = 'i';
char curPlayer = turn % 2 == 0 ? 'X' : 'O';
const int MAX_TURNS = 9;

// displays the tic-tac-toe board depending on the letter(s) entered
void displayBoard();

// determines who the winner is based which cells have been entered
bool hasWinner(char, char, char, char, char, char, char, char, char);

// gathers the user inputs to select cell(s) on the board
char getInput(char, char, char, char, char, char, char, char, char, char);

int main()
{
    for (int turn = 0; turn < MAX_TURNS; turn++)
    {
        cout << endl;
        cout << "Current Board:" << endl;
        displayBoard();
        getInput(curPlayer, a, b, c, d, e, f, g, h, i);
    }
}

void displayBoard()
{
    cout << " " << a << " | " << b << " | " << c << endl
         << "---+---+---"
         << " " << d << " | " << e << " | " << f << endl
         << "---+---+---"
         << " " << g << " | " << h << " | " << i << endl
         << endl;
}

bool hasWinner(char, char, char, char, char, char, char, char, char)
{
    bool threeInARow;
    if ((a && d && g) == userChar || (b && e && h) == userChar || (c && f && i) == userChar || (a && b && c) == userChar || (d && e && f) == userChar || (g && h && i) == userChar || (a && e && i) == userChar || (c && e && g) == userChar)
    {
        threeInARow = true;
    }
    else
    {
        threeInARow = false;
    }
}

char getInput(char, char, char, char, char, char, char, char, char, char)
{
    cout << "Player " << curPlayer << ", which cell would you like to enter?" << endl;
    cin >> userCell;
    if (curPlayer == 1)
    {
        userChar = 'X';
    }
    else if (curPlayer == 2)
    {
        userChar = 'O';
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