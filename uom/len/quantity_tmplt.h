#pragma once

#include "len_convert.h"
#include "..\quantity_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix, Len uom, typename T = double>
using Quantity_len_template = Quantity_template<Len, prefix, uom, T>;

}
}
