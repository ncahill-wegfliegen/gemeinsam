#pragma once

#include "../../ratio/wtr_oil/puom_tmplt.h"

namespace nhill
{
namespace uom
{
namespace wor
{
/// <summary>SI gas oil ratio: cubic metres per cubic metres.</sumamry>
using m3_per_m3 = Prefixed_wtr_oil_ratio_template<Prefix::none, Vol::m3, Prefix::none, Vol::m3>;

/// <summary>API gas oil ratio: standard cubic feet per barrel.</summary>
using bbl_per_bbl = Prefixed_wtr_oil_ratio_template<Prefix::none, Vol::bbl, Prefix::none, Vol::bbl>;
}
}
}