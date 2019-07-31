#pragma once

#include "..\quantity.h"
#include "..\temp.h"

namespace nhill
{
namespace uom
{

template<typename T = double>
using Quantity_temp = Quantity<Temperature, T>;

namespace temp
{

template<typename T = double>
using quantity = Quantity_temp<T>;

}

}
}