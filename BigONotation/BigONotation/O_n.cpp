#include "O_n.h"
#include <iostream>
#include <cstdlib>

using namespace std;

O_n::O_n()
{
	for (int i = 0; i < sizeof(grades)/sizeof(grades[0]); i++)
	{
		grades[i] = (rand() % 100) + 1;
	}

}

O_n::~O_n()
{

}

int O_n::getGrades()
{
	for (int i = 0; i < sizeof(grades)/sizeof(grades[0]); i++)
	{
		cout << grades[i] << "\n";
	}
	return 0;
}