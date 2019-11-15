#pragma once

#include "port.h"
#include "range_direction.h"

namespace nhill
{
namespace uwi
{
namespace dls
{

NHILL_UWI_PORT_FUNCTION char to_char( Range_direction );
NHILL_UWI_PORT_FUNCTION Range_direction to_range_direction( char );

NHILL_UWI_PORT_FUNCTION bool is_valid_range_direction( char c );

}
}
}



