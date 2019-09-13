#include "sangle.h"
#include "../math/sign.h"
#include "../enum/core/int.h"
#include <boost/convert.hpp>
#include <boost/convert/stream.hpp>
#include <string>

using namespace std;
struct boost::cnv::by_default : boost::cnv::cstream{};

auto nhill::to_sangle( string_view str )->SAngle
{
   using namespace nhill;
   using nhill::math::Sign;
   auto npos{string_view::npos};
   size_t offset{0};

   // Find the sign
   auto pos_sign{str.find( '+' )};
   // Extract the sign
   Sign sign{Sign::pos}; // If there is no sign, assume positive
   if (pos_sign == npos)
   {
      pos_sign = str.find( '-' );
      if (pos_sign != npos)
      {
         sign = Sign::neg;
      }
   }
   if (pos_sign != npos)
   {
      offset = pos_sign + 1;
   }

   // Find the degree symbol (ALT+248)
   auto pos_deg{str.find( '°' )};
   // Extract the degree
   float deg{0};
   if (pos_deg != npos)
   {
      deg = boost::convert<float>( str.substr( offset, pos_deg - offset ) ).value();
      offset = pos_deg + 1;
   }

   // Find the arcminute symbol (ALT+039)
   auto pos_arcmin{str.find( '\'' )};
   // Extract the arcminute
   float arcmin{0};
   if (pos_arcmin != npos)
   {
      arcmin = boost::convert<float>( str.substr( offset, pos_arcmin - offset ) ).value();
      offset = pos_arcmin + 1;
   }

   // Find the arcsecond symbol (ALT+034)
   auto pos_arcsec{str.find( '\"' )};
   // Extract the arcsecond
   float arcsec{0};
   if (pos_arcsec != npos)
   {
      arcsec = boost::convert<float>( str.substr( offset, pos_arcsec - offset ) ).value();
   }

   return (deg != 0) ? SAngle{to_int( sign )*deg, arcmin, arcsec} : (arcmin != 0) ? SAngle{0, to_int( sign )*arcmin, arcsec} : SAngle{0, 0, to_int( sign )*arcsec};
}

