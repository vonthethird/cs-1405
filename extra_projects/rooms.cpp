/*
author: Von Reid
This is a game that involves moving directions in a place with multiple rooms.
My in-class group got the Southwest room, which is why you can only move North and East.
*/
#include <iostream>
#include <limits>

#include <vector> // for the vector image in zeldaASCII

#include <chrono> // <chrono> and <thread> are required for the time-pausing stuff in waitBoi()
#include <thread>

using std::cin;
using std::cout;
using std::endl;

char promptAnswer;
int roomNumber, sleepCounter = 0, travelCounter = 0;
void print(const std::vector<std::string> &picture)
{
    std::cout << '\n';
    for (const auto &line : picture)
        std::cout << line << '\n';
    std::cout << '\n';
}
std::vector<std::string> zeldaASCII =
    {
        R"(                                     /@)",
        R"(                     __        __   /\/)",
        R"(                    /==\      /  \_/\/)",
        R"(                  /======\    \/\__ \__)",
        R"(                /==/\  /\==\    /\_|__ \)",
        R"(             /==/    ||    \=\ / / / /_/)",
        R"(           /=/    /\ || /\   \=\/ /)",
        R"(        /===/   /   \||/   \   \===\)",
        R"(      /===/   /_________________ \===\)",
        R"(   /====/   / |                /  \====\)",
        R"( /====/   /   |  _________    /  \   \===\    THE LEGEND OF)",
        R"( /==/   /     | /   /  \ / / /  __________\)",
        R"(|===| /       |/   /____/ / /   \   _____ |\   /      \   _ \      \  \)",
        R"( \==\             /\   / / /     | |  /= \| | |        | | \ \     / _ \)",
        R"( \===\__    \    /  \ / / /   /  | | /===/  | |        | |  \ \   / / \ \)",
        R"(   \==\ \    \\ /____/   /_\ //  | |_____/| | |        | |   | | / /___\ \)",
        R"(   \===\ \   \\\\\\\/   /////// /|  _____ | | |        | |   | | |  ___  |)",
        R"(     \==\/     \\\\/ / //////   \| |/==/ \| | |        | |   | | | /   \ |)",
        R"(     \==\     _ \\/ / /////    _ | |==/     | |        | |  / /  | |   | |)",
        R"(       \==\  / \ / / ///      /|\| |_____/| | |_____/| | |_/ /   | |   | |)",
        R"(       \==\ /   / / /________/ |/_________|/_________|/_____/   /___\ /___\)",
        R"(         \==\  /               | /==/)",
        R"(         \=\  /________________|/=/)",
        R"(           \==\     _____     /==/)",
        R"(          / \===\   \   /   /===/)",
        R"(         / / /\===\  \_/  /===/)",
        R"(        / / /   \====\ /====/)",
        R"(       / / /      \===|===/)",
        R"(       |/_/         \===/)",
        R"(                      =)"};

int pickRoom()
{
    cout << "There are 4 numbered rooms." << endl
         << "Pick a room number to start in. (1, 2, 3, or 4)" << endl;
    cin >> roomNumber;
    while ((roomNumber != 1) && (roomNumber != 2) && (roomNumber != 3) && (roomNumber != 4))
    {
        cout << endl
             << "You dumb, stupid, incompetent idiot." << endl
             << "That's not a valid option. Try again." << endl;
        cin >> roomNumber;
    }
    cout << endl;
    return 0;
}

int changeRoom()
{
    cout << endl
         << "You are now in room " << roomNumber << "." << endl
         << endl;
    return 0;
}

int invalidPromptCheck()
{
    while ((promptAnswer != 'a') && (promptAnswer != 'b') && (promptAnswer != 'c'))
    {
        cout << endl
             << "You dumb, stupid, incompetent idiot." << endl
             << "That's not a valid option. Try again." << endl;
        cin >> promptAnswer;
    }
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
    cout << endl
         << "How many hours do you want to sleep?" << endl;
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
    cout << "." << endl;
    waitBoi();
    cout << "..." << endl;
    waitBoi();
    cout << "....." << endl;
    waitBoi();
    cout << "......." << endl;
    waitBoi();

    // Changes plural "hours" to singular "hour" for the possibility of 1 hour slept
    if (hoursSlept == 1)
    {
        cout << "You slept for " << hoursSlept << " hour." << endl
             << "Good job." << endl
             << endl;
    }
    else
    {
        cout << "You slept for " << hoursSlept << " hours." << endl
             << "Good job." << endl
             << endl;
    }

    return 0;
}

