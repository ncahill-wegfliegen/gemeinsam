#pragma once

#include "../puom_tmplt.h"
#include "../a2d.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix, A2d uom>
using Prefixed_a2d_template = Prefixed_uom_template<A2d, prefix, uom>;

}
}