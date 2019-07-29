#pragma once

#include "..\math\compare.h"
#include <cmath>
#include <cstdint>

namespace nhill
{
namespace geometry
{

template<typename T = double>
struct Pnt
{
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type (i.e., either integral or floating point type).");

   using value_type = T;

   T x; // Cartesian x-component
   T y; // Cartesian y-component
};

}
}

#pragma region Aliases
namespace nhill
{
namespace geometry
{

using Pntf  = Pnt<float>;
using Pntld = Pnt<long double>;

}
}
#pragma endregion


namespace nhill
{
namespace geometry
{

template<typename T> inline
bool operator==( const Pnt<T>& a, const Pnt<T>& b ) noexcept
{
   return nhill::math::equal<T, T>( a.x, b.x ) && nhill::math::equal<T, T>( a.y, b.y );
}

template<typename T> inline
bool operator!=( const Pnt<T>& a, const Pnt<T>& b ) noexcept
{
   return !(a == b);
}

template<typename T, typename U> inline
U distance( const Pnt<T>& a, const Pnt<T>& b ) noexcept
{
   static_assert(std::is_floating_point_v<T>, "The return type must be a floating point type: float, double, or long double.");

   U dx = b.x - a.x;
   U dy = b.y - a.y;

   return std::hypot<U,U>( dx, dy );
}

}
}

