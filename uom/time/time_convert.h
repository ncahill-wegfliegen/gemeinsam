#pragma once

#include "..\port.h"
#include "..\convert.h"
#include "..\time.h"

namespace nhill
{
namespace uom
{
template<> NHILL_UOM_PORT_FUNCTION
double convert( Prefix dst_prefix, Time dst_uom, double src_value, Prefix src_prefix, Time src_uom );
}
}