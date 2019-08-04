#pragma once

#include "..\puom.h"
#include "..\vol.h"

namespace nhill
{
namespace uom
{

using Prefixed_vol = Prefixed_uom<Volume>;

namespace vol
{
using puom = Prefixed_vol;
}

}
}