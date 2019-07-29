#pragma once

#include "..\temp.h"
#include "..\puom_tmplt.h"

namespace nhill
{
namespace uom
{

template<Prefix prefix, Temp uom>
using Prefixed_temp_template = Prefixed_uom_template<Temp, prefix, uom>;

}
}