#pragma once

#include "../../ratio/wtr_oil/quantity_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix_numerator, Volume uom_numerator, Prefix prefix_denominator, Volume uom_denominator, typename T = double>
using Quantity_wtr_oil_ratio_template = Quantity_ratio_template<Volume, Volume, prefix_numerator, uom_denominator, prefix_denominator, uom_denominator, T>;

namespace wor
{
template<typename T = double>
using v_m3_per_m3   = Quantity_wtr_oil_ratio_template<Prefix::none, Vol::m3 , Prefix::none, Vol::m3 , T>;
template<typename T = double>
using v_bbl_per_bbl = Quantity_wtr_oil_ratio_template<Prefix::none, Vol::bbl, Prefix::none, Vol::bbl, T>;
}

}
}