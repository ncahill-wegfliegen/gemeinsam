#pragma once

#include "../../ratio/gas_oil/quantity_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix_numerator, Volume uom_numerator, Prefix prefix_denominator, Volume uom_denominator, typename T = double>
using Quantity_gas_oil_ratio_template = Quantity_ratio_template<Volume, Volume, prefix_numerator, uom_denominator, prefix_denominator, uom_denominator, T>;

namespace gor
{
template<typename T = double>
using v_m3_per_m3   = Quantity_gas_oil_ratio_template<Prefix::none, Vol::m3 , Prefix::none, Vol::m3 , T>;

template<typename T = double>
using v_scf_per_bbl = Quantity_gas_oil_ratio_template<Prefix::none, Vol::scf, Prefix::none, Vol::bbl, T>;
}

}
}