#pragma once
#include <unistd.h>
#include "math.hpp"

namespace graphbases
{
    typedef float COORDS_DATATYPE;
    
	struct array
	{
		void *items;
		size_t size;
	};


	struct coords
	{
		COORDS_DATATYPE     x,
							y;

		bool eq(struct coords *c)
		{
			return (x == c->x && y == c->y);
		}

		bool eq(COORDS_DATATYPE _x, COORDS_DATATYPE _y)
		{
			return (x == _x && y == _y);
		}
	};



    struct graphPoint
    {
        struct graphPoint **targets = NULL;
        size_t numOfTargets = 0;
        struct coords c;
        COORDS_DATATYPE weight = INF;
        size_t i = 0;
        bool calculated = false;
    };
    
}
