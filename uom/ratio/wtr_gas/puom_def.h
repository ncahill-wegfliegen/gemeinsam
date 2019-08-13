#pragma once

#include "../../ratio/wtr_gas/puom_tmplt.h"

namespace nhill
{
namespace uom
{
namespace wgr
{
/// <summary>SI gas oil ratio: cubic metres per cubic metres.</sumamry>
using m3_per_e6m3 = Prefixed_wtr_gas_ratio_template<Prefix::none, Vol::m3, Prefix::e6, Vol::m3>;

/// <summary>API gas oil ratio: standard cubic feet per barrel.</summary>
using bbl_per_MMcf = Prefixed_wtr_gas_ratio_template<Prefix::none, Vol::bbl, Prefix::MM, Vol::cf>;
}
}
}