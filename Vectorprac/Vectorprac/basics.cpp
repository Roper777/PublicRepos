#include <stdio.h>
#include <iostream>
#include <vector> //a vector library is NEEDED to use vectors
#include "Header.cpp"

using namespace std;

// Date made: 1/10/2020
// Made by Matthew Robertson

int main()
{
	cout << "This group of files is used to explore the functionality of vectors and how to properly utilize them." << endl;
	cout << "I created this in order to experiment with the vector functionality in multiple ways to better my understanding." << endl;

	//method 1 to declare a vector. Pretty plain, declared empty at the start.
	vector <int> pickleJars;
	pickleJars.push_back(30);
	pickleJars.push_back(27);
	pickleJars.push_back(33);
	cout << pickleJars.capacity() << " is the vector capacity." << endl;
	// despite being size 3, spot '3' would be beyond scope at this point.
	pickleJars.push_back(45);
	cout << pickleJars.size() << " is the current size." << endl;
	pickleJars.pop_back(); // size should return to 3, and 45 should be removed.
	cout << pickleJars.size() << " is the current size, post pop." << endl;


	for (unsigned int i = 0; i < pickleJars.size(); i++)
	{
		cout << pickleJars[i] << " pickles in jar " << i + 1 << " ." << endl;
	}
	cout << pickleJars.size() << "is the current size." << endl;
	cout << pickleJars.capacity() << " is the vector capacity now." << endl;


	cout << "Attempting resize to size 7." << endl;
	pickleJars.resize(7);// resize does not fill the elements its creates. These spots will have '0' in them.
	cout << pickleJars.size() << " is the current size." << endl;
	cout << pickleJars.capacity() << " is the vector capacity now." << endl;

	for (unsigned int i = 0; i < pickleJars.size(); i++)
	{
		cout << pickleJars[i] << " pickles in jar " << i + 1 << " ." << endl;
	}

	cout << "Testing reserve command. Going to reserve 20 jars." << endl;
	pickleJars.reserve(20);
	//reserve does not set size, but rather the CAPACITY - which is different. Capacity will grow to meet size if Size > Capacity. But size won't, since it's dependent on elements in the vector.
	for (unsigned int i = 0; i < pickleJars.size(); i++)
	{
		cout << pickleJars[i] << " pickles in jar " << i + 1 << " ." << endl;
	}
	cout << pickleJars.size() << " is the current size." << endl;
	cout << pickleJars.capacity() << " is the vector capacity now." << endl;

}