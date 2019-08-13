#pragma once

#include "../quantity_ratio_tmplt.h"
#include "../time.h"

namespace nhill
{
namespace uom
{

template<typename Uom, Prefix prefix_numerator, Uom uom_numerator, Prefix prefix_denominator, Time uom_denominator, typename T = double>
using Quantity_rate_template = Quantity_ratio_template<Uom, Time, prefix_numerator, uom_numerator, prefix_denominator, uom_denominator, T>;

}
}
