#ifndef REDUCER_MORE_H_
#define REDUCER_MORE_H_

#include "reducer.h"

struct SumReducer : BaseReducer{
    void map(uint64_t a) final;

    void map_range(const uint64_t *begin, const uint64_t *end) final;

private:
    void map_(uint64_t a);
};

struct CountReducer : BaseReducer{
	void map(uint64_t) final;

	void map_range(const uint64_t *start, const uint64_t *end) final;
};



#endif

