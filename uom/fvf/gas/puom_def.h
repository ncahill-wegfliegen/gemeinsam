#pragma once

#include "../../fvf/gas/puom_tmplt.h"

namespace nhill
{
namespace uom
{
namespace fvf
{
namespace gas
{
using rcf_per_scf = Prefixed_fvf_gas_template<Prefix::none, Vol::rcf, Prefix::none, Vol::scf>;
using rb_per_scf  = Prefixed_fvf_gas_template<Prefix::none, Vol::rb , Prefix::none, Vol::scf>;
using rb_per_Mscf = Prefixed_fvf_gas_template<Prefix::none, Vol::rb , Prefix::M   , Vol::scf>;
using m3_per_m3   = Prefixed_fvf_gas_template<Prefix::none, Vol::m3 , Prefix::none, Vol::m3>;
}
}
}
}