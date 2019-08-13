#pragma once


namespace nhill
{
namespace uom
{

enum class Length
{
   none,

   /// <summary>metre</summary>
   m,

   /// <summary>inch</summary>
   in,
   /// <summary>foot</summary>
   ft,
   /// <summary>yard</summary>
   yd,
   /// <summary>mile</summary>
   mi,

   end,
   begin = none,
   defalt = m,
   count = end - begin,
};


using Len = nhill::uom::Length;
}
}

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "../enum/core/text/bundle_container.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_UOM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::uom::Len>& nhill::text::bundle_container<nhill::uom::Len>();
#pragma endregion

#include "../enum/core/text/methods.h"
#include "../enum/core/text/stream_in.h"
#include "../enum/core/text/stream_out.h"
#pragma endregion

#pragma region Additional Extensions
#include "../enum/som.h"
namespace nhill
{
template<> NHILL_UOM_PORT_FUNCTION
nhill::Som to_som( nhill::uom::Len e );
}
#pragma endregion
