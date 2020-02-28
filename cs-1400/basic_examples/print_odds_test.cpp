#include <iostream>
using namespace std;

int main()
{
    int i = 0, total = 0;
    for (i = 13; i <= 27; i = i + 2)
    {
        cout << i << endl;
        total = total + i;
    }
    cout << total << endl;
}