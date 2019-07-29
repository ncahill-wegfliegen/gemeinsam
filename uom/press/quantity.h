#pragma once

#include "..\quantity.h"
#include "..\press.h"

namespace nhill
{
namespace uom
{

template<typename T>
using Quantity_press = Quantity<T, Pressure>;

namespace press
{
template<typename T>
using quantity = Quantity_press<T>;
}

}
}