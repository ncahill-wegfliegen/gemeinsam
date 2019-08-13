#pragma once

#include "../time.h"
#include "../puom_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix_, Time uom_>
using Prefixed_time_template = Prefixed_uom_template<Time, prefix_, uom_>;

}
}