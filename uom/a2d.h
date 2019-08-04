#pragma once

namespace nhill
{
namespace uom
{

enum class Area_2d
{
   none,

   /// <summary>SI: metres squared</summary>
   m2,

   /// <summary>API: square feet</summary>
   sqft,

   /// <summary>SI: hectare</summary>
   ha,

   /// <summary>API: acre</summary>
   ac,

   end,
   begin = none,
   defalt = m2,
};

/// <summary>An short alias for the Area_2d enumeration.</summary>
using A2d = Area_2d;

}
}

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "..\enum\core\text\bundle_container.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_UOM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::uom::A2d>& nhill::text::bundle_container<nhill::uom::A2d>();
#pragma endregion

#include "..\enum\core\text\methods.h"
#include "..\enum\core\text\stream_in.h"
#include "..\enum\core\text\stream_out.h"
#pragma endregion

#pragma region Additional Extensions
#include "..\enum\som.h"
namespace nhill
{
template<> NHILL_UOM_PORT_FUNCTION
nhill::Som to_som( nhill::uom::A2d e );
}
#pragma endregion