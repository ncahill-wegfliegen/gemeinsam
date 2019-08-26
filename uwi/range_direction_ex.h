#pragma once

#include "range_direction.h"

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "../enum/core/text/bundle_container.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_UWI_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::uwi::dls::Range_direction>& nhill::text::bundle_container<nhill::uwi::dls::Range_direction>();
#pragma endregion

#include "../enum/core/text/methods.h"
#include "../enum/core/text/stream_in.h"
#include "../enum/core/text/stream_out.h"
#pragma endregion

#pragma region Additional Extensions
namespace nhill
{
namespace uwi
{
namespace dls
{

NHILL_UWI_PORT_FUNCTION char to_char( Range_direction );
NHILL_UWI_PORT_FUNCTION Range_direction to_range_direction( char );

NHILL_UWI_PORT_FUNCTION bool is_valid_range_direction( char c );

}
}
}

#pragma endregion

