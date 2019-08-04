#pragma once

#include "..\vol.h"
#include "..\puom_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix_, Vol uom_>
using Prefixed_vol_template = Prefixed_uom_template<Vol, prefix_, uom_>;

}
}
