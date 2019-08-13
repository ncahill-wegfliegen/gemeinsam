#pragma once

#include "../quantity.h"
#include "../a2d.h"

namespace nhill
{
namespace uom
{

template<typename T = double>
using Quantity_a2d = Quantity<Area_2d, T>;

namespace a2d
{
template<typename T = double>
using quantity = Quantity_a2d<T>;
}

}
}