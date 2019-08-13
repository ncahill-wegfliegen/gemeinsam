#pragma once

#include "../utility/enable_if.h"
#include <cmath>

// https://stackoverflow.com/questions/16443682/c-power-of-integer-template-meta-programming

namespace nhill
{
namespace math
{
namespace detail
{

template<typename T, uint8_t N>
struct pow_of_ten_helper
{
   static constexpr T pow_of_ten() noexcept
   {
      return pow_of_ten_helper<T, N - 1>::pow_of_ten()*10;
   }
};

template< typename T>
struct pow_of_ten_helper<T, 0>
{
   static constexpr T pow_of_ten() noexcept
   {
      return 1;
   }
};

}
}
}


namespace nhill
{
namespace math
{


template<typename T, uint8_t N, typename enable_if::is_math_type<T>* = nullptr>
constexpr T pow_of_ten() noexcept
{
   return detail::pow_of_ten_helper<T, N>::pow_of_ten();
}


template<typename T, typename enable_if::is_math_type<T>* = nullptr>
constexpr T pow_of_ten( int8_t n ) noexcept
{
   int8_t nn{ (n < 0 ? -n : n) };
   T p{ (0 == nn) ? 1 : pow_of_ten<T>( nn - 1 )*10 };
   if( n < 0 )
   {
      p = static_cast<T>(1) / p;
   }
   return p;
}


}
}