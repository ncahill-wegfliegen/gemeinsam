#pragma once

#include "precision.h"
#include "sign.h"
#include "..\utility\enable_if.h"
#include <algorithm>
#include <limits>

// http://realtimecollisiondetection.net/blog/?p=89
// https://stackoverflow.com/questions/5416414/signed-unsigned-comparisons


namespace nhill
{
namespace math
{
// https://randomascii.wordpress.com/2012/02/25/comparing-floating-point-numbers-2012-edition/
// https://stackoverflow.com/questions/40249504/sign-mantissa-and-exponent-of-a-double


template<typename T>
struct Floating_point_limits
{
   static constexpr int wman{0};
   [[nodiscard]] static constexpr int width_mantisa() noexcept { return 0; }
   [[nodiscard]] static constexpr int width_exponent() noexcept { return 0; }
   [[nodiscard]] static constexpr int width_sign() noexcept { return 0; }

   using sint = int;      // signed integer type
   using uint = unsigned; // unsigned integer type
};

template<>
struct Floating_point_limits<double>
{
   static constexpr int wman{std::numeric_limits<double>::digits - 1};
   [[nodiscard]] static constexpr int width_mantisa() noexcept { return std::numeric_limits<double>::digits - 1; } // 52
   [[nodiscard]] static constexpr int width_exponent() noexcept { return 64 - 1 - width_mantisa(); } // 11
   [[nodiscard]] static constexpr int width_sign() noexcept { return 1; } // 1

   using sint = int64_t;  // signed integer type
   using uint = uint64_t; // unsigned integer type;
};

template<>
struct Floating_point_limits<float>
{
   static constexpr int wman{std::numeric_limits<float>::digits - 1};
   [[nodiscard]] static constexpr int width_mantisa() noexcept { return std::numeric_limits<float>::digits - 1; } // 23
   [[nodiscard]] static constexpr int width_exponent() noexcept { return 32 - 1 - width_mantisa(); } // 8
   [[nodiscard]] static constexpr int width_sign() noexcept { return 1; } // 1

   using sint = int32_t;  // signed integer type
   using uint = uint32_t; // unsigned integer type
};


template<typename T, typename nhill::enable_if::is_float_type<T>* = nullptr>
union Floating_point_type
{
   using sint = typename Floating_point_limits<T>::sint;
   static constexpr sint man{typename Floating_point_limits<T>::width_mantisa()};

   Floating_point_type( T num = {0} ) : f( num ) {}
   // Portable extraction of components.
   bool negative() const { return i < 0; }
   sint raw_mantissa() const { return i & ((1 << man) - 1); }
   sint raw_exponent() const { return (i >> man) & 0xFF; }

   sint i;
   T f;
};

/// <summary>Almost equal (absolute comparison).</summary>
template<typename T, typename nhill::enable_if::is_float_type<T>* = nullptr>
bool almost_equal_abs( T a, T b, T max_diff = std::numeric_limits<T>::epsilon() )
{
   T diff{std::fabs( a - b )};

   return diff <= max_diff;
}

/// <summary>Almost equal (relative comparison).</summary>
template<typename T, typename nhill::enable_if::is_float_type<T>* = nullptr>
bool almost_equal_rel( T a, T b, T max_diff = std::numeric_limits<T>::epsilon() )
{
   // Assumes that almost_equal_abs has already been checked

   T largest{b > a ? b : a};
   T diff{std::fabs( a - b )};

   a = std::fabs( a );
   b = std::fabs( b );

   return diff <= largest * max_diff;
}

/// <summary>Almost equal (units in last place comparison).</summary>
template<typename T, typename nhill::enable_if::is_float_type<T>* = nullptr>
bool almost_equal_ulp( T a, T b, int max_diff = 1 )
{
   // Assumes that almost_equal_abs has already been checked

   Floating_point_type<T> fpa{a};
   Floating_point_type<T> fpb{b};

   // Different signs means they do not match.
   if( fpa.negative() != fpb.negative() )
   {
      // Check for equality to make sure +0==-0
      return (a == b);
   }

   // Find the difference in ULPs.
   int diff = static_cast<int>(std::abs( fpa.i - fpb.i ));
   return diff <= max_diff;
}

}
}

