#pragma once

#include <cstdint>
#include "../som/som.h"

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "core/text/bundle_container.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_ENUM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::Som>& nhill::text::bundle_container<nhill::Som>();
#pragma endregion

#include "core/text/methods.h"
#include "core/text/stream_in.h"
#include "core/text/stream_out.h"
#pragma endregion

#pragma region Additional Extensions
#include "../utility/exception/not_implemented.h"
namespace nhill
{
template<class Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr> inline
nhill::Som to_som( Enum e )
{
   throw nhill::Not_implemented( "nhill::to_som.  Must be specialized for each particular enumeration." );
}
}
#pragma endregion


