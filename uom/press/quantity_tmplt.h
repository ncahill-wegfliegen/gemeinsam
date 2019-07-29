#pragma once

#include "press_convert.h"
#include "..\quantity_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix, Press uom>
using Quantity_press_template = Quantity_template<Press, prefix, uom>;

}
}
