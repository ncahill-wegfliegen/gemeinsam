#pragma once

#include "../../puom_ratio.h"
#include "../../prefix.h"
#include "../../vol.h"

namespace nhill
{
namespace uom
{

using Prefixed_fvf_oil = Prefixed_uom_ratio<Volume, Volume>;

namespace fvf
{
namespace oil
{
using puom = Prefixed_fvf_oil;
}
}

}
}