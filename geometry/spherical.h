#pragma once

#include "radian.h"
#include "magnitude.h"
#include <type_traits>

namespace nhill
{
namespace geometry
{

template<typename T = double>
struct Spherical
{
   static_assert(std::is_floating_point_v<T>, "The template parameter must be a floating point type: float, double, or long double.");

   using value_type = T;

   Magnitude<T> r; // The polar radius.
   Radian<T>    θ; // The azimuth angle (theta) in radians (in xy-plane).
   Radian<T>    φ; // The polar angle (phi) in radians (from positive x-axis). ALT+237
};

}
}

#pragma region Aliases
namespace nhill
{
namespace geometry
{

using Sphericalf  = Spherical<float>;
using Sphericalld = Spherical<long double>;

}
}
#pragma endregion

#pragma region Methods
namespace nhill
{
namespace geometry
{

template<typename T> inline
bool operator==( const Spherical<T>& a, const Spherical<T>& b ) noexcept
{
   return math::equal<T, T>( a.r, b.r ) && math::equal<T, T>( a.θ, b.θ ) && math::equal<T,T>( a.φ, b.φ);
}

template<typename T> inline
bool operator!=( const Spherical<T>& a, const Spherical<T>& b ) noexcept
{
   return !(a == b);
}

}
}
#pragma endregion