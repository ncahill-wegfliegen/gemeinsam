#pragma once

#include "../../fvf/oil/puom_tmplt.h"

namespace nhill
{
namespace uom
{
namespace fvf
{
namespace oil
{
using rb_per_stb = Prefixed_uom_fvf_oil_template<Prefix::none, Vol::rb, Prefix::none, Vol::stb>;
using m3_per_m3  = Prefixed_uom_fvf_oil_template<Prefix::none, Vol::m3, Prefix::none, Vol::m3>;
}
}
}
}