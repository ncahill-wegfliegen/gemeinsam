#pragma once

#include "puom_ratio.h"

namespace nhill
{
namespace uom
{

template<typename Uom_numerator, typename Uom_denominator, Prefix prefix_numerator, Uom_numerator uom_numerator, Prefix prefix_denominator, Uom_denominator uom_denominator>
class Prefixed_uom_ratio_template : public Prefixed_uom_ratio<Uom_numerator, Uom_denominator>
{
public:
	using base = Prefixed_uom_ratio<Uom_numerator, Uom_denominator>;
	using base::base;
};

namespace ratio
{
template<typename Uom_numerator, typename Uom_denominator, Prefix prefix_numerator, Uom_numerator uom_numerator, Prefix prefix_denominator, Uom_denominator uom_denominator>
using puom_def = Prefixed_uom_ratio_template<Uom_numerator, Uom_denominator, prefix_numerator, uom_numerator, prefix_denominator, uom_denominator>;
}
}
}
