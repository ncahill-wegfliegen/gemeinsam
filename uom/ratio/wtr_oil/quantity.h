#pragma once

#include "../../quantity_ratio.h"
#include "../../vol.h"

namespace nhill
{
namespace uom
{
template<typename T = double>
using Quantity_wtr_oil_ratio = Quantity_ratio<Volume, Volume, T>;

namespace wor
{
template<typename T = double>
using quantity = Quantity_wtr_oil_ratio<T>;
}

}
}
