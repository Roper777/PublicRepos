#include "O_n_log_n.h"

#include <iostream>
#include <time.h>
#include <stdio.h> 


using namespace std;

nLogN::nLogN()
{
	srand(time(NULL));
	aSize = sizeof(nodes) / sizeof(nodes[0]);
	for (int y = 0; y < aSize; y++)
	{
		nodes[y] = (rand() % 29) + 1;
	}

}

nLogN::~nLogN()
{

}

void nLogN::heapify(int arr[], int size, int index)
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < size && nodes[left] > nodes[largest]) // Largest in this statement can be substituted for 'index', since those remain the same thing at this point
	{
		largest = left;
	}

	if (right < size && nodes[right] > nodes[largest]) // Largest in this statement can be substituted for 'index', since those remain the same thing at this point
	{
		largest = right;
	}

	if (largest != index)
	{
		swap(arr[index], arr[largest]);

		heapify(arr, size, largest);
	}


}

void nLogN::HeapSort(int arr[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		//build heap
		heapify(arr, size, i);
	}

	for (int i = size - 1; i > 0; i--)
	{
		
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);

	}
}

void nLogN::begin()
{
	cout << "Printing out the current array before it gets heap-sorted \n";
	for (int i = 0; i < aSize; i++)
	{
		cout << nodes[i] << endl;
	}
	HeapSort(nodes, aSize);


	cout << "Printing out what should be the heap-sorted array" << endl;
	for (int i = 0; i < aSize; i++)
	{
		cout << nodes[i] << endl;
	}
}