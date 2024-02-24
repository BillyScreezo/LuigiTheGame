#pragma once
#include <ctime>
class Timer
{
private:
	unsigned int time0, time1, delay;
	int secCounter;
public:
	Timer();
	void erase();
	void set();
	void check();
	unsigned int get();
};
