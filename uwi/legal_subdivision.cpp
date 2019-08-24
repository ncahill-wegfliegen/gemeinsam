#include "legal_subdivision.h"
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


bool nhill::uwi::dls::is_valid_legal_subdivision( int v )
{
   return 1 <= v && v <= 16;
}
