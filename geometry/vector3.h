#pragma once

#include "convert.h"
#include "../math/compare.h"
#include <type_traits>

namespace nhill
{
namespace geometry
{

template<typename C>
class Vector3
{
   static_assert(std::is_arithmetic_v<C>, "The template parameter must be an arithmetic type (i.e., either integral or floating point type).");

public:
   using value_type = C;

   Vector3();
   Vector3( C x, C y, C z );

   Vector3( const Vector3& );
   Vector3& operator=( const Vector3& );

   Vector3( Vector3&& ) noexcept;
   Vector3& operator=( Vector3&& ) noexcept;

   ~Vector3();

   C x() const; // Get the cartesian x-component of the vector.
   void x( C ); // Set the cartesian x-component of the vector.

   C y() const; // Get the cartesian y-component of the vector.
   void y( C ); // Set the cartesian y-component of the vector.

   C z() const; // Get the cartesian z-component of the vector.
   void z( C ); // Set the cartesian z-component of the vector.

private:
   C x_;
   C y_;
   C z_;
};

}
}


namespace nhill
{
namespace geometry
{

template<typename C> inline
bool operator==( const Vector3<C>& a, const Vector3<C>& b ) noexcept
{
   using namespace nhill::math;

   return equal<C, C>( a.x(), b.x() ) && equal<C, C>( a.y(), b.y() ) && equal<C,C>( a.z(), b.z() );
}

template<typename C> inline
bool operator!=( const Vector3<C>& a, const Vector3<C>& b ) noexcept
{
   return !(a == b);
}

template<typename C> inline
auto operator+( const Vector3<C>& a, const Vector3<C>& b ) noexcept->Vector3<C>
{
   return {a.x() + b.x(), a.y() + b.y(), a.z() + b.z()};
}

template<typename C> inline
auto operator+=( Vector3<C>& a, const Vector3<C>& b ) noexcept->Vector3<C> &
{
   a.x( a.x() + b.x() );
   a.y( a.y() + b.y() );
   a.z( a.z() + b.z() );

   return a;
}

template<typename C> inline
auto operator-( const Vector3<C>& a, const Vector3<C>& b ) noexcept->Vector3<C>
{
   return {a.x() - b.x(), a.y() - b.y(), a.z() - b.z()};
}

template<typename C> inline
auto operator-=( Vector3<C>& a, const Vector3<C>& b ) noexcept->Vector3<C> &
{
   a.x( a.x() - b.x() );
   a.y( a.y() - b.y() );
   a.z( a.z() - b.z() );

   return a;
}

template<typename C> inline
auto operator*( C a, const Vector3<C>& b ) noexcept->Vector3<C>
{
   return {a * b.x(), a * b.y(), a.b.z()};
}

template<typename C> inline
auto operator*( const Vector3<C>& a, C b ) noexcept->Vector3<C>
{
   return {a.x() * b, a.y() * b, a.z() * b};
}

template<typename C> inline
auto operator*=( Vector3<C>& a, C b ) noexcept->Vector3<C> &
{
   a.x( a.x() * b );
   a.y( a.y() * b );
   a.z( a.z() * b );

   return a;
}

template<typename C> inline
C operator*( const Vector3<C>& a, const Vector3<C>& b ) noexcept
{
   return a.x() * b.x() + a.y() * b.y() + a.z() * b.z();
}


}
}


#pragma region Definitions
template<typename C> inline
nhill::geometry::Vector3<C>::Vector3()
   : x_{0}
   , y_{0}
   , z_{0}
{
}

template<typename C> inline
nhill::geometry::Vector3<C>::Vector3( C x, C y, C z )
   : x_{x}
   , y_{y}
   , z_{z}
{
}

template<typename C> inline
nhill::geometry::Vector3<C>::Vector3( const Vector3& ) = default;

template<typename C> inline
auto nhill::geometry::Vector3<C>::operator=( const Vector3& )->Vector3 & = default;

template<typename C> inline
nhill::geometry::Vector3<C>::Vector3( Vector3&& ) noexcept = default;

template<typename C> inline
auto nhill::geometry::Vector3<C>::operator=( Vector3&& ) noexcept->Vector3 & = default;

template<typename C> inline
nhill::geometry::Vector3<C>::~Vector3() = default;

template<typename C> inline
C nhill::geometry::Vector3<C>::x() const
{
   return x_;
}

template<typename C> inline
void nhill::geometry::Vector3<C>::x( C value )
{
   x_ = value;
}

template<typename C>
C nhill::geometry::Vector3<C>::y() const
{
   return y_;
}

template<typename C>
void nhill::geometry::Vector3<C>::y( C value )
{
   y_ = value;
}

template<typename C>
C nhill::geometry::Vector3<C>::z() const
{
   return z_;
}

template<typename C>
void nhill::geometry::Vector3<C>::zy( C value )
{
   z_ = value;
}


#pragma endregion