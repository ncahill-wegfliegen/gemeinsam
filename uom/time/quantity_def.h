#pragma once

#include "quantity_tmplt.h"

namespace nhill
{
namespace uom
{
namespace time
{
/// <summary>Quantity of time: second</summary>
template<typename T = double>
using v_s = Quantity_time_template<Prefix::none, Time::s, T>;
/// <summary>Quantity of time: minute</summary>
template<typename T = double>
using v_min = Quantity_time_template<Prefix::none, Time::min, T>;
/// <summary>Quantity of time: hour</summary>
template<typename T = double>
using v_h = Quantity_time_template<Prefix::none, Time::h, T>;
/// <summary>Quantity of time: day</summary>
template<typename T = double>
using v_d = Quantity_time_template<Prefix::none, Time::d, T>;
/// <summary>Quantity of time: week</summary>
template<typename T = double>
using v_wk = Quantity_time_template<Prefix::none, Time::wk, T>;
/// <summary>Quantity of time: month</summary>
template<typename T = double>
using v_mo = Quantity_time_template<Prefix::none, Time::mo, T>;
/// <summary>Quantity of time: year</summary>
template<typename T = double>
using v_yr = Quantity_time_template<Prefix::none, Time::yr, T>;
}
}
}