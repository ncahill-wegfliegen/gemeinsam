#pragma once

namespace nhill
{
namespace uom
{
/// <summary>The degree symbol is Alt+248.</summary>
enum class Temperature
{
   none = -1,
   K,
   degC,
   degF,
   degR,

   end,
   begin = none,
   defalt = degC,
   count = end - begin,
};

using Temp = nhill::uom::Temperature;

}
}

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "..\enum\core\text\bundle_container.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_UOM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::uom::Temp>& nhill::text::bundle_container<nhill::uom::Temp>();
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
nhill::Som to_som( nhill::uom::Temp e );
}
#pragma endregion
