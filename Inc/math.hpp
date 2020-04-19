#pragma once

#include <math.h>
#include <cmath>
#include <cstdint>

#define sqr(x) ((x * x))

#ifndef INF
    #ifdef COORDS_DATATYPE
        #define INF static_cast<COORDS_DATATYPE>(~0)
    #else
        #define INF static_cast<uint16_t>(~0)
    #endif
#endif //ifndef INF

#ifndef NULL
    #define NULL 0x00
#endif //ifndef NULL

#ifndef PI
    #define PI 3.14159
#endif //ifndef PI

#define sgn(x) ((x < 0.0)? -1 : 1)
#define abs(x) ((x > 0)? x : (x * -1))
