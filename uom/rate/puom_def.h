#pragma once

#include "puom_tmplt.h"
#include "..\vol.h"

namespace nhill
{
namespace uom
{
namespace rate
{

/// <summary>SI oil rate: metres cubed per day</summary>
using m3d = Prefixed_rate_template<Vol, Prefix::none, Vol::m3, Prefix::none, Time::d>;
/// <summary>SI oil rate: one thousand metres cubed per day</summary>
using e3m3d = Prefixed_rate_template<Vol, Prefix::e3, Vol::m3, Prefix::none, Time::d>;
/// <summary>SI oil rate: one million metres cubed per day</summary>
using e6m3d = Prefixed_rate_template<Vol, Prefix::e6, Vol::m3, Prefix::none, Time::d>;
/// <summary>SI oil rate: one billion metres cubed per day</summary>
using e9m3d = Prefixed_rate_template<Vol, Prefix::e9, Vol::m3, Prefix::none, Time::d>;

/// <summary>API oil rate: barrels per day</summary>
using bbld = Prefixed_rate_template<Vol, Prefix::none, Vol::bbl, Prefix::none, Time::d>;
/// <summary>SI rate: one thousand barrels per day</summary>
using Mbbld = Prefixed_rate_template<Vol, Prefix::M, Vol::bbl, Prefix::none, Time::d>;
/// <summary>SI rate: one million barrels per day</summary>
using MMbbld = Prefixed_rate_template<Vol, Prefix::MM, Vol::bbl, Prefix::none, Time::d>;
/// <summary>SI rate: one billion barrels per day</summary>
using Bbbld = Prefixed_rate_template<Vol, Prefix::B, Vol::bbl, Prefix::none, Time::d>;

/// <summary>API oil rate: reservoir barrels per day</summary>
using rbd = Prefixed_rate_template<Vol, Prefix::none, Vol::rb, Prefix::none, Time::d>;
/// <summary>API oil rate: one thousand reservoir barrels per day</summary>
using Mrbd = Prefixed_rate_template<Vol, Prefix::M, Vol::rb, Prefix::none, Time::d>;
/// <summary>API oil rate: one million reservoir barrels per day</summary>
using MMrbd = Prefixed_rate_template<Vol, Prefix::MM, Vol::rb, Prefix::none, Time::d>;
/// <summary>API oil rate: one billion reservoir barrels per day</summary>
using Brbd = Prefixed_rate_template<Vol, Prefix::B, Vol::rb, Prefix::none, Time::d>;

/// <summary>API oil rate: standard barrels per day</summary>
using stbd = Prefixed_rate_template<Vol, Prefix::none, Vol::stb, Prefix::none, Time::d>;
/// <summary>API oil rate: one thousand standard barrels per day</summary>
using Mstbd = Prefixed_rate_template<Vol, Prefix::M, Vol::stb, Prefix::none, Time::d>;
/// <summary>API oil rate: one million standard barrels per day</summary>
using MMstbd = Prefixed_rate_template<Vol, Prefix::MM, Vol::stb, Prefix::none, Time::d>;
/// <summary>API oil rate: one billion standard barrels per day</summary>
using Bstbd = Prefixed_rate_template<Vol, Prefix::B, Vol::stb, Prefix::none, Time::d>;

/// <summary>API gas rate: cubic feet per day</summary>
using cfd = Prefixed_rate_template<Vol, Prefix::none, Vol::cf, Prefix::none, Time::d>;
/// <summary>SI gas rate: one thousand cubic feet per day</summary>
using Mcfd = Prefixed_rate_template<Vol, Prefix::M, Vol::cf, Prefix::none, Time::d>;
/// <summary>SI gas rate: one million cubic feet per day</summary>
using MMcfd = Prefixed_rate_template<Vol, Prefix::MM, Vol::cf, Prefix::none, Time::d>;
/// <summary>SI gas rate: one billion cubic feet per day</summary>
using Bcfd = Prefixed_rate_template<Vol, Prefix::B, Vol::cf, Prefix::none, Time::d>;

/// <summary>API gas rate: reservoir cubic feet per day</summary>
using rcfd = Prefixed_rate_template<Vol, Prefix::none, Vol::rcf, Prefix::none, Time::d>;
/// <summary>API gas rate: one thousand reservoir cubic feet per day</summary>
using Mrcfd = Prefixed_rate_template<Vol, Prefix::M, Vol::rcf, Prefix::none, Time::d>;
/// <summary>API gas rate: one million reservoir cubic feet per day</summary>
using MMrcfd = Prefixed_rate_template<Vol, Prefix::MM, Vol::rcf, Prefix::none, Time::d>;
/// <summary>API gas rate: one billion reservoir cubic feet per day</summary>
using Brcfd = Prefixed_rate_template<Vol, Prefix::B, Vol::rcf, Prefix::none, Time::d>;

/// <summary>API gas rate: standard cubic feet per day</summary>
using scfd = Prefixed_rate_template<Vol, Prefix::none, Vol::scf, Prefix::none, Time::d>;
/// <summary>API gas rate: one thousand standard cubic feet per day</summary>
using Mscfd = Prefixed_rate_template<Vol, Prefix::M, Vol::scf, Prefix::none, Time::d>;
/// <summary>API gas rate: one million standard cubic feet per day</summary>
using MMscfd = Prefixed_rate_template<Vol, Prefix::MM, Vol::scf, Prefix::none, Time::d>;
/// <summary>API gas rate: one billion standard cubic feet per day</summary>
using Bscfd = Prefixed_rate_template<Vol, Prefix::B, Vol::scf, Prefix::none, Time::d>;

/// <summary>API gas rate: barrels of oil equivalent per day</summary>
using boed = Prefixed_rate_template<Vol, Prefix::none, Vol::boe, Prefix::none, Time::d>;
/// <summary>API gas rate: one thousand barrels of oil equivalent per day</summary>
using Mboed = Prefixed_rate_template<Vol, Prefix::M, Vol::boe, Prefix::none, Time::d>;
/// <summary>API gas rate: one million  barrels of oil equivalent per day</summary>
using MMboed = Prefixed_rate_template<Vol, Prefix::MM, Vol::boe, Prefix::none, Time::d>;
/// <summary>API gas rate: one billion barrels of oil equivalent per day</summary>
using Bboed = Prefixed_rate_template<Vol, Prefix::B, Vol::boe, Prefix::none, Time::d>;

}
}
}