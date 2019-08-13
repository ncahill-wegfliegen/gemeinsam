#pragma once

#include "../press.h"
#include "../puom_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix_, Press uom_>
using Prefixed_press_template = Prefixed_uom_template<Press, prefix_, uom_>;

}
}