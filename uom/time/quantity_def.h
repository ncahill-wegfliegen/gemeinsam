#pragma once

#include "quantity_tmplt.h"

namespace nhill
{
namespace uom
{
namespace time
{
/// <summary>Quantity of time: second</summary>
using v_s = Quantity_time_template<Prefix::none, Time::s>;
/// <summary>Quantity of time: minute</summary>
using v_min = Quantity_time_template<Prefix::none, Time::min>;
/// <summary>Quantity of time: hour</summary>
using v_h = Quantity_time_template<Prefix::none, Time::h>;
/// <summary>Quantity of time: day</summary>
using v_d = Quantity_time_template<Prefix::none, Time::d>;
/// <summary>Quantity of time: week</summary>
using v_wk = Quantity_time_template<Prefix::none, Time::wk>;
/// <summary>Quantity of time: month</summary>
using v_mo = Quantity_time_template<Prefix::none, Time::mo>;
/// <summary>Quantity of time: year</summary>
using v_yr = Quantity_time_template<Prefix::none, Time::yr>;
}
}
}