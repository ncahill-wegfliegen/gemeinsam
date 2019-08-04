#pragma once

#include "..\port.h"
#include "..\convert.h"
#include "..\a2d.h"

namespace nhill
{
namespace uom
{

template<> NHILL_UOM_PORT_FUNCTION
double convert( Prefix dst_prefix, A2d dst_uom, double src_value, Prefix src_prefix, A2d src_uom );

}
}