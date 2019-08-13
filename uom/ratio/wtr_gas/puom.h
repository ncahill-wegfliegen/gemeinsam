#pragma once

#include "../../puom_ratio.h"
#include "../../vol.h"

namespace nhill
{
namespace uom
{

using Prefixed_wtr_gas_ratio = Prefixed_uom_ratio<Volume, Volume>;

namespace wgr
{
using puom = Prefixed_wtr_gas_ratio;
}

}
}