#include "../time.h"

template<> inline
const nhill::text::Bundle_container<nhill::uom::Time>& nhill::text::bundle_container<nhill::uom::Time>()
{
   using namespace nhill::uom;

   static const Bundle_container<Time> bundles{
      { Time::none,{ "NA", "NA", "none", "", "None" } },
      //
   { Time::s  ,{ { Text::code, "S"   },{ Text::string, "s"   },{ Text::description, "second" } } },
   { Time::min,{ { Text::code, "MIN" },{ Text::string, "min" },{ Text::description, "minute" } } },
   { Time::h  ,{ { Text::code, "H"   },{ Text::string, "h"   },{ Text::description, "hour"   } } },
   { Time::d  ,{ { Text::code, "D"   },{ Text::string, "d"   },{ Text::description, "day"    } } },
   { Time::wk ,{ { Text::code, "WK"  },{ Text::string, "wk"  },{ Text::description, "week"   } } },
   { Time::mo ,{ { Text::code, "MO"  },{ Text::string, "mo"  },{ Text::description, "month"  } } },
   { Time::yr ,{ { Text::code, "YR"  },{ Text::string, "yr"  },{ Text::description, "year"   } } }
   };
   return bundles;
}
