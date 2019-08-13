#pragma once

#include "../math/compare.h"
#include <cmath>
#include <cstdint>

namespace nhill
{
namespace geometry
{

template<typename T = double>
struct Pnt3
{
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type (i.e., either integral or floating point type).");

   using value_type = T;

   T x; // Cartesian x-component
   T y; // Cartesian y-component
   T z; // Cartesian z-component
};

}
}

#pragma region Aliases
namespace nhill
{
namespace geometry
{

using Pntef  = Pnt3<float>;
using Pnteld = Pnt3<long double>;

}
}
#pragma endregion


namespace nhill
{
namespace geometry
{

template<typename T> inline
bool operator==( const Pnt3<T>& a, const Pnt3<T>& b ) noexcept
{
   return nhill::math::equal<T, T>( a.x, b.x ) && nhill::math::equal<T, T>( a.y, b.y ) && nhill::math::equal<T, T>( a.z, b.z);
}

template<typename T> inline
bool operator!=( const Pnt3<T>& a, const Pnt3<T>& b ) noexcept
{
   return !(a == b);
}

template<typename T, typename U> inline
U distance( const Pnt3<T>& a, const Pnt3<T>& b ) noexcept
{
   static_assert(std::is_floating_point_v<T>, "The return type must be a floating point type: float, double, or long double.");

   U dx = b.x - a.x;
   U dy = b.y - a.y;
   U dz = b.z - a.z;

   return std::sqrt<U, U>( dx*dx + dy*dy + dz*dz );
}


}
}

