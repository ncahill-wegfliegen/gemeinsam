#pragma once

#include "pnt.h"
#include <cstdint>

namespace nhill
{
namespace geometry
{

template<typename T = double>
struct Rect
{
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type (i.e., either integral or floating point type).");

   using value_type = T;

   T left;
   T bottom;

   T right;
   T top;
};
}
}

namespace nhill
{
namespace geometry
{

using Rectf  = Rect<float>;
//using Rect   = Rect<double>;
using Rectld = Rect<long double>;

using Recti = Rect<int>;
using Recti8 = Rect<int8_t>;
using Recti16 = Rect<int16_t>;
using Recti32 = Rect<int32_t>;
using Recti64 = Rect<int64_t>;

using Rectu = Rect<unsigned>;
using Rectu8  = Rect<uint8_t>;
using Rectu16 = Rect<uint16_t>;
using Rectu32 = Rect<uint32_t>;
using Rectu64 = Rect<uint64_t>;

}
}

namespace nhill
{
namespace geometry
{

template<typename T> inline
auto get_left_bottom( const Rect<T> & rect ) noexcept->Pnt<T>
{
   return {rect.left, rect.bottom};
}

template<typename T> inline
auto get_right_top( const Rect<T> & rect ) noexcept->Pnt<T>
{
   return {rect.right, rect.top};
}

template<typename T, std::enable_if_t<std::is_integral_v<T>>* = nullptr> inline
T get_width( const Rect<T> & rect ) noexcept
{
   return std::abs( rect.right - rect.left );
}

template<typename T, std::enable_if_t<std::is_floating_point_v<T>>* = nullptr> inline
T get_width( const Rect<T> & rect ) noexcept
{
   return std::fabs( rect.right - rect.left );
}

template<typename T, std::enable_if_t<std::is_integral_v<T>>* = nullptr> inline
T get_height( const Rect<T> & rect ) noexcept
{
   return std::abs( rect.top - rect.bottom );
}

template<typename T, std::enable_if_t<std::is_floating_point_v<T>>* = nullptr> inline
T get_height( const Rect<T> & rect ) noexcept
{
   return std::fabs( rect.top - rect.bottom );
}

template<typename T> inline
Pnt<T> get_size( const Rect<T>& rect ) noexcept
{
   return {get_width<T>( rect ), get_height<T>( rect )};
}

}
}