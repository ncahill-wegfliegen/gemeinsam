#pragma once

#include "../vol/quantity_tmplt.h"

namespace nhill
{
namespace uom
{
namespace vol
{
/// <summary>SI volume: millimetres cubed</summary>
template<typename T = double>
using v_mm3 = Quantity_vol_template<Prefix::milli, Vol::m3, T>;
/// <summary>SI volume: centimetres cubed</summary>
template<typename T = double>
using v_cm3 = Quantity_vol_template<Prefix::centi, Vol::m3, T>;
/// <summary>SI volume: metres cubed</summary>
template<typename T = double>
using v_m3 = Quantity_vol_template<Prefix::none, Vol::m3, T>;
/// <summary>SI volume: kilometres cubed</summary>
template<typename T = double>
using v_km3 = Quantity_vol_template<Prefix::kilo, Vol::m3, T>;
/// <summary>SI volume: one thousand metres cubed</summary>
template<typename T = double>
using v_e3m3 = Quantity_vol_template<Prefix::e3, Vol::m3, T>;
/// <summary>SI volume: one million metres cubed</summary>
template<typename T = double>
using v_e6m3 = Quantity_vol_template<Prefix::e6, Vol::m3, T>;
/// <summary>SI volume: one billion metres cubed</summary>
template<typename T = double>
using v_e9m3 = Quantity_vol_template<Prefix::e9, Vol::m3, T>;
/// <summary>SI volume: hetare metre</summary>
template<typename T = double>
using v_ham = Quantity_vol_template<Prefix::none, Vol::ham, T>;


/// <summary>API volume: cubic inches</summary>
template<typename T = double>
using v_cuin = Quantity_vol_template<Prefix::none, Vol::cuin, T>;
/// <summary>API volume: cubic feet</summary>
template<typename T = double>
using v_cuft = Quantity_vol_template<Prefix::none, Vol::cuft, T>;
/// <summary>API volume: cubic yards</summary>
template<typename T = double>
using v_cuyd = Quantity_vol_template<Prefix::none, Vol::cuyd, T>;
/// <summary>API volume: cubic miles</summary>
template<typename T = double>
using v_cumi = Quantity_vol_template<Prefix::none, Vol::cumi, T>;
/// <summary>API volume: acre-feet</summary>
template<typename T = double>
using v_acft = Quantity_vol_template<Prefix::none, Vol::acft, T>;

/// <summary>API Oil volume: barrel</summary>
template<typename T = double>
using v_bbl = Quantity_vol_template<Prefix::none, Vol::bbl, T>;
/// <summary>SI volume: one thousand barrels</summary>
template<typename T = double>
using v_Mbbl = Quantity_vol_template<Prefix::M, Vol::bbl, T>;
/// <summary>SI volume: one million barrels</summary>
template<typename T = double>
using v_MMbbl = Quantity_vol_template<Prefix::MM, Vol::bbl, T>;
/// <summary>SI volume: one billion barrels</summary>
template<typename T = double>
using v_Bbbl = Quantity_vol_template<Prefix::B, Vol::bbl, T>;

/// <summary>API Oil volume: reservoir barrel</summary>
template<typename T = double>
using v_rb = Quantity_vol_template<Prefix::none, Vol::rb, T>;
/// <summary>SI volume: one thousand reservoir barrels</summary>
template<typename T = double>
using v_Mrb = Quantity_vol_template<Prefix::M, Vol::rb, T>;
/// <summary>SI volume: one million reservoir barrels</summary>
template<typename T = double>
using v_MMrb = Quantity_vol_template<Prefix::MM, Vol::rb, T>;
/// <summary>SI volume: one billion reservoir barrels</summary>
template<typename T = double>
using v_Brb = Quantity_vol_template<Prefix::B, Vol::rb, T>;

/// <summary>API Oil volume: standard barrel</summary>
template<typename T = double>
using v_stb = Quantity_vol_template<Prefix::none, Vol::stb, T>;
/// <summary>SI volume: one thousand standard barrels</summary>
template<typename T = double>
using v_Mstb = Quantity_vol_template<Prefix::M, Vol::stb, T>;
/// <summary>SI volume: one million standard barrels</summary>
template<typename T = double>
using v_MMstb = Quantity_vol_template<Prefix::MM, Vol::stb, T>;
/// <summary>SI volume: one billion standard barrels</summary>
template<typename T = double>
using v_Bstb = Quantity_vol_template<Prefix::B, Vol::stb, T>;

/// <summary>API Gas volume: cubic feet</summary>
template<typename T = double>
using v_cf = Quantity_vol_template<Prefix::none, Vol::cf, T>;
/// <summary>SI volume: one thousand cubic feet</summary>
template<typename T = double>
using v_Mcf = Quantity_vol_template<Prefix::M, Vol::cf, T>;
/// <summary>SI volume: one million cubic feet</summary>
template<typename T = double>
using v_MMcf = Quantity_vol_template<Prefix::MM, Vol::cf, T>;
/// <summary>SI volume: one billion cubic feet</summary>
template<typename T = double>
using v_Bcf = Quantity_vol_template<Prefix::B, Vol::cf, T>;

/// <summary>API Gas volume: reservoir cubic feet</summary>
template<typename T = double>
using v_rcf = Quantity_vol_template<Prefix::none, Vol::rcf, T>;
/// <summary>SI volume: one thousand reservoir cubic feet</summary>
template<typename T = double>
using v_Mrcf = Quantity_vol_template<Prefix::M, Vol::rcf, T>;
/// <summary>SI volume: one million reservoir cubic feet</summary>
template<typename T = double>
using v_MMrcf = Quantity_vol_template<Prefix::MM, Vol::rcf, T>;
/// <summary>SI volume: one billion reservoir cubic feet</summary>
template<typename T = double>
using v_Brcf = Quantity_vol_template<Prefix::B, Vol::rcf, T>;

/// <summary>API Gas volume: standard cubic feet</summary>
template<typename T = double>
using v_scf = Quantity_vol_template<Prefix::none, Vol::scf, T>;
/// <summary>SI volume: one thousand standard cubic feet</summary>
template<typename T = double>
using v_Mscf = Quantity_vol_template<Prefix::M, Vol::scf, T>;
/// <summary>SI volume: one million standard cubic feet</summary>
template<typename T = double>
using v_MMscf = Quantity_vol_template<Prefix::MM, Vol::scf, T>;
/// <summary>SI volume: one billion standard cubic feet</summary>
template<typename T = double>
using v_Bscf = Quantity_vol_template<Prefix::B, Vol::scf, T>;

/// <summary>API Gas volume: barrels of oil equivalent</summary>
template<typename T = double>
using v_boe = Quantity_vol_template<Prefix::none, Vol::boe, T>;
/// <summary>API Gas volume: one thousand barrels of oil equivalent</summary>
template<typename T = double>
using v_Mboe = Quantity_vol_template<Prefix::M, Vol::boe, T>;
/// <summary>API Gas volume:one million  barrels of oil equivalent</summary>
template<typename T = double>
using v_MMboe = Quantity_vol_template<Prefix::MM, Vol::boe, T>;
/// <summary>API Gas volume: one billion barrels of oil equivalent</summary>
template<typename T = double>
using v_Bboe = Quantity_vol_template<Prefix::B, Vol::boe, T>;
}
}
}