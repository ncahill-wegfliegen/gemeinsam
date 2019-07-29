#pragma once

#include "quantity_tmplt.h"

namespace nhill
{
namespace uom
{
namespace press
{
/// <summary>SI pressure: pascal</summary>
using v_Pa = Quantity_press_template<Prefix::none, Press::Pa>;
/// <summary>SI pressure: hectopascal</summary>
using v_hPa = Quantity_press_template<Prefix::hecto, Press::Pa>;
/// <summary>SI pressure: kilopascal</summary>
using v_kPa = Quantity_press_template<Prefix::kilo, Press::Pa>;

/// <summary>SI pressure: millibar</summary>
using v_mb = Quantity_press_template<Prefix::milli, Press::bar>;
/// <summary>SI pressure: bar</summary>
using v_bar = Quantity_press_template<Prefix::none, Press::bar>;

/// <summary>API pressure: technical atmosphere</summary>
using v_at = Quantity_press_template<Prefix::none, Press::at>;
/// <summary>API pressure: atmosphere</summary>
using v_atm = Quantity_press_template<Prefix::none, Press::atm>;
/// <summary>API pressure: torr</summary>
using v_torr = Quantity_press_template<Prefix::none, Press::torr>;
/// <summary>API pressure: pounds per square inch absolute</summary>
using v_psia = Quantity_press_template<Prefix::none, Press::psia>;
/// <summary>API pressure: pounds per square inch gauge</summary>
using v_psig = Quantity_press_template<Prefix::none, Press::psig>;
}
}
}