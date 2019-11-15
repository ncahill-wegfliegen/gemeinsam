#pragma once

#include "port.h"
#include "../utility/compare.h"
#include "../utility/buffer.h"
#include "../enum/survey_system.h"
#include <string_view>
#include <ostream>
#include <istream>

namespace nhill
{
namespace uwi
{
class Dls;
class Nts;
}

class NHILL_UWI_PORT_CLASS Uwi
{
public:
	Uwi();

	Uwi( const uwi::Dls& dls );
	Uwi& operator=( const uwi::Dls& dls );

	//Uwi( const Nts& nts );
	//Uwi& operator=( const Nts& nts );

	/// <summary>Validate and convert to sort format (if necessary).</summary>
   Uwi( std::string_view );
	/// <summary>Validate and convert to sort format (if necessary).</summary>
	Uwi& operator=( std::string_view );

   Uwi( const Uwi& );
   Uwi& operator=( const Uwi& );

   Uwi( Uwi&& ) noexcept;
   Uwi& operator=( Uwi&& ) noexcept;

   ~Uwi();

	/// <summary>The survey system associated with the uwi.</summary>
   Survey_system survey_system() const;
	/// <summary>The uwi in the 'sort' format for the uwi type.</summary>
   const char* value() const;
	/// <summary>Validate and convert to sort format (if necessary).</summary>
	void value( std::string_view );

	/// <summary>The number of characters (not including null terminator).</summary>
	size_t length() const;
	/// <summary>The size of internal buffer (including null terminator): size = length + 1.</summary>
	size_t size() const;

	///  <summary>This method does NOT validate the string.
	///     <para>You have to be absolutely certain that the string is a valid uwi sort format.</para>
	/// </summary>
	/// <remarks>This method is provided for efficiency. It skips the validation for strings that are known to be in a valid sort format.</summary>
	void set_unchecked( std::string_view );

private:
	Buffer buf_{};
};

}

namespace nhill
{

template<> NHILL_UWI_PORT_FUNCTION
Compare compare( const Uwi& a, const Uwi& b ) noexcept;

NHILL_UWI_PORT_FUNCTION bool operator==( const Uwi& a, const Uwi& b );
NHILL_UWI_PORT_FUNCTION bool operator!=( const Uwi& a, const Uwi& b );

NHILL_UWI_PORT_FUNCTION bool operator<( const Uwi& a, const Uwi& b );
NHILL_UWI_PORT_FUNCTION bool operator>( const Uwi& a, const Uwi& b );

NHILL_UWI_PORT_FUNCTION bool operator<=( const Uwi& a, const Uwi& b );
NHILL_UWI_PORT_FUNCTION bool operator>=( const Uwi& a, const Uwi& b );

NHILL_UWI_PORT_FUNCTION std::istream& operator>>( std::istream& in, Uwi& uwi );
NHILL_UWI_PORT_FUNCTION std::ostream& operator<<( std::ostream& out, const Uwi& uwi );


}
