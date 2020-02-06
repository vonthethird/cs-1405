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
using std::endl;

/*int pressEnter()
{
    cout << "Press the ENTER key";
    if (cin.std::istream::get() == '\n')
        cout << "Good job.\n";
    else
        cout << "I meant ONLY the ENTER key... Oh well.\n";
    return 0;
}*/

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
}

int promptQuestions()
{
    char promptAnswer;
    cout << "From the 3 options, enter 1 letter (a, b, or c):\n";
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
    }
    else if (promptAnswer == 'b')
    {
        cout << "\nYou moved East.\n";
    }
    else if (promptAnswer == 'c')
    {
        optionC();
        promptQuestions();
    }
}

int main()
{
    cout << "Hello, welcome to the game!\nYou may or may not survive this, so be careful.\n\n";
    promptQuestions();
}