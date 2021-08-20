#include "O_n_squared.h"
#include <iostream>
#include <cstdlib>


using namespace std;

O_n_squared::O_n_squared()
{
	cout << "We're populating an array and walking through it, and pairing the numbers with one another each step. \n" ;
}

O_n_squared::~O_n_squared()
{

}



void O_n_squared::getGradesPair()
{
	for (int i = 0; i < sizeof(grades) / sizeof(grades[0]); i++)
	{
		cout << grades[i] << "(Base) ";
		for (int j = 0; j < sizeof(grades) / sizeof(grades[0]); j++)
		{
			cout << ", " << grades[j] ;
		}
		cout << " \n";
	}
}


void O_n_squared::BubbleSort()
{
	cout << "For another example, we'll do a bubble sort. We carry the biggest number in an array to the end by comparing two numbers next to each other \n";
	cout << "This continues until the array is sorted least to greatest. \n";
	int temp;
	for (int i = 0; i < sizeof(grades) / sizeof(grades[0]); i++)
	{
		for (int j = i + 1; j < sizeof(grades) / sizeof(grades[0]); j++)
		{
			if (grades[i] > grades[j])
			{
				temp = grades[i];
				grades[i] = grades[j];
				grades[j] = temp;

			}
		}
	}

	for (int x = 0; x < sizeof(grades) / sizeof(grades[0]); x++)
	{
		cout << grades[x] << "\n";
	}
	
}