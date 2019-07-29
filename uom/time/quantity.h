#pragma once

#include "..\quantity.h"
#include "..\time.h"

namespace nhill
{
namespace uom
{

template<typename T>
using Quantity_time = Quantity<T, Time>;

namespace time
{
template<typename T>
using quantity = Quantity_time<T>;
}

}
}