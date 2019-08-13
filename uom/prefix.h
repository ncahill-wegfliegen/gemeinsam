#pragma once

namespace nhill
{
namespace uom
{

enum class Prefix
{
    yocto = -24,
    zepto = -21,
    atto  = -18,
    femto = -15,
    pico  = -12,
    nano  = -9 ,
    micro = -6 ,
    milli = -3 ,
    centi = -2 ,
    deci  = -1 ,
    none  = 0  ,
    deca  = 1  ,
    hecto = 2  ,
    kilo  = 3  ,
    mega  = 6  ,
    giga  = 9  ,
    tera  = 12 ,
    peta  = 15 ,
    exa   = 18 ,
    zetta = 21 ,
    yotta = 24 ,
    // SI: one thousand
    e3 = 103,
    // SI: one million
    e6= 106,
    // SI: one billion
    e9= 109,
    // API: one thousand
    M=203,
    // API: one million
    MM= 206,
    // API: one billion
    B= 209,
   
};

}
}

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "../enum/core/text/bundle_container.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_UOM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::uom::Prefix>& nhill::text::bundle_container<nhill::uom::Prefix>();
#pragma endregion

#include "../enum/core/text/methods.h"
#include "../enum/core/text/stream_in.h"
#include "../enum/core/text/stream_out.h"
#pragma endregion


#pragma region Additional Extensions
namespace nhill
{
/// <summary>The power of ten associated with the given prefix; e.g, milli->10^-3 has power -3.</summary>
/// <param name="e">The given prefix.</param>
/// <returns>The power of ten.</returns>
NHILL_UOM_PORT_FUNCTION int to_power( nhill::uom::Prefix e );

/// <summary>The decimal factor associated with the given prefix; e.g., milli->10^-3 has factor 0.001.</summary>
/// <param name="e">The given prefix.</param>
/// <returns>The factor.</returns>
NHILL_UOM_PORT_FUNCTION double to_factor( nhill::uom::Prefix e );
}
#pragma endregion
