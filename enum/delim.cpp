#include "delim.h"

template<>
const nhill::text::Bundle_container<nhill::Delim>& nhill::text::bundle_container<nhill::Delim>()
{
   static const Bundle_container<Delim> bundles{
      { Delim::none     , {"none"      }},
      { Delim::tab      , {"tab"       }},
      { Delim::comma    , {"comma"     }},
      { Delim::space    , {"space"     }},
      { Delim::colon    , {"colon"     }},
      { Delim::semicolon, {"semicolon" }},
      { Delim::other    , {"other"     }}
   };

   return bundles;
}
