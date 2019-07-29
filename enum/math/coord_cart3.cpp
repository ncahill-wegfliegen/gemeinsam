#include "..\math\coord_cart3.h"

template<>
const nhill::text::Bundle_container<nhill::Coord_cart3>& nhill::text::bundle_container<nhill::Coord_cart3>()
{
   static const Bundle_container<Coord_cart3> bundles{
      { Coord_cart3::x, { "x" } },
      { Coord_cart3::y, { "y" } },
      { Coord_cart3::z, { "z" } },
   };

   return bundles;
}
