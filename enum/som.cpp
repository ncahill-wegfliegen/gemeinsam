#include "som.h"

template<>
const nhill::text::Bundle_container<nhill::Som>& nhill::text::bundle_container<nhill::Som>()
{
   static const Bundle_container<nhill::Som> bundles{
      { nhill::Som::none  ,{ { Text::code, "NA"     }, { Text::string, "none"   }, { Text::label, ""       }, { Text::description, "None" } } },
      { nhill::Som::si    ,{ { Text::code, "SI"     }, { Text::string, "si"     }, { Text::label, "SI"     }, { Text::description, "Le Système International d'Unités" } } },
      { nhill::Som::api   ,{ { Text::code, "API"    }, { Text::string, "api"    }, { Text::label, "API"    }, { Text::description, "American Petroleum Institute" } } },
      { nhill::Som::metric,{ { Text::code, "METRIC" }, { Text::string, "metric" }, { Text::label, "METRIC" }, { Text::description, "Metric" } } },
   };
   return bundles;
}
