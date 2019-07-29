#pragma once

#include "time_convert.h"
#include "..\quantity_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix, Time uom>
using Quantity_time_template = Quantity_template<Time, prefix, uom>;

}
}