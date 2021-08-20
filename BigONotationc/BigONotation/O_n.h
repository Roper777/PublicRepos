#pragma once
#include <iostream>

using namespace std;


class O_n
{
	public:
		O_n();
		~O_n();
		int getGrades();

	private:
		int grades[5] = { 0, 0, 0, 0, 0 };
	
};