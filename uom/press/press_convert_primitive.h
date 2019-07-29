#pragma once

#include "..\port.h"

// http://en.wikipedia.org/wiki/Pressure
// http://www.onlineconversion.com/pressure.htm

namespace nhill
{
namespace uom
{
namespace press
{

NHILL_UOM_PORT_PARAMETER extern const double Pa_per_bar;
NHILL_UOM_PORT_PARAMETER extern const double Pa_per_at;
NHILL_UOM_PORT_PARAMETER extern const double Pa_per_atm;
NHILL_UOM_PORT_PARAMETER extern const double Pa_per_torr;
NHILL_UOM_PORT_PARAMETER extern const double Pa_per_psia;

NHILL_UOM_PORT_PARAMETER extern const double bar_per_Pa  ;
NHILL_UOM_PORT_PARAMETER extern const double bar_per_at  ;
NHILL_UOM_PORT_PARAMETER extern const double bar_per_atm ;
NHILL_UOM_PORT_PARAMETER extern const double bar_per_torr;
NHILL_UOM_PORT_PARAMETER extern const double bar_per_psia;

NHILL_UOM_PORT_PARAMETER extern const double at_per_Pa  ;
NHILL_UOM_PORT_PARAMETER extern const double at_per_bar ;
NHILL_UOM_PORT_PARAMETER extern const double at_per_atm ;
NHILL_UOM_PORT_PARAMETER extern const double at_per_torr;
NHILL_UOM_PORT_PARAMETER extern const double at_per_psia;

NHILL_UOM_PORT_PARAMETER extern const double atm_per_Pa  ;
NHILL_UOM_PORT_PARAMETER extern const double atm_per_bar ;
NHILL_UOM_PORT_PARAMETER extern const double atm_per_at  ;
NHILL_UOM_PORT_PARAMETER extern const double atm_per_torr;
NHILL_UOM_PORT_PARAMETER extern const double atm_per_psia;

NHILL_UOM_PORT_PARAMETER extern const double torr_per_Pa  ;
NHILL_UOM_PORT_PARAMETER extern const double torr_per_bar ;
NHILL_UOM_PORT_PARAMETER extern const double torr_per_at  ;
NHILL_UOM_PORT_PARAMETER extern const double torr_per_atm ;
NHILL_UOM_PORT_PARAMETER extern const double torr_per_psia;

NHILL_UOM_PORT_PARAMETER extern const double psia_per_Pa  ;
NHILL_UOM_PORT_PARAMETER extern const double psia_per_bar ;
NHILL_UOM_PORT_PARAMETER extern const double psia_per_at  ;
NHILL_UOM_PORT_PARAMETER extern const double psia_per_atm ;
NHILL_UOM_PORT_PARAMETER extern const double psia_per_torr;

NHILL_UOM_PORT_FUNCTION double Pa_to_Pa  ( double Pa, double prefix_Pa = 1, double prefix_Pa_out = 1 );
NHILL_UOM_PORT_FUNCTION double Pa_to_bar ( double Pa, double prefix_Pa = 1, double prefix_bar = 1 );
NHILL_UOM_PORT_FUNCTION double Pa_to_at  ( double Pa, double prefix_Pa = 1 );
NHILL_UOM_PORT_FUNCTION double Pa_to_atm ( double Pa, double prefix_Pa = 1 );
NHILL_UOM_PORT_FUNCTION double Pa_to_torr( double Pa, double prefix_Pa = 1 );
NHILL_UOM_PORT_FUNCTION double Pa_to_psia( double Pa, double prefix_Pa = 1 );
NHILL_UOM_PORT_FUNCTION double Pa_to_psig( double Pa, double prefix_Pa = 1 );

NHILL_UOM_PORT_FUNCTION double bar_to_Pa  ( double bar, double prefix_bar = 1, double prefix_Pa = 1 );
NHILL_UOM_PORT_FUNCTION double bar_to_bar ( double bar, double prefix_bar = 1, double prefix_bar_out = 1 );
NHILL_UOM_PORT_FUNCTION double bar_to_at  ( double bar, double prefix_bar = 1 );
NHILL_UOM_PORT_FUNCTION double bar_to_atm ( double bar, double prefix_bar = 1 );
NHILL_UOM_PORT_FUNCTION double bar_to_torr( double bar, double prefix_bar = 1 );
NHILL_UOM_PORT_FUNCTION double bar_to_psia( double bar, double prefix_bar = 1 );
NHILL_UOM_PORT_FUNCTION double bar_to_psig( double bar, double prefix_bar = 1 );

NHILL_UOM_PORT_FUNCTION double at_to_Pa  ( double at, double prefix_Pa = 1 );
NHILL_UOM_PORT_FUNCTION double at_to_bar ( double at, double prefix_bar = 1 );
NHILL_UOM_PORT_FUNCTION double at_to_atm ( double at );
NHILL_UOM_PORT_FUNCTION double at_to_torr( double at );
NHILL_UOM_PORT_FUNCTION double at_to_psia( double at );
NHILL_UOM_PORT_FUNCTION double at_to_psig( double at );

NHILL_UOM_PORT_FUNCTION double atm_to_Pa  ( double atm, double prefix_Pa = 1 );
NHILL_UOM_PORT_FUNCTION double atm_to_bar ( double atm, double prefix_bar = 1 );
NHILL_UOM_PORT_FUNCTION double atm_to_at  ( double atm );
NHILL_UOM_PORT_FUNCTION double atm_to_torr( double atm );
NHILL_UOM_PORT_FUNCTION double atm_to_psia( double atm );
NHILL_UOM_PORT_FUNCTION double atm_to_psig( double atm );

NHILL_UOM_PORT_FUNCTION double torr_to_Pa  ( double torr, double prefix_Pa = 1 );
NHILL_UOM_PORT_FUNCTION double torr_to_bar ( double torr, double prefix_bar = 1 );
NHILL_UOM_PORT_FUNCTION double torr_to_at  ( double torr );
NHILL_UOM_PORT_FUNCTION double torr_to_atm ( double torr );
NHILL_UOM_PORT_FUNCTION double torr_to_psia( double torr );
NHILL_UOM_PORT_FUNCTION double torr_to_psig( double torr );

NHILL_UOM_PORT_FUNCTION double psia_to_Pa  ( double psia, double prefix_Pa = 1 );
NHILL_UOM_PORT_FUNCTION double psia_to_bar ( double psia, double prefix_bar = 1 );
NHILL_UOM_PORT_FUNCTION double psia_to_at  ( double psia );
NHILL_UOM_PORT_FUNCTION double psia_to_atm ( double psia );
NHILL_UOM_PORT_FUNCTION double psia_to_torr( double psia );
NHILL_UOM_PORT_FUNCTION double psia_to_psig( double psia );

NHILL_UOM_PORT_FUNCTION double psig_to_Pa  ( double psig, double prefix_Pa = 1 );
NHILL_UOM_PORT_FUNCTION double psig_to_bar ( double psig, double prefix_bar = 1 );
NHILL_UOM_PORT_FUNCTION double psig_to_at  ( double psig );
NHILL_UOM_PORT_FUNCTION double psig_to_atm ( double psig );
NHILL_UOM_PORT_FUNCTION double psig_to_torr( double psig );
NHILL_UOM_PORT_FUNCTION double psig_to_psia( double psig );
}
}
}