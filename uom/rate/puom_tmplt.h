#pragma once

#include "..\puom_ratio_tmplt.h"
#include "..\time.h"

namespace nhill
{
namespace uom
{

template<typename Uom, Prefix prefix_numerator, Uom uom_numerator, Prefix prefix_denominator, Time uom_denominator>
using Prefixed_rate_template = Prefixed_uom_ratio_template<Uom, Time, prefix_numerator, uom_numerator, prefix_denominator, uom_denominator>;

}
}