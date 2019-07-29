#pragma once

#include "pnt.h"
#include "vector.h"
#include "vector_algebra.h"

namespace nhill
{
namespace geometry
{

template<typename T>
class Line_param
{
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type (i.e., either integral or floating point type).");

public:
   using value_type = T;

   Pnt<T> p;
   Vector<T> v;

   Pnt<T> get_point( T t ) const;
};


}
}


template<typename T> inline 
auto nhill::geometry::Line_param<T>::get_point( T t ) const->Pnt<T>
{
   return p + (t * v);
}