namespace nhill
{
namespace math
{

template<typename T, typename U, typename std::enable_if_t<sizeof( T ) >= sizeof( U )>* = nullptr>
bool equal( typename std::enable_if_t<enable_if::is_math_fp<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_fp<U>::value, U> y ) noexcept
{
   if( almost_equal_abs( x, y ) )
   {
      return true;
   }
   else if( almost_equal_rel( x, y ) )
   {
      return true;
   }
   else if( almost_equal_ulp( x, y ) )
   {
      return true;
   }
   else
   {
      return false;
   }
}

template<typename T, typename U, typename std::enable_if_t<sizeof( T ) < sizeof( U )>* = nullptr>
bool equal( typename std::enable_if_t<enable_if::is_math_fp<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_fp<U>::value, U> y ) noexcept
{
   return equal<U, T>( y, x );
}

template<typename T, typename U>
bool equal( typename std::enable_if_t<enable_if::is_math_fp<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_sint<U>::value, U> y ) noexcept
{
   T ty{ static_cast<T>(y) };
   return equal<T, T>( x, ty );
}

template<typename T, typename U>
bool equal( typename std::enable_if_t<enable_if::is_math_fp<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_uint<U>::value, U> y ) noexcept
{
   T ty{ static_cast<T>(y) };
   return equal<T, T>( x, ty );
}



template<typename T, typename U>
constexpr bool equal( typename std::enable_if_t<enable_if::is_math_sint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_sint<U>::value, U> y ) noexcept
{
   return x == y;
}

template<typename T, typename U>
constexpr bool equal( typename std::enable_if_t<enable_if::is_math_sint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_uint<U>::value, U> y ) noexcept
{
   return (x < 0) ? false : (x == y);
}

template<typename T, typename U>
bool equal( typename std::enable_if_t<enable_if::is_math_sint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_fp<U>::value, U> y ) noexcept
{
   U ux{ static_cast<U>(x) };
   return equal<U, U>( ux, y );
}



template<typename T, typename U>
constexpr bool equal( typename std::enable_if_t<enable_if::is_math_uint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_sint<U>::value, U> y ) noexcept
{
#pragma warning(suppress:4018) // signed/unsigned mismatch
   return (y < 0) ? false : (x < y);
}

template<typename T, typename U>
constexpr bool equal( typename std::enable_if_t<enable_if::is_math_uint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_uint<U>::value, U> y ) noexcept
{
   return x < y;
}

template<typename T, typename U>
bool equal( typename std::enable_if_t<enable_if::is_math_uint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_fp<U>::value, U> y ) noexcept
{
   U ux{ static_cast<U>(x) };
   return equal<U, U>( ux, y );
}




template<typename T, typename enable_if::is_math_type<T>* = nullptr>
constexpr bool zero( T x ) noexcept
{
   return equal<T, uint8_t>( x, 0U );
}







template<typename T, typename U>
constexpr bool less( typename std::enable_if_t<enable_if::is_math_sint<T>::value,T> x, typename std::enable_if_t<enable_if::is_math_sint<U>::value, U> y ) noexcept
{
   return x < y;
}

template<typename T, typename U>
constexpr bool less( typename std::enable_if_t<enable_if::is_math_sint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_uint<U>::value, U> y ) noexcept
{
#pragma warning(suppress:4018) // signed/unsigned mismatch
   return ( x < 0 ) ? true : (x < y);
}

template<typename T, typename U>
bool less( typename std::enable_if_t<enable_if::is_math_sint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_fp<U>::value, U> y ) noexcept
{
   return (!equal<T,U>(x,y)) && (x < y);
}




template<typename T, typename U>
constexpr bool less( typename std::enable_if_t<enable_if::is_math_uint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_sint<U>::value, U> y ) noexcept
{
#pragma warning(suppress:4018) // signed/unsigned mismatch
   return (y < 0) ? false : (x < y);
}

template<typename T, typename U>
constexpr bool less( typename std::enable_if_t<enable_if::is_math_uint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_uint<U>::value, U> y ) noexcept
{
   return x < y;
}

template<typename T, typename U>
bool less( typename std::enable_if_t<enable_if::is_math_uint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_fp<U>::value, U> y ) noexcept
{
   return (!equal<T,U>(x,y)) && ( !zero<U>(y) && (y < 0) ? false : (x < y) );
}




template<typename T, typename U>
bool less( typename std::enable_if_t<enable_if::is_math_fp<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_sint<U>::value, U> y ) noexcept
{
   return (!equal<T, U>( x, y )) && (x < y);
}

template<typename T, typename U>
bool less( typename std::enable_if_t<enable_if::is_math_fp<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_uint<U>::value, U> y ) noexcept
{
   return (!equal<T,U>(x,y)) && ( !zero<T>(x) && (x < 0) ? true : (x < y));
}

template<typename T, typename U>
bool less( typename std::enable_if_t<enable_if::is_math_fp<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_fp<U>::value, U> y ) noexcept
{
   return (!equal<T, U>( x, y )) && (x < y);
}



template<typename T, typename U>
constexpr bool greater( typename std::enable_if_t<enable_if::is_math_sint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_sint<U>::value, U> y ) noexcept
{
   return x > y;
}

template<typename T, typename U>
constexpr bool greater( typename std::enable_if_t<enable_if::is_math_sint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_uint<U>::value, U> y ) noexcept
{
#pragma warning(suppress:4018) // signed/unsigned mismatch
   return (x < 0) ? false : (x > y);
}

template<typename T, typename U>
bool greater( typename std::enable_if_t<enable_if::is_math_sint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_fp<U>::value, U> y ) noexcept
{
   return (!equal<T, U>( x, y )) && (x > y);
}




template<typename T, typename U>
constexpr bool greater( typename std::enable_if_t<enable_if::is_math_uint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_sint<U>::value, U> y ) noexcept
{
   return (y < 0) ? true : (x > y);
}

template<typename T, typename U>
constexpr bool greater( typename std::enable_if_t<enable_if::is_math_uint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_uint<U>::value, U> y ) noexcept
{
   return x > y;
}

template<typename T, typename U>
bool greater( typename std::enable_if_t<enable_if::is_math_uint<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_fp<U>::value, U> y ) noexcept
{
   return (!equal<T,U>(x,y)) && ( !zero<U>(y) && (y < 0) ? true : (x > y));
}




template<typename T, typename U>
bool greater( typename std::enable_if_t<enable_if::is_math_fp<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_sint<U>::value, U> y ) noexcept
{
   return !equal<T, U>( x, y ) && (x > y);
}

template<typename T, typename U>
bool greater( typename std::enable_if_t<enable_if::is_math_fp<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_uint<U>::value, U> y ) noexcept
{
   return (!equal<T,U>(x,y)) && ( !zero<T>(x) && (x < 0) ? false : (x > y));
}

template<typename T, typename U>
bool greater( typename std::enable_if_t<enable_if::is_math_fp<T>::value, T> x, typename std::enable_if_t<enable_if::is_math_fp<U>::value, U> y ) noexcept
{
   return (!equal<T, U>( x, y )) && (x > y);
}





template<typename T, typename U, typename enable_if::is_math_type<T>* = nullptr, typename enable_if::is_math_type<U>* = nullptr>
constexpr bool less_or_equal( T x, U y )  noexcept
{
   return less<T, U>( x, y ) || equal<T, U>( x, y );
}

template<typename T, typename U, typename enable_if::is_math_type<T>* = nullptr, typename enable_if::is_math_type<U>* = nullptr>
constexpr bool greater_or_equal( T x, U y ) noexcept
{
   return greater<T, U>( x, y ) || equal<T, U>( x, y );
}


template<typename T, typename U, typename enable_if::is_math_type<T>* = nullptr, typename enable_if::is_math_type<U>* = nullptr>
constexpr int compare( T x, U y ) noexcept
{
   return less<T,U>( x, y ) ? -1 : greater<T, U>( x, y ) ? 1 : 0;
}




template<typename T, typename enable_if::is_math_type<T>* = nullptr>
constexpr Sign sign( T x ) noexcept
{
   T z{0};
   return less<T, T>( x, z ) ? Sign::neg : Sign::pos;
}



template<typename T, typename U>
struct Compare_greater 
{
   constexpr bool operator()( T v1, U v2 ) const noexcept
   {
      return greater<T, U>( v1, v2 );
   }
};

template<typename T, typename U>
struct Compare_greater_or_equal 
{
   constexpr bool operator()( T v1, U v2 ) const noexcept
   {
      return greater_or_equal<T, U>( v1, v2 );
   }
};

template<typename T, typename U>
struct Compare_less 
{
   constexpr bool operator()( T v1, U v2 ) const noexcept
   {
      return less<T, U>( v1, v2 );
   }
};

template<typename T, typename U>
struct Compare_less_or_equal 
{
   constexpr bool operator()( T v1, U v2 ) const noexcept
   {
      return less_or_equal<T, U>( v1, v2 );
   }
};

}
}




