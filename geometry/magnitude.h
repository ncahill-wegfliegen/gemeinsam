#pragma once

#include "..\math\compare.h"

namespace nhill
{
namespace geometry
{

/// <summary>Floating point radian angle.</summary>
template<typename T>
class Magnitude
{
public:
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type: either integral or floating point type.");
   using value_type = T;

   Magnitude( T = 0 ) noexcept;
   Magnitude& operator=( T ) noexcept;

   Magnitude( const Magnitude& ) noexcept;
   Magnitude& operator=( const Magnitude& ) noexcept;

   Magnitude( Magnitude&& ) noexcept;
   Magnitude& operator=( Magnitude&& ) noexcept;

   ~Magnitude() noexcept;

   operator T() const noexcept;

   T value() const;
   void value( T );

   static bool is_valid( T );

protected:
   void validate( T ) const;

private:
   T value_;
};

}
}


#pragma region Operators
namespace nhill
{
namespace geometry
{

template<typename T> inline
bool operator==( const Magnitude<T>& a, const Magnitude<T>& b ) noexcept
{
   return nhill::math::equal<T, T>( a.value(), b.value() );
}

template<typename T> inline
bool operator!=( const Magnitude<T>& a, const Magnitude<T>& b ) noexcept
{
   return !(a == b);
}

template<typename T> inline
bool operator>( const Magnitude<T>& a, const Magnitude<T>& b ) noexcept
{
   return nhill::math::greater<T, T>( a.value(), b.value() );
}

template<typename T> inline
bool operator>=( const Magnitude<T>& a, const Magnitude<T>& b ) noexcept
{
   return nhill::math::greater_or_equal<T, T>( a.value(), b.value() );
}

template<typename T> inline
bool operator<( const Magnitude<T>& a, const Magnitude<T>& b ) noexcept
{
   return nhill::math::less<T, T>( a.value(), b.value() );
}

template<typename T> inline
bool operator<=( const Magnitude<T>& a, const Magnitude<T>& b ) noexcept
{
   return nhill::math::less_or_equal<T, T>( a.value(), b.value() );
}

template<typename T> inline
auto operator+( const Magnitude<T>& a, const Magnitude<T>& b ) noexcept->Magnitude<T>
{
   return {a.value() + b.value()};
}

template<typename T> inline
auto operator-( const Magnitude<T>& a, const Magnitude<T>& b ) noexcept->Magnitude<T>
{
   return {a.value() - b.value()};
}

template<typename T> inline
auto operator+=( const Magnitude<T>& a, const Magnitude<T>& b ) noexcept->Magnitude<T> &
{
   a.value(a.value() + b.value());
   return *this;
}

template<typename T> inline
auto operator-=( const Magnitude<T>& a, const Magnitude<T>& b ) noexcept->Magnitude<T> &
{
   a.value( a.value() - b.value());
   return *this;
}

template<typename T> inline
auto operator*( T a, const Magnitude<T>& b ) noexcept->Magnitude<T>
{
   return {a * b.value()};
}
template<typename T> inline
auto operator*( const Magnitude<T>& a, T b ) noexcept->Magnitude<T>
{
   return {a.value() * b};
}

template<typename T> inline
auto operator*=( Magnitude<T>& a, T b ) noexcept->Magnitude<T> &
{
   a.value(a.value() * b);
   return *this;
}

}
}
#pragma endregion

#pragma region Definitions
template<typename T> inline
nhill::geometry::Magnitude<T>::Magnitude( T value ) noexcept
{
   this->value( value );
}

template<typename T> inline
auto nhill::geometry::Magnitude<T>::operator=( T value ) noexcept->Magnitude &
{
   value_ = value;
   return *this;
}

template<typename T> inline
nhill::geometry::Magnitude<T>::Magnitude( const Magnitude& ) noexcept = default;

template<typename T> inline
auto nhill::geometry::Magnitude<T>::operator=( const Magnitude& other ) noexcept->Magnitude & = default;

template<typename T> inline
nhill::geometry::Magnitude<T>::Magnitude( Magnitude&& ) noexcept = default;

template<typename T> inline
auto nhill::geometry::Magnitude<T>::operator=( Magnitude&& ) noexcept->Magnitude & = default;

template<typename T> inline
nhill::geometry::Magnitude<T>::~Magnitude() noexcept = default;

template<typename T> inline
nhill::geometry::Magnitude<T>::operator T() const noexcept
{
   return value();
}

template<typename T> inline
T nhill::geometry::Magnitude<T>::value() const
{
   return value_;
}

template<typename T> inline
void nhill::geometry::Magnitude<T>::value( T val )
{
   validate( val );
   value_ = val;
}
template<typename T> inline 
bool nhill::geometry::Magnitude<T>::is_valid( T val )
{
   return nhill::math::greater_or_equal<T,uint8_t>( val, 0);
}
template<typename T> inline 
void nhill::geometry::Magnitude<T>::validate( T val ) const
{
   if( !is_valid( val ) )
   {
      throw std::invalid_argument( "The value = " + std::to_string( val ) + " is out of range: [0, infinity)." );
   }
}
#pragma endregion

