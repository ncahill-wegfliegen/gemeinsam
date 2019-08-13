#pragma once

#include "../math/compare.h"

namespace nhill
{
namespace geometry
{

/// <summary>Floating point radian angle.</summary>
template<typename T = double>
class Radian
{
public:
   static_assert(std::is_floating_point_v<T>, "The template parameter must be a floating point type: float, double, or long double.");
   using value_type = T;

   Radian( T = 0 ) noexcept;
   Radian& operator=( T ) noexcept;

   Radian( const Radian& ) noexcept;
   Radian& operator=( const Radian& ) noexcept;

   Radian( Radian&& ) noexcept;
   Radian& operator=( Radian&& ) noexcept;

   ~Radian() noexcept;

   operator T() const noexcept;

   T value() const;
   void value( T );

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

using Radianf  = Radian<float>;
//using Radian   = RadianT<double>;
using Radianld = Radian<long double>;

}
}
#pragma endregion

#pragma region Operators
namespace nhill
{
namespace geometry
{



template<typename T> inline
bool operator==( const Radian<T>& a, const Radian<T>& b ) noexcept
{
   return nhill::math::equal<T, T>( a.value(), b.value() );
}

template<typename T> inline
bool operator!=( const Radian<T>& a, const Radian<T>& b ) noexcept
{
   return !(a == b);
}

template<typename T> inline
bool operator>( const Radian<T>& a, const Radian<T>& b ) noexcept
{
   return math::greater<T, T>( a.value(), b.value() );
}

template<typename T> inline
bool operator>=( const Radian<T>& a, const Radian<T>& b ) noexcept
{
   return math::greater_or_equal<T, T>( a.value(), b.value() );
}

template<typename T> inline
bool operator<( const Radian<T>& a, const Radian<T>& b ) noexcept
{
   return math::less<T, T>( a.value(), b.value() );
}

template<typename T> inline
bool operator<=( const Radian<T>& a, const Radian<T>& b ) noexcept
{
   return math::less_or_equal<T, T>( a.value(), b.value() );
}

template<typename T> inline
auto operator+( const Radian<T>& a, const Radian<T>& b ) noexcept->Radian<T>
{
   return {a.value() + b.value()};
}

template<typename T> inline
auto operator-( const Radian<T>& a, const Radian<T>& b ) noexcept->Radian<T>
{
   return {a.value() - b.value()};
}


template<typename T> inline
auto operator+=( const Radian<T>& a, const Radian<T>& b ) noexcept->Radian<T> &
{
   a = (a.value() + b.value());
   return *this;
}

template<typename T> inline
auto operator-=( const Radian<T>& a, const Radian<T>& b ) noexcept->Radian<T> &
{
   a = (a.value() - b.value());
   return *this;
}

template<typename T> inline
auto operator*( T a, const Radian<T>& b ) noexcept->Radian<T>
{
   return {a * b.value()};
}
template<typename T> inline
auto operator*( const Radian<T>& a, T b  ) noexcept->Radian<T>
{
   return {a.value() * b};
}

template<typename T> inline
auto operator*=( Radian<T>& a, T b ) noexcept->Radian<T> &
{
   a = (a.value() * b);
   return *this;
}

}
}
#pragma endregion

#pragma region Definitions
template<typename T> inline
nhill::geometry::Radian<T>::Radian( T value ) noexcept
   : value_{value}
{
}

template<typename T> inline
auto nhill::geometry::Radian<T>::operator=( T value ) noexcept->Radian &
{
   value_ = value;
   return *this;
}

template<typename T> inline
nhill::geometry::Radian<T>::Radian( const Radian & ) noexcept = default;

template<typename T> inline
auto nhill::geometry::Radian<T>::operator=( const Radian & other ) noexcept->Radian & = default;

template<typename T> inline
nhill::geometry::Radian<T>::Radian( Radian && ) noexcept = default;

template<typename T> inline
auto nhill::geometry::Radian<T>::operator=( Radian && ) noexcept->Radian& = default;

template<typename T> inline
nhill::geometry::Radian<T>::~Radian() noexcept = default;

template<typename T> inline
nhill::geometry::Radian<T>::operator T() const noexcept
{
   return value();
}

template<typename T> inline
T nhill::geometry::Radian<T>::value() const
{
   return value_;
}

template<typename T> inline
void nhill::geometry::Radian<T>::value( T val)
{
   return value_ = val;
}
#pragma endregion

