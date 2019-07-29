#pragma once

#include "..\port.h"

// http://en.wikipedia.org/wiki/Conversion_of_units_of_temperature

namespace nhill
{
namespace uom
{
namespace temp
{

NHILL_UOM_PORT_FUNCTION double K_to_K( double K, double prefix_K = 1, double prefix_K_out = 1 );
NHILL_UOM_PORT_FUNCTION double K_to_degC( double K, double prefix_K = 1 );
NHILL_UOM_PORT_FUNCTION double K_to_degF( double K, double prefix_K = 1 );
NHILL_UOM_PORT_FUNCTION double K_to_degR( double K, double prefix_K = 1 );

NHILL_UOM_PORT_FUNCTION double degC_to_K( double degC, double prefix_K = 1 );
NHILL_UOM_PORT_FUNCTION double degC_to_degF( double degC );
NHILL_UOM_PORT_FUNCTION double degC_to_degR( double degC );

NHILL_UOM_PORT_FUNCTION double degF_to_K( double degF, double prefix_K = 1 );
NHILL_UOM_PORT_FUNCTION double degF_to_degC( double degF );
NHILL_UOM_PORT_FUNCTION double degF_to_degR( double degF );

NHILL_UOM_PORT_FUNCTION double degR_to_K( double degR, double prefix_K = 1 );
NHILL_UOM_PORT_FUNCTION double degR_to_degC( double degR );
NHILL_UOM_PORT_FUNCTION double degR_to_degF( double degR );

}
}
}