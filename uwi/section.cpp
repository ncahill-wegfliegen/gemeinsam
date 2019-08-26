#include "section.h"
#include "../utility/str_query.h"
#include <stdexcept>

using namespace std;

auto nhill::uwi::dls::Section_validator_throw::operator()( value_type val ) const->value_type
{
   if( !is_valid_section( val ) )
   {
      throw invalid_argument( "The value '" + to_string( val ) + "' is not a valid section: it must be in the range [1,36]." );
   }
   return val;
}

nhill::uwi::dls::Section_validator_throw::Section_validator_throw()
   : base{ 1 }
{
}


auto nhill::uwi::dls::Section_validator_pin::operator()( value_type val ) const->value_type
{
   if( val < 1 )
   {
      return 1;
   }
   else if( 36 < val )
   {
      return 36;
   }
   else
   {
      return val;
   }
}

nhill::uwi::dls::Section_validator_pin::Section_validator_pin()
   : base{ 1 }
{
}


bool nhill::uwi::dls::is_valid_section( int i )
{
   return 1 <= i && i <= 36;
}

bool nhill::uwi::dls::is_valid_section( const char* s )
{
	if( !str::is_integer( s, 1, 2 ) )
	{
		return false;
	}
	else
	{
		int i{ atoi( s ) };
		return is_valid_section( i );
	}
}
