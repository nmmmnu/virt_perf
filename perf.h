#ifndef PERF_H_
#define PERF_H_

#include <chrono>

struct Perf{
	auto operator()() const{
		using namespace std::chrono;

		auto const stop = high_resolution_clock::now();

		return duration_cast<microseconds>(stop - now).count();
	}

	void reset(){
		now = std::chrono::high_resolution_clock::now();
	}

private:
	using Point = std::chrono::time_point<std::chrono::high_resolution_clock>;

	Point now = std::chrono::high_resolution_clock::now();
};

#endif

