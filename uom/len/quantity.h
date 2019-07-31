#pragma once

#include "len_convert.h"
#include "..\quantity.h"

namespace nhill
{
namespace uom
{

template<typename T = double>
using Quantity_len = Quantity<Length, T>;

namespace len
{
template<typename T = double>
using quantity = Quantity_len<T>;
}

}
}