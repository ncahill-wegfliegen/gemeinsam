#pragma once

#include "radian.h"
#include "magnitude.h"
#include <type_traits>
#include <cmath>

namespace nhill
{
namespace geometry
{

template<typename T = double>
struct Polar
{
   static_assert(std::is_floating_point_v<T>, "The template parameter must be a floating point type: float, double, or long double.");

   using value_type = T;

   Magnitude<T> r; // The polar radius.
   Radian<T>    θ; // The polar angle (theta) in radians.
};

}
}

#pragma region Aliases
namespace nhill
{
namespace geometry
{

using Polarf  = Polar<float>;
//using Polar   = Polar<double>;
using Polarld = Polar<long double>;

}
}
#pragma endregion

#pragma region Methods
namespace nhill
{
namespace geometry
{

template<typename T> inline
bool operator==( const Polar<T>& a, const Polar<T> & b ) noexcept
{
   return math::equal<T, T>( a.r, b.r ) && math::equal<T, T>( a.θ, b.θ );
}

template<typename T> inline
bool operator!=( const Polar<T> & a, const Polar<T> & b ) noexcept
{
   return !(a == b);
}

//template<typename T> inline
//auto operator+( const PolarT<T> & a, const PolarT<T> & b ) noexcept->PolarT<T>
//{
//   T x{to_cartesion_x( a ) + to_cartesian_x( b )};
//   T y{to_cartesian_y( a ) + to_cartesian_y( b )};
//
//   return cartesian_to_polar( x, y );
//}
//
//template<typename T> inline
//auto operator+=( PolarT<T> & a, const PolarT<T> & b ) noexcept->PolarT<T> &
//{
//   T x{to_cartesion_x( a ) + to_cartesian_x( b )};
//   T y{to_cartesian_y( a ) + to_cartesian_y( b )};
//
//   a = cartesian_to_polar( x, y );
//
//   return a;
//}
//
//template<typename T> inline
//auto operator-( const PolarT<T> & a, const PolarT<T> & b ) noexcept->PolarT<T>
//{
//   T x{to_cartesion_x( a ) - to_cartesian_x( b )};
//   T y{to_cartesian_y( a ) - to_cartesian_y( b )};
//
//   return cartesian_to_polar( x, y );
//}
//
//template<typename T> inline
//auto operator-=( PolarT<T> & a, const PolarT<T> & b ) noexcept->PolarT<T> &
//{
//   T x{to_cartesion_x( a ) - to_cartesian_x( b )};
//   T y{to_cartesian_y( a ) - to_cartesian_y( b )};
//
//   a = cartesian_to_polar( x, y );
//
//   return a;
//}
//
//template<typename T> inline
//auto operator*( T a, const PolarT<T> & b ) noexcept->PolarT<T>
//{
//   return {a * b.r, b.θ};
//}
//
//template<typename T> inline
//auto operator*(  const PolarT<T> & a, T b ) noexcept->PolarT<T>
//{
//   return {b * a.r, a.θ};
//}
//
//template<typename T> inline
//auto operator*=( PolarT<T>& a, T b ) noexcept->PolarT<T>&
//{
//   a.r *= b;
//   return a;
//}
//
//template<typename T> inline
//T operator*( const PolarT<T> & a, const PolarT<T> & b ) noexcept
//{
//   using namespace std;
//   return a.r * b.r * (cos( a.θ ) * cos( b.θ ) + sin( a.θ ) * sin( b.θ ));
//}

template<typename T> inline
T distance( const Polar<T>& a, const Polar<T>& b ) noexcept
{
   T d2{a.r * a.r + b.r * b.r - 2 * a.r * b.r * std::cos( b.θ - a.θ )};

   return std::sqrt(d2);
}


}
}
#pragma endregion