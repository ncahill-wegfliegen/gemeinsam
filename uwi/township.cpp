#include "township.h"
#include "../utility/str_query.h"
#include <stdexcept>

using namespace std;

auto nhill::uwi::dls::Township_validator_throw::operator()( value_type val ) const->value_type
{
   if( !is_valid_township( val ) )
   {
      throw invalid_argument( "The value '" + to_string( val ) + "' is not a valid township: it must be in the range [1,126]." );
   }
   return val;
}

nhill::uwi::dls::Township_validator_throw::Township_validator_throw()
   : base{ 1 }
{
}

auto nhill::uwi::dls::Township_validator_pin::operator()( value_type val ) const->value_type
{
   if( val < 1 )
   {
      return 1;
   }
   else if( 126 < val )
   {
      return 126;
   }
   else
   {
      return val;
   }
}

nhill::uwi::dls::Township_validator_pin::Township_validator_pin()
   : base{ 1 }
{
}

bool nhill::uwi::dls::is_valid_township( int i )
{
   return 1 <= i && i <= 126;
}

bool nhill::uwi::dls::is_valid_township( const char* s )
{
	if( !str::is_integer( s, 1, 3 ) )
	{
		return false;
	}
	else
	{
		int i{ atoi( s ) };
		return is_valid_township( i );
	}
}
