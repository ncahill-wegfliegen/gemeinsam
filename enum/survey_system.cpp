#include "survey_system.h"

template<> inline
const nhill::text::Bundle_container<nhill::Survey_system>& nhill::text::bundle_container<nhill::Survey_system>()
{
   static const Bundle_container<Survey_system> bundles{
      { Survey_system::none,{ "NA", "N/A", "none", "", "None" } },
      //
      { Survey_system::dls  ,{ { Text::code, "DLS"   }, { Text::string, "dls"   }, { Text::label, "DLS"    } } },
      { Survey_system::nts  ,{ { Text::code, "NTS"   }, { Text::string, "nts"   }, { Text::label, "NTS"    } } },
      { Survey_system::fps  ,{ { Text::code, "FPS"   }, { Text::string, "fps"   }, { Text::label, "FPS"    } } },
      { Survey_system::api  ,{ { Text::code, "API"   }, { Text::string, "api"   }, { Text::label, "API"    } } },
      { Survey_system::ll   ,{ { Text::code, "LL"    }, { Text::string, "ll"    }, { Text::label, "LonLat" } } },
      { Survey_system::other,{ { Text::code, "OTHER" }, { Text::string, "other" }, { Text::label, "Other"  } } }
   };

   return bundles;
}
