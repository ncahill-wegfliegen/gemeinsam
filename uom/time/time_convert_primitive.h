#pragma once

#include "../port.h"

namespace nhill
{
namespace uom
{
namespace time
{

NHILL_UOM_PORT_PARAMETER extern const double s_per_min;
NHILL_UOM_PORT_PARAMETER extern const double min_per_h;
NHILL_UOM_PORT_PARAMETER extern const double h_per_d  ;
NHILL_UOM_PORT_PARAMETER extern const double d_per_wk ;
NHILL_UOM_PORT_PARAMETER extern const double mo_per_yr;

NHILL_UOM_PORT_PARAMETER extern const double d_per_yr;
NHILL_UOM_PORT_PARAMETER extern const double d_per_mo;

NHILL_UOM_PORT_PARAMETER extern const double s_per_h ;
NHILL_UOM_PORT_PARAMETER extern const double s_per_d ;
NHILL_UOM_PORT_PARAMETER extern const double s_per_wk;
NHILL_UOM_PORT_PARAMETER extern const double s_per_mo;
NHILL_UOM_PORT_PARAMETER extern const double s_per_yr;

NHILL_UOM_PORT_PARAMETER extern const double min_per_s ;
NHILL_UOM_PORT_PARAMETER extern const double min_per_d ;
NHILL_UOM_PORT_PARAMETER extern const double min_per_wk;
NHILL_UOM_PORT_PARAMETER extern const double min_per_mo;
NHILL_UOM_PORT_PARAMETER extern const double min_per_yr;

NHILL_UOM_PORT_PARAMETER extern const double h_per_s  ;
NHILL_UOM_PORT_PARAMETER extern const double h_per_min;
NHILL_UOM_PORT_PARAMETER extern const double h_per_wk ;
NHILL_UOM_PORT_PARAMETER extern const double h_per_mo ;
NHILL_UOM_PORT_PARAMETER extern const double h_per_yr ;

NHILL_UOM_PORT_PARAMETER extern const double d_per_s  ;
NHILL_UOM_PORT_PARAMETER extern const double d_per_min;
NHILL_UOM_PORT_PARAMETER extern const double d_per_h  ;

NHILL_UOM_PORT_PARAMETER extern const double wk_per_s  ;
NHILL_UOM_PORT_PARAMETER extern const double wk_per_min;
NHILL_UOM_PORT_PARAMETER extern const double wk_per_h  ;
NHILL_UOM_PORT_PARAMETER extern const double wk_per_d  ;
NHILL_UOM_PORT_PARAMETER extern const double wk_per_mo ;
NHILL_UOM_PORT_PARAMETER extern const double wk_per_yr ;

NHILL_UOM_PORT_PARAMETER extern const double mo_per_s  ;
NHILL_UOM_PORT_PARAMETER extern const double mo_per_min;
NHILL_UOM_PORT_PARAMETER extern const double mo_per_h  ;
NHILL_UOM_PORT_PARAMETER extern const double mo_per_d  ;
NHILL_UOM_PORT_PARAMETER extern const double mo_per_wk ;

NHILL_UOM_PORT_PARAMETER extern const double yr_per_s  ;
NHILL_UOM_PORT_PARAMETER extern const double yr_per_min;
NHILL_UOM_PORT_PARAMETER extern const double yr_per_h  ;
NHILL_UOM_PORT_PARAMETER extern const double yr_per_d  ;
NHILL_UOM_PORT_PARAMETER extern const double yr_per_wk ;
NHILL_UOM_PORT_PARAMETER extern const double yr_per_mo ;


NHILL_UOM_PORT_FUNCTION double s_to_s( double s, double prefix_s = 1, double prefix_s_out = 1 );
NHILL_UOM_PORT_FUNCTION double s_to_min( double s, double prefix_s = 1 );
NHILL_UOM_PORT_FUNCTION double s_to_h( double s, double prefix_s = 1 )  ;
NHILL_UOM_PORT_FUNCTION double s_to_d( double s, double prefix_s = 1 )  ;
NHILL_UOM_PORT_FUNCTION double s_to_wk( double s, double prefix_s = 1 ) ;
NHILL_UOM_PORT_FUNCTION double s_to_mo( double s, double prefix_s = 1 ) ;
NHILL_UOM_PORT_FUNCTION double s_to_yr( double s, double prefix_s = 1 ) ;

NHILL_UOM_PORT_FUNCTION double min_to_s( double min, double prefix_s = 1 );
NHILL_UOM_PORT_FUNCTION double min_to_h( double min ) ;
NHILL_UOM_PORT_FUNCTION double min_to_d( double min ) ;
NHILL_UOM_PORT_FUNCTION double min_to_wk( double min );
NHILL_UOM_PORT_FUNCTION double min_to_mo( double min );
NHILL_UOM_PORT_FUNCTION double min_to_yr( double min );

NHILL_UOM_PORT_FUNCTION double h_to_s( double h, double prefix_s = 1 );
NHILL_UOM_PORT_FUNCTION double h_to_min( double h );
NHILL_UOM_PORT_FUNCTION double h_to_d( double h )  ;
NHILL_UOM_PORT_FUNCTION double h_to_wk( double h ) ;
NHILL_UOM_PORT_FUNCTION double h_to_mo( double h ) ;
NHILL_UOM_PORT_FUNCTION double h_to_yr( double h ) ;

NHILL_UOM_PORT_FUNCTION double d_to_s( double d, double prefix_s = 1 );
NHILL_UOM_PORT_FUNCTION double d_to_min( double d );
NHILL_UOM_PORT_FUNCTION double d_to_h( double d )  ;
NHILL_UOM_PORT_FUNCTION double d_to_wk( double d ) ;
NHILL_UOM_PORT_FUNCTION double d_to_mo( double d ) ;
NHILL_UOM_PORT_FUNCTION double d_to_yr( double d ) ;

NHILL_UOM_PORT_FUNCTION double wk_to_s( double wk, double prefix_s = 1 );
NHILL_UOM_PORT_FUNCTION double wk_to_min( double wk );
NHILL_UOM_PORT_FUNCTION double wk_to_h( double wk )  ;
NHILL_UOM_PORT_FUNCTION double wk_to_d( double wk )  ;
NHILL_UOM_PORT_FUNCTION double wk_to_mo( double wk ) ;
NHILL_UOM_PORT_FUNCTION double wk_to_yr( double wk ) ;

NHILL_UOM_PORT_FUNCTION double mo_to_s( double mo, double prefix_s = 1 );
NHILL_UOM_PORT_FUNCTION double mo_to_min( double mo );
NHILL_UOM_PORT_FUNCTION double mo_to_h( double mo )  ;
NHILL_UOM_PORT_FUNCTION double mo_to_d( double mo )  ;
NHILL_UOM_PORT_FUNCTION double mo_to_wk( double mo ) ;
NHILL_UOM_PORT_FUNCTION double mo_to_yr( double mo ) ;

NHILL_UOM_PORT_FUNCTION double yr_to_s( double yr, double prefix_s = 1 );
NHILL_UOM_PORT_FUNCTION double yr_to_min( double yr );
NHILL_UOM_PORT_FUNCTION double yr_to_h( double yr )  ;
NHILL_UOM_PORT_FUNCTION double yr_to_d( double yr )  ;
NHILL_UOM_PORT_FUNCTION double yr_to_wk( double yr ) ;
NHILL_UOM_PORT_FUNCTION double yr_to_mo( double yr ) ;

}
}
}