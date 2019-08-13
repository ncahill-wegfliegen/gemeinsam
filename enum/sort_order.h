#pragma once

#include <cstdint>

namespace nhill
{

/// <summary>SortOrder Enumeration</summary>
enum class Sort_order : std::int8_t
{
   none       = -1,
   ascending  =  0,
   descending =  1,

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
const nhill::text::Bundle_container<nhill::Sort_order>& nhill::text::bundle_container<nhill::Sort_order>();
#pragma endregion

#include "core/text/methods.h"
#include "core/text/stream_in.h"
#include "core/text/stream_out.h"
#pragma endregion
