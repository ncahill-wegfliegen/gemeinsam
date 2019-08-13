#pragma once

#include "../temp.h"
#include "../temp/puom_tmplt.h"

namespace nhill
{
namespace uom
{
namespace temp
{

/// <summary>SI temperature: kelvin</summary>
using K = Prefixed_temp_template<Prefix::none, Temp::K>;

/// <summary>API temperature: degree Celsius (degree symbol Alt+248).</summary>
using degC = Prefixed_temp_template<Prefix::none, Temp::degC>;
/// <summary>API temperature: degree Fahrenheit (degree symbol Alt+248).</summary>
using degF = Prefixed_temp_template<Prefix::none, Temp::degF>;
/// <summary>API temperature: degree Rankine (degree symbol Alt+248).</summary>
using degR = Prefixed_temp_template<Prefix::none, Temp::degR>;

}
}
}