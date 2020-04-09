// author: Von Reid

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using std::string;
using std::vector;

// most important functions
int binaryFind(const vector<string> &, const string &); // returns the index of str in the given sorted vector or -1 if not found

// test functions
void testDriver();

int main()
{
    testDriver();

    // main() shit
}

int binaryFind(const vector<string> &strs, const string &str)
{
    int index = 0;
    string strValue;
    //do {
    //    strValue = strs[index];
    //    index++;
    //} while (strValue == string);
    //int maxIndex = --index;
    int maxIndex = strs.size();
    for (index = 0, index < maxIndex; index++;)
    {
        strValue = strs[index];
        std::cout << strValue << std::endl;
        std::cout << strs[index] << std::endl;
        if (strValue == str)
        {
            return index;
        }
    }

    return -1; // if the above for() loop can't find a match, it will return -1 to indicate that &str does not equal any of the values in the &strs vector
}

void testDriver()
{
    {
        // test find empty
        vector<string> strs;
        assert(binaryFind(strs, "bye") == -1);
    }
    {
        // test find single
        vector<string> strs = {"bye"};
        assert(binaryFind(strs, "bye") == 0);
        assert(binaryFind(strs, "bo") == -1);
    }
    {
        // test find multi
        vector<string> strs = {"bye", "hello", "hi", "howdy"};
        // linear find
        assert(binaryFind(strs, "bye") == 0);
        assert(binaryFind(strs, "where") == -1);
        assert(binaryFind(strs, "hi") == 2);
        assert(binaryFind(strs, "howdy") == 3);
    }
}