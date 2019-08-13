#pragma once

#include "../quantity_ratio.h"
#include "../time.h"

namespace nhill
{
namespace uom
{

template<typename Uom, typename T = double>
using Quantity_rate = Quantity_ratio<Uom, Time, T>;

namespace rate
{
template<typename Uom, typename T = double>
using quantity = Quantity_rate<Uom, T>;
}

}
}
