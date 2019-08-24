#include "meridian.h"
#include <stdexcept>

using namespace std;

auto nhill::uwi::dls::Meridian_validator_throw::operator()( value_type val ) const->value_type
{
   if( !is_valid_meridian( val ) )
   {
      throw invalid_argument( "The value '" + to_string( val ) + "' is not a valid meridian: it must be in the range [1,6]." );
   }
   return val;
}

nhill::uwi::dls::Meridian_validator_throw::Meridian_validator_throw()
   : base{ 1 }
{
}


auto nhill::uwi::dls::Meridian_validator_pin::operator()( value_type val ) const->value_type
{
   if( val < 1 )
   {
      return 1;
   }
   else if( 6 < val )
   {
      return 6;
   }
   else
   {
      return val;
   }
}

nhill::uwi::dls::Meridian_validator_pin::Meridian_validator_pin()
   : base{ 1 }
{
}


bool nhill::uwi::dls::is_valid_meridian( int v )
{
   return 1 <= v && v <= 6;
}


