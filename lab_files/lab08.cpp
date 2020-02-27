// author: Von Reid

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

char userCell, userChar, a = 'a', b = 'b', c = 'c', d = 'd', e = 'e', f = 'f', g = 'g', h = 'h', i = 'i';
int curPlayer = 0;

// displays the tic-tac-toe board depending on the letter(s) entered
void displayBoard(char, char, char, char, char, char, char, char, char);

// determines who the winner is based which cells have been entered
bool hasWinner(char, char, char, char, char, char, char, char, char);

// gathers the user inputs to select cell(s) on the board
char getInput(int, char, char, char, char, char, char, char, char, char);

int main()
{
    //
}

void displayBoard(char, char, char, char, char, char, char, char, char)
{
    cout << "  a | b | c"
         << " ---+---+---"
         << "  d | e | f"
         << " ---+---+--"
         << "  g | h | i" << endl;
}

bool hasWinner(char, char, char, char, char, char, char, char, char)
{
    bool threeInARow;
    if ((a && d && g) == 'X' || (b && e && h) == 'X' || (c && f && i) == 'X' || (a && b && c) == 'X' || (d && e && f) == 'X' || (g && h && i) == 'X' || (a && e && i) == 'X' || (c && e && g) == 'X')
    {
        threeInARow = true;
    }
    else
    {
        threeInARow = false;
    }
}

char getInput(int, char, char, char, char, char, char, char, char, char)
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