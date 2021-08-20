#pragma once
#include <iostream>

using namespace std;

class nLogN
{
public:
	nLogN();
	~nLogN();
	void HeapSort(int arr[], int size);
	void heapify(int arr[], int size, int index);
	void begin();

private:
	int nodes[9];
	int aSize;


};