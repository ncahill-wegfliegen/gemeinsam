#pragma once

#include "vol_convert.h"
#include "..\quantity_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix, Volume uom, typename T = double>
using Quantity_vol_template = Quantity_template<Volume, prefix, uom, T>;

}
}