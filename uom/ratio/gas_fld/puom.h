#pragma once

#include "../../puom_ratio.h"
#include "../../vol.h"

namespace nhill
{
namespace uom
{

using Prefixed_gas_fld_ratio = Prefixed_uom_ratio<Volume, Volume>;

namespace gfr
{
using puom = Prefixed_gas_fld_ratio;
}

}
}