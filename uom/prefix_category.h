#pragma once

namespace nhill
{
namespace uom
{
enum class Prefix_category
{
    none,
    si,
    engineering,
    api,

    end,
    begin = none,

    metric = si,
    defalt = none,
};

}
}

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "../enum/core/text/bundle_container.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_UOM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::uom::Prefix_category>& nhill::text::bundle_container<nhill::uom::Prefix_category>();
#pragma endregion

#include "../enum/core/text/methods.h"
#include "../enum/core/text/stream_in.h"
#include "../enum/core/text/stream_out.h"
#pragma endregion


#pragma region Additional Extensions
#include "prefix.h"
namespace nhill
{
NHILL_UOM_PORT_FUNCTION nhill::uom::Prefix_category to_category( nhill::uom::Prefix e );
}
#pragma endregion