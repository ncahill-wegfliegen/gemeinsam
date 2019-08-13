#pragma once

#include "../../quantity_ratio.h"
#include "../../vol.h"

namespace nhill
{
namespace uom
{

template<typename T = double>
using Quantity_cnd_gas_ratio = Quantity_ratio<Volume, Volume, T>;

namespace cgr
{
template<typename T = double>
using quantity = Quantity_cnd_gas_ratio<T>;
}

}
}
