#pragma once

#include "../../fvf/gas/quantity_tmplt.h"

namespace nhill
{
namespace uom
{
namespace fvf
{
namespace gas
{
template<typename T = double>
using v_rcf_per_scf = Quantity_fvf_gas_template<Prefix::none, Vol::rcf, Prefix::none, Vol::scf, T>;
template<typename T = double>
using v_rb_per_scf  = Quantity_fvf_gas_template<Prefix::none, Vol::rb , Prefix::none, Vol::scf, T>;
template<typename T = double>
using v_rb_per_Mscf = Quantity_fvf_gas_template<Prefix::none, Vol::rb , Prefix::M   , Vol::scf, T>;
template<typename T = double>
using v_m3_per_m3   = Quantity_fvf_gas_template<Prefix::none, Vol::m3 , Prefix::none, Vol::m3 , T>;
}
}
}
}