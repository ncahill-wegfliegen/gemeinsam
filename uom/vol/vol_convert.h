#pragma once

#include "..\port.h"
#include "..\convert.h"
#include "..\vol.h"

namespace nhill
{
namespace uom
{
namespace vol
{
NHILL_UOM_PORT_PARAMETER extern double cf_per_boe;
}
template<> NHILL_UOM_PORT_PARAMETER
double convert( Prefix dst_prefix, Vol dst_uom, double src_value, Prefix src_prefix, Vol src_uom );
}
}
