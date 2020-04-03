// author: Von Reid
// this is for the H.W. #15 assignment in CS-1400
#include <iostream>

int main()
{

int i;

/*  5.
&& makes it so the statement returns true if both statements are true.
i.e.    */
if (i < 10 && i > 0){} // will only process if i is both greater than 0 and less than 10


/*  6.
|| makes it so the statement returns true if one of the statements is true.
i.e.    */
if ((i < 10) || (i > 0)){}  // will only process if i is either greater than 0 or less than 10, so only one of them has to be true.


//  18. &&
//  19. ||
//  20. !
//  21. left-to-right
//  22. &&
//  23. ||
//  34. 
        bool minimum = false;
        int hours = 0;
        if (minimum)
        {
            hours = 10;
        }
// 35.
        int amount1 = 0, amount2 = 0;
        if (amount1 > 10 && amount2 < 200)
        {
            if (amount1 > amount2)
            {
                std::cout << amount1 << std::endl;
            }
            if (amount2 > amount1) // could also do `else` or `else if`, but the exercise demands nested if statements
            {
                std::cout << amount2 << std::endl;
            }

        }
// 36.
        int grade = 101;
        if (grade >= 0 && grade <= 100)
        {
            std::cout << "The number is valid" << std::endl;
        }
// 37.
        int temperature = 200;
        if (temperature >= -50 && temperature <= 150)
        {
            std::cout << "The number is valid" << std::endl;
        }
// 38.
        hours = 1;
        if (hours <= 0 || hours >= 80)
        {
            std::cout << "The number is not valid" << std::endl;
        }
// 51.  T
// 52.  F
// 53.  T
// 54.  T
// 55.  F
// 56.  T
// 57.  T
// 62.  it needs to be `if (x <= 20)` because less-than-or-equal-to is TECHNICALLY the same thing
// 63.  it needs to be `if (count >= 0 && count <= 100)` because && is for 'within' the range
// 64.  it needs to be `if (count < 0 || count > 100)` because || is for 'outside' the range

}