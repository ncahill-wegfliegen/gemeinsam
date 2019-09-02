#pragma once

#include "format.h"

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "../enum/core/text/bundle_container.h"
#include "../enum/core/values.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_UWI_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::uwi::Format>& nhill::text::bundle_container<nhill::uwi::Format>();
#pragma endregion

#pragma region Values
template<> NHILL_UWI_PORT_FUNCTION inline nhill::uwi::Format nhill::begin() { return uwi::Format::none; }
template<> NHILL_UWI_PORT_FUNCTION inline nhill::uwi::Format nhill::end() { return to_enum<uwi::Format>( to_int(uwi::Format::full_dressed) + 1); }
#pragma endregion

#include "../enum/core/text/methods.h"
#include "../enum/core/text/stream_in.h"
#include "../enum/core/text/stream_out.h"
#pragma endregion

