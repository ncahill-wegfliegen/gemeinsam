#pragma once

#include "../../quantity_ratio.h"
#include "../../vol.h"

namespace nhill
{
namespace uom
{

template<typename T = double>
using Quantity_gas_oil_ratio = Quantity_ratio<Volume, Volume, T>;

namespace gor
{
template<typename T = double>
using quantity = Quantity_gas_oil_ratio<T>;
}

}
}
