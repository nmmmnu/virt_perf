#ifndef REDUCER_H_
#define REDUCER_H_

#include <cstdint>

struct BaseReducer{
    uint64_t result = 0;

    virtual void map(uint64_t a) = 0;
    virtual void map_range(const uint64_t *begin, const uint64_t *end) = 0;

    virtual ~BaseReducer() = default;
};

#endif

