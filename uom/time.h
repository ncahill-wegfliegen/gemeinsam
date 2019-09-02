#pragma once

namespace nhill
{
namespace uom
{

enum class Time
{
   none,
   /// <summary>second</summary>
   s,
   /// <summary>minute</summary>
   min,
   /// <summary>hour</summary>
   h,
   /// <summary>day</summary>
   d,
   /// <summary>week</summary>
   wk,
   /// <summary>month</summary>
   mo,
   /// <summary>year</summary>
   yr,
};

}
}

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "../enum/core/text/bundle_container.h"
#include "../enum/core/values.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_UOM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::uom::Time>& nhill::text::bundle_container<nhill::uom::Time>();
#pragma endregion

#pragma region Values
template<> inline nhill::uom::Time nhill::begin() { return uom::Time::none; }
template<> inline nhill::uom::Time nhill::end() { return to_enum<nhill::uom::Time>( to_int( uom::Time::yr ) + 1 ); }
#pragma endregion

#include "../enum/core/text/methods.h"
#include "../enum/core/text/stream_in.h"
#include "../enum/core/text/stream_out.h"
#pragma endregion
