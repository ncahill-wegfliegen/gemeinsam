#include "legal_subdivision.h"
#include "../utility/str_query.h"
#include <stdexcept>

using namespace std;

auto nhill::uwi::dls::Legal_subdivision_validator_throw::operator()( value_type val ) const->value_type
{
   if( !is_valid_legal_subdivision( val ) )
   {
      throw invalid_argument( "The value '" + to_string( val ) + "' is not a valid legal subdivision: it must be in the range [1,16]." );
   }
   return val;
}

auto nhill::uwi::dls::Legal_subdivision_validator_throw::operator()( string_view s) const->string_view
{
	if( !is_valid_legal_subdivision( s ) )
	{
		throw invalid_argument( "The value '" + string{ s } +"' is not a valid legal subdivision: it must be in the range [1,16]." );
	}
	return s;
}

nhill::uwi::dls::Legal_subdivision_validator_throw::Legal_subdivision_validator_throw()
   : base{ 1 }
{
}


auto nhill::uwi::dls::Legal_subdivision_validator_pin::operator()( value_type val ) const->value_type
{
   if( val < 1 )
   {
      return 1;
   }
   else if( 16 < val )
   {
      return 16;
   }
   else
   {
      return val;
   }
}

nhill::uwi::dls::Legal_subdivision_validator_pin::Legal_subdivision_validator_pin()
   : base{ 1 }
{
}


bool nhill::uwi::dls::is_valid_legal_subdivision( int i )
{
   return 1 <= i && i <= 16;
}

bool nhill::uwi::dls::is_valid_legal_subdivision( const string& s )
{
	if( str::is_integer( s, 1, 2 ) )
	{
		int i{ atoi( s.c_str() ) };
		return is_valid_legal_subdivision( i );
	}
	else
	{
		return false;
	}
}
