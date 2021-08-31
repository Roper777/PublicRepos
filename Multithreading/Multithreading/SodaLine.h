#pragma once
#include <iostream> // standard io library

using namespace std;

class SodaLine
{

public:
	SodaLine();
	~SodaLine();
	void setCycle();
	int getCycle();
	void threader(int);
	void bottleLoader();
	
	
private:
	int bottle1, bottle2, bottle3, bottle4, bottle5 ;
	int cycle;
};