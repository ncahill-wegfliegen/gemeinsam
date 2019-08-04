#pragma once

#include "a2d_convert.h"
#include "..\quantity_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix, A2d uom, typename T = double>
using Quantity_a2d_template = Quantity_template<A2d, prefix, uom, T>;

}
}