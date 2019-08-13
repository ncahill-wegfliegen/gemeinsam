#pragma once

#include "../../ratio/gas_oil/puom_tmplt.h"

namespace nhill
{
namespace uom
{
namespace gor
{
/// <summary>SI gas oil ratio: cubic metres per cubic metres.</sumamry>
using m3_per_m3 = Prefixed_gas_oil_ratio_template<Prefix::none, Vol::m3, Prefix::none, Vol::m3>;

/// <summary>API gas oil ratio: standard cubic feet per barrel.</summary>
using scf_per_bbl = Prefixed_gas_oil_ratio_template<Prefix::none, Vol::scf, Prefix::none, Vol::bbl>;

/// <summary>API gas oil ratio: standard thousand cubic feet per barrel.</summary>
using Mscf_per_bbl = Prefixed_gas_oil_ratio_template<Prefix::M, Vol::scf, Prefix::none, Vol::bbl>;
}
}
}