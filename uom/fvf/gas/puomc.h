#pragma once

#include "../../puom_ratioc.h"
#include "../../vol.h"

namespace nhill
{
namespace uom
{
using Prefixed_fvf_gas_container = Prefixed_uom_ratio_container<Volume, Volume>;

namespace fvf
{
namespace gas
{
using puomc = Prefixed_fvf_gas_container;
}
}

}
}