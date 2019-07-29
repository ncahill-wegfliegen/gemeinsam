#pragma once

#include "compare.h"
#include <cmath>

// https://stackoverflow.com/questions/16443682/c-power-of-integer-template-meta-programming

namespace gs
{
namespace math
{
namespace detail
{

template<typename T, uint8_t N>
struct pow_helper
{
   static constexpr T pow( const T x ) noexcept
   {
      return pow_helper<T, N - 1>::pow( x )*x;
   }
};

template< typename T>
struct pow_helper<T, 0>
{
   static constexpr T pow( const T x ) noexcept
   {
      return 1;
   }
};

}
}
}


namespace gs
{
namespace math
{

template<typename T, uint8_t N, typename enable_if::is_math_type<T>* = nullptr>
constexpr T pow( const T x ) noexcept
{
   return detail::pow_helper<T, N>::pow( x );
}


template<typename T, typename enable_if::is_math_type<T>* = nullptr>
constexpr T pow( const T x, int8_t n ) noexcept
{
   Sign s{ sign<int8_t>( n ) };
   int8_t nn{ static_cast<int8_t>(std::abs( n )) };
   T p{ (0 == nn) ? 1 : pow<T>( x, nn - 1 )*x };
   if( s == Sign::neg )
   {
      p = static_cast<T>(1) / p;
   }
   return p;
}


template<typename T, typename enable_if::is_math_type<T>* ef>
constexpr T floor_pow_of_ten( T x, /*Out, Optional*/ int8_t* n  ) noexcept;

template<typename T, typename enable_if::is_math_type<T>* = nullptr>
constexpr T ceil_pow_of_ten( T x, /*Out, Optional*/ int8_t* n = nullptr ) noexcept
{
   Sign s = sign( x );
   x = std::abs( x );
   if( s == Sign::neg )
   {
      return -floor_pow_of_ten<T>( x, n );
   }

   int8_t nn{ static_cast<int8_t>( std::ceil( std::log10( x ) ) )};
   if( n != nullptr )
   {
      *n = nn;
   }

   T p{ pow_of_ten<T>( nn ) };
   return p;
}

template<typename T, typename enable_if::is_math_type<T>* = nullptr>
constexpr T floor_pow_of_ten( T x, /*Out, Optional*/ int8_t* n = nullptr ) noexcept
{
   Sign s = sign( x );
   x = std::abs( x );
   if( s == Sign::neg )
   {
      return -ceil_pow_of_ten<T>( x, n );
   }

   int8_t nn{ static_cast<int8_t>( std::floor( std::log10( x ) ) )};
   if( n != nullptr )
   {
      *n = nn;
   }

   T p{ pow_of_ten<T>( nn ) };
   return p;
}

template<typename T, typename enable_if::is_math_type<T>* = nullptr>
constexpr uint8_t first_digit( T x ) noexcept
{
   x = static_cast<T>( std::abs( x ) );

   // https://www.geeksforgeeks.org/find-first-last-digits-number/
   // Remove the last digit from the number
   // until only one digit is left
   if( less<T, T>( x, 1 ) )
   {
      while( less<T, T>( x, 1 ) )
      {
         x *= 10;
      }
   }
   else
   {
      while( greater_or_equal<T, T>( x, 10 ) )
      {
         x /= 10;
      }
   }

   return static_cast<uint8_t>(x);
}

template<typename T, typename enable_if::is_math_type<T>* ef>
constexpr T floor_dEn( T x, /*Out, Optional*/ int8_t* n  ) noexcept;

/// <summary>The smallest number of the form dx10^n, that is greater than the given number.
///   <para>Where d is the first digit of the given number and n is a power.</para>
/// </summary>
/// <remarks>8645.34 --> 9000
///   <para>-8645.34 --> -8000</para>
/// </remarks>
template<typename T, typename enable_if::is_math_type<T>* = nullptr>
constexpr T ceil_dEn( T x, /*Out, Optional*/ int8_t* n = nullptr ) noexcept
{
   Sign s{ sign( x ) };
   T xx = static_cast<T>(std::abs( x ));
   if( s == Sign::neg )
   {
      return -floor_dEn( xx, n );
   }

   uint8_t d{ first_digit<T>( xx ) };
   T p = floor_pow_of_ten<T>( xx, n );
   xx = d * p;

   if( !equal<T, T>( x, xx ) ) // is boundary value?
   {
      ++d;
      xx = d * p;
   }

   return xx;
}

/// <summary>The largest number of the form dx10^n, that is less than the given number.
///   <para>Where d is the first digit of the given number and n is a power.</para>
/// </summary>
/// <remarks>8645.34 --> 8000
///   <para>-8645.34 --> -9000</para>
/// </remarks>
template<typename T, typename enable_if::is_math_type<T>* = nullptr>
constexpr T floor_dEn( T x, /*Out, Optional*/ int8_t* n = nullptr ) noexcept
{
   Sign s{ sign( x ) };
   x = static_cast<T>( std::abs( x ) );
   if( s == Sign::neg )
   {
      return -ceil_dEn( x, n );
   }
   
   uint8_t d{ first_digit<T>( x ) };
   x = floor_pow_of_ten<T>( x, n );
   x *= d;


   return x;
}

/// <summary>The smallest number of either the form dx10^n or d5x10n, that is greater than the given number.
///   <para>Where d is the first digit of the given number and n is a power.</para>
/// </summary>
/// <remarks>8645.34 --> 9000
///   <para>8465.34 --> 8500</para>
///   <para>-8645.34 --> -8500</para>
///   <para>-8465.34 --> -8000</para>
/// </remarks>
template<typename T, typename enable_if::is_math_type<T>* = nullptr>
constexpr T ceil_d5En( T x, /*Out, Optional*/ int8_t* n = nullptr ) noexcept
{
   int8_t nn{ 0 };
   T xx = floor_dEn<T>( x, &nn );
   T xxx{ xx + 5 * pow_of_ten<T>( nn - 1 ) };

   if( greater<T, T>( x, xxx ) )
   {
      xxx = ceil_dEn( x, &nn );
   }

   if( n != nullptr )
   {
      *n = nn;
   }

   return xxx;
}

/// <summary>The largest number of either the form dx10^n or d5x10n, that is greater than the given number.
///   <para>Where d is the first digit of the given number and n is a power.</para>
/// </summary>
/// <remarks>8645.34 --> 8500
///   <para>8465.34 --> 8000</para>
///   <para>-8645.34 --> -9000</para>
///   <para>-8465.34 --> -8500</para>
/// </remarks>
template<typename T, typename enable_if::is_math_type<T>* = nullptr>
constexpr T floor_d5En( T x, /*Out, Optional*/ int8_t* n = nullptr ) noexcept
{
   Sign s{ sign( x ) };
   x = static_cast<T>(std::abs( x ));
   if( s == Sign::neg )
   {
      return -ceil_d5En( x, n );
   }

   int8_t nn{ 0 };
   T xx = floor_dEn<T>( x, &nn );
   T xxx{ xx + 5 * pow_of_ten<T>( nn - 1 ) };

   if( n != nullptr )
   {
      *n = nn;
   }

   if( less<T, T>( x, xxx ) )
   {
      xxx = xx;
   }

   return xxx;
}




}
}