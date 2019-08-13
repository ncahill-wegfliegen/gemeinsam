#pragma once

#include "../port.h"

namespace nhill
{
namespace uom
{
namespace len
{

NHILL_UOM_PORT_PARAMETER extern const double in_per_ft;
NHILL_UOM_PORT_PARAMETER extern const double ft_per_yd;
NHILL_UOM_PORT_PARAMETER extern const double ft_per_mi;

NHILL_UOM_PORT_PARAMETER extern const double m_per_in;
NHILL_UOM_PORT_PARAMETER extern const double m_per_ft;
NHILL_UOM_PORT_PARAMETER extern const double m_per_yd;
NHILL_UOM_PORT_PARAMETER extern const double m_per_mi;

NHILL_UOM_PORT_PARAMETER extern const double ft_per_m;
NHILL_UOM_PORT_PARAMETER extern const double ft_per_in;

NHILL_UOM_PORT_PARAMETER extern const double in_per_m;
NHILL_UOM_PORT_PARAMETER extern const double in_per_yd;
NHILL_UOM_PORT_PARAMETER extern const double in_per_mi;

NHILL_UOM_PORT_PARAMETER extern const double yd_per_m;
NHILL_UOM_PORT_PARAMETER extern const double yd_per_in;
NHILL_UOM_PORT_PARAMETER extern const double yd_per_ft;
NHILL_UOM_PORT_PARAMETER extern const double yd_per_mi;

NHILL_UOM_PORT_PARAMETER extern const double mi_per_m;
NHILL_UOM_PORT_PARAMETER extern const double mi_per_in;
NHILL_UOM_PORT_PARAMETER extern const double mi_per_ft;
NHILL_UOM_PORT_PARAMETER extern const double mi_per_yd;



NHILL_UOM_PORT_PARAMETER double m_to_m( double m, double prefix_m = 1, double prefix_m_out = 1 );
NHILL_UOM_PORT_PARAMETER double m_to_in( double m, double prefix_m = 1 );
NHILL_UOM_PORT_PARAMETER double m_to_ft( double m, double prefix_m = 1 );
NHILL_UOM_PORT_PARAMETER double m_to_yd( double m, double prefix_m = 1 );
NHILL_UOM_PORT_PARAMETER double m_to_mi( double m, double prefix_m = 1 );

NHILL_UOM_PORT_PARAMETER double in_to_m( double in, double prefix_m = 1 );
NHILL_UOM_PORT_PARAMETER double in_to_ft( double in );
NHILL_UOM_PORT_PARAMETER double in_to_yd( double in );
NHILL_UOM_PORT_PARAMETER double in_to_mi( double in );

NHILL_UOM_PORT_PARAMETER double ft_to_m( double ft, double prefix_m = 1 );
NHILL_UOM_PORT_PARAMETER double ft_to_in( double ft );
NHILL_UOM_PORT_PARAMETER double ft_to_yd( double ft );
NHILL_UOM_PORT_PARAMETER double ft_to_mi( double ft );

NHILL_UOM_PORT_PARAMETER double yd_to_m( double yd, double prefix_m = 1 );
NHILL_UOM_PORT_PARAMETER double yd_to_in( double yd );
NHILL_UOM_PORT_PARAMETER double yd_to_ft( double yd );
NHILL_UOM_PORT_PARAMETER double yd_to_mi( double yd );

NHILL_UOM_PORT_PARAMETER double mi_to_m( double mi, double prefix_m = 1 );
NHILL_UOM_PORT_PARAMETER double mi_to_in( double mi );
NHILL_UOM_PORT_PARAMETER double mi_to_ft( double mi );
NHILL_UOM_PORT_PARAMETER double mi_to_yd( double mi );

}
}
}
