#pragma once

#include "temp_convert.h"
#include "..\quantity_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix_, Temp uom_>
using Quantity_temp_template = Quantity_template<Temp, prefix_, uom_>;

}
}