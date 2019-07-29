#pragma once

#include "port.h"
#include "..\utility\enable_if.h"
#include "..\math\compare.h"
#include "..\utility\chr.h"
#include <gsl\gsl_assert>

#pragma region Adjust Methods
namespace nhill
{

template<typename T, typename enable_if::is_math_fp_type<T>* = nullptr>
T adjust_arcminute(T value, unsigned* arcdeg = nullptr)
{
   if (math::less_or_equal<T, int8_t>(value, -60) || math::greater_or_equal<T, uint8_t>(value, 60))
   {
      // Set the degree (if required)
      if (arcdeg != nullptr)
      {
         *arcdeg += static_cast<unsigned>(std::trunc(static_cast<long double>(value) / 60.0));
      }

      // The value will be in the interval (-60,60).
      value = static_cast<T>(std::fmod(value, static_cast<T>(60)));
   }

   Ensures((math::greater<T, int8_t>(value, -60) && math::less<T, uint8_t>(value, 60)));

   return value;
}

template<typename T, typename enable_if::is_math_sint_type<T>* = nullptr>
T adjust_arcminute(T value, unsigned* arcdeg = nullptr)
{
   if ((value <= -60) || (value >= 60))
   {
      // Set the degree (if required)
      if (arcdeg != nullptr)
      {
         *arcdeg += static_cast<unsigned>(value / 60);
      }

      // The value will be in the interval (-60,60).
      value = (value % 60);
   }

   Ensures(((value > -60) && (value < 60)));

   return value;
}

template<typename T, typename enable_if::is_math_uint_type<T>* = nullptr>
T adjust_arcminute(T value, unsigned* arcdeg = nullptr)
{
   if (value >= 60)
   {
      // Set the degree (if required)
      if (arcdeg != nullptr)
      {
         *arcdeg += static_cast<unsigned>(value / 60);
      }

      // The value will be in the interval [0,60).
      value = value % 60;
   }

   Ensures((value < 60));

   return value;
}


/// <summary>Adjusts the arcminute value to be in the interval (-60,60).</summary>
class  Adjust_arcminute_signed
{
   template<typename T, typename enable_if::is_math_signed_type<T>* = nullptr >
   T adjust(T value, unsigned* arcdeg = nullptr)
   {
      return adjust_arcminute<T>(value, arcdeg);
   }
};

/// <summary>Adjusts the arcminute value to be in the interval [0,60).</summary>
class  Adjust_arcminute_unsigned
{
   template<typename T, typename enable_if::is_math_signed_type<T>* = nullptr >
   T adjust(T value, unsigned* arcdeg = nullptr)
   {
      return adjust_arcminute<T>(value, arcdeg);
   }
};


}
#pragma endregion

namespace nhill
{

class NHILL_GMTRY_PORT_CLASS  Arcminute
{
public:
   using value_type = uint8_t;

#pragma region Constructors, Assignments, Destructor
   Arcminute();

   /// <ensures>The value is in the open interval (-60,+60).</ensures>
   Arcminute( unsigned int value );
   /// <ensures>The value is in the open interval (-60,+60).</ensures>
   Arcminute& operator=( unsigned int value );

   Arcminute( const Arcminute& );
   Arcminute& operator=( const Arcminute& );

   Arcminute( Arcminute&& ) noexcept;
   Arcminute& operator=( Arcminute&& ) noexcept;

   ~Arcminute();
#pragma endregion

#pragma region Operators
   operator unsigned int() const;
#pragma endregion

#pragma region Properties
   unsigned int value() const;

   /// <ensures>The value is in the open interval (-60,+60).</ensures>
   void value( unsigned value, unsigned* arcdeg = nullptr );
#pragma endregion

#pragma region Methods
   void clear();
#pragma endregion

private:
#pragma region Data Members
   value_type value_;
#pragma endregion
};

}


#pragma region Operators and Methods
namespace nhill
{

NHILL_GMTRY_PORT_FUNCTION Arcminute operator+( const Arcminute& a, const Arcminute& b ) noexcept;
NHILL_GMTRY_PORT_FUNCTION Arcminute operator-( const Arcminute& a, const Arcminute& b ) noexcept;
NHILL_GMTRY_PORT_FUNCTION Arcminute add      ( const Arcminute& a, const Arcminute& b, unsigned* arcdeg = nullptr ) noexcept;
NHILL_GMTRY_PORT_FUNCTION Arcminute substract( const Arcminute& a, const Arcminute& b, unsigned* arcdeg = nullptr ) noexcept;

NHILL_GMTRY_PORT_FUNCTION bool operator==( const Arcminute& a, const Arcminute& b ) noexcept;
NHILL_GMTRY_PORT_FUNCTION bool operator!=( const Arcminute& a, const Arcminute& b ) noexcept;

NHILL_GMTRY_PORT_FUNCTION bool operator>( const Arcminute& a, const Arcminute& b ) noexcept;
NHILL_GMTRY_PORT_FUNCTION bool operator<( const Arcminute& a, const Arcminute& b ) noexcept;

NHILL_GMTRY_PORT_FUNCTION bool operator>=( const Arcminute& a, const Arcminute& b ) noexcept;
NHILL_GMTRY_PORT_FUNCTION bool operator<=( const Arcminute& a, const Arcminute& b ) noexcept;

}
#pragma endregion 

