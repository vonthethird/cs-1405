#include <iostream>
using std::string;
using std::cout;
using std::endl;

// int is short for integer
// this function will return the sum of a and b
int plus(int a, int b) {
    return a + b;
}

int main() {
    // get todo items from user
    string item1Name = "eat lunch";
    bool item1Done = false;
    char item1Category = 'A';
    float item1Importance = 2.5;
    // minutes since the beginning of the year
    int item1Due = 18 * 24 * 60; // jan 18th midnight

    // second item
    string item2Name = "homework";
    bool item2Done = false;
    char item2Category = 'B';
    float item2Importance = 4.5;
    int item2Due = 18 * 24 * 60; // jan 18th midnight
    

    cout << "Item 1" << endl;
    cout << "------" << endl;
    cout << "Name: " << item1Name << endl;
    cout << "Importance: " << item1Importance << endl;
    cout << "Category: " << item1Category << endl;
    cout << "Due: " << item1Due << endl;
    cout << "Done?: " << item1Done << endl;

    cout << endl;
    cout << "Item 2" << endl;
    cout << "------" << endl;
    cout << "Name: " << item2Name << endl;
    cout << "Importance: " << item2Importance << endl;
    cout << "Category: " << item2Category << endl;
    cout << "Due: " << item2Due << endl;
    cout << "Done?: " << item2Done << endl;

    // allow user to check off todo items

    // return 0 means "no errors to report"
    return 0;
}