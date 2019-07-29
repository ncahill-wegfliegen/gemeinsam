#pragma once

#include "quantity_tmplt.h"

namespace nhill
{
namespace uom
{
namespace temp
{
/// <summary>SI temperature: kelvin</summary>
using v_K = Quantity_temp_template<Prefix::none, Temp::K>;

/// <summary>API temperature: degree Celsius</summary>
using v_degC = Quantity_temp_template<Prefix::none, Temp::degC>;
/// <summary>API temperature: degree Fahrenheit</summary>
using v_degF = Quantity_temp_template<Prefix::none, Temp::degF>;
/// <summary>API temperature: degree Rankine</summary>
using v_degR = Quantity_temp_template<Prefix::none, Temp::degR>;
}
}
}