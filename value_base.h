
#pragma once

#include "value.h"
#include "../math/compare.h"
#include "../utility/compare.h"
#include "../enum/core/int.h"
#include <type_traits>
#include <string>
#include <string_view>
#include <sstream>
#include <istream>
#include <ostream>

namespace nhill
{
namespace utility
{

//template<typename T>
//class Value_validator
//{
//public:
//   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type (integral or floating point).");
//
//   using value_type = T;
//
//   Value_validator( T default_value = 0 )
//      : default_value{default_value}
//   { }
//
//   virtual T operator()( T value ) const = 0;
//   const T default_value;
//};
//
//template<typename T>
//class Default_value_validator final : public Value_validator<T>
//{
//public:
//   T operator()( T value ) const final
//   {
//      return value;
//   }
//};

template<typename T, typename Validator = typename Default_value_validator<T> >
class Value_base 
{
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type (integral or floating point).");
   static_assert(std::is_base_of_v<Value_validator<T>, Validator>, "The validator must be derived from Value_validator.");

public:
   using value_type = T;
   using validator_type = Validator;

   Value_base();

   template<typename U, typename std::enable_if_t<std::is_arithmetic_v<U>>* = nullptr> Value_base( U );
   template<typename U, typename std::enable_if_t<std::is_arithmetic_v<U>>* = nullptr> Value_base& operator=( U );

   Value_base( std::string_view );
   Value_base& operator=( std::string_view );

   Value_base( const Value_base& );
   Value_base& operator=( const Value_base& );

   Value_base( Value_base&& ) noexcept;
   Value_base& operator=( Value_base&& ) noexcept;

   virtual ~Value_base();

   operator T() const;
   explicit operator std::string() const;

   T value() const;
   template<typename U = T> typename std::enable_if_t<std::is_arithmetic_v<U>,U> value() const;
   template<typename U, typename std::enable_if_t<std::is_arithmetic_v<U>>* = nullptr> void value( U );

   std::string string() const;
   void value( std::string_view );

   void clear();

private:
   T value_;
};

}
}

#pragma region Operators
namespace nhill 
{

template<typename AT, typename AValidator, typename BT, typename BValidator> inline
Compare compare( const utility::Value_base<AT,AValidator>& a, const utility::Value_base<BT,BValidator>& b )
{
   return to_enum<Compare>( math::compare<AT, BT>( a.value(), b.value() ) );
}

namespace utility
{

template<typename AT, typename AValidator, typename BT, typename BValidator> inline
bool operator==( const Value_base<AT, AValidator>& a, const Value_base<BT, BValidator>& b )
{
   return compare<AT, AValidator, BT, BValidator>( a, b ) == Compare::equal;
}

template<typename AT, typename AValidator, typename BT, typename BValidator> inline
bool operator!=( const Value_base<AT, AValidator>& a, const Value_base<BT, BValidator>& b )
{
   return !(a == b);
}

template<typename AT, typename AValidator, typename BT, typename BValidator> inline
bool operator<( const Value_base<AT, AValidator>& a, const Value_base<BT, BValidator>& b )
{
   return compare<AT, AValidator, BT, BValidator>( a, b ) == Compare::less;
}

template<typename AT, typename AValidator, typename BT, typename BValidator> inline
bool operator>( const Value_base<AT, AValidator>& a, const Value_base<BT, BValidator>& b )
{
   return compare<AT, AValidator, BT, BValidator>( a, b ) == Compare::greater;
}

template<typename AT, typename AValidator, typename BT, typename BValidator> inline
bool operator<=( const Value_base<AT, AValidator>& a, const Value_base<BT, BValidator>& b )
{
   return !(a > b);
}

template<typename AT, typename AValidator, typename BT, typename BValidator> inline
bool operator>=( const Value_base<AT, AValidator>& a, const Value_base<BT, BValidator>& b )
{
   return !( a > b);
}


template<typename T, typename Validator, typename std::enable_if_t<std::is_integral_v<T>&& std::is_signed_v<T>>* = nullptr>
std::ostream& operator<<( std::ostream& os, Value_base<T, Validator>& value )
{
   os << static_cast<intmax_t>( value.value());
   return os;
}

template<typename T, typename Validator, typename std::enable_if_t<std::is_integral_v<T>&& std::is_unsigned_v<T>>* = nullptr>
std::ostream & operator<<( std::ostream & os, Value_base<T, Validator> & value )
{
   os << static_cast<uintmax_t>(value.value());
   return os;
}

template<typename T, typename Validator, typename std::enable_if_t<std::is_floating_point_v<T>>* = nullptr>
std::ostream & operator<<( std::ostream & os, Value_base<T, Validator> & value )
{
   os << static_cast<long double>(value.value());
   return os;
}

template<typename T, typename Validator, typename std::enable_if_t<std::is_integral_v<T> && std::is_signed_v<T>>* = nullptr>
std::istream & operator>>( std::istream & is, Value_base<T, Validator> & value )
{
   intmax_t v; // largest signed integer type
   is >> v;
   value.value<intmax_t>( v );
   return is;
}

template<typename T, typename Validator, typename std::enable_if_t<std::is_integral_v<T>&& std::is_unsigned_v<T>>* = nullptr>
std::istream & operator>>( std::istream & is, Value_base<T, Validator> & value )
{
   uintmax_t v; // largest unsigned integer typw
   is >> v;
   value.value<uintmax_t>( v );
   return is;
}

template<typename T, typename Validator, typename std::enable_if_t<std::is_floating_point_v<T>>* = nullptr>
std::istream & operator>>( std::istream & is, Value_base<T, Validator> & value )
{
   long double v; // largest floating point typw
   is >> v;
   value.value<long double>( v );
   return is;
}

template<typename T, typename Validator>
Value_base<T, Validator>& operator*=( Value_base<T, Validator>& a, T b )
{
   a.value<T>( a.value() * b );
   return a;
}

template<typename T, typename Validator>
Value_base<T, Validator>& operator*=( T a, Value_base<T, Validator>& b )
{
   b.value<T>( b.value() * a );
   return a;
}

template<typename T, typename Validator>
Value_base<T, Validator>& operator/=( Value_base<T, Validator>& a, T b )
{
   a.value<T>( a.value() / b );
   return a;
}

template<typename T, typename Validator>
Value_base<T, Validator>& operator/=( T a, Value_base<T, Validator>& b )
{
   b.value<T>( b.value() / a );
   return a;
}

}
}
#pragma endregion

