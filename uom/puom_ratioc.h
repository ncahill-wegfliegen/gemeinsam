#pragma once

#include "puom_ratio.h"
#include <vector>

namespace nhill
{
namespace uom
{

template<typename Uom_numerator, typename Uom_denominator>
using Prefixed_uom_ratio_container = std::vector< Prefixed_uom_ratio<Uom_numerator, Uom_denominator> >;

namespace ratio
{
template<typename Uom_numerator, typename Uom_denominator>
using puomc = Prefixed_uom_ratio_container<Uom_numerator, Uom_denominator>;
}

}
}