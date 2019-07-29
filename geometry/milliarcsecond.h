#pragma once

#include "port.h"
#include "arcminute.h"
#include "arcsecond.h"

namespace nhill
{

class NHILL_GMTRY_PORT_CLASS Milliarcsecond
{
public:
   using value_type = uint16_t;

#pragma region Constructors, Assignments, Destructor
   Milliarcsecond( unsigned int value = 0 );
   Milliarcsecond& operator=( unsigned int value );

   Milliarcsecond( const Milliarcsecond& );
   Milliarcsecond& operator=( const Milliarcsecond& );

   Milliarcsecond(  Milliarcsecond&& ) noexcept;
   Milliarcsecond& operator=(  Milliarcsecond&& ) noexcept;

   ~Milliarcsecond();
#pragma endregion

#pragma region Operators
   operator unsigned int() const;
#pragma endregion

#pragma region Properties
   unsigned int value() const;
 
   template<typename T, nhill::enable_if::is_math_type<T>* = nullptr>
   void value( T value, unsigned* arcsec = nullptr, unsigned* arcmin = nullptr, unsigned* arcdeg = nullptr );
#pragma endregion

#pragma region Methods
   void clear();
#pragma endregion

private:
#pragma region Data Members
   value_type value_;
#pragma endregion
};


template<typename T, nhill::enable_if::is_math_type<T>* = nullptr> inline
T adjust_milliarcsecond( T value, unsigned* arcsec = nullptr, unsigned* arcmin = nullptr, unsigned* arcdeg = nullptr )
{
   Expects( (math::greater_or_equal<T, uint8_t>( value, 0U )) );

   if (math::greater_or_equal<T, uint16_t>( value, 1000U ))
   {
      // Set the arcsecond, arcminute, and arcdegree (if required)
      if (arcsec != nullptr)
      {
         unsigned arcsec_temp{*arcsec};
         arcsec_temp += static_cast<unsigned>(std::trunc( value / 1000 ));
         *arcsec += adjust_arcsecond<unsigned>( arcsec_temp, arcmin, arcdeg );
      }

      // The value will be in the interval [0,1000).
      value = static_cast<T>(fmod( value, 1000 ));
   }

   Ensures( (math::greater_or_equal<T, uint8_t>( value, 0U ) && math::less<T, uint16_t>( value, 1000U )) );

   return value;
}

}

#pragma region Operators
namespace nhill
{

NHILL_GMTRY_PORT_FUNCTION Milliarcsecond operator+( const Milliarcsecond& a, const Milliarcsecond& b ) noexcept;
NHILL_GMTRY_PORT_FUNCTION Milliarcsecond operator-( const Milliarcsecond& a, const Milliarcsecond& b ) noexcept;
NHILL_GMTRY_PORT_FUNCTION Arcminute add( const Milliarcsecond& a, const Milliarcsecond& b, int* arcsec = nullptr, int* arcmin = nullptr, int* arcdeg = nullptr ) noexcept;
NHILL_GMTRY_PORT_FUNCTION Arcminute substract( const Milliarcsecond& a, const Milliarcsecond& b, int* arcsec = nullptr, int* arcmin = nullptr, int* arcdeg = nullptr ) noexcept;

NHILL_GMTRY_PORT_FUNCTION bool operator==( const Milliarcsecond& a, const Milliarcsecond& b ) noexcept;
NHILL_GMTRY_PORT_FUNCTION bool operator!=( const Milliarcsecond& a, const Milliarcsecond& b ) noexcept;

NHILL_GMTRY_PORT_FUNCTION bool operator>( const Milliarcsecond& a, const Milliarcsecond& b ) noexcept;
NHILL_GMTRY_PORT_FUNCTION bool operator<( const Milliarcsecond& a, const Milliarcsecond& b ) noexcept;

NHILL_GMTRY_PORT_FUNCTION bool operator>=( const Milliarcsecond& a, const Milliarcsecond& b ) noexcept;
NHILL_GMTRY_PORT_FUNCTION bool operator<=( const Milliarcsecond& a, const Milliarcsecond& b ) noexcept;


}
#pragma endregion

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
void nhill::Milliarcsecond::value( T value, unsigned * arcsec, unsigned * arcmin, unsigned * arcdeg )
{
   value_ = static_cast<value_type>(adjust_milliarcsecond<T>(value, arcsec, arcmin, arcdeg));

   Ensures( (( value_ >= 0U ) && ( value < 1000U)) );
}


