#include "SodaLine.h"
#include <iostream>
#include <time.h> // srand
#include <stdio.h> // rand

using namespace std;

SodaLine::SodaLine()
{

}

SodaLine::~SodaLine()
{

}

void SodaLine::fillBottle(int input)
{
	int bottle = input;
	int remainder = 0;
	while (bottle < 100)
	{
		srand(time(NULL));
		remainder = 100 - bottle;
		if (remainder == 1)
			bottle += 1;
		else if (bottle < 100)
		{
			bottle += (rand() % remainder) + 1;
		}

		if (bottle > 100)
		{
			int overflow = bottle % 100;
			cout << "The bottle is overfilled by " << overflow << " %. Draining excess... \n";
			bottle -= overflow;
			cout << "Excess drained. \n";
		}

	}



}