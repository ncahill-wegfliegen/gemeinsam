#include "..\math\coord_polar.h"

template<>
const nhill::text::Bundle_container<nhill::Coord_polar>& nhill::text::bundle_container<nhill::Coord_polar>()
{
   static const Bundle_container<Coord_polar> bundles{
      { Coord_polar::r, { "r" } },
      { Coord_polar::t, { "t" } },
   };

   return bundles;
}
