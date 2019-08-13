#pragma once

//#include "port.h"
#include "../math/compare.h"
#include "../utility/enable_if.h"
#include <gsl/gsl_assert>
#include <cstdint>
#include <type_traits>

#pragma region Adjust Degree Methods
namespace nhill
{

#pragma region Adjust Degree [0,360)
/// <summary>Take any <paramref name="value"/> and adjust it so that it is in the range [0,360).</summary>
template<typename T, typename nhill::enable_if::is_math_fp_type<T>* = nullptr> inline
T adjust_arcdegree_c0_360o(T value)
{
   // The remainder value will be in the interval (-360,360)
   value = std::fmod(value, static_cast<T>(360));

   // Adjust the value so that it is in the interval [0,360)
   if (nhill::math::less<T, uint8_t>(value, 0U))
   {
      value += 360;
   }

   Ensures((nhill::math::greater_or_equal<T, uint8_t>(value, 0U) && nhill::math::less<T, uint16_t>(value, 360U)));

   return value;
}

/// <summary>Take any <paramref name="value"/> and adjust it so that it is in the range [0,360).</summary>
template<typename T, typename nhill::enable_if::is_math_sint_type<T>* = nullptr> inline
T adjust_arcdegree_c0_360o(T value)
{
   // The remainder value will be in the interval (-360,360)
   value = (value % 360);

   // Adjust the value so that it is in the interval [0,360)
   if (value < 0)
   {
      value += 360;
   }

   Ensures(((value >= 0) && (value < 360)));

   return value;
}

/// <summary>Take any <paramref name="value"/> and adjust it so that it is in the range [0,360).</summary>
template<typename T, typename nhill::enable_if::is_math_uint_type<T>* = nullptr> inline
T adjust_arcdegree_c0_360o(T value)
{
   value = value % 360U;

   Ensures((value >= 0U) && (value < 360U));

   return value;
}
#pragma endregion

#pragma region Adjust Degree [-180,180)
/// <summary>Take any <paramref name="value"/> and adjust it so that it is in the range [-180,180).</summary>
template<typename T, typename enable_if::is_math_fp_type<T>* = nullptr>
T adjust_arcdegree_cn180_180o(T value)
{
   // The remainder value is in the interval (-360,360)
   value = static_cast<T>(std::fmod(value, 360));

   // Adjust to the interval [-180,180)
   if (math::greater_or_equal<T, uint8_t>(value, 180U))
   {
      value -= static_cast<T>(360);
   }
   else if (math::less<T, int16_t>(value, -180))
   {
      value += static_cast<T>(360);
   }

   Ensures((math::greater_or_equal<T, int16_t>(value, -180) && math::less<T, uint8_t>(value, 180U)));

   return value;
}

/// <summary>Take any <paramref name="value"/> and adjust it so that it is in the range [-180,180).</summary>
template<typename T, typename enable_if::is_math_sint_type<T>* = nullptr>
T adjust_arcdegree_cn180_180o(T value)
{
   // The remainder value is in the interval (-360,360)
   value = (value % 360);

   // Adjust to the interval [-180,180)
   if (value >= 180)
   {
      value -= 360;
   }
   else if (value < -180)
   {
      value += 360;
   }

   Ensures(((value >= -180) && (value < 180)));

   return value;
}

/// <summary>Take any <paramref name="value"/> and adjust it so that it is in the range [-180,180).</summary>
template<typename T, typename enable_if::is_math_uint_type<T>* = nullptr>
T adjust_arcdegree_cn180_180o(T value)
{
   // The remainder value is in the interval [0,180)
   value = (value % 180);

   Ensures(((value >= 0) && (value < 180)));

   return value;
}
#pragma endregion

#pragma region Adjust Degree [0,180]
template<typename T, typename enable_if::is_math_type<T>* = nullptr>
T adjust_arcdegree_c0_180c(T value)
{
   Expects((math::greater_or_equal<T, uint8_t>(value, 0)));

   if (math::greater<T, uint8_t>(value, 0))
   {
      // The quotient of the value and 180
      T quot{ static_cast<T>(value / 180) };
      // The quotient truncated to an unsigned integer
      uint64_t uquot{ static_cast<uint64_t>(std::floor(quot)) };
      // The integer multiple of 180
      T mult{ static_cast<T>(uquot * 180U) };

      // Is the value equal to an integer multiple of 180?
      if (math::equal<T, T>(value, mult))
      {
         // Yes. The return value is 180
         value = static_cast<T>(180);
      }
      else // No
      {
         // The return value is the remainder of the value and 180
         value = static_cast<T>(std::fmod(value, 180));
      }
   }

   Ensures((math::greater_or_equal<T, uint8_t>(value, 0) && math::less_or_equal<T, uint16_t>(value, 180U)));
   return value;
}
#pragma endregion 

#pragma region Adjust Degree [-90,90]
/// <summary>Take any <paramref name="value"/> and adjust it so that it is in the range [-90,90].</summary>
template<typename T, typename enable_if::is_math_type<T>* = nullptr>
T adjust_arcdegree_cn90_90c(T value)
{
   using namespace std;
   using namespace nhill::math;

   // The remainder value is in the interval (-180,180)
   value = static_cast<T>(fmod(value, 180));

   // Adjust to the interval [-90,90]
   if (greater<T, uint8_t>(value, 90U))
   {
      value = (180 - value);
   }
   else if (less<T, int8_t>(value, -90))
   {
      value = (-180 - value);
   }

   Ensures((greater_or_equal<T, int8_t>(value, -90) && less_or_equal<T, uint8_t>(value, 90U)));

   return value;
}

/// <summary>Take any <paramref name="value"/> and adjust it so that it is in the range [0,90].</summary>
template<typename T, typename enable_if::is_math_type<T>* = nullptr>
T adjust_arcdegree_c0_90c(T value)
{
   Expects((math::greater_or_equal<T, uint8_t>(value, 0U)));

   using namespace std;
   using namespace nhill::math;

   // The remainder value is in the interval [0,180)
   value = static_cast<T>(fmod(value, 180));

   // Adjust to the interval [0,90]
   if (greater<T, uint8_t>(value, 90U))
   {
      value = 180 - value;
   }

   Ensures((greater_or_equal<T, uint8_t>(value, 0) && less_or_equal<T, uint8_t>(value, 90U)));

   return value;
}
#pragma endregion


class Adjust_arcdegree
{
public:
   virtual ~Adjust_arcdegree() = 0;
};
inline Adjust_arcdegree::~Adjust_arcdegree() {}

class Adjust_arcdegree_c0_360o : public Adjust_arcdegree
{
public:
   using underlying_type = uint16_t;

