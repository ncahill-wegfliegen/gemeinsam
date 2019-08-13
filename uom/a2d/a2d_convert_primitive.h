#pragma once

#include "../port.h"

namespace nhill
{
namespace uom
{
namespace a2d
{

NHILL_UOM_PORT_PARAMETER extern const double sqft_per_m2;
NHILL_UOM_PORT_PARAMETER extern const double sqft_per_ha;
NHILL_UOM_PORT_PARAMETER extern const double sqft_per_ac;

NHILL_UOM_PORT_PARAMETER extern const double m2_per_ha;
NHILL_UOM_PORT_PARAMETER extern const double m2_per_ac;
NHILL_UOM_PORT_PARAMETER extern const double m2_per_sqft;

NHILL_UOM_PORT_PARAMETER extern const double ac_per_m2;
NHILL_UOM_PORT_PARAMETER extern const double ac_per_sqft;
NHILL_UOM_PORT_PARAMETER extern const double ac_per_ha;

NHILL_UOM_PORT_PARAMETER extern const double ha_per_m2;
NHILL_UOM_PORT_PARAMETER extern const double ha_per_sqft;
NHILL_UOM_PORT_PARAMETER extern const double ha_per_ac;

NHILL_UOM_PORT_PARAMETER double m2_to_m2  ( double m2, double prefix_m = 1, double prefix_m_dest = 1 );
NHILL_UOM_PORT_PARAMETER double m2_to_sqft( double m2, double prefix_m = 1 );
NHILL_UOM_PORT_PARAMETER double m2_to_ha  ( double m2, double prefix_m = 1 ) ;
NHILL_UOM_PORT_PARAMETER double m2_to_ac  ( double m2, double prefix_m = 1 ) ;

NHILL_UOM_PORT_PARAMETER double sqft_to_m2( double sqft, double prefix_m = 1 );
NHILL_UOM_PORT_PARAMETER double sqft_to_ha( double sqft );
NHILL_UOM_PORT_PARAMETER double sqft_to_ac( double sqft );

NHILL_UOM_PORT_PARAMETER double ha_to_m2  ( double ha, double prefix_m = 1 );
NHILL_UOM_PORT_PARAMETER double ha_to_sqft( double ha );
NHILL_UOM_PORT_PARAMETER double ha_to_ac  ( double ha ) ;

NHILL_UOM_PORT_PARAMETER double ac_to_m2  ( double ac, double prefix_m = 1 );
NHILL_UOM_PORT_PARAMETER double ac_to_sqft( double ac );
NHILL_UOM_PORT_PARAMETER double ac_to_ha  ( double ac ) ;

}
}
}