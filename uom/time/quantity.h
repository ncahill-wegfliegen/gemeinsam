#pragma once

#include "..\quantity.h"
#include "..\time.h"

namespace nhill
{
namespace uom
{

template<typename T = double>
using Quantity_time = Quantity<Time, T>;

namespace time
{
template<typename T = double>
using quantity = Quantity_time<T>;
}

}
}