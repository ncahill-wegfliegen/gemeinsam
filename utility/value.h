#pragma once

#include "..\math\compare.h"
#include <type_traits>
#include <string>
#include <sstream>
#include <string_view>

namespace nhill
{
namespace utility
{

template<typename T>
struct Value_validator
{
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type (integral or floating point).");

	virtual T operator()( T value ) const = 0;

   struct Default : public Value_validator<T>
   {
		T operator()( T value ) const override
		{
			return value;
		}
   };

   using default_type = Default;
};

template<typename T, typename Validator = typename Value_validator<T>::default_type >
class Value
{
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type (integral or floating point).");
   static_assert(std::is_base_of_v<Value_validator<T>, Validator>, "The validator must be derived from Value_validator.");

public:
   using value_type = T;
   using validator_type = Validator;

   Value( T = 0 );
   Value& operator=( T );

   Value( const Value& );
   Value& operator=( const Value& );

   Value( Value&& );
   Value& operator=( Value&& );

   virtual ~Value();

   operator T() const;

   T value() const;
   void value( T );

   std::string to_string() const;
   bool parse( std::string_view str );

private:
   T value_;
};


}
}

#pragma region Operators
namespace nhill 
{
namespace utility
{

template<typename T, typename Validator >
std::istream & operator>>( std::istream & is, Value<T, Validator> & value )
{
   T v;
   is >> v;
   value.value( v );
   return is;
}

}
}
#pragma endregion

#pragma region Definitions
template<typename T, typename Validator>
inline nhill::utility::Value<T, Validator>::Value( T val )
{
   value( val );
}

template<typename T, typename Validator>
inline auto nhill::utility::Value<T, Validator>::operator=( T val )->Value &
{
   value( val );
   return *this;
}

template<typename T, typename Validator>
inline nhill::utility::Value<T, Validator>::Value( const Value& ) = default;

template<typename T, typename Validator>
inline auto nhill::utility::Value<T, Validator>::operator=( const Value& )->Value & = default;

template<typename T, typename Validator>
inline nhill::utility::Value<T, Validator>::Value( Value&& ) = default;

template<typename T, typename Validator>
inline auto nhill::utility::Value<T, Validator>::operator=( Value&& )->Value & = default;

template<typename T, typename Validator>
inline nhill::utility::Value<T, Validator>::~Value() = default;

template<typename T, typename Validator>
inline nhill::utility::Value<T, Validator>::operator T() const
{
   return value();
}

template<typename T, typename Validator>
inline T nhill::utility::Value<T, Validator>::value() const
{
   return value_;
}

template<typename T, typename Validator>
inline void nhill::utility::Value<T, Validator>::value( T value )
{
   Validator validator;
	value_ = validator( value );
}

template<typename T, typename Validator>
inline std::string nhill::utility::Value<T, Validator>::to_string() const
{
   std::ostringstream oss;
   oss << value();
   return oss.str();
}

template<typename T, typename Validator>
inline bool nhill::utility::Value<T, Validator>::parse( std::string_view str )
{
   std::stringstream iss;
   iss << str;
   iss >> *this;
}
#pragma endregion