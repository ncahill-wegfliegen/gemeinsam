#pragma once

namespace nhill
{
namespace uom
{
enum class Pressure
{
   none,
   Pa,
   bar,
   at,
   atm,
   torr,
   psia,
   psig,
};

using Press = nhill::uom::Pressure;

}
}

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "../enum/core/text/bundle_container.h"
#include "../enum/core/values.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_UOM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::uom::Press>& nhill::text::bundle_container<nhill::uom::Press>();
#pragma endregion

#pragma region Values
template<> inline nhill::uom::Pressure nhill::begin() { return uom::Pressure::none; }
template<> inline nhill::uom::Pressure nhill::end() { return to_enum<nhill::uom::Pressure>( to_int( uom::Pressure::psig ) + 1 ); }
#pragma endregion

#include "../enum/core/text/methods.h"
#include "../enum/core/text/stream_in.h"
#include "../enum/core/text/stream_out.h"
#pragma endregion

#pragma region Additional Extensions
#include "../enum/som.h"
namespace nhill
{
template<> NHILL_ENUM_PORT_FUNCTION
nhill::Som to_som( nhill::uom::Press e );
}
#pragma endregion

