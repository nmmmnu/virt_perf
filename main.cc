#include "perf.h"
#include "reducer_more.h"


std::size_t user_map(const uint64_t *begin, const uint64_t *end, BaseReducer &r);
std::size_t user_map_whole(const uint64_t *begin, const uint64_t *end, BaseReducer &r);



template<typename Reducer>
auto user_map_template(const uint64_t *begin, const uint64_t *end, Reducer &r){
	r.result = 0;

	for(auto it = begin; it != end; ++it)
		r.map(*it);

	return r.result;
}

template<typename Reducer>
auto user_map_whole_template(const uint64_t *begin, const uint64_t *end, Reducer &r){
	r.map_range(begin, end);

	return r.result;
}


#include <iostream>

template<typename Reducer, typename Container>
void test(const char *name, Reducer cr, Container const &v, Perf &p){
	std::cout << name << '\n';

	p.reset();
	user_map(v.data(), v.data() + v.size(), cr);
	std::cout << cr.result << '\n';
	std::cout << "Time: " << p() << " microseconds" << '\n';

	p.reset();
	user_map_template(v.data(), v.data() + v.size(), cr);
	std::cout << cr.result << '\n';
	std::cout << "Time: " << p() << " microseconds" << '\n';

	p.reset();
	user_map_whole(v.data(), v.data() + v.size(), cr);
	std::cout << cr.result << '\n';
	std::cout << "Time: " << p() << " microseconds" << '\n';

	p.reset();
	user_map_whole_template(v.data(), v.data() + v.size(), cr);
	std::cout << cr.result << '\n';
	std::cout << "Time: " << p() << " microseconds" << '\n';
}

#include <numeric>
#include <vector>

int main() {
	std::vector<uint64_t> v(1'000'000'000);
	std::iota(std::begin(v), std::end(v), 1);

	Perf p;

	test("Count",	CountReducer{},	v, p);
	test("Sum",	SumReducer{},	v, p);
}
