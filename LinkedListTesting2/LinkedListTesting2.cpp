// LinkedListTesting2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
using namespace std;

void democode() {
    //a vector is a template for a variable array. This creates an array of strings with size 100.
    vector<string> myArray(100);
    //vectors have a size function
    int myArraySize = myArray.size();
    //this assigns all values in myArray2 as thingymobob
    vector<string> myArray2(100, "thingymobob");

    //vectors allow for initialising with values. Size is automatically assigned.
    vector<string> myArray3{ "a","bc","def","ghij","klmno","pqrstu","vwxyzab" };
}





int main()
{


    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
