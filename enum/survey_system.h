#pragma once

// Define the collection of strings for an enumeration that is NOT continuous.
// The enumeration class MUST define the 'count' field.
// http://www.jakeshirley.com/c-macro-defined-enums/

#include <cstdint>

namespace nhill
{

enum class Survey_system : std::int16_t
{
   none,
   dls,
   nts,
   fps,
   api,
   ll, // longitude, latitude
   other,

   // used for iteration
   end,
   begin = none,
};

}

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "core/text/bundle_container.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_ENUM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::Survey_system>& nhill::text::bundle_container<nhill::Survey_system>();
#pragma endregion

#include "core/text/methods.h"
#include "core/text/stream_in.h"
#include "core/text/stream_out.h"
#pragma endregion

