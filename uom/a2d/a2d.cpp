#include "..\a2d.h"

template<>
const nhill::text::Bundle_container<nhill::uom::A2d>& nhill::text::bundle_container<nhill::uom::A2d>()
{
   using namespace nhill::uom;

   static const Bundle_container<A2d> bundles{
      { A2d::none,{ "NA", "NA", "none", "", "None" } },
      //
   { A2d::m2  ,{ { Text::code, "M2"   },{ Text::string, "m2"   },{ Text::label, "m²"    },{ Text::description, "metre squared" } } },
   { A2d::sqft,{ { Text::code, "SQFT" },{ Text::string, "sqft" },{ Text::label, "sq ft" },{ Text::description, "square foot" } } },
   { A2d::ha  ,{ { Text::code, "HA"   },{ Text::string, "ha"   },{ Text::label, "ha"    },{ Text::description, "hectare" } } },
   { A2d::ac  ,{ { Text::code, "AC"   },{ Text::string, "ac"   },{ Text::label, "ac"    },{ Text::description, "acre" } } }
   };
   return bundles;
}

template<>
nhill::Som nhill::to_som( nhill::uom::A2d e )
{
   using namespace nhill::uom;
   switch( e )
   {
   case A2d::m2:
   case A2d::sqft:
   case A2d::ha:
      return Som::si;

   case A2d::ac:
      return Som::api;

   default:
      return Som::none;
   }
}
