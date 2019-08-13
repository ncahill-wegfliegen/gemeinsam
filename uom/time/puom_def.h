#pragma once

#include "../time/puom_tmplt.h"

namespace nhill
{
namespace uom
{
namespace time
{
/// <summary>Prefixed unit of time: second</summary>
using s = Prefixed_time_template<Prefix::none, Time::s>;
/// <summary>Prefixed unit of time: minute</summary>
using min = Prefixed_time_template<Prefix::none, Time::min>;
/// <summary>Prefixed unit of time: hour</summary>
using h = Prefixed_time_template<Prefix::none, Time::h>;
/// <summary>Prefixed unit of time: day</summary>
using d = Prefixed_time_template<Prefix::none, Time::d>;
/// <summary>Prefixed unit of time: week</summary>
using wk = Prefixed_time_template<Prefix::none, Time::wk>;
/// <summary>Prefixed unit of time: month</summary>
using mo = Prefixed_time_template<Prefix::none, Time::mo>;
/// <summary>Prefixed unit of time: year</summary>
using yr = Prefixed_time_template<Prefix::none, Time::yr>;
}
}
}