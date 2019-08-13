#pragma once

#include "../puom_ratio.h"
#include "../time.h"

namespace nhill
{
namespace uom
{

template<typename Uom>
using Prefixed_rate = Prefixed_uom_ratio<Uom, Time>;

namespace rate
{
template<typename Uom>
using puom = Prefixed_rate<Uom>;
}

}
}