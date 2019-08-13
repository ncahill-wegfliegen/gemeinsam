#pragma once

#include "../../puom_ratio.h"
#include "../../vol.h"

namespace nhill
{
namespace uom
{

using Prefixed_cnd_gas_ratio = Prefixed_uom_ratio<Volume, Volume>;

namespace cgr
{
using puom = Prefixed_cnd_gas_ratio;
}

}
}