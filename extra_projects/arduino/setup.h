// setUp() functions

#include <iostream>
#include <cassert>

void pinNumSwitch(int);
bool inputNumSwitch(int);

int defPut(int pinNum, int inputNum) // use this to declare inputs/outputs
{
    pinNumSwitch(pinNum);
    bool trueInp = inputNumSwitch(inputNum);
}

void pinNumSwitch(int pinNum)
{
    switch (pinNum)
    {
    case 0:
        
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    }
}

bool inputNumSwitch(int inputNum)
{
    bool isInput;

    switch (inputNum)
    {
    case 0:
        isInput = true;
        break;
    case 1:
        isInput = false;
        break;
    default:
        std::cout << "error in isInput switch(), setup.h defPut()" << std::endl;
        assert(false);
    }

    return isInput;
}