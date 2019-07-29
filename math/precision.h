#pragma once

#include "pow_of_ten.h"
#include "..\utility\enable_if.h"

namespace nhill
{
namespace math
{

template<typename T, typename enable_if::is_math_int_type<T>* = nullptr>
constexpr uint8_t precision_default() noexcept
{
   return 0;
}

template<typename T, typename enable_if::is_math_fp_type<T>* = nullptr>
constexpr uint8_t precision_default() noexcept
{
   return std::numeric_limits<T>::digits10 - 1 ;
}


template<typename T, typename enable_if::is_math_type<T>* = nullptr>
class Precision
{
public:
   Precision() = delete;
   Precision( const Precision& ) = delete;
   Precision( Precision&& ) = delete;
   ~Precision() = delete;

public:
   Precision & operator=( const Precision& ) = delete;
   Precision& operator=( Precision&& ) = delete;

public:
   static uint8_t value() noexcept;
   static void value( uint8_t value ) noexcept;
   static void push( uint8_t value ) noexcept;
   static void pop() noexcept;

public:
   static T multiplier() noexcept;
   static T epsilon() noexcept;

private:
   static uint8_t value_;
   static uint8_t push_;
   static T multiplier_;
   static T epsilon_;
};


}
}


template<typename T, typename nhill::enable_if::is_math_type<T>* ef> 
uint8_t nhill::math::Precision<T, ef>::value_{ precision_default<T>() };

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> 
uint8_t nhill::math::Precision<T, ef>::push_{ precision_default<T>() };

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> 
T nhill::math::Precision<T, ef>::multiplier_{ pow_of_ten<T>( precision_default<T>() ) };

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> 
T nhill::math::Precision<T, ef>::epsilon_{ 1 / pow_of_ten<T>( precision_default<T>() ) };


template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
uint8_t nhill::math::Precision<T, ef>::value() noexcept
{
   return value_;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
void nhill::math::Precision<T, ef>::value( uint8_t value ) noexcept
{
   if( enable_if::is_math_fp<T>::value )
   {
      value_ = value;
      multiplier_ = nhill::math::pow_of_ten<T>( value_ );
      epsilon_ = 1 / multiplier_;
   }
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
void nhill::math::Precision<T, ef>::push( uint8_t value ) noexcept
{
   push_ = value_;
   Precision::value( value );
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
void nhill::math::Precision<T, ef>::pop() noexcept
{
   value( push_ );
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
T nhill::math::Precision<T, ef>::multiplier() noexcept
{
   return multiplier_;
}

template<typename T, typename nhill::enable_if::is_math_type<T>* ef> inline
T nhill::math::Precision<T, ef>::epsilon() noexcept
{
   return epsilon_;
}
