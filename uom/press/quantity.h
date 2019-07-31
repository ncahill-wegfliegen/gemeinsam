#pragma once

#include "..\quantity.h"
#include "..\press.h"

namespace nhill
{
namespace uom
{

template<typename T = double>
using Quantity_press = Quantity<Pressure, T>;

namespace press
{
template<typename T = double>
using quantity = Quantity_press<T>;
}

}
}