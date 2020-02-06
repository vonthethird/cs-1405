/*
author: Von Reid
This is a game that involves moving directions in a place with multiple rooms.
My in-class group got the Southwest room, which is why you can only move North and East.
*/
#include <iostream>
#include <chrono>
#include <thread>
#include <limits>

using std::cin;
using std::cout;

/*int pressEnter()
{
    cout << "Press the ENTER key";
    if (cin.std::istream::get() == '\n')
        cout << "Good job.\n";
    else
        cout << "I meant ONLY the ENTER key... Oh well.\n";
    return 0;
}*/

char promptAnswer;
int roomNumber;

int waitBoi()
{
    std::chrono::seconds dura(1);
    std::this_thread::sleep_for(dura);
}

int optionC()
{
    cin.clear();
    float hoursSlept = 0;
    cout << "\nHow many hours do you want to sleep?\n";
    cin >> hoursSlept;
    /* tried to prevent user from entering anything that's not a number, can't figure it out. I'll come back to it later.
    while (cin.fail())
    {
        cin.clear();
        cout << "Dude. That's not a number. I expected better than that from you.";
        cin >> hoursSlept;
    }
    */
    waitBoi();
    cout << ".\n";
    waitBoi();
    cout << "...\n";
    waitBoi();
    cout << ".....\n";
    waitBoi();
    cout << ".......\n";
    waitBoi();
    if (hoursSlept == 1)
    {
        cout << "You slept for " << hoursSlept << " hour.\nGood job.\n\n";
    }
    else
    {
        cout << "You slept for " << hoursSlept << " hours.\nGood job.\n\n";
    }
    return 0;
}

int roomOneQuestions()
{
    cout << "There are 3 choices you can make.\nEnter 1 letter (a, b, or c) to choose:\n";
    cout << "a) Move South\n"
         << "b) Move East\n"
         << "c) Go to sleep\n";
    cin >> promptAnswer;
    while ((promptAnswer != 'a') && (promptAnswer != 'b') && (promptAnswer != 'c'))
    {
        cout << "\nYou dumb, stupid, incompetent idiot.\nThat's not a valid option. Try again.\n";
        cin >> promptAnswer;
    }
    /*if (promptAnswer == 'a')
    {
        cout << "\nYou moved South.\n";
        cout << "\nYou are now in room 2.\n\n";
        //roomTwoQuestions();
    }
    else if (promptAnswer == 'b')
    {
        cout << "\nYou moved East.\n";
    }
    else if (promptAnswer == 'c')
    {
        optionC();
        roomOneQuestions();
    }*/
    return 0;
}

int roomTwoQuestions()
{
    cout << "There are 3 choices you can make.\nEnter 1 letter (a, b, or c) to choose:\n";
    cout << "a) Move North\n"
         << "b) Move East\n"
         << "c) Go to sleep\n";
    cin >> promptAnswer;
    while ((promptAnswer != 'a') && (promptAnswer != 'b') && (promptAnswer != 'c'))
    {
        cout << "\nYou dumb, stupid, incompetent idiot.\nThat's not a valid option. Try again.\n";
        cin >> promptAnswer;
    }
    /*if (promptAnswer == 'a')
    {
        cout << "\nYou moved North.\n";
    }
    else if (promptAnswer == 'b')
    {
        cout << "\nYou moved East.\n";
    }
    else if (promptAnswer == 'c')
    {
        optionC();
        roomTwoQuestions();
    }*/
    return 0;
}

int pickRoom()
{
    cout << "There are 4 numbered rooms.\nPick a room number to start in. (1, 2, 3, or 4)\n";
    cin >> roomNumber;
    while ((roomNumber != 1) && (roomNumber != 2) && (roomNumber != 3) && (roomNumber != 4))
    {
        cout << "\nYou dumb, stupid, incompetent idiot.\nThat's not a valid option. Try again.\n";
        cin >> roomNumber;
    }
    switch (roomNumber)
    {
    case 1:
        cout << "\nYou are now in room 1.\n\n";
        break;
    case 2:
        cout << "\nYou are now in room 2.\n\n";
        roomTwoQuestions();
        break;
    case 3:
        cout << "\nYou are now in room 3.\n\n";
        break;
    case 4:
        cout << "\nYou are now in room 4.\n\n";
        break;
    }
    return 0;
}

int roomOneChoices()
{
    if (promptAnswer == 'a')
    {
        cout << "\nYou moved South.\n";
        cout << "\nYou are now in room 2.\n\n";
        roomNumber == 2;
        roomTwoQuestions();
    }
    else if (promptAnswer == 'b')
    {
        cout << "\nYou moved East.\n";
    }
    else if (promptAnswer == 'c')
    {
        optionC();
        roomOneQuestions();
    }
}

int main()
{
    cout << "Hello, welcome to the game!\nYou may or may not survive this, so be careful.\n\n";
    pickRoom();
    while (roomNumber < 5)
    {
        while (roomNumber == 1)
        {
            roomOneQuestions();
            roomOneChoices();
        }
    }
    return 0;
}