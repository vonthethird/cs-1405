// author: Von Reid

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int turnsTaken, curPlayer;
char userCell, userChar, winChar, a, b, c, d, e, f, g, h, i;
bool threeInARow;
const int MAX_TURNS = 9;     // There are only 9 cells, so there can only be a max of 9 turns
const char X = 'X', O = 'O'; // I'd rather use const variables instead of 'X' and 'O' chars every time X and O are used in this program

// displays the tic-tac-toe board depending on the letter(s) entered
void displayBoard();

// determines who the winner is based which cells have been entered
bool hasWinner(bool);

// gathers the user inputs to select cell(s) on the board
char getInput(char, char, char, char, char, char, char, char, char, char);

// sub-level evaluations for getInput, just to separate it into smaller functions ;)
void updateCell();     // replaces cell letters with Xs and Os
void assignUserChar(); // determines whether the cell will have an X or an O based off of curPlayer number

// tests to prevent user error
char checkFilledCell(char); // prevents users from selecting a cell that has already been filled with X or O
char checkSwitch();

int main()
{
    a = 'a', b = 'b', c = 'c', d = 'd', e = 'e', f = 'f', g = 'g', h = 'h', i = 'i';
    cout << endl;
    cout << "----------------------------------" << endl;
    cout << "- Welcome to tic-tac-toe! -" << endl;
    cout << "----------------------------------" << endl
         << endl;
    cout << "Players will take turns choosing an unoccupied cell." << endl;
    cout << "The first player to get 3 in a row (or column or diagonal) wins!" << endl;

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
            break; // kills the loop, because you can end the game before turnsTaken == MAX_TURNS by filling 3 cells in a row
        }
    }

    displayBoard(); // final board display

    if (threeInARow == true)
    {
        cout << "Player " << winChar << " won!" << endl;
    }
    // only initiates if the users reach a stalemate
    else
    {
        cout << "Looks like a draw. Oof. Better start over bro." << endl;
    }

    return 0;
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
    // I know. These 2 bool variables are gross. But hey, it works lololol
    bool threeX = ((a == X && d == X && g == X) || (b == X && e == X && h == X) || (c == X && f == X && i == X) || (a == X && b == X && c == X) || (d == X && e == X && f == X) || (g == X && h == X && i == X) || (a == X && e == X && i == X) || (c == X && e == X && g == X));
    bool threeO = ((a == O && d == O && g == O) || (b == O && e == O && h == O) || (c == O && f == O && i == O) || (a == O && b == O && c == O) || (d == O && e == O && f == O) || (g == O && h == O && i == O) || (a == O && e == O && i == O) || (c == O && e == O && g == O));

    // determines who the winner is after 3 cells in a row get filled
    if (threeX == true)
    {
        threeInARow = true;
        winChar = X;
    }
    else if (threeO == true)
    {
        threeInARow = true;
        winChar = O;
    }
    else
    {
        threeInARow = false;
    }
    return threeInARow;
}

char getInput(char, char, char, char, char, char, char, char, char, char)
{
    assignUserChar();
    cout << "Player " << userChar << ", which cell would you like to enter?" << endl;
    cin >> userCell;
    updateCell();
}

void updateCell()
{
    checkSwitch();

    // because of how repetitive this switch is, my tingling spidey-senses tell me that there is most likely a better way to refactor this somehow, right?!
    // unfortunately, I don't know if I'm fluent enough in C++ yet to figure it out yet. After all, I'm only halfway thru the semester yo. *shrug* I have to much hwk to do that I don't have time to dig into the possibilities.
    // but I yeeted this out of getInput() into a separate function to make things look cleaner *dab*
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
}

void assignUserChar()
{
    switch (curPlayer)
    {
    case 1:
        userChar = X;
        break;
    case 2:
        userChar = O;
        break;
    }
}

char checkFilledCell(char cellChar)
{
    cout << endl
         << "Oof, that cell already has a " << cellChar << " in it." << endl
         << "Please select a different cell." << endl
         << "It's really not that complicated u dumbhead." << endl;
    cin >> userCell;

    return userCell;
}

char checkSwitch()
{
    switch (userCell)
    {
    case 'a':
        while (a == X || a == O)
        {
            checkFilledCell(a);
            if (userCell != 'a')
            {
                break;
            }
        }
        break;
    case 'b':
        while (b == X || b == O)
        {
            checkFilledCell(b);
            if (userCell != 'b')
            {
                break;
            }
        }
        break;
    case 'c':
        while (c == X || c == O)
        {
            checkFilledCell(c);
            if (userCell != 'c')
            {
                break;
            }
        }
        break;
    case 'd':
        while (d == X || d == O)
        {
            checkFilledCell(d);
            if (userCell != 'd')
            {
                break;
            }
        }
        break;
    case 'e':
        while (e == X || e == O)
        {
            checkFilledCell(e);
            if (userCell != 'e')
            {
                break;
            }
        }
        break;
    case 'f':
        while (f == X || f == O)
        {
            checkFilledCell(f);
            if (userCell != 'f')
            {
                break;
            }
        }
        break;
    case 'g':
        while (g == X || g == O)
        {
            checkFilledCell(g);
            if (userCell != 'g')
            {
                break;
            }
        }
        break;
    case 'h':
        while (h == X || h == O)
        {
            checkFilledCell(h);
            if (userCell != 'h')
            {
                break;
            }
        }
        break;
    case 'i':
        while (i == X || i == O)
        {
            checkFilledCell(i);
            if (userCell != 'i')
            {
                break;
            }
        }
        break;
    }

    return userCell;
}