#include "../math/coord_cart2.h"

template<>
const nhill::text::Bundle_container<nhill::Coord_cart2>& nhill::text::bundle_container<nhill::Coord_cart2>()
{
   static const Bundle_container<Coord_cart2> bundles{
      { Coord_cart2::x, { "x" } },
      { Coord_cart2::y, { "y" } },
   };

   return bundles;
}
