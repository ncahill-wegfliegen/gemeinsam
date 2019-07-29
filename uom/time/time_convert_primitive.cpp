#include "time_convert_primitive.h"

NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::s_per_min { 60 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::min_per_h { 60 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::h_per_d   { 24 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::d_per_wk  {  7 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::mo_per_yr { 12 };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::d_per_yr{ 365.242 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::d_per_mo{ nhill::uom::time::d_per_yr / nhill::uom::time::mo_per_yr };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::s_per_h  { nhill::uom::time::s_per_min * nhill::uom::time::min_per_h};
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::s_per_d  { nhill::uom::time::s_per_h * nhill::uom::time::h_per_d    };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::s_per_wk { nhill::uom::time::s_per_d * nhill::uom::time::d_per_wk   };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::s_per_mo { nhill::uom::time::s_per_d * nhill::uom::time::d_per_mo   };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::s_per_yr { nhill::uom::time::s_per_d * nhill::uom::time::d_per_yr   };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::min_per_s  { 1.0 / nhill::uom::time::s_per_min       };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::min_per_d  { nhill::uom::time::min_per_h * nhill::uom::time::h_per_d };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::min_per_wk { nhill::uom::time::min_per_d * nhill::uom::time::d_per_wk};
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::min_per_mo { nhill::uom::time::min_per_d * nhill::uom::time::d_per_mo};
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::min_per_yr { nhill::uom::time::min_per_d * nhill::uom::time::d_per_yr};

NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::h_per_s{ 1.0 / nhill::uom::time::s_per_h };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::h_per_min{ 1.0 / nhill::uom::time::min_per_h };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::h_per_wk{ nhill::uom::time::h_per_d * nhill::uom::time::d_per_wk };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::h_per_mo{ nhill::uom::time::h_per_d * nhill::uom::time::d_per_mo };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::h_per_yr{ nhill::uom::time::h_per_d * nhill::uom::time::d_per_yr };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::d_per_s{ 1.0 / nhill::uom::time::s_per_d };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::d_per_min{ 1.0 / nhill::uom::time::min_per_s };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::d_per_h{ 1.0 / nhill::uom::time::h_per_d };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::wk_per_s   { 1.0 / nhill::uom::time::s_per_wk };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::wk_per_min { 1.0 / nhill::uom::time::min_per_wk };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::wk_per_h   { 1.0 / nhill::uom::time::h_per_wk };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::wk_per_d   { 1.0 / nhill::uom::time::d_per_wk };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::wk_per_mo  { nhill::uom::time::wk_per_d * nhill::uom::time::d_per_mo };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::wk_per_yr  { nhill::uom::time::wk_per_d * nhill::uom::time::d_per_yr };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::mo_per_s   { 1.0 / nhill::uom::time::s_per_mo };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::mo_per_min { 1.0 / nhill::uom::time::min_per_mo };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::mo_per_h   { 1.0 / nhill::uom::time::h_per_mo };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::mo_per_d   { 1.0 / nhill::uom::time::d_per_mo };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::mo_per_wk  { 1.0 / nhill::uom::time::wk_per_mo };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::yr_per_s   { 1.0 / nhill::uom::time::s_per_yr };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::yr_per_min { 1.0 / nhill::uom::time::min_per_yr };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::yr_per_h   { 1.0 / nhill::uom::time::h_per_yr };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::yr_per_d   { 1.0 / nhill::uom::time::d_per_yr };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::yr_per_wk  { 1.0 / nhill::uom::time::wk_per_yr };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::time::yr_per_mo  { 1.0 / nhill::uom::time::mo_per_yr };



double nhill::uom::time::s_to_s( double s, double prefix_s /*= 1*/, double prefix_s_out /*= 1*/ ) { return (s*prefix_s) / prefix_s_out; }
double nhill::uom::time::s_to_min( double s, double prefix_s /*= 1*/ ) { return (s * prefix_s) * min_per_s; }
double nhill::uom::time::s_to_h( double s, double prefix_s /*= 1*/ ) { return  (s * prefix_s) * h_per_s; }
double nhill::uom::time::s_to_d( double s, double prefix_s /*= 1*/ ) { return  (s*prefix_s) * d_per_s; }
double nhill::uom::time::s_to_wk( double s, double prefix_s /*= 1*/ ) { return (s * prefix_s) * wk_per_s; }
double nhill::uom::time::s_to_mo( double s, double prefix_s /*= 1*/ ) { return (s * prefix_s) * mo_per_s; }
double nhill::uom::time::s_to_yr( double s, double prefix_s /*= 1*/ ) { return(s * prefix_s) * yr_per_s; }

double nhill::uom::time::min_to_s( double min, double prefix_s /*= 1*/ ) { return (min * s_per_min) / prefix_s; }
double nhill::uom::time::min_to_h( double min ) { return min * h_per_min; }
double nhill::uom::time::min_to_d( double min ) { return min * d_per_min; }
double nhill::uom::time::min_to_wk( double min ) { return min * wk_per_min; }
double nhill::uom::time::min_to_mo( double min ) { return min * mo_per_min; }
double nhill::uom::time::min_to_yr( double min ) { return min * yr_per_min; }

double nhill::uom::time::h_to_s( double h, double prefix_s /*= 1*/ ) { return(h*s_per_h) / prefix_s; }
double nhill::uom::time::h_to_min( double h ) { return h * min_per_h; }
double nhill::uom::time::h_to_d( double h ) { return h * d_per_h; }
double nhill::uom::time::h_to_wk( double h ) { return h * wk_per_h; }
double nhill::uom::time::h_to_mo( double h ) { return h * mo_per_h; }
double nhill::uom::time::h_to_yr( double h ) { return h * yr_per_h; }

double nhill::uom::time::d_to_s( double d, double prefix_s /*= 1*/ ) { return (d*s_per_d) / prefix_s; }
double nhill::uom::time::d_to_min( double d ) { return  d * min_per_d; }
double nhill::uom::time::d_to_h( double d ) { return d * h_per_d; }
double nhill::uom::time::d_to_wk( double d ) { return d * wk_per_d; }
double nhill::uom::time::d_to_mo( double d ) { return d * mo_per_d; }
double nhill::uom::time::d_to_yr( double d ) { return d * yr_per_d; }

double nhill::uom::time::wk_to_s( double wk, double prefix_s /*= 1*/ ) { return (wk*s_per_wk) / prefix_s; }
double nhill::uom::time::wk_to_min( double wk ) { return wk * min_per_wk; }
double nhill::uom::time::wk_to_h( double wk ) { return wk * h_per_wk; }
double nhill::uom::time::wk_to_d( double wk ) { return wk * d_per_wk; }
double nhill::uom::time::wk_to_mo( double wk ) { return wk * mo_per_wk; }
double nhill::uom::time::wk_to_yr( double wk ) { return wk * yr_per_wk; }

double nhill::uom::time::mo_to_s( double mo, double prefix_s /*= 1*/ ) { return (mo*s_per_mo) / prefix_s; }
double nhill::uom::time::mo_to_min( double mo ) { return mo * min_per_mo; }
double nhill::uom::time::mo_to_h( double mo ) { return mo * h_per_mo; }
double nhill::uom::time::mo_to_d( double mo ) { return mo * d_per_mo; }
double nhill::uom::time::mo_to_wk( double mo ) { return mo * wk_per_mo; }
double nhill::uom::time::mo_to_yr( double mo ) { return mo * yr_per_mo; }

double nhill::uom::time::yr_to_s( double yr, double prefix_s /*= 1*/ ) { return (yr*s_per_yr) / prefix_s; }
double nhill::uom::time::yr_to_min( double yr ) { return yr * min_per_yr; }
double nhill::uom::time::yr_to_h( double yr ) { return yr * h_per_yr; }
double nhill::uom::time::yr_to_d( double yr ) { return yr * d_per_yr; }
double nhill::uom::time::yr_to_wk( double yr ) { return yr * wk_per_yr; }
double nhill::uom::time::yr_to_mo( double yr ) { return yr * mo_per_yr; }
