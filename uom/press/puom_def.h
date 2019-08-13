#pragma once

#include "../press/puom_tmplt.h"

namespace nhill
{
namespace uom
{
namespace press
{
/// <summary>SI pressure: pascal</summary>
using Pa = Prefixed_press_template<Prefix::none, Press::Pa>;
/// <summary>SI pressure: hectopascal</summary>
using hPa = Prefixed_press_template<Prefix::hecto, Press::Pa>;
/// <summary>SI pressure: kilopascal</summary>
using kPa = Prefixed_press_template<Prefix::kilo, Press::Pa>;

/// <summary>SI pressure: millibar</summary>
using mb = Prefixed_press_template<Prefix::milli, Press::bar>;
/// <summary>SI pressure: bar</summary>
using bar = Prefixed_press_template<Prefix::none, Press::bar>;

/// <summary>API pressure: technical atmosphere</summary>
using at = Prefixed_press_template<Prefix::none, Press::at>;
/// <summary>API pressure: atmosphere</summary>
using atm = Prefixed_press_template<Prefix::none, Press::atm>;
/// <summary>API pressure: torr</summary>
using torr = Prefixed_press_template<Prefix::none, Press::torr>;
/// <summary>API pressure: pounds per square inch absolute</summary>
using psia = Prefixed_press_template<Prefix::none, Press::psia>;
/// <summary>API pressure: pounds per square inch gauge</summary>
using psig = Prefixed_press_template<Prefix::none, Press::psig>;
}
}
}