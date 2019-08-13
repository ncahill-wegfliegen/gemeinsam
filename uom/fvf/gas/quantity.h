#pragma once

#include "../../fvf/quantity_fvf.h"

namespace nhill
{
namespace uom
{
template<typename T = double>
using Quantity_fvf_gas = Quantity_fvf<T>;

namespace fvf
{
namespace gas
{
template<typename T = double>
using quantity = nhill::uom::Quantity_fvf_gas<T>;
}
}

}
}
