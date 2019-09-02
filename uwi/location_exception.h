#pragma once

#include "port.h"
#include "../utility/strn.h"
#include "../utility/compare.h"
#include <string>
#include <string_view>
#include <ostream>
#include <istream>
#include <memory>

namespace nhill
{
namespace uwi
{
namespace dls
{

class NHILL_UWI_PORT_CLASS Location_exception 
{
public:
	using Str = Strn<2>;

   Location_exception();

   Location_exception( std::string_view );
   Location_exception& operator=( std::string_view );

   template<size_t N> Location_exception( const char( &s )[N] );
   template<size_t N> Location_exception& operator=( const char( &s )[N] );

   Location_exception( int );
   Location_exception& operator=( int );

   Location_exception( const Location_exception& );
   Location_exception& operator=( const Location_exception& );

   Location_exception( Location_exception&& ) noexcept;
   Location_exception& operator=( Location_exception&& ) noexcept;

   ~Location_exception();

	std::string value() const noexcept;
   void value( std::string_view );

   int integer() const;
   void value( int );

   void clear();

   static bool is_valid( std::string_view s, std::string* error_msg = nullptr);
   static bool is_valid( int i, std::string* error_msg = nullptr );

	/// <summary>Beware! No checking and no validation.<para>Only use this if you are absolutely certian that the string is a valid two character DLS location exception.</para></summary>
	/// <exception cref="std::invalid_argument">Thrown if the length of the string is greater than two characters.</exception>
	void set_unchecked( std::string_view s ); 

private:
#pragma warning(suppress:4251)
	Str s_{};
};

}
}
}

namespace nhill
{
template<> NHILL_UWI_PORT_FUNCTION inline
Compare compare( const uwi::dls::Location_exception& a, const uwi::dls::Location_exception& b );

namespace uwi
{
namespace dls
{

NHILL_UWI_PORT_FUNCTION bool is_valid_location_exception( std::string_view s, std::string* error_msg = nullptr );
NHILL_UWI_PORT_FUNCTION bool is_valid_location_exception( int i, std::string* error_msg = nullptr );

NHILL_UWI_PORT_FUNCTION std::ostream& operator<<( std::ostream& out, const Location_exception& le );
NHILL_UWI_PORT_FUNCTION std::istream& operator>>( std::istream& in, Location_exception& le );

NHILL_UWI_PORT_FUNCTION bool operator==( const Location_exception& a, const Location_exception& b );
NHILL_UWI_PORT_FUNCTION bool operator!=( const Location_exception& a, const Location_exception& b );

NHILL_UWI_PORT_FUNCTION bool operator<( const Location_exception& a, const Location_exception& b );
NHILL_UWI_PORT_FUNCTION bool operator>( const Location_exception& a, const Location_exception& b );

NHILL_UWI_PORT_FUNCTION bool operator<=( const Location_exception& a, const Location_exception& b );
NHILL_UWI_PORT_FUNCTION bool operator>=( const Location_exception& a, const Location_exception& b );

}
}
}



template<size_t N>
inline nhill::uwi::dls::Location_exception::Location_exception( const char( &s )[N] )
	: Location_exception{&s[0]}
{
}

template<size_t N>
inline auto nhill::uwi::dls::Location_exception::operator=( const char( &s )[N] )->Location_exception &
{
	value( &s[0] );
	return *this;
}