   ~Adjust_arcdegree_c0_360o() {}

   template<typename T>
   T operator()(T value)
   {
      return adjust_arcdegree_c0_360o<T>(value);
   }
};

class Adjust_arcdegree_cn180_180o : public Adjust_arcdegree
{
public:
   using underlying_type = int16_t;

   ~Adjust_arcdegree_cn180_180o() {}

   template<typename T>
   T operator()(T value)
   {
      return adjust_arcdegree_cn180_180o<T>(value);
   }
};

/// <summary>Adjust the value so that it is in the interval [0,180].</summary>
class Adjust_arcdegree_c0_180c : public Adjust_arcdegree
{
public:
   using underlying_type = uint16_t;

   ~Adjust_arcdegree_c0_180c() {}

   template<typename T, typename enable_if::is_math_type<T>* = nullptr>
   T operator()(T value)
   {
      return adjust_arcdegree_c0_180c<T>(value);
   }
};

class Adjust_arcdegree_cn90_90c : public Adjust_arcdegree
{
public:
   using underlying_type = uint8_t;

   ~Adjust_arcdegree_cn90_90c() {}

   template<typename T>
   T operator()(T value)
   {
      return adjust_arcdegree_cn90_90c<T>(value);
   }
};

/// <summary>Adjust the value so that it is in the interval [0,90].</summary>
class Adjust_arcdegree_c0_90c : public Adjust_arcdegree
{
public:
   using underlying_type = uint8_t;

