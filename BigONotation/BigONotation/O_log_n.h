#pragma once
#include <iostream>

using namespace std;

class logN
{
	public:
		logN();
		~logN();
		int binarySearch(int[], int, int, int);
		void inputReader();

	private:
		int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };


};