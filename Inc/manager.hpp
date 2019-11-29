#pragma once
#include <unistd.h>
#include "graphbases.hpp"

namespace manager
{
    using graphbases::graphPoint;

    const size_t WAY_SIZE = 255;
    extern struct graphPoint* way[];
    extern size_t size;
    extern size_t curr;

    void addPoint(struct graphPoint* p);
    void flush();

    struct graphPoint* next();
    struct graphPoint* getCurr();
    
}
