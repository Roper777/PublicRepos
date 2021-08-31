// Multithreading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // standard io library
#include <thread> // required to use threads.
#include "SodaLine.h"

using namespace std; 

int main()
{
    int cycle = 0;
    cout << "This multi-threading example will simulate a fantasy bottling line." << endl;
    cout << "5 bottles are filled at differing intervals and sent off the line." << endl;
    cout << "Once one is sent off the line, another will not take its place until all others are sent off." << endl; // do this by utilizing the 'join' function
 
    SodaLine Line1;

    Line1.setCycle();

    Line1.~SodaLine();
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
