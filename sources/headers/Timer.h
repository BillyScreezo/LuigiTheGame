#pragma once

class Timer final {
private:
	unsigned time_start;
	unsigned time_end;
	unsigned delay;
	unsigned secCounter;
public:
	Timer() : time_start{ 0 }, time_end{ 0 }, delay{ 0 }, secCounter{ 0 } {};
	inline void erase() {time_start = 0; time_end = 0; delay = 0; secCounter = 0;}
	inline unsigned get() { return secCounter; }
	void set();
	void check();
};
