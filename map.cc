#include "reducer.h"

#if 0
std::size_t user_map_test(const uint64_t *begin, const uint64_t *end, BaseReducer &r){
	r.result = 0;

	void (BaseReducer::*f)(int) = &BaseReducer::map;

	for(auto it = begin; it != end; ++it)
		(r.*f)(*it);

	return r.result;
}
#endif

std::size_t user_map(const uint64_t *begin, const uint64_t *end, BaseReducer &r){
	r.result = 0;

	for(auto it = begin; it != end; ++it)
		r.map(*it);

	return r.result;
}

std::size_t user_map_whole(const uint64_t *begin, const uint64_t *end, BaseReducer &r){
	r.result = 0;

	r.map_range(begin, end);

	return r.result;
}


