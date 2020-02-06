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
int roomNumber, sleepCounter = 0, travelCounter = 0;

int changeRoom()
{
    cout << "\nYou are now in room " << roomNumber << ".\n\n";
    return 0;
}

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

int roomOne()
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
    if (promptAnswer == 'a')
    {
        cout << "\nYou moved South.\n";
        roomNumber = 2, travelCounter++;
        changeRoom();
    }
    else if (promptAnswer == 'b')
    {
        cout << "\nYou moved East.\n";
        roomNumber = 4, travelCounter++;
        changeRoom();
    }
    else if (promptAnswer == 'c')
    {
        optionC();

        roomNumber = 1, sleepCounter++;
    }
    return 0;
}

int roomTwo()
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
    if (promptAnswer == 'a')
    {
        cout << "\nYou moved North.\n";
        roomNumber = 1, travelCounter++;
        changeRoom();
    }
    else if (promptAnswer == 'b')
    {
        cout << "\nYou tried moving East, but there turns out to be no door.\n";
        cout << "What will you do now?\n";
        roomNumber = 2;
    }
    else if (promptAnswer == 'c')
    {
        optionC();

        roomNumber = 2, sleepCounter++;
    }
    return 0;
}

int roomThree()
{
    cout << "There are 3 choices you can make.\nEnter 1 letter (a, b, or c) to choose:\n";
    cout << "a) Move North\n"
         << "b) Move West\n"
         << "c) Go to sleep\n";
    cin >> promptAnswer;
    while ((promptAnswer != 'a') && (promptAnswer != 'b') && (promptAnswer != 'c'))
    {
        cout << "\nYou dumb, stupid, incompetent idiot.\nThat's not a valid option. Try again.\n";
        cin >> promptAnswer;
    }
    if (promptAnswer == 'a')
    {
        cout << "\nYou moved North.\n";
        roomNumber = 4, travelCounter++;
        changeRoom();
    }
    else if (promptAnswer == 'b')
    {
        cout << "\nYou tried moving West, but there turns out to be no door.\n";
        cout << "What will you do now?\n";
        roomNumber = 3;
    }
    else if (promptAnswer == 'c')
    {
        optionC();

        roomNumber = 3, sleepCounter++;
    }
    return 0;
}

int roomFour()
{
    cout << "There are 3 choices you can make.\nEnter 1 letter (a, b, or c) to choose:\n";
    cout << "a) Move South\n"
         << "b) Move West\n"
         << "c) Go to sleep\n";
    cin >> promptAnswer;
    while ((promptAnswer != 'a') && (promptAnswer != 'b') && (promptAnswer != 'c'))
    {
        cout << "\nYou dumb, stupid, incompetent idiot.\nThat's not a valid option. Try again.\n";
        cin >> promptAnswer;
    }
    if (promptAnswer == 'a')
    {
        cout << "\nYou moved South.\n";
        roomNumber = 3, travelCounter++;
        changeRoom();
    }
    else if (promptAnswer == 'b')
    {
        cout << "\nYou moved West.\n";
        roomNumber = 1, travelCounter++;
        changeRoom();
    }
    else if (promptAnswer == 'c')
    {
        optionC();

        roomNumber = 4, sleepCounter++;
    }
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
    return 0;
}

int main()
{
    cout << "Hello, welcome to the game!\nYou may or may not survive this, so be careful.\n\n";
    pickRoom();
    cin.clear();
    while (roomNumber < 5)
    {
        switch (roomNumber)
        {
        case 1:
            roomOne();
            break;
        case 2:
            roomTwo();
            break;
        case 3:
            roomThree();
            break;
        case 4:
            roomFour();
            break;
        }
        if (sleepCounter > 6 && travelCounter > 5)
        {
            roomNumber = 5;
        }
    }
    cout << "\n\n***Suddenly, you woke up and realized it was all a dream.***\nThere are no rooms, and there are no doors.\nThis was simply a figment of your imagination.\nBut hey, at least you finally escaped! (for now.....)\n\n";
    cout << "You slept " << sleepCounter << " times, and you went to a different room " << travelCounter << " times.\nYou were quite determined to escape. I'll have to find better ways to trick you next time...\n\n";
    return 0;
}