// author: Von Reid
// this is for the H.W. #17 assignment in CS-1400
#include <iostream>

int main()
{
    // 16. increment, decrement

    // 17. prefix

    // 18. postfix

    // 19. body

    // 20. iteration

    // 23. infinite

    // 24. loop control variable

    // 35.

    /* made product a double because the problem never specified integer
    so the user has to be able to enter "a number", which COULD potentially be a big ol' decimal */
    double product, userInp = 0;
    while (product < 100)
    {
        std::cout << "Enter any number, I will multiply it and give you the product." << std::endl;
        std::cin >> userInp;
        product = userInp * 10;
        std::cout << std::endl << "I took that number and multiplied it by 10." << std::endl << "The new product is " << product << std::endl;
    }

    // 47. F (because the operand must be an lvalue)

    // 48. T

    // 49. F

    // 50. T

    // 65. The `result` variable will cause an error, because the ++ operator is being used with an invalid operand. `++(num1 + num2)` is not a lvalue operand.

    /* 66.
    1. The char variable `again` doesn't have a value. At least, not the value it's trying to compare to in the loop. So because of this, the while() loop will never be executed. You should have something like `char again = 'y';` so the loop can be executed.
    2. `cout << "Their sum is <<` will break, because the quotation marks never get closed off.
    3. The `while` loop doesn't even have curly brackets, so the first cout output will be stuck in an infinite loop since it's not contained.
    */
}