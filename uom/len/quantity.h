#pragma once

#include "len_convert.h"
#include "..\quantity.h"

namespace nhill
{
namespace uom
{

template<typename T>
using Quantity_len = Quantity<T, Length>;

namespace len
{
template<typename T>
using quantity = Quantity_len<T>;
}

}
}