#pragma region Definitions
template<typename T, typename Validator>
inline nhill::utility::Value_base<T, Validator>::Value_base()
{
   clear();
}

template<typename T, typename Validator>
template<typename U, typename std::enable_if_t<std::is_arithmetic_v<U>>* ef>
inline nhill::utility::Value_base<T, Validator>::Value_base( U val)
{
   value<U>( val );
}

template<typename T, typename Validator>
template<typename U, typename std::enable_if_t<std::is_arithmetic_v<U>>* ef>
inline auto nhill::utility::Value_base<T, Validator>::operator=(U val )->Value_base &
{
   value<U>( val );
   return *this;
}

template<typename T, typename Validator>
inline nhill::utility::Value_base<T, Validator>::Value_base( std::string_view  str)
{
   value( str );
}

template<typename T, typename Validator>
inline auto nhill::utility::Value_base<T, Validator>::operator=( std::string_view  str )->Value_base &
{
   value( str );
   return *this;
}

template<typename T, typename Validator>
inline nhill::utility::Value_base<T, Validator>::Value_base( const Value_base& ) = default;

template<typename T, typename Validator>
inline auto nhill::utility::Value_base<T, Validator>::operator=( const Value_base& )->Value_base & = default;

template<typename T, typename Validator>
inline nhill::utility::Value_base<T, Validator>::Value_base( Value_base&& ) noexcept = default;

template<typename T, typename Validator>
inline auto nhill::utility::Value_base<T, Validator>::operator=( Value_base&& ) noexcept->Value_base & = default;

template<typename T, typename Validator>
inline nhill::utility::Value_base<T, Validator>::~Value_base() = default;

template<typename T, typename Validator>
inline nhill::utility::Value_base<T, Validator>::operator T() const
{
   return value();
}

template<typename T, typename Validator>
inline nhill::utility::Value_base<T, Validator>::operator std::string() const
{
   return this->string();
}

template<typename T, typename Validator>
inline T nhill::utility::Value_base<T, Validator>::value() const
{
   return value_;
}

template<typename T, typename Validator>
template<typename U>
inline auto nhill::utility::Value_base<T, Validator>::value() const ->typename std::enable_if_t<std::is_arithmetic_v<U>, U>
{
   return static_cast<U>(value_);
}

template<typename T, typename Validator>
template<typename U, typename std::enable_if_t<std::is_arithmetic_v<U>>* ef>
inline void nhill::utility::Value_base<T, Validator>::value( U val )
{
   static const Validator validator;
   value_ = validator( static_cast<T>( val ) );
}

template<typename T, typename Validator>
inline std::string nhill::utility::Value_base<T, Validator>::string() const
{
   std::ostringstream oss;
   oss << value();
   return oss.str();
}

template<typename T, typename Validator>
inline void nhill::utility::Value_base<T, Validator>::value( std::string_view s )
{
   std::stringstream iss;
   iss << s;
   iss >> *this;
}

template<typename T, typename Validator>
inline void nhill::utility::Value_base<T, Validator>::clear()
{
   static const Validator validator;
   value_ = validator.default_value;
}
#pragma endregion