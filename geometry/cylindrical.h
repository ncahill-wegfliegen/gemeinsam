#pragma once

#include "radian.h"
#include "magnitude.h"
#include <type_traits>

namespace nhill
{
namespace geometry
{

template<typename T = double>
struct Cylindrical
{
   static_assert(std::is_floating_point_v<T>, "The template parameter must be a floating point type: float, double, or long double.");

   using value_type = T;

   Magnitude<T> r; // The polar radius.
   Radian<T>    θ; // The azimuth angle (theta) in radians (in xy-plane).
   T            z; // The height (z-axis).
};

}
}

#pragma region Aliases
namespace nhill
{
namespace geometry
{

using Cylindricalf  = Cylindrical<float>;
using Cylindricalld = Cylindrical<long double>;

}
}
#pragma endregion

#pragma region Methods
namespace nhill
{
namespace geometry
{

template<typename T> inline
bool operator==( const Cylindrical<T>& a, const Cylindrical<T>& b ) noexcept
{
   return math::equal<T, T>( a.r, b.r ) && math::equal<T, T>( a.θ, b.θ ) math::equal<T,T>(a.z, b.z);
}

template<typename T> inline
bool operator!=( const Cylindrical<T>& a, const Cylindrical<T>& b ) noexcept
{
   return !(a == b);
}

}
}
#pragma endregion