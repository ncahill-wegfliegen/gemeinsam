#include "uwi.h"
#include "../enum/survey_system_ex.h"
#include "dls.h"
#include <algorithm>

using namespace std;

namespace
{
using namespace nhill;
using namespace nhill::uwi;

/// <summary>This assumes that the test for 'plain' has already been done.</summary>
bool is_valid_dls( string_view str, Dls& dls )
{
   
   if( dls::is_full( str, &dls ) )
   {
      return true;
   }
   else if( dls::is_full_dressed( str, &dls ) )
   {
      return true;
   }
   else if( dls::is_sort( str, &dls ) )
   {
      return true;
   }
   else if( dls::is_full( str, &dls ) )
   {
      return true;
   }
   else if( dls::is_plain_dressed( str, &dls ) )
   {
      return true;
   }
   else
   {
      return false;
   }
}

}

nhill::Uwi::Uwi() = default;

nhill::Uwi::Uwi( const uwi::Dls& dls )
{
	set_unchecked( dls.sort() );
}

auto nhill::Uwi::operator=( const uwi::Dls& dls )->Uwi &
{
	set_unchecked( dls.sort() );
	return *this;
}


nhill::Uwi::Uwi( std::string_view str )
	: buf_{}
{
   value( str ); // validate and convert
}

auto nhill::Uwi::operator=( std::string_view str )->Uwi &
{
   value( str ); // validate and convert
   return *this;
}

nhill::Uwi::Uwi( const Uwi& other ) = default;
auto nhill::Uwi::operator=( const Uwi& other )->Uwi & = default;

nhill::Uwi::Uwi( Uwi&& other ) noexcept = default;
auto nhill::Uwi::operator=( Uwi&& other ) noexcept->Uwi & = default;

nhill::Uwi::~Uwi() = default;

auto nhill::Uwi::survey_system() const->Survey_system
{
	if( buf_.empty() )
	{
		return Survey_system::none;
	}
	else
	{
		return to_enum<Survey_system>( buf_[0] + '0' );
	}
}

const char* nhill::Uwi::value() const
{
   return buf_.c_str();
}

void nhill::Uwi::value( std::string_view str )
{
	// Is this already in sort format?
	if( uwi::dls::is_sort( str ) )
	{
		set_unchecked( str );
		return;
	}

	// Is it some other format?
	uwi::Dls dls;
	if( is_valid_dls( str, dls ) )
	{
		set_unchecked( dls.sort() );
		return;
	}

	throw invalid_argument( "The string '" + string{ str } +"' is not a valid uwi." );
}

size_t nhill::Uwi::length() const
{
	return buf_.length();
}

size_t nhill::Uwi::size() const
{
	return buf_.size();
}

void nhill::Uwi::set_unchecked( std::string_view s)
{
	buf_ = s;
}


template<>
auto nhill::compare( const Uwi& a, const Uwi& b )->Compare
{
	return to_enum<Compare>( strcmp( a.value(), b.value() ) );
}


bool nhill::operator==( const Uwi& a, const Uwi& b )
{
	return compare<const Uwi&>( a, b ) == Compare::equal;
}

bool nhill::operator!=( const Uwi& a, const Uwi& b )
{
	return !(a == b);
}

bool nhill::operator<( const Uwi& a, const Uwi& b )
{
	return compare<const Uwi&>( a, b ) == Compare::less;
}

bool nhill::operator>( const Uwi& a, const Uwi& b )
{
	return compare<const Uwi&>( a, b ) == Compare::greater;
}

bool nhill::operator<=( const Uwi& a, const Uwi& b )
{
	return !(a > b);
}

bool nhill::operator>=( const Uwi& a, const Uwi& b )
{
	return !(a < b);
}

istream& nhill::operator>>( istream& in, Uwi& uwi )
{
	string s;
	in >> s;
	uwi.value( s );
	return in;
}

ostream& nhill::operator<<( ostream& out, const Uwi& uwi )
{
	return out << uwi.value();
}
