// author: Von Reid
// does a thing (I'll fill this out later)

#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int programNumber;
string programName;
char exitChar;

int promptExitProgram()
{
    switch (programNumber)
    {
    case 1:
        programName = "1)First";
        break;
    case 2:
        programName = "2)Second";
        break;
    case 3:
        programName = "3)Third";
        break;
    }
    cout << endl
         << "Enter the letter <x> to exit " << programName << "Program." << endl
         << "Enter any other letter to restart " << programName << "Program." << endl;
    cin >> exitChar;
    cout << endl;
}

int firstProgramTrig()
{
    cout << endl
         << "Enter an angle in degree units." << endl
         << "I will calculate the sin(), cos(), and tan() for that angle." << endl;
    double pi = M_PI, thAngleDeg; // 'th' is short for 'theta' (the θ symbol in trig functions)
    cin >> thAngleDeg;

    // converts the angle from degrees to radians
    double thAngleRad = thAngleDeg * pi / 180;

    // each of these 3 variables calculates the degrees into the 3 trig functions
    double sinAngle = sin(thAngleRad);
    double cosAngle = cos(thAngleRad);
    double tanAngle = tan(thAngleRad);
    cout << "sin(θ) is: " << sinAngle << endl;
    cout << "cos(θ) is: " << cosAngle << endl;
    cout << "tan(θ) is: " << tanAngle << endl;

    return 0;
}

int firstProgramRand()
{
    string continueInput;
    cout << endl
         << "Enter any letter to continue." << endl;
    cin >> continueInput;
    cout << endl
         << "Now, I will generate a random number and run it through some calculations." << endl;

    // generate a random number
    srand(time(NULL));
    const int MIN_VALUE = -10;
    const int MAX_VALUE = 10;
    int randInt = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;

    // run the random number through some calculations
    double expInt, logInt, log10Int, sqrtInt, absInt;
    expInt = exp(randInt);
    logInt = log(randInt);
    log10Int = log10(randInt);
    sqrtInt = sqrt(randInt);
    absInt = abs(randInt);

    int checkNAN = (isnan(logInt) && isnan(log10Int) && isnan(sqrtInt));
    int checkInf = (isinf(logInt) && isinf(log10Int));
    if (checkNAN == 1)
    {
        string logNAN, log10NAN, sqrtNAN;
        logNAN = log10NAN = sqrtNAN = "This didn't return a real number.";
        cout << "Number: " << randInt << endl
             << "Exponent: " << expInt << endl
             << "Natural Logarithm: " << logNAN << endl
             << "Base-10 Logarithm: " << log10NAN << endl
             << "Square Root: " << sqrtNAN << endl
             << "Absolute Value: " << absInt << endl;
    }
    else if (checkInf == 1)
    {
        string logInf, log10Inf;
        logInf = log10Inf = "∞";
        cout << "Number: " << randInt << endl
             << "Exponent: " << expInt << endl
             << "Natural Logarithm: " << logInf << endl
             << "Base-10 Logarithm: " << log10Inf << endl
             << "Square Root: " << sqrtInt << endl
             << "Absolute Value: " << absInt << endl;
    }
    else
    {
        // print out the outputs of the previous calculations
        cout << "Number: " << randInt << endl;
        cout << "Exponent: " << expInt << endl;
        cout << "Natural Logarithm: " << logInt << endl;
        cout << "Base-10 Logarithm: " << log10Int << endl;
        cout << "Square Root: " << sqrtInt << endl;
        cout << "Absolute Value: " << absInt << endl;
    }

    return 0;
}

int secondProgram()
{
    cout << endl
         << "Please enter your income: " << endl;
    float annIncome, taxRate;
    cin >> annIncome;

    // calculate the tax rates by using number ranges
    if (annIncome >= 120000)
    {
        taxRate = 23.5;
    }
    else if ((annIncome >= 90000) && (annIncome <= 119999.99))
    {
        taxRate = 20.6;
    }
    else if ((annIncome >= 45000) && (annIncome <= 89999.99))
    {
        taxRate = 18.2;
    }
    else if (annIncome < 45000)
    {
        taxRate = 12.0;
    }

    cout << "Based on your income, your tax rate rate is " << taxRate << "%" << endl;

    return 0;
}

int thirdProgram()
{
    char food;
    cout << endl
         << "Pick a letter to reveal a food:" << endl
         << "a)" << endl
         << "b)" << endl
         << "c)" << endl;
    cin >> food;
    if ((food != 'a') && (food != 'b') && (food != 'c'))
    {
        cout << "You have selected an undefined food." << endl
             << "Pick a valid letter, don't be an idiot.";
        cin >> food;
    }
    switch (food)
    {
    case 'a':
        cout << "a is for apple" << endl;
        break;
    case 'b':
        cout << "b is for banana" << endl;
        break;
    case 'c':
        cout << "c is for carrot" << endl;
        break;
    }

    return 0;
}

int main()
{
    int programChoice;
    cout << "Hello, this lab assignment had 3 programs in it." << endl
         << endl;
    while (programChoice != 4)
    {
        exitChar = 'a';
        cout << "Please enter one of these numbers to activate a program:" << endl
             << endl
             << "1)First Program" << endl
             << "Calculates 3 trig functions from the degrees of an angle you enter, then it generates a random number and runs it through some calculations." << endl
             << endl
             << "2)Second Program" << endl
             << "Determines the tax rate for an income you enter (based on a table of tax rate constants from the lab program)." << endl
             << endl
             << "3)Third Program" << endl
             << "Outputs a certain food based on a letter the user inputs." << endl
             << endl
             << "4)<Exit>" << endl;
        cin >> programChoice;
        switch (programChoice)
        {
        case 1:
            programNumber = 1;
            while (exitChar != 'x')
            {
                firstProgramTrig();
                firstProgramRand();
                promptExitProgram();
            }
            break;
        case 2:
            programNumber = 2;
            while (exitChar != 'x')
            {
                secondProgram();
                promptExitProgram();
            }
            break;
        case 3:
            programNumber = 3;
            while (exitChar != 'x')
            {
                thirdProgram();
                promptExitProgram();
            }
            break;
        case 4:
            return 0;
            break;
        }
    }
}