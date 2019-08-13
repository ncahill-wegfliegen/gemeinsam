#pragma once

#include "gs/util/enable_if.h"
#include <limits>

// http://realtimecollisiondetection.net/blog/?p=89

namespace gs
{
namespace math
{

template<typename T, typename enable_if::is_math_type<T>* = nullptr>
class Tolerance
{
private:
   Tolerance() = delete;
   Tolerance( const Tolerance& ) = delete;
   Tolerance( Tolerance&& ) = delete;
   ~Tolerance() = delete;

private:
   Tolerance& operator=( const Tolerance& ) = delete;
   Tolerance& operator=( Tolerance&& ) = delete;

public:
   static T absolute() { return abs_; }

   template<typename U, typename enable_if::is_math_int_type<U>* = nullptr>
   static void absolute( typename std::enable_if_t<std::is_same<U, T>::value, T> ) {}

   template<typename U, typename enable_if::is_math_fp_type<U>* = nullptr>
   static void absolute( typename std::enable_if_t<std::is_same<U, T>::value, T> value ) { abs_ = value; }



   static T relative() { return rel_; }

   template<typename U, typename enable_if::is_math_int_type<U>* = nullptr>
   static void relative( typename std::enable_if_t<std::is_same<U, T>::value, T> ) {}

   template<typename U, typename enable_if::is_math_fp_type<U>* = nullptr>
   static void relative( typename std::enable_if_t<std::is_same<U, T>::value, T> value ) { rel_ = value; }

private:
   static T abs_;
   static T rel_;
};

template<typename T, typename enable_if::is_math_type<T>* ef>
T Tolerance<T, ef>::abs_{ typename std::numeric_limits<T>::epsilon() /** static_cast<T>(50)*/ };

template<typename T, typename enable_if::is_math_type<T>* ef>
T Tolerance<T, ef>::rel_{ typename std::numeric_limits<T>::epsilon() /** static_cast<T>(50)*/ };

}
}