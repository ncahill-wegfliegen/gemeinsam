#pragma once

#include "..\port.h"
#include "..\convert.h"
#include "..\len.h"

namespace nhill
{
namespace uom
{
template<> NHILL_UOM_PORT_FUNCTION
double convert( Prefix dst_prefix, Length dst_uom, double src_value, Prefix src_prefix, Length src_uom );
}
}