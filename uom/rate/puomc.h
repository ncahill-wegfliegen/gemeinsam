#pragma once

#include "..\puom_ratioc.h"
#include "..\time.h"

namespace nhill
{
namespace uom
{

template<typename Uom>
using Prefixed_rate_container = Prefixed_uom_ratio_container<Uom, Time>;

namespace rate
{
template<typename Uom>
using puomc = Prefixed_rate_container<Uom>;
}

}
}