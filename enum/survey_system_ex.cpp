#include "survey_system_ex.h"

template<> inline
const nhill::text::Bundle_container<nhill::Survey_system>& nhill::text::bundle_container<nhill::Survey_system>()
{
   static const Bundle_container<Survey_system> bundles{
      { Survey_system::none,{ "NA", "N/A", "none", "", "None" } },
      //
      { Survey_system::dls  ,{ { Text::code, "DLS"   }, { Text::string, "dls"   }, { Text::label, "DLS"   }, {Text::description, "Dominion Land Survey"			} } },
      { Survey_system::nts  ,{ { Text::code, "NTS"   }, { Text::string, "nts"   }, { Text::label, "NTS"   }, {Text::description, "National Topographic Series"	} } },
      { Survey_system::fps  ,{ { Text::code, "FPS"   }, { Text::string, "fps"   }, { Text::label, "FPS"   }, {Text::description, "Federal Permit System"			} } },
      { Survey_system::geo  ,{ { Text::code, "GEO"   }, { Text::string, "geo"   }, { Text::label, "GEO"   }, {Text::description, "Geodetic Coordinates"			} } },
      { Survey_system::api  ,{ { Text::code, "API"   }, { Text::string, "api"   }, { Text::label, "API"   }, {Text::description, "American Petroleum Institute"} } },
      { Survey_system::other,{ { Text::code, "OTHER" }, { Text::string, "other" }, { Text::label, "Other" }, {Text::description, "Other"								} } }
   };

   return bundles;
}

template<> 
nhill::Survey_system nhill::begin()
{
	return Survey_system::none;
}

template<>
nhill::Survey_system nhill::end()
{
	int i{ to_int( Survey_system::other ) };
	++i;
	return to_enum<Survey_system>( i );
}
