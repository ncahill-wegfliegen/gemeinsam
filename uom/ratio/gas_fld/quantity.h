#pragma once

#include "../../quantity_ratio.h"
#include "../../vol.h"

namespace nhill
{
namespace uom
{

template<typename T = double>
using Quantity_gas_fld_ratio = Quantity_ratio<Volume, Volume, T>;

namespace gfr
{
template<typename T = double>
using quantity = Quantity_gas_fld_ratio<T>;
}

}
}
