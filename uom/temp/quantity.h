#pragma once

#include "..\quantity.h"
#include "..\temp.h"

namespace nhill
{
namespace uom
{

template<typename T>
using Quantity_temp = Quantity<T, Temperature>;

namespace temp
{

template<typename T>
using quantity = Quantity_temp<T>;

}

}
}