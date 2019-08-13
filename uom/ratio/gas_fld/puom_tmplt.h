#pragma once

#include "../../puom_ratio_tmplt.h"
#include "../../vol.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix_numerator, Volume uom_numerator, Prefix prefix_denominator, Volume uom_denominator>
using Prefixed_gas_fld_ratio_template = Prefixed_uom_ratio_template<Volume, Volume, prefix_numerator, uom_numerator, prefix_denominator, uom_denominator>;

}
}
