#pragma once

#include "../quantity_tmplt.h"
#include "../press.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix, Press uom, typename T = double>
using Quantity_press_template = Quantity_template<Press, prefix, uom, T>;

}
}
