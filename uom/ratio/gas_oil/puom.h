#pragma once

#include "../../puom_ratio.h"
#include "../../vol.h"

namespace nhill
{
namespace uom
{

using Prefixed_gas_oil_ratio = Prefixed_uom_ratio<Volume, Volume>;

namespace gor
{
using puom = Prefixed_gas_oil_ratio;
}

}
}