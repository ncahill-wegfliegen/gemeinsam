#include "../press.h"

template<> inline
const nhill::text::Bundle_container<nhill::uom::Press>& nhill::text::bundle_container<nhill::uom::Press>()
{
   using namespace nhill::uom;

   static const Bundle_container<Press> bundles{
      { Press::none,{ "NA", "NA", "none", "", "None" } },
      //
   { Press::Pa  ,{ { Text::code, "PA"    },{ Text::string, "Pa"    },{ Text::description, "pascal"  } } },
   { Press::bar ,{ { Text::code, "BAR"   },{ Text::string, "bar"   },{ Text::description, "bar"  } } },
   { Press::at  ,{ { Text::code, "AT"    },{ Text::string, "at"    },{ Text::description, "technical atmosphere"  } } },
   { Press::atm ,{ { Text::code, "ATM"   },{ Text::string, "atm"   },{ Text::description, "atmosphere"  } } },
   { Press::torr,{ { Text::code, "TORR"  },{ Text::string, "torr"  },{ Text::description, "torr"  } } },
   { Press::psia,{ { Text::code, "PSIA"  },{ Text::string, "psia"  },{ Text::description, "pounds per square inch absolute"  } } },
   { Press::psig,{ { Text::code, "PSIG"  },{ Text::string, "psig"  },{ Text::description, "pounds per square inch gauge"  } } }
   };
   return bundles;
}

template<>
nhill::Som nhill::to_som( nhill::uom::Press e )
{
   using namespace nhill::uom;
   switch( e )
   {
   case Press::Pa:
      return Som::si;

   case Press::bar:
   case Press::at:
   case Press::atm:
   case Press::torr:
   case Press::psia:
   case Press::psig:
      return Som::api;

   default:
      return Som::none;
   }
}