#pragma once

#include "../../fvf/quantity_fvf.h"

namespace nhill
{
namespace uom
{
template<typename T = double>
using Quantity_fvf_oil = Quantity_fvf<T>;

namespace fvf
{
namespace oil
{
template<typename T = double>
using quantity = nhill::uom::Quantity_fvf_oil<T>;
}
}

}
}
