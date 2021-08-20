#pragma once
#include <iostream>

using namespace std;

class O_n_squared
{
	public:
		O_n_squared();
		~O_n_squared();
		void getGradesPair();
		void BubbleSort();

	private:
		int grades[5] = { 46, 23, 12, 95, 78 };

};