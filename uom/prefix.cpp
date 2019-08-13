#include "prefix.h"
#include "../enum/core/int.h"

template<>
const nhill::text::Bundle_container<nhill::uom::Prefix>& nhill::text::bundle_container<nhill::uom::Prefix>()
{
   using namespace nhill::uom;

   static const Bundle_container<Prefix> bundles{
   { Prefix::yocto,  { "y"  , "y"  , "yocto"  , "y"  , "yocto"  } },
   { Prefix::zepto,  { "z"  , "z"  , "zepto"  , "z"  , "zepto"  } },
   { Prefix::atto,   { "a"  , "a"  , "atto"   , "a"  , "atto"   } },
   { Prefix::femto,  { "f"  , "f"  , "femto"  , "f"  , "femto"  } },
   { Prefix::pico,   { "p"  , "p"  , "pico"   , "p"  , "pico"   } },
   { Prefix::nano,   { "n"  , "n"  , "nano"   , "n"  , "nano"   } },
   { Prefix::micro,  { "µ"  , "µ"  , "micro"  , "µ"  , "micro"  } },
   { Prefix::milli,  { "m"  , "m"  , "milli"  , "m"  , "milli"  } },
   { Prefix::centi,  { "c"  , "c"  , "centi"  , "c"  , "centi"  } },
   { Prefix::deci,   { "d"  , "d"  , "deci"   , "d"  , "deci"   } },
   { Prefix::none,   { "NA" , "NA" , "none"   , ""   , ""       } },
   { Prefix::deca,   { "da" , "da" , "deca"   , "da" , "deca"   } },
   { Prefix::hecto,  { "h"  , "h"  , "hecto"  , "h"  , "hecto"  } },
   { Prefix::kilo,   { "k"  , "k"  , "kilo"   , "k"  , "kilo"   } },
   { Prefix::mega,   { "M"  , "M"  , "mega"   , "M"  , "mega"   } },
   { Prefix::giga,   { "G"  , "G"  , "giga"   , "G"  , "giga"   } },
   { Prefix::tera,   { "T"  , "T"  , "tera"   , "T"  , "tera"   } },
   { Prefix::peta,   { "P"  , "P"  , "peta"   , "P"  , "peta"   } },
   { Prefix::exa,    { "E"  , "E"  , "exa"    , "E"  , "exa"    } },
   { Prefix::zetta,  { "Z"  , "Z"  , "zetta"  , "Z"  , "zetta"  } },
   { Prefix::yotta,  { "Y"  , "Y"  , "yotta"  , "Y"  , "yotta"  } },
   { Prefix::e3,     { "e3" , "e3" , "e3"     , "e3" , "e3"     } },
   { Prefix::e6,     { "e6" , "e6" , "e6"     , "e6" , "e6"     } },
   { Prefix::e9,     { "e9" , "e9" , "e9"     , "e9" , "e9"     } },
   { Prefix::M,      { "M"  , "M"  , "M"      , "M"  , "M"      } },
   { Prefix::MM,     { "MM" , "MM" , "MM"     , "MM" , "MM"     } },
   { Prefix::B,      { "B"  , "B"  , "B"      , "B"  , "B"      } }
   };
   return bundles;
}

int nhill::to_power( nhill::uom::Prefix e )
{
   using Prefix = nhill::uom::Prefix;
   switch( e )
   {
   case Prefix::e3: return 3;
   case Prefix::e6: return 6;
   case Prefix::e9: return 9;
   case Prefix::M: return 3;
   case Prefix::MM: return 6;
   case Prefix::B: return 9;
   default: return to_int( e );
   }
}

double nhill::to_factor( nhill::uom::Prefix e )
{
   double power = to_power( e );
   double factor = std::pow( 10.0, power );
   return factor;
}
