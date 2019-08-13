#pragma once

#include "../../rate/quantity_tmplt.h"
#include "../../len.h"
#include "../../prefix.h"

namespace nill
{
namespace uom
{
namespace rate
{

template<typename T = double>
using v_mps = Quantity_rate_template<Len, Prefix::none, Len::m, Prefix::none, Time::s, T>;

template<typename T = double>
using v_kmps = Quantity_rate_template<Len, Prefix::kilo, Len::m, Prefix::none, Time::s, T>;

template<typename T = double>
using v_kmph = Quantity_rate_template<Len, Prefix::kilo, Len::m, Prefix::none, Time::h, T>;

}
}
}
