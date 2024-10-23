#include "reducer_more.h"

void CountReducer::map(uint64_t){
	++result;
}

void CountReducer::map_range(const uint64_t *begin, const uint64_t *end){
	result = static_cast<std::size_t>(end - begin);
}

void SumReducer::map(uint64_t a){
        map_(a);
}

void SumReducer::map_range(const uint64_t *begin, const uint64_t *end){
    for(auto it = begin; it != end; ++it)
        map_(*it);
}

void SumReducer::map_(uint64_t a){
        result += a;
}

