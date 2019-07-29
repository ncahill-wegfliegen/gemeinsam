#include "..\math\coord_spher.h"

template<>
const nhill::text::Bundle_container<nhill::Coord_shper>& nhill::text::bundle_container<nhill::Coord_shper>()
{
   static const Bundle_container<Coord_shper> bundles{
      { Coord_shper::r, { "r" } },
      { Coord_shper::t, { "t" } },
      { Coord_shper::p, { "p" } },
   };

   return bundles;
}
