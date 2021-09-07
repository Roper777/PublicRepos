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
	auto bottleFill = [=](int bottleNum) mutable noexcept -> void
	{
		int remainder = 0;
		int bottle = 0;
		srand(time(NULL));
			
		while (bottle < 100)
		{

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
				printf("The bottle is overfilled by %i percent. Draining excess... \n", overflow);
				bottle1 -= overflow; //remove the surplus
				cout << "Excess drained. \n";
			}

			switch (bottleNum)
			{

			case 1:
				bottle1 = bottle;
				break;
			case 2:
				bottle2 = bottle;
				break;
			case 3:
				bottle3 = bottle;
				break;
			case 4:
				bottle4 = bottle;
				break;
			case 5:
				bottle5 = bottle;
				break;
			default:
				cout << "I do not know how you got here, but we managed to get to an invalid bottle value. Let's just leave." << endl;
				break;
			}

		}
		printf("Bottle %i is filled completely \n", bottleNum);
	};

	for (int i = 0; i < c; i++)
	{
		thread b1(bottleFill, 1); // fill switcher does an access violation, more testing is required.
		
		

		thread b2(bottleFill, 2);

		thread b3(bottleFill, 3);

		thread b4(bottleFill, 4);

		thread b5(bottleFill, 5);

		b1.join();

		printf("Checking bottle 1: %i . \n", bottle1);

		b2.join();

		b3.join();

		b4.join();

		b5.join();

		bottleLoader();
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