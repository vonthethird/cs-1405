// author: Von Reid

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

char a = 'a', b = 'b', c = 'c', d = 'd', e = 'e', f = 'f', g = 'g', h = 'h', i = 'i';

// displays the tic-tac-toe board depending on the letter(s) entered
string displayBoard(char);

// determines who the winner is
bool hasWinner();

int main()
{
    //
}

string displayBoard()
{
    cout << "  a | b | c"
         << " ---+---+---"
         << "  d | e | f"
         << " ---+---+--"
         << "  g | h | i" << endl;
}

bool hasWinner()
{
    bool threeInARow;
    if ((a && d && g) || (b && e && h) || (c && f && i) || (a && b && c) || (d && e && f) || (g && h && i) || (a && e && i) || (c && e && g))
    {
        threeInARow = true;
    }
    else
    {
        threeInARow = false;
    }
}