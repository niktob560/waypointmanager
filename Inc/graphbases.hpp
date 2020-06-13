#ifndef __GRAPH_BASES_HPP__
#define __GRAPH_BASES_HPP__


#include <unistd.h>
#include <stdint.h>
#include "math.hpp"

namespace graphbases
{
    typedef int16_t COORDS_DATATYPE;
    
	struct array
	{
		void *items;
		uint8_t size;
	};


	struct coords
	{
		COORDS_DATATYPE     x,
							y;

		constexpr bool eq(const struct coords *c)
		{
			return (x == c->x && y == c->y);
		}
		constexpr bool eq(const struct coords c)
		{
			return (x == c.x && y == c.y);
		}

		constexpr bool eq(const COORDS_DATATYPE _x, const COORDS_DATATYPE _y)
		{
			return (x == _x && y == _y);
		}


		constexpr struct coords rotate(const float teta)
		{
			return {static_cast<COORDS_DATATYPE>(x * cos(teta) - y * sin(teta)), static_cast<COORDS_DATATYPE>(x * sin(teta) + y * cos(teta))};
		}

		constexpr struct coords moveToNewZero(const struct coords *newZero)
		{
			return {static_cast<COORDS_DATATYPE>(newZero->x - x), static_cast<COORDS_DATATYPE>(newZero->y - y)};
		}

		constexpr struct coords 	restoreGlobalZero(const struct coords *newZero)
		{
			return {static_cast<COORDS_DATATYPE>(newZero->x + x), static_cast<COORDS_DATATYPE>(newZero->y + y)};
		}

		constexpr struct coords rotate(const struct coords *zero, const float teta)
		{
			return moveToNewZero(zero).rotate(teta).restoreGlobalZero(zero);
		}
	};



    struct graphPoint
    {
        struct graphPoint *targets[10];
        uint8_t				numOfTargets = 0;
        uint16_t		 	weight = 0xFFFF;
        uint8_t				i = 0;
        bool 				calculated = false;
    };
    
}

#endif