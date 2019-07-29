#include "sangle.h"
#include "..\math\sign.h"
#include "..\enum\core\int.h"

using namespace std;


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
      deg = static_cast<float>(atof( str.substr( offset, pos_deg - offset ).data() ));
      offset = pos_deg + 1;
   }

   // Find the arcminute symbol (ALT+039)
   auto pos_arcmin{str.find( '\'' )};
   // Extract the arcminute
   float arcmin{0};
   if (pos_arcmin != npos)
   {
      arcmin = static_cast<float>(atof( str.substr( offset, pos_arcmin - offset ).data() ));
      offset = pos_arcmin + 1;
   }

   // Find the arcsecond symbol (ALT+034)
   auto pos_arcsec{str.find( '\"' )};
   // Extract the arcsecond
   float arcsec{0};
   if (pos_arcsec != npos)
   {
      arcsec = static_cast<float>(atof( str.substr( offset, pos_arcsec - offset ).data() ));
   }

   return (deg != 0) ? SAngle{to_int( sign )*deg, arcmin, arcsec} : (arcmin != 0) ? SAngle{0, to_int( sign )*arcmin, arcsec} : SAngle{0, 0, to_int( sign )*arcsec};
}