int altPrompts()
{
    std::string optionThree, optionThreeResult;
    if (roomNumber == 2)
    {
        optionThree = "3)Crawl into the deep hole in the ground";
    }
    else if (roomNumber == 3)
    {
        optionThree = "3)Approach the dark figure moving in the corner of the room";
        optionThreeResult = "";
    }
    cout << "What will you do now?" << endl;
    int altPromptAnswer;
    cout << "1)Pick up mysterious glowing mushroom on the wall" << endl
         << "2)Give up" << endl
         << optionThree << endl
         << "4)Go back to the previous choices for this room" << endl;
    cin >> altPromptAnswer;
    switch (altPromptAnswer)
    {
    case 1:
        waitBoi();
        cout << "." << endl;
        waitBoi();
        cout << "..." << endl;
        cout << endl
             << "After a few minutes, all of the colors around you start to flow together." << endl
             << "You see a whole new world of colors. An especially bright red light shines through a portal in the wall." << endl
             << "Will you jump into the portal?" << endl
             << "<y>/<n>" << endl;
        char portalAnswer;
        cin >> portalAnswer;
        cout << endl
             << "It doesn't matter what you chose, because you have no control anymore." << endl
             << "You jump into the portal head-first." << endl;

        break;
    case 2:
        cout << "You never escaped the rooms..." << endl
             << "Oh well..." << endl
             << "Goodnight." << endl;
        break;
    case 3:
        if (roomNumber == 2)
        {
            cout << "You crawl for a little while." << endl;
            waitBoi();
            cout << "." << endl;
            waitBoi();
            cout << "..." << endl;
            waitBoi();
            cout << "....." << endl;
            waitBoi();
            cout << "You appear in a foggy room. You see an old man with a white beard, which hasn't been trimmed in centuries." << endl;
            cout << "The old man looks you in the eyes and yells, 'It's dangerous to go alone! Take this!'" << endl
                 << "He places a beautiful sword in your hands. 'You are the chosen one, the hero of courage! You must save us!'" << endl;
            cout << "You nod, then exit the cave. You're no longer in the random room labyrinth, you're now in Hyrule." << endl
                 << "The people of this world need you, so you're now their savior. Defeat the evil Lord Ganon and restore the Triforce to its former glory." << endl
                 << endl;
            waitBoi();
            cout << "Only you can save us, Link." << endl;
            waitBoi();
            print(zeldaASCII);
            waitBoi();
            char anyLetterToContinue;
            cout << endl
                 << "Please enter any letter to continue." << endl;
            cin >> anyLetterToContinue;
        }
        else if (roomNumber == 3)
        {
            cout << "";
        }
        break;
    case 4:
        break;
    }
}

int roomOne()
{
    cout << "There are 3 choices you can make." << endl
         << "Enter 1 letter (a, b, or c) to choose:" << endl;
    cout << "a) Move South" << endl
         << "b) Move East" << endl
         << "c) Go to sleep" << endl;
    cin >> promptAnswer;
    invalidPromptCheck();
    switch (promptAnswer)
    {
    case 'a':
        cout << endl
             << "You moved South." << endl;
        roomNumber = 2, travelCounter++;
        changeRoom();
        break;
    case 'b':
        cout << endl
             << "You moved East." << endl;
        roomNumber = 4, travelCounter++;
        changeRoom();
        break;
    case 'c':
        optionC();
        roomNumber = 1, sleepCounter++;
        break;
    }
    return 0;
}

int roomTwo()
{
    cout << "There are 3 choices you can make." << endl
         << "Enter 1 letter (a, b, or c) to choose:" << endl;
    cout << "a) Move North" << endl
         << "b) Move East" << endl
         << "c) Go to sleep" << endl;
    cin >> promptAnswer;
    invalidPromptCheck();
    switch (promptAnswer)
    {
    case 'a':
        cout << endl
             << "You moved North." << endl;
        roomNumber = 1, travelCounter++;
        changeRoom();
        break;
    case 'b':
        cout << endl
             << "You tried moving East, but there turns out to be no door." << endl
             << endl;
        roomNumber = 2;
        altPrompts();
        break;
    case 'c':
        optionC();
        roomNumber = 2, sleepCounter++;
        break;
    }

    return 0;
}

int roomThree()
{
    cout << "There are 3 choices you can make." << endl
         << "Enter 1 letter (a, b, or c) to choose:" << endl;
    cout << "a) Move North" << endl
         << "b) Move West" << endl
         << "c) Go to sleep" << endl;
    cin >> promptAnswer;
    invalidPromptCheck();
    switch (promptAnswer)
    {
    case 'a':
        cout << endl
             << "You moved North." << endl;
        roomNumber = 4, travelCounter++;
        changeRoom();
        break;
    case 'b':
        cout << endl
             << "You tried moving West, but there turns out to be no door." << endl
             << endl;
        roomNumber = 3;
        altPrompts();
        break;
    case 'c':
        optionC();
        roomNumber = 3, sleepCounter++;
        break;
    }

    return 0;
}

int roomFour()
{
    cout << "There are 3 choices you can make." << endl
         << "Enter 1 letter (a, b, or c) to choose:" << endl;
    cout << "a) Move South" << endl
         << "b) Move West" << endl
         << "c) Go to sleep" << endl;
    cin >> promptAnswer;
    invalidPromptCheck();
    switch (promptAnswer)
    {
    case 'a':
        cout << endl
             << "You moved South." << endl;
        roomNumber = 3, travelCounter++;
        changeRoom();
        break;
    case 'b':
        cout << endl
             << "You moved West." << endl;
        roomNumber = 1, travelCounter++;
        changeRoom();
        break;
    case 'c':
        optionC();
        roomNumber = 4, sleepCounter++;
        break;
    }

    return 0;
}

int main()
{
    cout << "Hello, welcome to the game!" << endl
         << "You may or may not survive this, so be careful." << endl
         << endl;
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
    if (roomNumber == 5)
    {
        cout << endl
             << endl
             << "***Suddenly, you woke up and realized it was all a dream.***" << endl
             << "There are no rooms, and there are no doors." << endl
             << "This was simply a figment of your imagination." << endl
             << "But hey, at least you finally escaped! (for now.....)" << endl
             << endl;
        cout << "You slept " << sleepCounter << " times, and you went to a different room " << travelCounter << " times." << endl
             << "You were quite determined to escape. I'll have to find better ways to trick you next time..." << endl
             << endl;
    }
    return 0;
}