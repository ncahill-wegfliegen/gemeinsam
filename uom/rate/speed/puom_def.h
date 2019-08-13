#pragma once

#include "../../rate/puom_tmplt.h"
#include "../../len.h"

namespace nhill
{
namespace uom
{
namespace rate
{

/// <summary>Metres per second.</summary>
template<typename T = double>
using mps = Prefixed_rate_template<Len, Prefix::none, Len::m, Prefix::none, Time::s, T>;
/// <summary>Kilometres per second.</summary>
template<typename T = double>
using kmps = Prefixed_rate_template<Len, Prefix::kilo, Len::m, Prefix::none, Time::s, T>;

/// <summary>Kilometres per hour.</summary>
template<typename T = double>
using kmph = Prefixed_rate_template<Len, Prefix::kilo, Len::m, Prefix::none, Time::h, T>;

}
}
}
