#include "Timer.h"
#include <ctime>

void Timer::set() { time_start = clock(); }

void Timer::check()
{
	time_end = clock();
	delay = time_end - time_start;

	if (delay >= 1000)
	{
		secCounter += delay / 1000;
		time_start = clock();
	}
}