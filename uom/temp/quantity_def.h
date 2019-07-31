#pragma once

#include "quantity_tmplt.h"

namespace nhill
{
namespace uom
{
namespace temp
{
/// <summary>SI temperature: kelvin</summary>
template<typename T = double>
using v_K = Quantity_temp_template<Prefix::none, Temp::K, T>;

/// <summary>API temperature: degree Celsius</summary>
template<typename T = double>
using v_degC = Quantity_temp_template<Prefix::none, Temp::degC, T>;
/// <summary>API temperature: degree Fahrenheit</summary>
template<typename T = double>
using v_degF = Quantity_temp_template<Prefix::none, Temp::degF, T>;
/// <summary>API temperature: degree Rankine</summary>
template<typename T = double>
using v_degR = Quantity_temp_template<Prefix::none, Temp::degR, T>;
}
}
}