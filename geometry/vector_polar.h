#pragma once

#include "convert.h"
#include "../math/compare.h"
#include <type_traits>

namespace nhill
{
namespace geometry
{

template<typename P = double>
class Vector_polar
{
public:
   static_assert(std::is_floating_point_v<P>, "The template parameter must be a floating point type: float, double, or long double.");
   
   using value_type = P;

   Vector_polar();
   Vector_polar( P r, P θ );
   
   Vector_polar( const Vector_polar& );
   Vector_polar& operator=( const Vector_polar& );

   Vector_polar( Vector_polar&& ) noexcept;
   Vector_polar& operator=( Vector_polar&& ) noexcept;

   ~Vector_polar();

   P r() const; // The magnitude (length) of the vector.
   void r( P );

   P θ(); // The direction of the vector as an angle in radians (theta).
   void θ( P );

   template<typename C = P> C x() const; // Get the cartesian x-component of the vector.
   template<typename C = P> C y() const; // Get the cartesian y-component of the vector.
   template<typename C> void cartesian( C x, C y );

private:
   P r_;
   P θ_;
};

}
}


namespace nhill
{
namespace geometry
{

template<typename P> inline
bool operator==( const Vector_polar<P>& a, const Vector_polar<P>& b ) noexcept
{
   return math::equal<P, P>( a.r(), b.r() ) && math::equal<P, P>( a.θ(), b.θ() );
}

template<typename P> inline
bool operator!=( const Vector_polar<P>& a, const Vector_polar<P>& b ) noexcept
{
   return !(a == b);
}

template<typename P> inline
auto operator+( const Vector_polar<P>& a, const Vector_polar<P>& b ) noexcept->Vector_polar<P>
{
   Vector_polar<P> tmp{a};
   tmp += b;
   return tmp;
}

template<typename P> inline
auto operator+=( Vector_polar<P>& a, const Vector_polar<P>& b ) noexcept->Vector_polar<P>&
{
   P xa{polar_to_cartesion_x<P>( a.r(), a.θ() )};
   P xb{polar_to_cartesian_x<P>( b.r(), b.θ() )};

   P ya{polar_to_cartesian_y<P>( a.r(), a.θ() )};
   P yb{polar_to_cartesian_y<P>( b.r(), b.θ() )};

   P x{xa + xb};
   P y{ya + yb};

   a = to_polar( {x, y} );

   return a;
}

template<typename P> inline
auto operator-( const Vector_polar<P>& a, const Vector_polar<P>& b ) noexcept->Vector_polar<P>
{
   Vector_polar<P> tmp{a};
   tmp -= b;
   return tmp;
}

template<typename P> inline
auto operator-=( Vector_polar<P>& a, const Vector_polar<P>& b ) noexcept->Vector_polar<P> &
{
   P xa{polar_to_cartesion_x<P>( a.r(), a.θ() )};
   P xb{polar_to_cartesian_x<P>( b.r(), b.θ() )};

   P ya{polar_to_cartesian_y<P>( a.r(), a.θ() )};
   P yb{polar_to_cartesian_y<P>( b.r(), b.θ() )};

   P x{xa - xb};
   P y{ya - yb};

   a = to_polar( {x, y} );

   return a;
}

template<typename P> inline
auto operator*( P a, const Vector_polar<P>& b ) noexcept->Vector_polar<P>
{
   return {a * b.r(), b.θ()};
}

template<typename P> inline
auto operator*( const Vector_polar<P>& a, P b) noexcept->Vector_polar<P>
{
   return a.polar() * b;
}

template<typename P> inline
auto operator*=( Vector_polar<P>& a, P b ) noexcept->Vector_polar<P>&
{
   a = {a.polar() * b};
   return a;
}

template<typename P> inline
P operator*( const Vector_polar<P>& a, const Vector_polar<P>& b ) noexcept
{
   return a.polar() * b.polar();
}

}
}


#pragma region Definitions
template<typename P> inline 
nhill::geometry::Vector_polar<P>::Vector_polar()
   : r_{0}
   , θ_{0}
{
}

template<typename P> inline 
nhill::geometry::Vector_polar<P>::Vector_polar( P r, P θ )
   : r_{mag}
   , θ_{dir}
{
}

template<typename P> inline
nhill::geometry::Vector_polar<P>::Vector_polar( const Vector_polar& ) = default;

template<typename P> inline
auto nhill::geometry::Vector_polar<P>::operator=( const Vector_polar& )->Vector_polar & = default;

template<typename P> inline
nhill::geometry::Vector_polar<P>::Vector_polar( Vector_polar&& ) noexcept = default;

template<typename P> inline
auto nhill::geometry::Vector_polar<P>::operator=( Vector_polar&& ) noexcept->Vector_polar & = default;

template<typename P> inline
nhill::geometry::Vector_polar<P>::~Vector_polar() = default;

template<typename P> inline 
auto nhill::geometry::Vector_polar<P>::r() const->P
{
   return r_;
}

template<typename P> inline 
void nhill::geometry::Vector_polar<P>::r( P r)
{
   r_ = r;
}

template<typename P> inline 
auto nhill::geometry::Vector_polar<P>::θ()->P
{
   return θ_;
}

template<typename P> inline 
void nhill::geometry::Vector_polar<P>::θ( P θ )
{
   θ_ = θ;
}

template<typename P>
template<typename C> inline 
C nhill::geometry::Vector_polar<P>::x() const
{
   return polar_to_cartesian_x<C,P>(r_, θ_ );
}

template<typename P>
template<typename C> inline 
C nhill::geometry::Vector_polar<P>::y() const
{
   return polar_to_cartesian_y<C,P>(r_, θ_ );
}

template<typename P>
template<typename C> inline
void nhill::geometry::Vector_polar<P>::cartesian( C x, C y )
{
   std::tie( r_, θ_) = cartesian_to_polar<P, C>( x, y );
}

#pragma endregion