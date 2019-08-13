#pragma once

#include "../../fvf/oil/quantity_tmplt.h"

namespace nhill
{
namespace uom
{
namespace fvf
{
namespace oil
{
template<typename T = double>
using v_rb_per_stb = Quantity_fvf_oil_template<Prefix::none, Vol::rb, Prefix::none, Vol::stb, T>;
template<typename T = double>
using v_m3_per_m3  = Quantity_fvf_oil_template<Prefix::none, Vol::m3, Prefix::none, Vol::m3 , T>;
}
}
}
}