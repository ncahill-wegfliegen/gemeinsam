#include "log_level.h"

template<> 
const nhill::text::Bundle_container<nhill::log::Level>& nhill::text::bundle_container<nhill::log::Level>()
{
   using namespace nhill::log;     // enumeration type

   static const Bundle_container<Level> bundles{
      { Level::none , { { Text::string, "none"  }, { Text::label, ""      } } },
      { Level::off  , { { Text::string, "off"   }, { Text::label, "Off"   } } },
      { Level::fatal, { { Text::string, "fatal" }, { Text::label, "Fatal" } } },
      { Level::error, { { Text::string, "error" }, { Text::label, "Error" } } },
      { Level::warn , { { Text::string, "warn"  }, { Text::label, "Warn"  } } },
      { Level::info , { { Text::string, "info"  }, { Text::label, "Info"  } } },
      { Level::debug, { { Text::string, "debug" }, { Text::label, "Debug" } } },
      { Level::all  , { { Text::string, "all"   }, { Text::label, "All"   } } },
   };

   return bundles;
}
