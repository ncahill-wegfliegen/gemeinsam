#pragma once

#include "../../puom_ratio.h"
#include "../../vol.h"

namespace nhill
{
namespace uom
{

using Prefixed_wtr_oil_ratio = Prefixed_uom_ratio<Volume, Volume>;

namespace wor
{
using puom = Prefixed_wtr_oil_ratio;
}

}
}