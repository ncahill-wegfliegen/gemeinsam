#pragma once

#include "../quantity_ratio.h"
#include "../vol.h"

namespace nhill
{
namespace uom
{
template<typename T = double>
using Quantity_fvf = Quantity_ratio<Volume, Volume, T>;

namespace fvf
{
template<typename T = double>
using Quantity = Quantity_fvf<T>;
}
}
}
