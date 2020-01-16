// A simple C++ program

/*
# is a preprocessor, which reads the program before it is compiled. It sets up the source code for the compile.
include is a directive, which causes the preprocessor to include the contents of a header file in the program.
iostream is the name of the header file.
<> indicate that iostream is a standard C++ file.
i.e. you cannot use "cout" without iostream
*/
#include <iostream>
/*
this declares that the program will be accessing entities whose names are part of the namespace called "std".
in order for a program to use the entities in iostream, it must have access to the std namespace.
*/
using namespace std;

// this declares a function with the name "main"
// everything inside of {} is the "main" function itself
int main()
{
    // this will display everything inside of the string
    // a sring is "" wrapped around word(s)
    cout << "Yeet skeet this program is pretty neat lol";
    // after the cout successfuly prints out the string, this will send 0 to the operating system
    // the value 0 usually tells the OS that the program was executed successfully
    return 0;
}