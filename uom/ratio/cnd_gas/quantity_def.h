#pragma once

#include "../../ratio/cnd_gas/quantity_tmplt.h"
#include "../../vol.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix_numerator, Volume uom_numerator, Prefix prefix_denominator, Volume uom_denominator, typename T = double>
using Quantity_cnd_gas_ratio_template = Quantity_ratio_template<Volume, Volume, prefix_numerator, uom_denominator, prefix_denominator, uom_denominator, T>;

namespace cgr
{
template<typename T = double>
using v_m3_per_e6m3  = Quantity_cnd_gas_ratio_template<Prefix::none, Vol::m3 , Prefix::e6, Vol::m3, T>;

template<typename T = double>
using v_bbl_per_MMcf = Quantity_cnd_gas_ratio_template<Prefix::none, Vol::bbl, Prefix::MM, Vol::cf, T>;
}

}
}