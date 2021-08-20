// BigONotation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "O_1.h"
#include "O_log_n.h"
#include "O_n.h"
#include "O_n_log_n.h"
#include "O_n_squared.h"
#include "O_2_power_n.h"
#include "O_n_factorial.h"

using namespace std;

int main()
{
    std::cout << "A quick summary of common Big O notation with examples.\n";
    O_1 one;
    one.O_1Process();
    one.~O_1();
    O_n byN;
    byN.getGrades();
    byN.~O_n();
    O_n_squared nSquare;
    nSquare.getGradesPair();
    nSquare.BubbleSort();
    nSquare.~O_n_squared();
    twoPowerN TPN;
    TPN.fibonacci(5);
    TPN.~twoPowerN();
    logN LN;


    nLogN NLN;
    NLN.begin();
    NLN.~nLogN();

    return 0;

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
