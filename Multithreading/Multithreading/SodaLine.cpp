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
		srand(time(NULL));
		switch (bottleNum)
		{
		case 1:
			
			while (bottle1 < 100)
			{
				
				remainder = 100 - bottle1;
				if (remainder == 1)
					bottle1 += 1;
				else if (bottle1 < 100)
				{
					bottle1 += (rand() % remainder) + 1;
				}

				if (bottle1 > 100) //Bottles shouldn't (or cannot) hold more than they are capable. With the way I have the bottles to set up, it can potentially go over 100.
				{
					int overflow = bottle1 % 100; // calculate how much the bottle is overfilled
					cout << "The bottle is overfilled by " << overflow << " %. Draining excess... \n";
					bottle1 -= overflow; //remove the surplus
					cout << "Excess drained. \n";
				}

				else if (bottle1 == 100)
				{
					cout << " \nBottle number " << bottleNum << " finished filling." << endl;
				}
			}
			break;

		case 2:
			while (bottle2 < 100)
			{

				remainder = 100 - bottle2;
				if (remainder == 1)
					bottle2 += 1;
				else if (bottle2 < 100)
				{
					bottle2 += (rand() % remainder) + 1;
				}

				if (bottle2 > 100) //Bottles shouldn't (or cannot) hold more than they are capable. With the way I have the bottles to set up, it can potentially go over 100.
				{
					int overflow = bottle2 % 100; // calculate how much the bottle is overfilled
					cout << "The bottle is overfilled by " << overflow << " %. Draining excess... \n";
					bottle2 -= overflow; //remove the surplus
					cout << "Excess drained. \n";
				}

				else if (bottle2 == 100)
				{
					cout << " \nBottle number " << bottleNum << " finished filling." << endl;
				}
			}
			break;
		case 3:
			while (bottle3 < 100)
			{

				remainder = 100 - bottle3;
				if (remainder == 1)
					bottle3 += 1;
				else if (bottle3 < 100)
				{
					bottle3 += (rand() % remainder) + 1;
				}

				if (bottle3 > 100) //Bottles shouldn't (or cannot) hold more than they are capable. With the way I have the bottles to set up, it can potentially go over 100.
				{
					int overflow = bottle3 % 100; // calculate how much the bottle is overfilled
					cout << "The bottle is overfilled by " << overflow << " %. Draining excess... \n";
					bottle3 -= overflow; //remove the surplus
					cout << "Excess drained. \n";
				}

				else if (bottle3 == 100)
				{
					cout << " \nBottle number " << bottleNum << " finished filling." << endl;
				}
			}
			break;

		case 4:
			while (bottle4 < 100)
			{

				remainder = 100 - bottle4;
				if (remainder == 1)
					bottle4 += 1;
				else if (bottle4 < 100)
				{
					bottle4 += (rand() % remainder) + 1;
				}

				if (bottle4 > 100) //Bottles shouldn't (or cannot) hold more than they are capable. With the way I have the bottles to set up, it can potentially go over 100.
				{
					int overflow = bottle4 % 100; // calculate how much the bottle is overfilled
					cout << "The bottle is overfilled by " << overflow << " %. Draining excess... \n";
					bottle4 -= overflow; //remove the surplus
					cout << "Excess drained. \n";
				}

				else if (bottle4 == 100)
				{
					cout << " \nBottle number " << bottleNum << " finished filling." << endl;
				}
			}
			break;
		case 5:
			while (bottle5 < 100)
			{

				remainder = 100 - bottle5;
				if (remainder == 1)
					bottle5 += 1;
				else if (bottle5 < 100)
				{
					bottle5 += (rand() % remainder) + 1;
				}

				if (bottle5 > 100) //Bottles shouldn't (or cannot) hold more than they are capable. With the way I have the bottles to set up, it can potentially go over 100.
				{
					int overflow = bottle5 % 100; // calculate how much the bottle is overfilled
					cout << "The bottle is overfilled by " << overflow << " %. Draining excess... \n";
					bottle2 -= overflow; //remove the surplus
					cout << "Excess drained. \n";
				}

				else if (bottle5 == 100)
				{
					cout << " \nBottle number " << bottleNum << " finished filling." << endl;
				}
			}
			break;
		default:
			cout << "I do not know how you got here, but we managed to get to an invalid bottle value. Let's just leave." << endl;
		}

	};

	for (int i = 0; i < c; i++)
	{
		thread b1(bottleFill, 1); // fill switcher does an access violation, more testing is required.
		
		thread b2(bottleFill, 2);

		thread b3(bottleFill, 3);

		thread b4(bottleFill, 4);

		thread b5(bottleFill, 5);

		b1.join();

		cout << "Just to check! Bottle 1 is currently filled " << bottle1 << " percent!" << endl;

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