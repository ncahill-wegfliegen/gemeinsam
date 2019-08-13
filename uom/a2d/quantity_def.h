#pragma once

#include "../a2d/quantity_tmplt.h"

namespace nhill
{
namespace uom
{
namespace a2d
{
/// <summary>SI two-dimensional area quantity: millimetre squared</summary>
template<typename T = double>
using v_mm2 = Quantity_a2d_template<Prefix::milli, A2d::m2, T>;
/// <summary>SI two-dimensional area quantity: centimetre sqaured</summary>
template<typename T = double>
using v_cm2 = Quantity_a2d_template<Prefix::centi, A2d::m2, T>;
/// <summary>SI two-dimensional area quantity: metre sqaured</summary>
template<typename T = double>
using v_m2 = Quantity_a2d_template<Prefix::none, A2d::m2, T>;
/// <summary>SI two-dimensional area quantity: kilometre squared</summary>
template<typename T = double>
using v_km2 = Quantity_a2d_template<Prefix::kilo, A2d::m2, T>;

/// <summary>API two-dimensional area quantity: square feet</summary>
template<typename T = double>
using v_sqft = Quantity_a2d_template<Prefix::none, A2d::sqft, T>;
/// <summary>SI two-dimensional area quantity: hectare</summary>
template<typename T = double>
using v_ha = Quantity_a2d_template<Prefix::none, A2d::ha, T>;
/// <summary>API two-dimensional area quantity: acre</summary>
template<typename T = double>
using v_ac = Quantity_a2d_template<Prefix::none, A2d::ac, T>;
}
}
}