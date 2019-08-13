#pragma once

#include "../quantity.h"
#include "../vol.h"

namespace nhill
{
namespace uom
{

template<typename T = double>
using Quantity_vol = Quantity<Volume, T>;

namespace vol
{
template<typename T = double>
using quantity = Quantity_vol<T>;
}

}
}