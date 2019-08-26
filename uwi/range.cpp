#include "range.h"
#include "../utility/str_query.h"
#include <stdexcept>

using namespace std;

auto nhill::uwi::dls::Range_validator_throw::operator()( value_type val ) const->value_type
{
   if( !is_valid_range( val ) )
   {
      throw invalid_argument( "The value '" + to_string( val ) + "' is not a valid range: it must be in the range [1,30]." );
   }
   return val;
}

nhill::uwi::dls::Range_validator_throw::Range_validator_throw()
   : base{ 1 }
{
}


auto nhill::uwi::dls::Range_validator_pin::operator()( value_type val ) const->value_type
{
   if( val < 1 )
   {
      return 1;
   }
   else if( 30 < val )
   {
      return 30;
   }
   else
   {
      return val;
   }
}

nhill::uwi::dls::Range_validator_pin::Range_validator_pin()
   : base{ 1 }
{
}


bool nhill::uwi::dls::is_valid_range( int i )
{
   return 1 <= i && i <= 30;
}


bool nhill::uwi::dls::is_valid_range( const char* s )
{
	if( !str::is_integer( s, 1, 2 ) )
	{
		return false;
	}
	else
	{
		int i{ atoi( s ) };
		return is_valid_range( i );
	}
}