   ~Adjust_arcdegree_c0_90c() {}

   template<typename T>
   T operator()(T value)
   {
      return adjust_arcdegree_c0_90c<T>(value);
   }
};

}
#pragma endregion

namespace nhill
{

template<typename Adjust>
using Arcdegree_enable_if_type = std::enable_if_t< std::is_base_of_v<Adjust_arcdegree, Adjust> >;

/// <summary>A dgree value in the range determined by the adjust method.</summary>
template<typename Adjust, typename Arcdegree_enable_if_type<Adjust>* = nullptr >
class Arcdegree
{
public:
#pragma region Aliases
   using value_type = typename Adjust::underlying_type;
   using adjust_type = Adjust;
#pragma endregion

#pragma region Constructors, Assignments, Destructor
   Arcdegree();

   /// <summary>The <paramref name="value"/> is adjusted so that it is in the range determined by the adjust method.</summary>
   template<typename U>
   Arcdegree( U value );
   /// <summary>The <paramref name="value"/> is adjusted so that it is in the range determined by the adjust method.</summary>
   template<typename U>
   Arcdegree& operator=( U value );

   Arcdegree( const Arcdegree& );
   Arcdegree& operator=( const Arcdegree& );

   Arcdegree( Arcdegree&& ) noexcept;
   Arcdegree& operator=( Arcdegree&& ) noexcept;

   ~Arcdegree();
#pragma endregion

#pragma region Operators
   operator value_type() const;
#pragma endregion

#pragma region Properties
   value_type value() const;

