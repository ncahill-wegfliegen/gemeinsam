#pragma once

#include "puom_tmplt.h"

namespace nhill
{
namespace uom
{
namespace vol
{

/// <summary>SI volume: millimetres cubed</summary>
using mm3 = Prefixed_vol_template<Prefix::milli, Vol::m3>;
/// <summary>SI volume: centimetres cubed</summary>
using cm3 = Prefixed_vol_template<Prefix::centi, Vol::m3>;
/// <summary>SI volume: metres cubed</summary>
using m3 = Prefixed_vol_template<Prefix::none, Vol::m3>;
/// <summary>SI volume: kilometres cubed</summary>
using km3 = Prefixed_vol_template<Prefix::kilo, Vol::m3>;
/// <summary>SI volume: one thousand metres cubed</summary>
using e3m3 = Prefixed_vol_template<Prefix::e3, Vol::m3>;
/// <summary>SI volume: one million metres cubed</summary>
using e6m3 = Prefixed_vol_template<Prefix::e6, Vol::m3>;
/// <summary>SI volume: one billion metres cubed</summary>
using e9m3 = Prefixed_vol_template<Prefix::e9, Vol::m3>;
/// <summary>SI volume: hectare metre</summary>
using ham = Prefixed_vol_template<Prefix::none, Vol::ham>;

/// <summary>API volume: cubic inches</summary>
using cuin = Prefixed_vol_template<Prefix::none, Vol::cuin>;
/// <summary>API volume: cubic feet</summary>
using cuft = Prefixed_vol_template<Prefix::none, Vol::cuft>;
/// <summary>API volume: cubic yards</summary>
using cuyd = Prefixed_vol_template<Prefix::none, Vol::cuyd>;
/// <summary>API volume: cubic miles</summary>
using cumi = Prefixed_vol_template<Prefix::none, Vol::cumi>;
/// <summary>API volume: acre-feet</summary>
using acft = Prefixed_vol_template<Prefix::none, Vol::acft>;

/// <summary>API Oil volume: barrel</summary>
using bbl = Prefixed_vol_template<Prefix::none, Vol::bbl>;
/// <summary>SI volume: one thousand barrels</summary>
using Mbbl = Prefixed_vol_template<Prefix::M, Vol::bbl>;
/// <summary>SI volume: one million barrels</summary>
using MMbbl = Prefixed_vol_template<Prefix::MM, Vol::bbl>;
/// <summary>SI volume: one billion barrels</summary>
using Bbbl = Prefixed_vol_template<Prefix::B, Vol::bbl>;

/// <summary>API Oil volume: reservoir barrel</summary>
using rb = Prefixed_vol_template<Prefix::none, Vol::rb>;
/// <summary>SI volume: one thousand reservoir barrels</summary>
using Mrb = Prefixed_vol_template<Prefix::M, Vol::rb>;
/// <summary>SI volume: one million reservoir barrels</summary>
using MMrb = Prefixed_vol_template<Prefix::MM, Vol::rb>;
/// <summary>SI volume: one billion reservoir barrels</summary>
using Brb = Prefixed_vol_template<Prefix::B, Vol::rb>;

/// <summary>API Oil volume: standard barrel</summary>
using stb = Prefixed_vol_template<Prefix::none, Vol::stb>;
/// <summary>SI volume: one thousand standard barrels</summary>
using Mstb = Prefixed_vol_template<Prefix::M, Vol::stb>;
/// <summary>SI volume: one million standard barrels</summary>
using MMstb = Prefixed_vol_template<Prefix::MM, Vol::stb>;
/// <summary>SI volume: one billion standard barrels</summary>
using Bstb = Prefixed_vol_template<Prefix::B, Vol::stb>;

/// <summary>API Gas volume: cubic feet</summary>
using cf = Prefixed_vol_template<Prefix::none, Vol::cf>;
/// <summary>SI volume: one thousand cubic feet</summary>
using Mcf = Prefixed_vol_template<Prefix::M, Vol::cf>;
/// <summary>SI volume: one million cubic feet</summary>
using MMcf = Prefixed_vol_template<Prefix::MM, Vol::cf>;
/// <summary>SI volume: one billion cubic feet</summary>
using Bcf = Prefixed_vol_template<Prefix::B, Vol::cf>;

/// <summary>API Gas volume: reservoir cubic feet</summary>
using rcf = Prefixed_vol_template<Prefix::none, Vol::rcf>;
/// <summary>SI volume: one thousand reservoir cubic feet</summary>
using Mrcf = Prefixed_vol_template<Prefix::M, Vol::rcf>;
/// <summary>SI volume: one million reservoir cubic feet</summary>
using MMrcf = Prefixed_vol_template<Prefix::MM, Vol::rcf>;
/// <summary>SI volume: one billion reservoir cubic feet</summary>
using Brcf = Prefixed_vol_template<Prefix::B, Vol::rcf>;

/// <summary>API Gas volume: standard cubic feet</summary>
using scf = Prefixed_vol_template<Prefix::none, Vol::scf>;
/// <summary>SI volume: one thousand standard cubic feet</summary>
using Mscf = Prefixed_vol_template<Prefix::M, Vol::scf>;
/// <summary>SI volume: one million standard cubic feet</summary>
using MMscf = Prefixed_vol_template<Prefix::MM, Vol::scf>;
/// <summary>SI volume: one billion standard cubic feet</summary>
using Bscf = Prefixed_vol_template<Prefix::B, Vol::scf>;

/// <summary>API Gas volume: barrels of oil equivalent</summary>
using boe = Prefixed_vol_template<Prefix::none, Vol::boe>;
/// <summary>API Gas volume: one thousand barrels of oil equivalent</summary>
using Mboe = Prefixed_vol_template<Prefix::M, Vol::boe>;
/// <summary>API Gas volume:one million  barrels of oil equivalent</summary>
using MMboe = Prefixed_vol_template<Prefix::MM, Vol::boe>;
/// <summary>API Gas volume: one billion barrels of oil equivalent</summary>
using Bboe = Prefixed_vol_template<Prefix::B, Vol::boe>;

}
}
}