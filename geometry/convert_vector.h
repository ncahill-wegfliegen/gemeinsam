#pragma once

#include "vector.h"
#include "vector_polar.h"
#include "convert.h"

namespace nhill
{
namespace geometry
{

template<typename C, typename P>
Vector<C> to_cartesian( const Vector_polar<P>& v )
{
   auto [x,y] = polar_to_cartesian<P, U>( v.r, v.θ );
   return {x,y};
}

template<typename C, typename P>
C to_cartesian_x( const Vector_polar<P>& v )
{
   return polar_to_cartesian_x<C, P>( v.r(), v.θ() );
}

template<typename C, typename P>
C to_cartesian_y( const Vector_polar<P>& v )
{
   return polar_to_cartesian_y<C, P>( v.r(), v.θ() );
}




template<typename P, typename C>
Vector_polar<P> to_polar( const Vector<C>& v )
{
   auto [r, θ ] = cartesian_to_polar<P, C>( v.x, v.y );
   return {r, θ};
}

template<typename P, typename C>
P to_polar_r( const Vector<C>& v )
{
   return cartesian_to_polar_r<P, C>( v.x(), v.y() );
}

template<typename P, typename C>
P to_polar_θ( const Vector<C>& v )
{
   return cartesian_to_polar_theta<P, C>( v.x(), v.y() );
}

}
}
