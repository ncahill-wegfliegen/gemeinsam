#pragma once

#include "compare.h"
#include "nhill/enum/core/int.h"
#include "nhill/enable_if.h"
#include <array>
#include <algorithm>

namespace nhill
{
namespace math
{

template<typename T, std::size_t N, typename nhill::enable_if::is_math_type<T>* = nullptr>
using Vector = std::array<T, N>;

}
}



template<typename T, std::size_t N, typename nhill::enable_if::is_math_type<T>* = nullptr>
auto operator+=( nhill::math::Vector<T, N>& v1, const nhill::math::Vector<T, N>& v2 ) noexcept->nhill::math::Vector<T, N>&
{
   std::transform( v1.begin(), v1.end(), v2.begin(), v1.begin(), []( T a, T b ) { return a + b; } );
   return v1;
}

template<typename T, std::size_t N, typename nhill::enable_if::is_math_type<T>* = nullptr>
auto operator+( nhill::math::Vector<T, N> v1, const nhill::math::Vector<T, N>& v2 ) noexcept-> nhill::math::Vector<T, N>
{
   return v1 += v2;
}

template<typename T, std::size_t N, typename nhill::enable_if::is_math_type<T>* = nullptr>
auto operator-=( nhill::math::Vector<T, N>& v1, const nhill::math::Vector<T, N>& v2 ) noexcept-> nhill::math::Vector<T, N>&
{
   std::transform( v1.begin(), v1.end(), v2.begin(), v1.begin(), []( T x, T y ) { return x - y; } );
   return v1;
}

template<typename T, std::size_t N, typename nhill::enable_if::is_math_type<T>* = nullptr>
auto operator-( nhill::math::Vector<T, N> v1, const nhill::math::Vector<T, N>& v2 ) noexcept-> nhill::math::Vector<T, N>
{
   return v1 -= v2;
}

template<typename T, std::size_t N, typename nhill::enable_if::is_math_type<T>* = nullptr>
auto operator*( const nhill::math::Vector<T, N>& v1, const nhill::math::Vector<T, N>& v2 ) noexcept->T
{
   using size_type = typename nhill::math::Vector<T, N>::size_type;

   T product{};

   for( size_type i = 0 ; i < N ; ++i )
   {
      product += v1[i] * v2[i];
   }

   return product;
}

template<typename T, std::size_t N, typename nhill::enable_if::is_math_type<T>* = nullptr>
auto operator*( T s, nhill::math::Vector<T, N> v ) noexcept->nhill::math::Vector<T, N>
{
   std::transform( v.begin(), v.end(), v.begin(), [&s]( T x ) { return s * x; } );
   return v;
}

template<typename T, std::size_t N, typename nhill::enable_if::is_math_type<T>* = nullptr>
bool operator==( const nhill::math::Vector<T, N>& v1, const nhill::math::Vector<T, N>& v2 ) noexcept
{
   return nhill::math::equal( v1, v2 );
}

template<typename T, std::size_t N, typename nhill::enable_if::is_math_type<T>* = nullptr>
bool operator!=( const nhill::math::Vector<T, N>& v1, const nhill::math::Vector<T, N>& v2 ) noexcept
{
   return !nhill::math::equal( v1, v2 );
}

namespace nhill
{
namespace math
{

template<typename T, std::size_t N, typename enable_if::is_math_type<T>* = nullptr>
bool equal( const Vector<T,N>& v1, const Vector<T,N>& v2 ) noexcept
{
   using size_type = typename Vector<T, N>::size_type;

   bool eq = true;
   for( size_type i = 0 ; i < N ; ++i )
   {
      if( !equal<T, T>( v1[i], v2[i] ) )
      {
         eq = false;
         break;
      }
   }

   return eq;
}

template<typename T, std::size_t N, typename enable_if::is_math_type<T>* = nullptr>
T magnitude( const Vector<T, N>& v ) noexcept
{
   T mag{ v*v };
   mag = std::sqrt( mag );
   return mag;
}

template<typename T, std::size_t N, typename enable_if::is_math_type<T>* = nullptr>
T distance( const Vector<T, N>& v1, const Vector<T, N>& v2 ) noexcept
{
   Vector<T, N> diff{ v1 - v2 };
   T dist{ magnitude( diff ) };

   return dist;
}

template<typename T, std::size_t N, typename enable_if::is_math_type<T>* = nullptr>
T angle( const Vector<T, N>& v1, const Vector<T, N>& v2 )
{
   // Cosine of theta
   T cost{ (v1*v2) / (magnitude( v1 )*magnitude( v2 )) };
   // Theta (in radians)
   T t{ std::acos( cost ) };
   // Theta (in degrees)
   T pi{ std::acos( static_cast<T>(-1) ) };
   T tt{ t * static_cast<T>(180) / pi };

   return tt;
}

/// <summary>The projection of <paramref name="x"/> onto <paramref name="y"/>.</summary>
template<typename T, std::size_t N, typename enable_if::is_math_type<T>* = nullptr>
Vector<T, N> projection( const Vector<T, N>& x, const Vector<T, N>& y )
{
   // The scalar multiple
   T s{ (x*y) / (y*y) };

   // The projection
   Vector<T, N> proj{ s*y };

   return proj;
}

/// <summary>The perpendicular component of <paramref name="x"/> with repect to <paramref name="y"/>.</summary>
template<typename T, std::size_t N, typename enable_if::is_math_type<T>* = nullptr>
Vector<T, N> perpendicular( const Vector<T, N>& x, const Vector<T, N>& y )
{
   // Projection of x onto y
   Vector<T, N> proj{ projection( x,y ) };

   // Perpendicular component of x wrt y
   Vector<T, N> perp{ x - proj };

   return perp;
}

template<typename T, typename enable_if::is_math_type<T>* = nullptr>
Vector<T, 3> cross( const Vector<T, 3>& P, const Vector<T, 3>& Q ) noexcept
{
   using size_type = typename Vector<T, 3>::size_type;

   size_type x{ static_cast<size_type>(nhill::to_int( Coordinate::x )) };
   size_type y{ static_cast<size_type>(nhill::to_int( Coordinate::y )) };
   size_type z{ static_cast<size_type>(nhill::to_int( Coordinate::z )) };

   Vector<T, 3> c;

   c[x] =   P[y] * Q[z] - P[z] * Q[y];
   c[y] = -(P[x] * Q[z] - P[z] * Q[x]);
   c[z] =   P[x] * Q[y] - P[y] * Q[x];

   return c;
}

}
}


