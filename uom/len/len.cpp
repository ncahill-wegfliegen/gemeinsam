#include "..\len.h"

template<>
const nhill::text::Bundle_container<nhill::uom::Len>& nhill::text::bundle_container<nhill::uom::Len>()
{
   using namespace nhill::uom;

   static const Bundle_container<Len> bundles{
      { Len::none,{ "NA", "NA", "none", "", "None" } },
      //
   { Len::m, { { Text::code, "M"   },{ Text::string, "m"  },{ Text::description, "metre" } } },
   { Len::in,{ { Text::code, "IN"  },{ Text::string, "in" },{ Text::description, "inch"  } } },
   { Len::ft,{ { Text::code, "FT"  },{ Text::string, "ft" },{ Text::description, "foot"  } } },
   { Len::yd,{ { Text::code, "YD"  },{ Text::string, "yd" },{ Text::description, "yard"  } } },
   { Len::mi,{ { Text::code, "MI"  },{ Text::string, "mi" },{ Text::description, "mile"  } } }
   };
   return bundles;
}

template<> inline
nhill::Som nhill::to_som( nhill::uom::Len e )
{
   using Len = nhill::uom::Len;
   switch( e )
   {
   case Len::m:
      return Som::si;

   case Len::in:
   case Len::ft:
   case Len::yd:
   case Len::mi:
      return Som::api;

   default:
      return Som::none;
   }
}

