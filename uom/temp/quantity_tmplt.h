#pragma once

#include "../temp/temp_convert.h"
#include "../quantity_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix_, Temp uom_, typename T = double>
using Quantity_temp_template = Quantity_template<Temp, prefix_, uom_, T>;

}
}