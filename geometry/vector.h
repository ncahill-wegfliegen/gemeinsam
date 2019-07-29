#pragma once

#include "convert.h"
#include "..\math\compare.h"
#include <type_traits>

namespace nhill
{
namespace geometry
{

template<typename C>
class Vector
{
   static_assert(std::is_arithmetic_v<C>, "The template parameter must be an arithmetic type (i.e., either integral or floating point type).");

public:
   using value_type = C;

   Vector();
   Vector( C x, C y );

   Vector( const Vector& );
   Vector& operator=( const Vector& );

   Vector( Vector&& ) noexcept;
   Vector& operator=( Vector&& ) noexcept;

   ~Vector();

   template<typename P = double> P r() const; // The polar radius
   template<typename P = double> P θ() const; // The polar angle in radians.
   template<typename P> void polar( P r, P θ );

   C x() const; // Get the cartesian x-component of the vector.
   void x( C );

   C y() const; // Get the cartesian y-component of the vector.
   void y( C );

private:
   C x_;
   C y_;
};

}
}


namespace nhill
{
namespace geometry
{

template<typename C> inline
bool operator==( const Vector<C>& a, const Vector<C>& b ) noexcept
{
   using namespace nhill::math;

   return equal<C, C>( a.x(), b.x() ) && equal<C, C>( a.y(), b.y() );
}

template<typename C> inline
bool operator!=( const Vector<C>& a, const Vector<C>& b ) noexcept
{
   return !(a == b);
}

template<typename C> inline
auto operator+( const Vector<C>& a, const Vector<C>& b ) noexcept->Vector<C>
{
   return {a.x() + b.x(), a.y() + b.y()};
}

template<typename C> inline
auto operator+=( Vector<C>& a, const Vector<C>& b ) noexcept->Vector<C> &
{
   a.x( a.x() + b.x() );
   a.y( a.y() + b.y() );

   return a;
}

template<typename C> inline
auto operator-( const Vector<C>& a, const Vector<C>& b ) noexcept->Vector<C>
{
   return {a.x() - b.x(), a.y() - b.y()};
}

template<typename C> inline
auto operator-=( Vector<C>& a, const Vector<C>& b ) noexcept->Vector<C> &
{
   a.x( a.x() - b.x() );
   a.y( a.y() - b.y() );

   return a;
}

template<typename C> inline
auto operator*( C a, const Vector<C>& b ) noexcept->Vector<C>
{
   return {a * b.x(), a * b.y()};
}

template<typename C> inline
auto operator*( const Vector<C>& a, C b ) noexcept->Vector<C>
{
   return {a.x() * b, a.y() * b};
}

template<typename C> inline
auto operator*=( Vector<C>& a, C b ) noexcept->Vector<C> &
{
   a.x( a.x() * b );
   a.y( a.y() * b );

   return a;
}

template<typename C> inline
C operator*( const Vector<C>& a, const Vector<C>& b ) noexcept
{
   return a.x() * b.x() + a.y() * b.y();
}


}
}


#pragma region Definitions
template<typename C> inline
nhill::geometry::Vector<C>::Vector()
   : x_{0}
   , y_{0}
{
}

template<typename C> inline
nhill::geometry::Vector<C>::Vector( C x, C y )
   : x_{x}
   , y_{y}
{
}

template<typename C> inline
nhill::geometry::Vector<C>::Vector( const Vector& ) = default;

template<typename C> inline
auto nhill::geometry::Vector<C>::operator=( const Vector& )->Vector & = default;

template<typename C> inline
nhill::geometry::Vector<C>::Vector( Vector&& ) noexcept = default;

template<typename C> inline
auto nhill::geometry::Vector<C>::operator=( Vector&& ) noexcept->Vector & = default;

template<typename C> inline
nhill::geometry::Vector<C>::~Vector() = default;

template<typename C>
template<typename P> inline
P nhill::geometry::Vector<C>::r() const
{
   return cartesian_to_polar_r<P, C>( x_, y_ );
}

template<typename C>
template<typename P> inline
P nhill::geometry::Vector<C>::θ() const
{
   return cartesian_to_polar_θ<P, C>( x_, y_ );
}

template<typename C>
template<typename P> inline
void nhill::geometry::Vector<C>::polar( P r, P θ )
{
   std::tie( x_, y_ ) = polar_to_cartesian<C, P>( r, θ );
}

template<typename C> inline
C nhill::geometry::Vector<C>::x() const
{
   return x_;
}

template<typename C> inline
void nhill::geometry::Vector<C>::x( C value )
{
   x_ = value;
}

template<typename C>
C nhill::geometry::Vector<C>::y() const
{
   return y_;
}

template<typename C>
void nhill::geometry::Vector<C>::y( C value )
{
   y_ = value;
}

#pragma endregion