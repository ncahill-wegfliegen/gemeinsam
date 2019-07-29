#pragma once

#include "pnt.h"
#include <type_traits>

namespace nhill
{
namespace geometry
{

template<typename T = double>
struct Line_cartesian
{
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type (i.e., either integral or floating point type).");

   using value_type = T;

   Pnt<T> a;
   Pnt<T> b;
};

}
}

namespace nhill
{
namespace geometry
{

template<typename T>
double length( const Line_cartesian<T>& line )
{
   return distance<T>( line.a, line.b );
}

template<typename T>
double distance( const Pnt<T> & pnt, const Line_cartesian<T> & line )
{
   double x0 = pnt.x;
   double y0 = pnt.y;

   double x1 = line.a.x;
   double y1 = line.a.y;

   double x2 = line.b.x;
   double y2 = line.b.y;

   double num{std::abs( (y2 - y1) * x0 - (x2 - x1) * y0 + x2 * y1 - y2 * x1 )};
   double den{length( line )};

   return num / den;
}

}
}
