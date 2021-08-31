#include "SodaLine.h"
#include <iostream>
#include <thread> // needed to create threads
#include <time.h> // srand
#include <stdio.h> // rand

using namespace std;

SodaLine::SodaLine()
{
	bottle1 = 0;
	bottle2 = 0;
	bottle3 = 0;
	bottle4 = 0;
	bottle5 = 0;
	cycle = 0;
}

SodaLine::~SodaLine()
{

}


void SodaLine::setCycle()
{
	cout << "But first, let's specify how many times this process will run. Enter in a numerical value." << endl;
	cin >> cycle;
	cout << "\nSo now we will run the simulation " << cycle << " times." << endl;
	threader(cycle);
}

int SodaLine::getCycle()
{
	return cycle;
}

void SodaLine::threader(int c)
{
	void *(*fillSwitcher) (int bNum);
	for (int i = 0; i < c; i++)
	{
		thread b1(fillSwitcher, 1); // fill switcher does an access violation, more testing is required.
		
		thread b2(fillSwitcher, 2);

		thread b3(fillSwitcher, 3);

		thread b4(fillSwitcher, 4);

		thread b5(fillSwitcher, 5);

		b1.join();

		cout << "Just to check! Bottle 1 is currently filled " << bottle1 << " percent!" << endl;

		b2.join();

		b3.join();

		b4.join();

		b5.join();

		bottleLoader();
	}
}


void SodaLine::fillSwitcher(int num)
{
	

	auto bottleFill = [=](int bottle) mutable noexcept
	{
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

			if (bottle > 100) //Bottles shouldn't (or cannot) hold more than they are capable. With the way I have the bottles to set up, it can potentially go over 100.
			{
				int overflow = bottle % 100; // calculate how much the bottle is overfilled
				cout << "The bottle is overfilled by " << overflow << " %. Draining excess... \n";
				bottle -= overflow; //remove the surplus
				cout << "Excess drained. \n";
			}

			else if (bottle == 100)
			{
				cout << " \nBottle number " << num << " finished filling." << endl;
			}
		}

	};


	switch (num)
	{
	case 1:
		bottleFill(bottle1);
	case 2:
		bottleFill(bottle2);
	case 3:
		bottleFill(bottle3);
	case 4:
		bottleFill(bottle4);
	case 5:
		bottleFill(bottle5);
	default:
		cout << "I do not know how you got here, but we managed to get to an invalid bottle value. Let's just leave." << endl;
	}
	
}



void SodaLine::bottleLoader()
{
	bottle1 = 0;
	bottle2 = 0;
	bottle3 = 0;
	bottle4 = 0;
	bottle5 = 0;
	cout << "Filled bottles have been shipped off the line and new, empty ones haven taken their place!" << endl;
}