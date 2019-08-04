#include "..\vol.h"

template<> inline
const nhill::text::Bundle_container<nhill::uom::Vol>& nhill::text::bundle_container<nhill::uom::Vol>()
{
   using namespace nhill::uom;

   static const Bundle_container<Vol> bundles{
      { Vol::none,{ "NA", "NA", "none", "", "None" } },
      //
   { Vol::m3  ,{ { Text::code, "M3"   },{ Text::string, "m3"   },{ Text::label, "m³"    },{ Text::description, "metre cubed"   } } },
   { Vol::ham ,{ { Text::code, "HAM"  },{ Text::string, "ham"  },{ Text::label, "ha-m"  },{ Text::description, "hectare metre" } } },
   { Vol::cuin,{ { Text::code, "CUIN" },{ Text::string, "cuin" },{ Text::label, "cu in" },{ Text::description, "cubic inch"    } } },
   { Vol::cuft,{ { Text::code, "CUFT" },{ Text::string, "cuft" },{ Text::label, "cu ft" },{ Text::description, "cubic foot"    } } },
   { Vol::cuyd,{ { Text::code, "CUYD" },{ Text::string, "cuyd" },{ Text::label, "cu yd" },{ Text::description, "cubic yard"    } } },
   { Vol::cumi,{ { Text::code, "CUMI" },{ Text::string, "cumi" },{ Text::label, "cu mi" },{ Text::description, "cubic mile"    } } },
   { Vol::acft,{ { Text::code, "ACFT" },{ Text::string, "acft" },{ Text::label, "ac-ft" },{ Text::description, "acre-foot"     } } },
   { Vol::bbl ,{ { Text::code, "BBL"  },{ Text::string, "bbl"  },{ Text::description, "barrel" } } },
   { Vol::rb  ,{ { Text::code, "RB"   },{ Text::string, "rb"   },{ Text::description, "reservoir barrel" } } },
   { Vol::stb ,{ { Text::code, "STB"  },{ Text::string, "stb"  },{ Text::description, "standard barrel" } } },
   { Vol::boe ,{ { Text::code, "BOE"  },{ Text::string, "boe"  },{ Text::description, "barrels of oil equivalent" } } },
   { Vol::cf  ,{ { Text::code, "CF"   },{ Text::string, "cf"   },{ Text::description, "cubic foot (gas)" } } },
   { Vol::rcf ,{ { Text::code, "RCF"  },{ Text::string, "rcf"  },{ Text::description, "reservoir cubic foot (gas)" } } },
   { Vol::scf ,{ { Text::code, "SCF"  },{ Text::string, "scf"  },{ Text::description, "standard cubic foot (gas)" } } },
   };
   return bundles;
}

template<>
nhill::Som nhill::to_som( nhill::uom::Vol e )
{
   using namespace nhill::uom;
   switch( e )
   {
   case Vol::m3:
   case Vol::ham:
      return Som::si;

   case Vol::cuin:
   case Vol::cuft:
   case Vol::cuyd:
   case Vol::cumi:
   case Vol::acft:
   case Vol::bbl:
   case Vol::rb:
   case Vol::stb:
   case Vol::boe:
   case Vol::cf:
   case Vol::rcf:
   case Vol::scf:
      return Som::api;

   default:
      return Som::none;
   }
}
