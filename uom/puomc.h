#pragma once

#include "puom.h"
#include <vector>

namespace nhill
{
namespace uom
{

template<typename Uom>
using Prefixed_uom_container = std::vector< Prefixed_uom<Uom> >;

template<typename Uom>
bool contains( const Prefixed_uom_container<Uom>& puomc, const Prefixed_uom<Uom>& puom )
{
   auto itr = std::find_if(
      puomc.begin(),
      puomc.end(),
      [&puom]( Prefixed_uom_container<Uom>::const_reference x ) { return x == puom; }
   );

   return itr != puomc.end();
}

}
}
