#pragma once

#include "../port.h"
#include "../convert.h"
#include "../temp.h"

namespace nhill
{
namespace uom
{

template<> NHILL_UOM_PORT_FUNCTION
double convert( Prefix dst_prefix, Temp dst_uom, double src_value, Prefix src_prefix, Temp src_uom );

}
}