   /// <summary>The <paramref name="value"/> is adjusted so that it is in the range determined by the adjust method.</summary>
   template<typename U> 
   void value( U value );
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

#pragma region Aliases
namespace nhill
{

using Arcdegree360 = Arcdegree<Adjust_arcdegree_c0_360o>;
using Arcdegree180 = Arcdegree<Adjust_arcdegree_cn180_180o>;
using Arcdegree90  = Arcdegree<Adjust_arcdegree_cn90_90c >;

}
#pragma endregion

#pragma region Operators
namespace nhill
{

template<typename Adjust, typename Arcdegree_enable_if_type<Adjust>* = nullptr>
Arcdegree<Adjust> operator+( const Arcdegree<Adjust>& a, const Arcdegree<Adjust>& b ) noexcept
{
   return {a.value() + b.value()};
}

template<typename Adjust, typename Arcdegree_enable_if_type<Adjust>* = nullptr>
Arcdegree<Adjust> operator-( const Arcdegree<Adjust>& a, const Arcdegree<Adjust>& b ) noexcept
{
   return {a.value() - b.value()};
}

template<typename Adjust, typename Arcdegree_enable_if_type<Adjust>* = nullptr>
bool operator==( const Arcdegree<Adjust>& a, const Arcdegree<Adjust>& b ) noexcept
{
   using T = typename Arcdegree<Adjust>::value_type;
   return nhill::math::equal<T, T>( a.value(), b.value() );
}

template<typename Adjust, typename Arcdegree_enable_if_type<Adjust>* = nullptr>
bool operator!=( const Arcdegree<Adjust>& a, const Arcdegree<Adjust>& b ) noexcept
{
   return !(a == b);
}

template<typename Adjust, typename Arcdegree_enable_if_type<Adjust>* = nullptr>
bool operator>( const Arcdegree<Adjust>& a, const Arcdegree<Adjust>& b ) noexcept
{
   using T = typename Arcdegree<Adjust>::value_type;
   return math::greater<T,T>( a.value(), b.value() );
}

template<typename Adjust, typename Arcdegree_enable_if_type<Adjust>* = nullptr>
bool operator<( const Arcdegree<Adjust>& a, const Arcdegree<Adjust>& b ) noexcept
{
   using T = typename Arcdegree<Adjust>::value_type;
   return math::less<T, T>( a.value(), b.value() );
}

template<typename Adjust, typename Arcdegree_enable_if_type<Adjust>* = nullptr>
bool operator>=( const Arcdegree<Adjust>& a, const Arcdegree<Adjust>& b ) noexcept
{
   return (a > b) || (a == b);
}

template<typename Adjust, typename Arcdegree_enable_if_type<Adjust>* = nullptr>
bool operator<=( const Arcdegree<Adjust>& a, const Arcdegree<Adjust>& b ) noexcept
{
   return (a < b) || (a == b);
}


}
#pragma endregion

#pragma region Definitions
template<typename Adjust, typename nhill::Arcdegree_enable_if_type<Adjust>* ef> inline
nhill::Arcdegree<Adjust, ef>::Arcdegree()
   : value_{0}
{
}

template<typename Adjust, typename nhill::Arcdegree_enable_if_type<Adjust>* ef>
template<typename U> inline
nhill::Arcdegree<Adjust, ef>::Arcdegree( U value )
   : value_{0}
{
   this->value<U>( value );
}

template<typename Adjust, typename nhill::Arcdegree_enable_if_type<Adjust>* ef>
template<typename U> inline
auto nhill::Arcdegree<Adjust, ef>::operator=( U value )->Arcdegree &
{
   this->value<U>( value );
   return *this;
}

template<typename Adjust, typename nhill::Arcdegree_enable_if_type<Adjust>* ef> inline
nhill::Arcdegree<Adjust, ef>::Arcdegree( const Arcdegree & ) = default;

template<typename Adjust, typename nhill::Arcdegree_enable_if_type<Adjust>* ef> inline
auto nhill::Arcdegree<Adjust, ef>::operator=( const Arcdegree & )->Arcdegree & = default;

template<typename Adjust, typename nhill::Arcdegree_enable_if_type<Adjust>* ef> inline
nhill::Arcdegree<Adjust, ef>::Arcdegree( Arcdegree && ) noexcept = default;

template<typename Adjust, typename nhill::Arcdegree_enable_if_type<Adjust>* ef> inline
auto nhill::Arcdegree<Adjust, ef>::operator=( Arcdegree && ) noexcept->Arcdegree & = default;

template<typename Adjust, typename nhill::Arcdegree_enable_if_type<Adjust>* ef> inline
nhill::Arcdegree<Adjust, ef>::~Arcdegree() = default;

template<typename Adjust, typename nhill::Arcdegree_enable_if_type<Adjust>* ef> inline
nhill::Arcdegree<Adjust, ef>::operator value_type() const
{
   return value();
}

template<typename Adjust, typename nhill::Arcdegree_enable_if_type<Adjust>* ef> inline
auto nhill::Arcdegree<Adjust, ef>::value() const->value_type
{
   return value_;
}

template<typename Adjust, typename nhill::Arcdegree_enable_if_type<Adjust>* ef> inline
void nhill::Arcdegree<Adjust, ef>::clear()
{
   value_ = 0;
}

template<typename Adjust, typename nhill::Arcdegree_enable_if_type<Adjust>* ef>
template<typename U> inline
void nhill::Arcdegree<Adjust, ef>::value( U value )
{
   static Adjust adjust;
   if (enable_if::is_math_int<value_type>::value && enable_if::is_math_fp<U>::value)
   {
      value_ = static_cast<value_type>(std::round(adjust( value )));
   }
   else
   {
      value_ = static_cast<value_type>(adjust( value ) );
   }
}
#pragma endregion