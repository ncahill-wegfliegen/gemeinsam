#pragma once

#include "..\math\compare.h"

namespace nhill
{
namespace geometry
{

/// <summary>Decimal Degree</summary>
template<typename T = double>
class Degree
{
public:
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type: either integral or floating point type.");
   using value_type = T;

   Degree( T = 0 ) noexcept;
   Degree& operator=( T ) noexcept;

   Degree( const Degree& ) noexcept;
   Degree& operator=( const Degree& ) noexcept;

   Degree( Degree&& ) noexcept;
   Degree& operator=( Degree&& ) noexcept;

   ~Degree() noexcept;

   operator T() const noexcept;

   T value() const noexcept;
   void value( T ) noexcept;

private:
   T value_;
};

}
}

#pragma region Aliases
namespace nhill
{
namespace geometry
{

using Degreef = Degree<float>;
//using Degree = Degree<double>;
using Degreeld = Degree<long double>;

}
}
#pragma endregion

#pragma region Operators
namespace nhill
{
namespace geometry
{

template<typename T> inline
bool operator==( const Degree<T>& a, const Degree<T>& b ) noexcept
{
   return nhill::math::equal<T, T>( a.value(), b.value() );
}

template<typename T> inline
bool operator!=( const Degree<T>& a, const Degree<T>& b ) noexcept
{
   return !( a == b);
}

template<typename T> inline
bool operator>( const Degree<T>& a, const Degree<T>& b ) noexcept
{
   return nhill::math::greater<T, T>( a.value(), b.value() );
}

template<typename T> inline
bool operator>=( const Degree<T>& a, const Degree<T>& b ) noexcept
{
   return nhill::math::greater_or_equal<T, T>( a.value(), b.value() );
}

template<typename T> inline
bool operator<( const Degree<T>& a, const Degree<T>& b ) noexcept
{
   return nhill::math::less<T, T>( a.value(), b.value() );
}

template<typename T> inline
bool operator<=( const Degree<T>& a, const Degree<T>& b ) noexcept
{
   return nhill::math::less_or_equal<T, T>( a.value(), b.value() );
}

template<typename T> inline
auto operator+( const Degree<T>& a, const Degree<T>& b ) noexcept->Degree<T>
{
   return {a.value() + b.value()};
}

template<typename T> inline
auto operator-( const Degree<T>& a, const Degree<T>& b ) noexcept->Degree<T>
{
   return {a.value() - b.value()};
}

template<typename T> inline
auto operator+=( Degree<T>& a, const Degree<T>& b ) noexcept->Degree<T> &
{
   a = (a.value() + b.value());
   return *this;
}

template<typename T> inline
auto operator-=( Degree<T>& a, const Degree<T>& b ) noexcept->Degree<T> &
{
   a = (a.value() - b.value());
   return *this;
}

template<typename T> inline
auto operator*( T a, const Degree<T>& b ) noexcept->Degree<T>
{
   return {a * b.value()};
}

template<typename T> inline
auto operator*( const Degree<T>& a, T b ) noexcept->Degree<T>
{
   return {a.value() * b};
}

template<typename T> inline
auto operator*=( Degree<T>& a, T b ) noexcept->Degree<T> &
{
   a = (a.value() * b);
   return a;
}

/// <summary>Adjust the degree so that it is within the interval [0, 360).</summary>
template<typename T> inline
T adjust_degree_c0_o360( T value) noexcept
{
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type: either integral or floating point type.");

   while( nhill::math::less<T, uint8_t>( value, 0U ) )
   {
      value += static_cast<T>(360);
   }

   while( nhill::math::greater_or_equal<T, uint16_t>( value, 360U ) )
   {
      value -= static_cast<T>(360);
   }

   return value;
}

/// <summary>Adjust the degree so that it is within the interval [-180, 180).</summary>
template<typename T> inline
T adjust_degree_cn180_o180( T value ) noexcept
{
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type: either integral or floating point type.");

   while( nhill::math::greater_or_equal<T, uint8_t>( value, 180U ) )
   {
      value -= static_cast<T>(360);
   }

   while( nhill::math::less<T, int16_t>( value, -180 ) )
   {
      value += static_cast<T>(360);
   }

   return value;
}

/// <summary>Adjust the degree so that it is within the interval [-90, 90].</summary>
template<typename T> inline
T adjust_degree_cn90_c90( T value ) noexcept
{
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type: either integral or floating point type.");

   // Adjust to the interval [-180,180)
   value = adjust_degree_cn180_o180(value);

   // Adjust to the interval [-90,90]
   if( nhill::math::less<T, int8_t>( value, -90 ) )
   {
      value = (-180 - value);
   }
   else if( nhill::math::greater<T, uint8_t>( value, 90U ) )
   {
      value = (180 - value);
   }

   return value;
}

}
}
#pragma endregion

#pragma region Definitions
template<typename T> inline
nhill::geometry::Degree<T>::Degree( T value ) noexcept
   : value_{value}
{
}

template<typename T> inline
auto nhill::geometry::Degree<T>::operator=( T value ) noexcept->Degree &
{
   value_ = value;
   return *this;
}

template<typename T> inline
nhill::geometry::Degree<T>::Degree( const Degree& ) noexcept = default;

template<typename T> inline
auto nhill::geometry::Degree<T>::operator=( const Degree& ) noexcept->Degree & = default;

template<typename T> inline
nhill::geometry::Degree<T>::Degree( Degree&& ) noexcept = default;

template<typename T> inline
auto nhill::geometry::Degree<T>::operator=( Degree&& ) noexcept->Degree & = default;

template<typename T> inline
nhill::geometry::Degree<T>::~Degree() noexcept = default;

template<typename T> inline
nhill::geometry::Degree<T>::operator T() const noexcept
{
   return value();
}

template<typename T> inline
T nhill::geometry::Degree<T>::value() const noexcept
{
   return value_;
}

template<typename T> inline
void nhill::geometry::Degree<T>::value( T value ) noexcept
{
   value_ = value;
}


#pragma endregion
