#include "prefix_category.h"
#include "prefix_values.h"

template<>
const nhill::text::Bundle_container<nhill::uom::Prefix_category>& nhill::text::bundle_container<nhill::uom::Prefix_category>()
{
   using namespace nhill::uom;

   static const Bundle_container<Prefix_category> bundles{
      { Prefix_category::none       ,{ "NA"    , "NA"     , "none"       , ""           , ""            } },
      { Prefix_category::si         ,{ "SI"    , "SI"     , "si"         , "SI"         , "SI"          } },
      { Prefix_category::engineering,{ "ENG"   , "ENG"    , "engineering", "Engineering", "Engineering" } },
      { Prefix_category::api        ,{ "API"   , "API"    , "api"        , "API"        , "API"         } },
      { Prefix_category::metric     ,{ "METRIC", "METRIC" , "metric"     , "METRIC"     , "METRIC"      } },
   };

   return bundles;
}

nhill::uom::Prefix_category nhill::to_category( nhill::uom::Prefix e )
{
   using namespace nhill::uom;

   auto found = std::find( prefix_values_si.begin(), prefix_values_si.end(), e );
   if( found != prefix_values_si.end() )
      return Prefix_category::si;

   found = std::find( prefix_values_engineering.begin(), prefix_values_engineering.end(), e );
   if( found != prefix_values_engineering.end() )
      return Prefix_category::engineering;

   found = std::find( prefix_values_api.begin(), prefix_values_api.end(), e );
   if( found != prefix_values_api.end() )
      return Prefix_category::api;

   return Prefix_category::none;
}

