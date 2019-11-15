#pragma once

#include "pnt.h"
#include "polar.h"
#include "convert.h"

namespace nhill
{
namespace geometry
{

template<typename C, typename P>
Pnt<C> to_cartesian( const Polar<P> & p )
{
   Pnt<C> pnt;
   std::tie(pnt.x, pnt.y) = polar_to_cartesian<P, U>( p.r, p.θ );
   return pnt;
}

template<typename C, typename P>
C to_cartesian_x( const Polar<P>& p )
{
   return polar_to_cartesian_x<C, P>( p.r, p.θ );
}

template<typename C, typename P>
C to_cartesian_y( const Polar<P>& p )
{
   return polar_to_cartesian_y<C, P>( p.r, p.θ );
}




template<typename P, typename C>
Polar<P> to_polar( const Pnt<C> & p )
{
   Polar<P> polar;
   std::tie(polar.r, polar.θ) = cartesian_to_polar<P, C>( p.x, p.y );
   return polar;
}

template<typename P, typename C>
P to_polar_r( const Pnt<C>& p )
{
   return cartesian_to_polar_r<P, C>( p.x, p.y );
}

template<typename P, typename C>
P to_polar_θ( const Pnt<C>& p )
{
   return cartesian_to_polar_theta<P, C>( p.x, p.y );
}

}
}

