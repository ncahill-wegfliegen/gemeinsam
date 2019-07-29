#pragma once

#include "port.h"
#include "arcminute.h"

namespace nhill
{

using Arcsecond = Arcminute;

template<typename T, nhill::enable_if::is_math_signed_type<T>* = nullptr> inline
T adjust_arcsecond( T value, unsigned* arcmin = nullptr, unsigned* arcdeg = nullptr )
{
   using namespace std;
   using namespace nhill::math;

   if (less_or_equal<T, int8_t>( value, -60 ) || greater_or_equal<T, uint8_t>( value, 60 ))
   {
      // Set the arcminute and degree (if required)
      if (arcmin != nullptr)
      {
         unsigned arcminute_temp{*arcmin};
         arcminute_temp += static_cast<unsigned>(trunc( value / 60 ));
         *arcmin += adjust_arcminute<unsigned>( arcminute_temp, arcdeg );
      }

      // The value will be in the interval (-60,60).
      value = static_cast<T>(fmod( value, 60 ));
   }

   Ensures( (greater<T,int8_t>(value,-60) && less<T,uint8_t>(value,60)) );

   return value;
}

template<typename T, typename nhill::enable_if::is_math_unsigned_type<T>* = nullptr> inline
T adjust_arcsecond( T value, unsigned* arcmin /*= nullptr*/, unsigned* arcdeg /*= nullptr*/ )
{
   if ( nhill::math::greater_or_equal<T, uint8_t>( value, 60 ))
   {
      // Set the arcminute and degree (if required)
      if (arcmin != nullptr)
      {
         unsigned arcminute_temp{*arcmin};
         arcminute_temp += static_cast<unsigned>(std::trunc( static_cast<double>( value )/ 60 ));
         *arcmin += nhill::adjust_arcminute<unsigned>( arcminute_temp, arcdeg );
      }

      // The value will be in the interval (-60,60).
      value = static_cast<T>(std::fmod( value, 60 ));
   }

   Ensures( ( nhill::math::less<T, uint8_t>( value, 60U ) ) );

   return value;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* = nullptr>
Arcsecond add( const Arcsecond& a, const Arcsecond& b, unsigned* arcmin = nullptr, unsigned* arcdeg = nullptr )
{
   Arcsecond arcsec{adjust_arcsecond<T>( a.value() + b.value(), arcmin )};
   if (arcmin != nullptr)
   {
      arcmin += adjust_arcminute<unsigned>( *arcmin, arcdeg );
   }
   return arcsec;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* = nullptr>
Arcsecond substract( const Arcsecond& a, const Arcsecond& b, unsigned* arcmin = nullptr, unsigned* arcdeg = nullptr )
{
   Arcsecond arcsec{adjust_arcsecond<T>( a.value() - b.value(), arcmin )};
   if (arcmin != nullptr)
   {
      arcmin += adjust_arcminute<unsigned>( *arcmin, arcdeg );
   }
   return arcsec;
}



}
