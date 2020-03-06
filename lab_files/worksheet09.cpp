// author: Von Reid

/*

1. A bug is a problem causing a program to crash or produce invalid output.
   It could be an error, mistake, defect or fault, which may cause failure or deviation from expected results.

2.
    a. Syntax error: an error that indicates something that must be fixed before the code can be compiled.
    b. Logical error: this error occurs when the desired output is not obtained when certain input values are given.
       These are fairly easy to detect if you follow the line of execution and determine why the program takes that path of execution.
    c. Run-time error: an error which occurs during program execution after successful compilation.

3. Testing a program with sample data can help you test inputs to determine if the correct outputs come out of it.

4. Hand-tracing is debugging a program without a computer, i.e. with paper and pencil. But it is becoming more and more irrelevant due to IDEs and debuggers.

5. Logical errors can be debugged with hand-tracing because you can draw out the process of execution in a program.

*/

// 6.
#include <iostream>
using namespace std;

int main()
{
    double x;
    cout << "Enter a value for x: ";
    cin >> x;

    double y1;
    y1 = 3 * x * x + 2 * x + 1;

    cout << "y1 = " << y1 << endl;

    double y2;
    y2 = 3 * x * x - 2 * x - 1;

    cout << "y2 = " << y2 << endl;

    return 0;
}

/* 7.
No, they don't. Sometimes one thing can break on a line, but stay hidden.
For example, if a variable value gets messed up somewhere, it can get very hard to trace it back to where the mess happened.
This is why assert() can be a useful tool, because you can test all sorts of things and it will tell you the line numbers of where errors ocurred. */