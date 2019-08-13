#pragma once

#include "../time/time_convert.h"
#include "../quantity_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix, Time uom, typename T = double>
using Quantity_time_template = Quantity_template<Time, prefix, uom, T>;

}
}