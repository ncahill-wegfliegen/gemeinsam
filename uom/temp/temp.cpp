#include "..\temp.h"

template<>
const nhill::text::Bundle_container<nhill::uom::Temp>& nhill::text::bundle_container<nhill::uom::Temp>()
{
   using namespace nhill::uom;

   static const Bundle_container<Temp> bundles{
      { Temp::none,{ "NA", "NA", "none", "", "None" } },
      //
   { Temp::K   ,{ "K"   , "K"   , "K"   , "K" , "kelvin"            } },
   { Temp::degC,{ "degC", "degC", "degC", "°C", "degree Celsius"    } },
   { Temp::degF,{ "degF", "degF", "degF", "°F", "degree Fahrenheit" } },
   { Temp::degR,{ "degR", "degR", "degR", "°R", "degree Rankine"    } },
   };
   return bundles;
}

template<>
nhill::Som nhill::to_som( nhill::uom::Temp e )
{
   using namespace nhill::uom;
   switch( e )
   {
   case Temp::K:
   return Som::si;

   case Temp::degC:
   case Temp::degF:
   case Temp::degR:
   return Som::api;

   default:
   return Som::none;
   }
}
