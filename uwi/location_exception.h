#pragma once

#include "port.h"
#include "../utility/compare.h"
#include <string>
#include <ostream>
#include <istream>

namespace nhill
{
namespace uwi
{
namespace dls
{

class NHILL_UWI_PORT_CLASS Location_exception
{
public:
   Location_exception();

   Location_exception( const char* );
   Location_exception& operator=( const char* );

   Location_exception( int );
   Location_exception& operator=( int );

   Location_exception( const Location_exception& );
   Location_exception& operator=( const Location_exception& );

   Location_exception( Location_exception&& ) noexcept;
   Location_exception& operator=( Location_exception&& ) noexcept;

   ~Location_exception();

   operator const char* () const;
   operator int() const;

	const char* value() const;
	void value( const char* );

	int ivalue() const;
	void value( int );

   void clear();

   static bool is_valid( const char* s, std::string* error_msg = nullptr);
   static bool is_valid( int i, std::string* error_msg = nullptr );

private:
	char s_[3]{};
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

NHILL_UWI_PORT_FUNCTION bool is_valid_location_exception( const char* s, std::string* error_msg = nullptr );
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
