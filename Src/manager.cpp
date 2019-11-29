#include "manager.hpp"

namespace manager
{
    using graphbases::graphPoint;
    
    struct graphPoint* way[WAY_SIZE];
    size_t size = 0;
    size_t curr = 0;

    #ifndef _BASIC_GRAPH_STRUCTS
    #define _BASIC_GRAPH_STRUCTS
    void addPoint(struct graphPoint* p)
    {
        if(size < WAY_SIZE)
            way[size++] = p;
    }

    struct graphPoint* next()
    {
        if(curr < size - 1)
            curr++;
        return getCurr();
    }

    void flush()
    {
        size = 0;
        curr = 0;
    }

    struct  graphPoint* getCurr()
    {
        return way[curr];
    }
    #endif
} // namespace manager
