#pragma once

#include "port.h"
#include "..\math\constants.h"
#include <string>

namespace nhill
{
namespace geometry
{

template<typename P, typename C> inline
P cartesian_to_polar_r( C x_, C y_ )
{
   static_assert(std::is_floating_point_v<P>, "The radian parameter must be a floating point type: float, double, or long double.");
   static_assert(std::is_arithmetic_v<C>    , "The cartesian parameters must be an arithmetic type (i.e., either integral or floating point type).");
   
   using namespace std;

   P x{static_cast<P>(x_)};
   P y{static_cast<P>(y_)};

   P r{hypot<P,P>( x, y )};

   return r;
}

template<typename P, typename C> inline
P cartesian_to_polar_θ( C x_, C y_ )
{
   static_assert(std::is_floating_point_v<P>, "The radian parameter must be a floating point type: float, double, or long double.");
   static_assert(std::is_arithmetic_v<C>, "The cartesian parameters must be an arithmetic type (i.e., either integral or floating point type).");

   using namespace std;

   P x{static_cast<P>(x_)};
   P y{static_cast<P>(y_)};

   P θ{atan2<P,P>( x, y )};

   return θ;
}

template<typename P, typename C> inline
std::tuple<P, P> cartesian_to_polar( C x_, C y_ )
{
   static_assert(std::is_floating_point_v<P>, "The polar parameters must be a floating point type: float, double, or long double.");
   static_assert(std::is_arithmetic_v<C>, "The cartesian parameters must be an arithmetic type (i.e., either integral or floating point type).");

   using namespace std;

   P x{static_cast<P>(x_)};
   P y{static_cast<P>(y_)};

   P r{hypot<P,P>( x, y )};
   P θ{atan2<P,P>( x, y )};

   return make_tuple( r, θ );
}







template<typename C, typename P, std::enable_if_t<std::is_floating_point_v<C>>* = nullptr>
C polar_to_cartesian_x( P r, P θ )
{
   static_assert(std::is_floating_point_v<P>, "The polar parameters must be a floating point type: float, double, or long double.");

   using namespace std;

   P x{r * cos( θ )};

   return static_cast<C>(x);
}

template<typename C, typename P, std::enable_if_t<std::is_integral_v<C>>* = nullptr>
C polar_to_cartesian_x( P r, P θ )
{
   static_assert(std::is_floating_point_v<P>, "The polar parameters must be a floating point type: float, double, or long double.");

   using namespace std;

   P x{r * cos( θ )};

   x = round( x );

   return static_cast<C>(x);
}

template<typename C, typename P, std::enable_if_t<std::is_floating_point_v<C>>* = nullptr>
C polar_to_cartesian_y( P r, P θ )
{
   static_assert(std::is_floating_point_v<P>, "The polar parameters must be a floating point type: float, double, or long double.");
   
   using namespace std;

   P y{r * sin( θ )};

   return static_cast<C>(y);
}

template<typename C, typename P, std::enable_if_t<std::is_integral_v<C>>* = nullptr>
C polar_to_cartesian_y( P r, P θ )
{
   static_assert(std::is_floating_point_v<P>, "The polar parameters must be a floating point type: float, double, or long double.");
   
   using namespace std;

   P y{r * sin( θ )};

   y = round( y );

   return static_cast<C>(y);
}

template<typename C, typename P, std::enable_if_t<std::is_floating_point_v<C>>* = nullptr>
std::tuple<C, C> polar_to_cartesian( P r, P θ )
{
   static_assert(std::is_floating_point_v<P>, "The polar type must be a floating point type: float, double, or long double.");

   using namespace std;

   P x{r * cos( θ )};
   P y{r * sin( θ )};

   return std::make_tuple( static_cast<C>(x), static_cast<C>(y) );
}

template<typename C, typename P, std::enable_if_t<std::is_integral_v<C>>* = nullptr>
std::tuple<C, C> polar_to_cartesian( P r, P θ )
{
   static_assert(std::is_floating_point_v<P>, "The polar type must be a floating point type: float, double, or long double.");
  
   using namespace std;

   P x{r * cos( θ )};
   P y{r * sin( θ )};

   x = round( x );
   y = round( y );

   return std::make_tuple( static_cast<C>(x), static_cast<C>(y) );
}








template<typename DEG, typename RAD, std::enable_if_t<std::is_floating_point_v<DEG>>* = nullptr>
DEG radian_to_degree( RAD radian )
{
   static_assert(std::is_floating_point_v<RAD>, "The radian must be a floating point type: float, double, or long double.");

   RAD rad{radian.value()};
   RAD deg_per_rad{nhill::math::Constants<RAD>::_180_pi()};
   RAD deg{rad * deg_per_rad};

   return static_cast<DEG>(deg );
}

template<typename DEG, typename RAD, std::enable_if_t<std::is_integral_v<DEG>>* = nullptr>
DEG radian_to_degree( RAD radian )
{
   static_assert(std::is_floating_point_v<RAD>, "The radian must be a floating point type: float, double, or long double.");

   RAD rad{radian.value()};
   RAD deg_per_rad{nhill::math::Constants<RAD>::_180_pi()};
   RAD deg{rad * deg_per_rad};

   deg = std::round<RAD>( deg );

   return static_cast<DEG>(deg);
}

template<typename RAD, typename DEG>
RAD degree_to_radian( DEG degree )
{
   static_assert(std::is_floating_point_v<RAD>, "The radian must be a floating point type: float, double, or long double.");
   static_assert(std::is_arithmetic_v<DEG>, "The degree must be an arithmetic type: either integral or floating point type.");

   RAD deg{static_cast<RAD>(degree.value())};
   RAD rad_per_deg{nhill::math::Constants<RAD>::pi_180()};
   RAD rad{deg * rad_per_deg};

   return rad;
}



NHILL_GMTRY_PORT_FUNCTION std::string angle_to_string( char sign, unsigned int arcdeg, unsigned int arcmin, unsigned int arcsec, unsigned int milliarcsec );

}
}
