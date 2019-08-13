#pragma once

#include "../../vol.h"
#include "../../quantity_ratio_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix_numerator, Volume uom_numerator, Prefix prefix_denominator, Volume uom_denominator, typename T = double>
using Quantity_fvf_gas_template = Quantity_ratio_template<Volume, Volume, prefix_numerator, uom_denominator, prefix_denominator, uom_denominator, T>;

}
}