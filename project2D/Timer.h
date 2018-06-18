#pragma once
#include <chrono>


class Timer
{
	typedef std::chrono::high_resolution_clock Clock;
public:
	Timer();
	//Timer() { reset; }
	~Timer() {}

	void reset() { m_epoch = Clock::now(); }

	// minutes?
	// hours?
	
	double seconds() const;
	long long milliseconds() const;
	long long nanoseconds() const;


private:

	Clock::time_point m_epoch;

};

