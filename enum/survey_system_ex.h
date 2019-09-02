#pragma once

#include "survey_system.h"

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "core/text/bundle_container.h"
#include "core/values.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_ENUM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::Survey_system>& nhill::text::bundle_container<nhill::Survey_system>();
#pragma endregion

#pragma region Values
template<> NHILL_ENUM_PORT_FUNCTION nhill::Survey_system nhill::begin();
template<> NHILL_ENUM_PORT_FUNCTION nhill::Survey_system nhill::end();
#pragma endregion

#include "core/text/methods.h"
#include "core/text/stream_in.h"
#include "core/text/stream_out.h"
#pragma endregion

