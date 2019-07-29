#include "..\math\coord_cyl.h"

template<>
const nhill::text::Bundle_container<nhill::Coord_cyl>& nhill::text::bundle_container<nhill::Coord_cyl>()
{
   static const Bundle_container<Coord_cyl> bundles{
      { Coord_cyl::r, { "r" } },
      { Coord_cyl::t, { "t" } },
      { Coord_cyl::z, { "z" } },
   };

   return bundles;
}
