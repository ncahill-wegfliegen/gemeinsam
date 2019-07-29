#pragma once

#include <cmath>

namespace nhill
{
namespace math
{

template<typename T>
class Constants
{
public:
   static_assert(std::is_floating_point_v<T>, "The template parameter must be a floating point type: float, double, or long double.");

   static constexpr T e        () noexcept; // e          2.71828182845904523536
   static constexpr T log2e    () noexcept; // log2(e)    1.44269504088896340736 
   static constexpr T log10e   () noexcept; // log10(e)   0.434294481903251827651 
   static constexpr T ln2      () noexcept; // ln(2)      0.693147180559945309417  
   static constexpr T ln10     () noexcept; // ln(10)     2.30258509299404568402 
   static constexpr T pi       () noexcept; // pi         3.14159265358979323846
   static constexpr T pi_2     () noexcept; // pi/2       1.57079632679489661923
   static constexpr T pi_4     () noexcept; // pi/4       0.785398163397448309616
   static constexpr T _1_pi    () noexcept; // 1/pi       0.318309886183790671538
   static constexpr T _2_pi    () noexcept; // 2/pi       0.636619772367581343076
   static constexpr T _2_sqrtpi() noexcept; // 2/sqrt(pi) 1.12837916709551257390
   static constexpr T sqrt2    () noexcept; // sqrt(2)    1.41421356237309504880
   static constexpr T _1_sqrt2 () noexcept; // 1/sqrt(2)  0.707106781186547524401

   static constexpr T _60  () noexcept; // 60
   static constexpr T _1_60() noexcept; // 1/180

   static constexpr T _180  () noexcept; // 180
   static constexpr T _1_180() noexcept; // 1/180

   static constexpr T _360  () noexcept; // 360
   static constexpr T _1_360() noexcept; // 1/360

   static constexpr T pi_180 () noexcept; // pi/180
   static constexpr T _180_pi() noexcept; // 180/pi

   static constexpr T _2pi_360() noexcept; // 2*pi/360
   static constexpr T _360_2pi() noexcept; // 360/(2*pi)
};

}
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::e() noexcept
{
   return static_cast<T>(M_E);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::log2e() noexcept
{
   return static_cast<T>(M_LOG2E);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::log10e() noexcept
{
   return static_cast<T>(M_LOG10E);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::ln2() noexcept
{
   return static_cast<T>(M_LN2);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::ln10() noexcept
{
   return static_cast<T>(M_LN10);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::pi() noexcept
{
   return static_cast<T>(M_PI);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::pi_2() noexcept
{
   return static_cast<T>(M_PI_2);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::pi_4() noexcept
{
   return static_cast<T>(M_PI_4);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::_1_pi() noexcept
{
   return static_cast<T>(M_1_PI);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::_2_pi() noexcept
{
   return static_cast<T>(M_2_PI);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::_2_sqrtpi() noexcept
{
   return static_cast<T>(M_2_SQRTPI);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::sqrt2() noexcept
{
   return static_cast<T>(M_SQRT2);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::_1_sqrt2() noexcept
{
   return static_cast<T>(M_SQRT1_2);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::_60() noexcept
{
   return static_cast<T>(60);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::_1_60() noexcept
{
   return static_cast<T>(0.0166666666666666666667);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::_180() noexcept
{
   return static_cast<T>(180);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::_1_180() noexcept
{
   return static_cast<T>(0.00555555555555555555556);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::_360() noexcept
{
   return static_cast<T>(360);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::_1_360() noexcept
{
   return static_cast<T>(0.00277777777777777777778);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::pi_180() noexcept
{
   return static_cast<T>(0.0174532925199432957692);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::_180_pi() noexcept
{
   return static_cast<T>(57.2957795130823208778);
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::_2pi_360() noexcept
{
   return nhill::math::Constants<T>::pi_180();
}

template<typename T>
inline constexpr T nhill::math::Constants<T>::_360_2pi() noexcept
{
   return nhill::math::Constants<T>::_180_pi();
}
