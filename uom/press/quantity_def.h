#pragma once

#include "quantity_tmplt.h"

namespace nhill
{
namespace uom
{
namespace press
{
/// <summary>SI pressure: pascal</summary>
template<typename T = double>
using v_Pa = Quantity_press_template<Prefix::none, Press::Pa, T>;
/// <summary>SI pressure: hectopascal</summary>
template<typename T = double>
using v_hPa = Quantity_press_template<Prefix::hecto, Press::Pa, T>;
/// <summary>SI pressure: kilopascal</summary>
template<typename T = double>
using v_kPa = Quantity_press_template<Prefix::kilo, Press::Pa, T>;

/// <summary>SI pressure: millibar</summary>
template<typename T = double>
using v_mb = Quantity_press_template<Prefix::milli, Press::bar, T>;
/// <summary>SI pressure: bar</summary>
template<typename T = double>
using v_bar = Quantity_press_template<Prefix::none, Press::bar, T>;

/// <summary>API pressure: technical atmosphere</summary>
template<typename T = double>
using v_at = Quantity_press_template<Prefix::none, Press::at, T>;
/// <summary>API pressure: atmosphere</summary>
template<typename T = double>
using v_atm = Quantity_press_template<Prefix::none, Press::atm, T>;
/// <summary>API pressure: torr</summary>
template<typename T = double>
using v_torr = Quantity_press_template<Prefix::none, Press::torr, T>;
/// <summary>API pressure: pounds per square inch absolute</summary>
template<typename T = double>
using v_psia = Quantity_press_template<Prefix::none, Press::psia, T>;
/// <summary>API pressure: pounds per square inch gauge</summary>
template<typename T = double>
using v_psig = Quantity_press_template<Prefix::none, Press::psig, T>;
}
}
}