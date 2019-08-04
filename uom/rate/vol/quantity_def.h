#pragma once

#include "..\quantity_tmplt.h"
#include "..\..\vol.h"

namespace nhill
{
namespace uom
{
namespace rate
{

/// <summary>SI oil rate: metres cubed per day</summary>
template<typename T = double>
using v_m3d = Quantity_rate_template<Vol, Prefix::none, Vol::m3, Prefix::none, Time::d, T>;
/// <summary>SI oil rate: one thousand metres cubed per day</summary>
template<typename T = double>
using v_e3m3d = Quantity_rate_template<Vol, Prefix::e3, Vol::m3, Prefix::none, Time::d, T>;
/// <summary>SI oil rate: one million metres cubed per day</summary>
template<typename T = double>
using v_e6m3d = Quantity_rate_template<Vol, Prefix::e6, Vol::m3, Prefix::none, Time::d, T>;
/// <summary>SI oil rate: one billion metres cubed per day</summary>
template<typename T = double>
using v_e9m3d = Quantity_rate_template<Vol, Prefix::e9, Vol::m3, Prefix::none, Time::d, T>;

/// <summary>API oil rate: barrel per day</summary>
template<typename T = double>
using v_bbld = Quantity_rate_template<Vol, Prefix::none, Vol::bbl, Prefix::none, Time::d, T>;
/// <summary>SI rate: one thousand barrels per day</summary>
template<typename T = double>
using v_Mbbld = Quantity_rate_template<Vol, Prefix::M, Vol::bbl, Prefix::none, Time::d, T>;
/// <summary>SI rate: one million barrels per day</summary>
template<typename T = double>
using v_MMbbld = Quantity_rate_template<Vol, Prefix::MM, Vol::bbl, Prefix::none, Time::d, T>;
/// <summary>SI rate: one billion barrels per day</summary>
template<typename T = double>
using v_Bbbld = Quantity_rate_template<Vol, Prefix::B, Vol::bbl, Prefix::none, Time::d, T>;

/// <summary>API oil rate: reservoir barrel per day</summary>
template<typename T = double>
using v_rbd = Quantity_rate_template<Vol, Prefix::none, Vol::rb, Prefix::none, Time::d, T>;
/// <summary>API oil rate: one thousand reservoir barrels per day</summary>
template<typename T = double>
using v_Mrbd = Quantity_rate_template<Vol, Prefix::M, Vol::rb, Prefix::none, Time::d, T>;
/// <summary>API oil rate: one million reservoir barrels per day</summary>
template<typename T = double>
using v_MMrbd = Quantity_rate_template<Vol, Prefix::MM, Vol::rb, Prefix::none, Time::d, T>;
/// <summary>API oil rate: one billion reservoir barrels per day</summary>
template<typename T = double>
using v_Brbd = Quantity_rate_template<Vol, Prefix::B, Vol::rb, Prefix::none, Time::d, T>;

/// <summary>API oil rate: standard barrel per day</summary>
template<typename T = double>
using v_stbd = Quantity_rate_template<Vol, Prefix::none, Vol::stb, Prefix::none, Time::d, T>;
/// <summary>API oil rate: one thousand standard barrels per day</summary>
template<typename T = double>
using v_Mstbd = Quantity_rate_template<Vol, Prefix::M, Vol::stb, Prefix::none, Time::d, T>;
/// <summary>API oil rate: one million standard barrels per day</summary>
template<typename T = double>
using v_MMstbd = Quantity_rate_template<Vol, Prefix::MM, Vol::stb, Prefix::none, Time::d, T>;
/// <summary>API oil rate: one billion standard barrels per day</summary>
template<typename T = double>
using v_Bstbd = Quantity_rate_template<Vol, Prefix::B, Vol::stb, Prefix::none, Time::d, T>;

/// <summary>API gas rate: cubic feet per day</summary>
template<typename T = double>
using v_cfd = Quantity_rate_template<Vol, Prefix::none, Vol::cf, Prefix::none, Time::d, T>;
/// <summary>SI gas rate: one thousand cubic feet per day</summary>
template<typename T = double>
using v_Mcfd = Quantity_rate_template<Vol, Prefix::M, Vol::cf, Prefix::none, Time::d, T>;
/// <summary>SI gas rate: one million cubic feet per day</summary>
template<typename T = double>
using v_MMcfd = Quantity_rate_template<Vol, Prefix::MM, Vol::cf, Prefix::none, Time::d, T>;
/// <summary>SI gas rate: one billion cubic feet per day</summary>
template<typename T = double>
using v_Bcfd = Quantity_rate_template<Vol, Prefix::B, Vol::cf, Prefix::none, Time::d, T>;

/// <summary>API gas rate: reservoir cubic feet per day</summary>
template<typename T = double>
using v_rcfd = Quantity_rate_template<Vol, Prefix::none, Vol::rcf, Prefix::none, Time::d, T>;
/// <summary>API gas rate: one thousand reservoir cubic feet per day</summary>
template<typename T = double>
using v_Mrcfd = Quantity_rate_template<Vol, Prefix::M, Vol::rcf, Prefix::none, Time::d, T>;
/// <summary>API gas rate: one million reservoir cubic feet per day</summary>
template<typename T = double>
using v_MMrcfd = Quantity_rate_template<Vol, Prefix::MM, Vol::rcf, Prefix::none, Time::d, T>;
/// <summary>API gas rate: one billion reservoir cubic feet per day</summary>
template<typename T = double>
using v_Brcfd = Quantity_rate_template<Vol, Prefix::B, Vol::rcf, Prefix::none, Time::d, T>;

/// <summary>API gas rate: standard cubic feet per day</summary>
template<typename T = double>
using v_scfd = Quantity_rate_template<Vol, Prefix::none, Vol::scf, Prefix::none, Time::d, T>;
/// <summary>API gas rate: one thousand standard cubic feet per day</summary>
template<typename T = double>
using v_Mscfd = Quantity_rate_template<Vol, Prefix::M, Vol::scf, Prefix::none, Time::d, T>;
/// <summary>API gas rate: one million standard cubic feet per day</summary>
template<typename T = double>
using v_MMscfd = Quantity_rate_template<Vol, Prefix::MM, Vol::scf, Prefix::none, Time::d, T>;
/// <summary>API gas rate: one billion standard cubic feet per day</summary>
template<typename T = double>
using v_Bscfd = Quantity_rate_template<Vol, Prefix::B, Vol::scf, Prefix::none, Time::d, T>;

/// <summary>API gas rate: barrels of oil equivalent per day</summary>
template<typename T = double>
using v_boed = Quantity_rate_template<Vol, Prefix::none, Vol::boe, Prefix::none, Time::d, T>;
/// <summary>API gas rate: one thousand barrels of oil equivalent per day</summary>
template<typename T = double>
using v_Mboed = Quantity_rate_template<Vol, Prefix::M, Vol::boe, Prefix::none, Time::d, T>;
/// <summary>API gas rate:one million  barrels of oil equivalent per day</summary>
template<typename T = double>
using v_MMboed = Quantity_rate_template<Vol, Prefix::MM, Vol::boe, Prefix::none, Time::d, T>;
/// <summary>API gas rate: one billion barrels of oil equivalent per day</summary>
template<typename T = double>
using v_Bboed = Quantity_rate_template<Vol, Prefix::B, Vol::boe, Prefix::none, Time::d, T>;

}
}
}

