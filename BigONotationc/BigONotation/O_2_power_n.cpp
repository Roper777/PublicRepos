#include "O_2_power_n.h"
#include <iostream>

using namespace std;


twoPowerN::twoPowerN()
{

	cout << "This one gets overwhelming fast. 2^n, aka two to the power of n is the second-worst common time complexity." << endl;
	cout << "Our example here would be a Fibonacci sequence. The next step in the sequences is the last step plus the one before that." << endl;
	cout << "So it goes: 0, 1, 1, 2, 3, 5, 8, 13, 21, etc." << endl;

}



twoPowerN::~twoPowerN()
{


}



int twoPowerN::fibonacci(int num)
{
	if (num <= 1)
	{
		return num;
	}

	else
	{
		return fibonacci(num - 2) + fibonacci(num - 1);
	}
}
