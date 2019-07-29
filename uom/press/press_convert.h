#pragma once

#include "..\port.h"
#include "..\convert.h"
#include "..\press.h"

namespace nhill
{
namespace uom
{
template<> NHILL_UOM_PORT_FUNCTION
double convert( Prefix dst_prefix, Press dst_uom, double src_value, Prefix src_prefix, Press src_uom );
}
}
