#pragma once

#include "polar.h"
#include <type_traits>

namespace nhill
{
namespace geometry
{

template<typename T = double>
struct Line_polar
{
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type (i.e., either integral or floating point type).");

   using value_type = T;

   Polar<T> a;
   Polar<T> b;
};

}
}

namespace nhill
{
namespace geometry
{

template<typename T>
double length( const Line_polar<T>& line )
{
   return distance<T>( line.a, line.b );
}


}
}
