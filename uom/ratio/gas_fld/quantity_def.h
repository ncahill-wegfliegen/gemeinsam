#pragma once

#include "../../ratio/gas_fld/quantity_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix_numerator, Volume uom_numerator, Prefix prefix_denominator, Volume uom_denominator, typename T = double>
using Quantity_gas_fld_ratio_template = Quantity_ratio_template<Volume, Volume, prefix_numerator, uom_denominator, prefix_denominator, uom_denominator, T>;

namespace gfr
{
template<typename T = double>
using v_m3_per_m3    = Quantity_gas_fld_ratio_template<Prefix::none, Vol::m3 , Prefix::none, Vol::m3, T>;

template<typename T = double>
using v_scf_per_bbl  = Quantity_gas_fld_ratio_template<Prefix::none, Vol::scf, Prefix::none, Vol::bbl, T>;

template<typename T = double>
using v_Mscf_per_bbl = Quantity_gas_fld_ratio_template<Prefix::M   , Vol::scf, Prefix::none, Vol::bbl, T>;
}

}
}