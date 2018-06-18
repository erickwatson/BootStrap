#include "Timer.h"



//Timer::Timer()
//{
//}
//
//
//Timer::~Timer()
//{
//}

//template <typename T>
//T Timer::elapsed() const {
//	return std::chrono::duration_cast<T>(Clock::now() -
//		m_epoch);
//}

// Get time in seconds and milliseconds
double Timer::seconds() const {
	return std::chrono::duration_cast<std::chrono::milliseconds>(
		Clock::now() - m_epoch).count() / 1000.0;
}

long long Timer::milliseconds() const {
	return std::chrono::duration_cast<std::chrono::milliseconds>(
		Clock::now() - m_epoch).count();
}

long long Timer::nanoseconds() const {
	return std::chrono::duration_cast<std::chrono::nanoseconds>(
		Clock::now() - m_epoch).count();
}



//Example code
/*
Timer start;

// code executes

float elapsedSeconds = start.seconds();
*/