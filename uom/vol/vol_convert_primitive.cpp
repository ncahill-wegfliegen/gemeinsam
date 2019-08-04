#include "vol_convert_primitive.h"
#include "..\a2d\a2d_convert_primitive.h"

NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cf_per_boe_default { 5800 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::boe_per_cf_default { 1.0 / nhill::uom::vol::cf_per_boe_default };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::m3_per_cuin { 16.387064E-6 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::m3_per_cuft { 0.028316846592 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::m3_per_cuyd { 0.764554857984 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::m3_per_cumi { 4168181825.440579584 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::m3_per_acft { 1233.48183754752 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::m3_per_bbl  { 0.158987294928 };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuin_per_m3   { 1.0 / nhill::uom::vol::m3_per_cuin };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuin_per_cuft { 1728 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuin_per_cuyd { 46656 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuin_per_cumi { 2.54358061E14 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuin_per_acft { 75271680 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuin_per_bbl  { 9702 };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuft_per_m3   { 1.0 / nhill::uom::vol::m3_per_cuft };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuft_per_cuin { 1.0 / nhill::uom::vol::cuin_per_cuft };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuft_per_cuyd { 27 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuft_per_cumi { 147197952000 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuft_per_acft { 43560 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuft_per_bbl  { 5.61 };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuyd_per_m3   { 1.0 / nhill::uom::vol::m3_per_cuyd };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuyd_per_cuin { 1.0 / nhill::uom::vol::cuin_per_cuyd };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuyd_per_cuft { 1.0 / nhill::uom::vol::cuft_per_cuyd };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuyd_per_cumi { 5451776000 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuyd_per_acft { 1613.33333 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cuyd_per_bbl  { 0.2079477635 };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cumi_per_m3   { 1.0 / nhill::uom::vol::m3_per_cumi };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cumi_per_cuin { 1.0 / nhill::uom::vol::cuin_per_cumi };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cumi_per_cuft { 1.0 / nhill::uom::vol::cuft_per_cumi };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cumi_per_cuyd { 1.0 / nhill::uom::vol::cuyd_per_cumi };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cumi_per_acft { 2.9592803E-7 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::cumi_per_bbl  { 3.814308050517E-11 };//26217074938.8;

NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::acft_per_m3   { 1.0 / nhill::uom::vol::m3_per_acft };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::acft_per_cuin { 1.0 / nhill::uom::vol::cuin_per_acft };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::acft_per_cuft { 1.0 / nhill::uom::vol::cuft_per_acft };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::acft_per_cuyd { 1.0 / nhill::uom::vol::cuyd_per_acft };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::acft_per_cumi { 1.0 / nhill::uom::vol::cumi_per_acft };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::acft_per_bbl  { 1.288931034E-4 };// =1/7758.367;// 26217074938.8;

NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::bbl_per_m3   { 1.0 / nhill::uom::vol::m3_per_bbl };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::bbl_per_cuin { 1.0 / nhill::uom::vol::cuin_per_bbl };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::bbl_per_cuft { 1.0 / nhill::uom::vol::cuft_per_bbl };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::bbl_per_cuyd { 1.0 / nhill::uom::vol::cuyd_per_bbl };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::bbl_per_cumi { 1.0 / nhill::uom::vol::cumi_per_bbl };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::vol::bbl_per_acft { 1.0 / nhill::uom::vol::acft_per_bbl };

namespace { double pow3( double x ) { return x * x*x; } }

double nhill::uom::vol::m3_to_m3( double m3, double prefix_m3 /*= 1*/, double prefix_m3_out /*= 1*/ ) { return m3 * pow3( prefix_m3 ) / pow3( prefix_m3_out ); }
double nhill::uom::vol::m3_to_ham( double m3, double prefix_m3 /*= 1*/, double prefix_ham /*= 1*/ ) { double ham = a2d::m2_to_ha( m3, prefix_m3 )*prefix_m3;  return ham / prefix_ham; }
double nhill::uom::vol::m3_to_cuin( double m3, double prefix_m3 /*= 1*/, double prefix_cuin /*= 1*/ ) { return m3 * pow3( prefix_m3 ) * cuin_per_m3 / prefix_cuin; }
double nhill::uom::vol::m3_to_cuft( double m3, double prefix_m3 /*= 1*/, double prefix_cuft /*= 1*/ ) { return m3 * pow3( prefix_m3 ) * cuft_per_m3 / prefix_cuft; }
double nhill::uom::vol::m3_to_cuyd( double m3, double prefix_m3 /*= 1*/, double prefix_cuyd /*= 1*/ ) { return m3 * pow3( prefix_m3 ) * cuyd_per_m3 / prefix_cuyd; }
double nhill::uom::vol::m3_to_cumi( double m3, double prefix_m3 /*= 1*/, double prefix_cumi /*= 1*/ ) { return m3 * pow3( prefix_m3 ) * cumi_per_m3 / prefix_cumi; }
double nhill::uom::vol::m3_to_acft( double m3, double prefix_m3 /*= 1*/, double prefix_acft /*= 1*/ ) { return m3 * pow3( prefix_m3 ) * acft_per_m3 / prefix_acft; }
double nhill::uom::vol::m3_to_bbl( double m3, double prefix_m3 /*= 1*/, double prefix_bbl /*= 1*/ ) { return m3 * pow3( prefix_m3 ) * bbl_per_m3 / prefix_bbl; }

double nhill::uom::vol::ham_to_m3( double ham, double prefix_ham /*= 1*/, double prefix_m3 /*= 1*/ ) { double m3 = a2d::ha_to_m2( ham, 1 )*prefix_ham;  return m3_to_m3( m3, 1, prefix_m3 ); }
double nhill::uom::vol::ham_to_ham( double ham, double prefix_ham /*= 1*/, double prefix_ham_out /*= 1*/ ) { return ham * pow3( prefix_ham ) / pow3( prefix_ham_out ); }
double nhill::uom::vol::ham_to_cuin( double ham, double prefix_ham /*= 1*/, double prefix_cuin /*= 1*/ ) { double m3 = ham_to_m3( ham, prefix_ham ); return m3_to_cuin( m3, 1, prefix_cuin ); }
double nhill::uom::vol::ham_to_cuft( double ham, double prefix_ham /*= 1*/, double prefix_cuft /*= 1*/ ) { double m3 = ham_to_m3( ham, prefix_ham ); return m3_to_cuft( m3, 1, prefix_cuft ); }
double nhill::uom::vol::ham_to_cuyd( double ham, double prefix_ham /*= 1*/, double prefix_cuyd /*= 1*/ ) { double m3 = ham_to_m3( ham, prefix_ham ); return m3_to_cuyd( m3, 1, prefix_cuyd ); }
double nhill::uom::vol::ham_to_cumi( double ham, double prefix_ham /*= 1*/, double prefix_cumi /*= 1*/ ) { double m3 = ham_to_m3( ham, prefix_ham ); return m3_to_cumi( m3, 1, prefix_cumi ); }
double nhill::uom::vol::ham_to_acft( double ham, double prefix_ham /*= 1*/, double prefix_acft /*= 1*/ ) { double m3 = ham_to_m3( ham, prefix_ham ); return m3_to_acft( m3, 1, prefix_acft ); }
double nhill::uom::vol::ham_to_bbl( double ham, double prefix_ham /*= 1*/, double prefix_bbl /*= 1*/ ) { double m3 = ham_to_m3( ham, prefix_ham ); return m3_to_bbl( m3, 1, prefix_bbl ); }

double nhill::uom::vol::cuin_to_m3( double cuin, double prefix_cuin /*= 1*/, double prefix_m3 /*= 1*/ ) { return cuin * prefix_cuin * m3_per_cuin / pow3( prefix_m3 ); }
double nhill::uom::vol::cuin_to_ham( double cuin, double prefix_cuin /*= 1*/, double prefix_ham /*= 1*/ ) { double m3 = cuin_to_m3( cuin, prefix_cuin );  return m3_to_ham( m3, 1, prefix_ham ); }
double nhill::uom::vol::cuin_to_cuin( double cuin, double prefix_cuin /*= 1*/, double prefix_cuin_out /*= 1*/ ) { return cuin * prefix_cuin / prefix_cuin_out; }
double nhill::uom::vol::cuin_to_cuft( double cuin, double prefix_cuin /*= 1*/, double prefix_cuft /*= 1*/ ) { return cuin * prefix_cuin * cuft_per_cuin / prefix_cuft; }
double nhill::uom::vol::cuin_to_cuyd( double cuin, double prefix_cuin /*= 1*/, double prefix_cuyd /*= 1*/ ) { return cuin * prefix_cuin * cuyd_per_cuin / prefix_cuyd; }
double nhill::uom::vol::cuin_to_cumi( double cuin, double prefix_cuin /*= 1*/, double prefix_cumi /*= 1*/ ) { return cuin * prefix_cuin * cumi_per_cuin / prefix_cumi; }
double nhill::uom::vol::cuin_to_acft( double cuin, double prefix_cuin /*= 1*/, double prefix_acft /*= 1*/ ) { return cuin * prefix_cuin * acft_per_cuin / prefix_acft; }
double nhill::uom::vol::cuin_to_bbl( double cuin, double prefix_cuin /*= 1*/, double prefix_bbl /*= 1*/ ) { return cuin * prefix_cuin * bbl_per_cuin / prefix_bbl; }

double nhill::uom::vol::cuft_to_m3( double cuft, double prefix_cuft /*= 1*/, double prefix_m3 /*= 1*/ ) { return cuft * prefix_cuft * m3_per_cuft / pow3( prefix_m3 ); }
double nhill::uom::vol::cuft_to_ham( double cuft, double prefix_cuft /*= 1*/, double prefix_ham /*= 1*/ ) { double m3 = cuft_to_m3( cuft, prefix_cuft );  return m3_to_ham( m3, 1, prefix_ham ); }
double nhill::uom::vol::cuft_to_cuin( double cuft, double prefix_cuft /*= 1*/, double prefix_cuin /*= 1*/ ) { return cuft * prefix_cuft * cuin_per_cuft / prefix_cuin; }
double nhill::uom::vol::cuft_to_cuft( double cuft, double prefix_cuft /*= 1*/, double prefix_cuft_out /*= 1*/ ) { return cuft * prefix_cuft / prefix_cuft_out; }
double nhill::uom::vol::cuft_to_cuyd( double cuft, double prefix_cuft /*= 1*/, double prefix_cuyd /*= 1*/ ) { return cuft * prefix_cuft * cuyd_per_cuft / prefix_cuyd; }
double nhill::uom::vol::cuft_to_cumi( double cuft, double prefix_cuft /*= 1*/, double prefix_cumi /*= 1*/ ) { return cuft * prefix_cuft * cumi_per_cuft / prefix_cumi; }
double nhill::uom::vol::cuft_to_acft( double cuft, double prefix_cuft /*= 1*/, double prefix_acft /*= 1*/ ) { return cuft * prefix_cuft * acft_per_cuft / prefix_acft; }
double nhill::uom::vol::cuft_to_bbl( double cuft, double prefix_cuft /*= 1*/, double prefix_bbl /*= 1*/ ) { return cuft * prefix_cuft * bbl_per_cuft / prefix_bbl; }

double nhill::uom::vol::cuyd_to_m3( double cuyd, double prefix_cuyd /*= 1*/, double prefix_m3 /*= 1*/ ) { return cuyd * prefix_cuyd *   m3_per_cuyd / pow3( prefix_m3 ); }
double nhill::uom::vol::cuyd_to_ham( double cuyd, double prefix_cuyd /*= 1*/, double prefix_ham /*= 1*/ ) { double m3 = cuyd_to_m3( cuyd, prefix_cuyd );  return m3_to_ham( m3, 1, prefix_ham ); }
double nhill::uom::vol::cuyd_to_cuin( double cuyd, double prefix_cuyd /*= 1*/, double prefix_cuin /*= 1*/ ) { return cuyd * prefix_cuyd * cuin_per_cuyd / prefix_cuin; }
double nhill::uom::vol::cuyd_to_cuft( double cuyd, double prefix_cuyd /*= 1*/, double prefix_cuft /*= 1*/ ) { return cuyd * prefix_cuyd * cuft_per_cuyd / prefix_cuft; }
double nhill::uom::vol::cuyd_to_cuyd( double cuyd, double prefix_cuyd /*= 1*/, double prefix_cuyd_out /*= 1*/ ) { return cuyd * prefix_cuyd / prefix_cuyd_out; }
double nhill::uom::vol::cuyd_to_cumi( double cuyd, double prefix_cuyd /*= 1*/, double prefix_cumi /*= 1*/ ) { return cuyd * prefix_cuyd * cumi_per_cuyd / prefix_cumi; }
double nhill::uom::vol::cuyd_to_acft( double cuyd, double prefix_cuyd /*= 1*/, double prefix_acft /*= 1*/ ) { return cuyd * prefix_cuyd * acft_per_cuyd / prefix_acft; }
double nhill::uom::vol::cuyd_to_bbl( double cuyd, double prefix_cuyd /*= 1*/, double prefix_bbl /*= 1*/ ) { return cuyd * prefix_cuyd *  bbl_per_cuyd / prefix_bbl; }

double nhill::uom::vol::cumi_to_m3( double cumi, double prefix_cumi /*= 1*/, double prefix_m3 /*= 1*/ ) { return cumi * prefix_cumi *   m3_per_cumi / pow3( prefix_m3 ); }
double nhill::uom::vol::cumi_to_ham( double cumi, double prefix_cumi /*= 1*/, double prefix_ham /*= 1*/ ) { double m3 = cumi_to_m3( cumi, prefix_cumi );  return m3_to_ham( m3, 1, prefix_ham ); }
double nhill::uom::vol::cumi_to_cuin( double cumi, double prefix_cumi /*= 1*/, double prefix_cuin /*= 1*/ ) { return cumi * prefix_cumi * cuin_per_cumi / prefix_cuin; }
double nhill::uom::vol::cumi_to_cuft( double cumi, double prefix_cumi /*= 1*/, double prefix_cuft /*= 1*/ ) { return cumi * prefix_cumi * cuft_per_cumi / prefix_cuft; }
double nhill::uom::vol::cumi_to_cuyd( double cumi, double prefix_cumi /*= 1*/, double prefix_cuyd /*= 1*/ ) { return cumi * prefix_cumi * cuyd_per_cumi / prefix_cuyd; }
double nhill::uom::vol::cumi_to_cumi( double cumi, double prefix_cumi /*= 1*/, double prefix_cumi_out /*= 1*/ ) { return cumi * prefix_cumi / prefix_cumi_out; }
double nhill::uom::vol::cumi_to_acft( double cumi, double prefix_cumi /*= 1*/, double prefix_acft /*= 1*/ ) { return cumi * prefix_cumi * acft_per_cumi / prefix_acft; }
double nhill::uom::vol::cumi_to_bbl( double cumi, double prefix_cumi /*= 1*/, double prefix_bbl /*= 1*/ ) { return cumi * prefix_cumi *  bbl_per_cumi / prefix_bbl; }

double nhill::uom::vol::acft_to_m3( double acft, double prefix_acft /*= 1*/, double prefix_m3 /*= 1*/ ) { return acft * prefix_acft *   m3_per_acft / pow3( prefix_m3 ); }
double nhill::uom::vol::acft_to_ham( double acft, double prefix_acft /*= 1*/, double prefix_ham /*= 1*/ ) { double m3 = acft_to_m3( acft, prefix_acft );  return m3_to_ham( m3, 1, prefix_ham ); }
double nhill::uom::vol::acft_to_cuin( double acft, double prefix_acft /*= 1*/, double prefix_cuin /*= 1*/ ) { return acft * prefix_acft * cuin_per_acft / prefix_cuin; }
double nhill::uom::vol::acft_to_cuft( double acft, double prefix_acft /*= 1*/, double prefix_cuft /*= 1*/ ) { return acft * prefix_acft * cuft_per_acft / prefix_cuft; }
double nhill::uom::vol::acft_to_cuyd( double acft, double prefix_acft /*= 1*/, double prefix_cuyd /*= 1*/ ) { return acft * prefix_acft * cuyd_per_acft / prefix_cuyd; }
double nhill::uom::vol::acft_to_cumi( double acft, double prefix_acft /*= 1*/, double prefix_cumi /*= 1*/ ) { return acft * prefix_acft * cumi_per_acft / prefix_cumi; }
double nhill::uom::vol::acft_to_acft( double acft, double prefix_acft /*= 1*/, double prefix_acft_out /*= 1*/ ) { return acft * prefix_acft / prefix_acft_out; }
double nhill::uom::vol::acft_to_bbl( double acft, double prefix_acft /*= 1*/, double prefix_bbl /*= 1*/ ) { return acft * prefix_acft *  bbl_per_acft / prefix_bbl; }

double nhill::uom::vol::bbl_to_m3( double bbl, double prefix_bbl /*= 1*/, double prefix_m3 /*= 1*/ ) { return bbl * prefix_bbl *   m3_per_bbl / pow3( prefix_m3 ); }
double nhill::uom::vol::bbl_to_ham( double bbl, double prefix_bbl /*= 1*/, double prefix_ham /*= 1*/ ) { double m3 = bbl_to_m3( bbl, prefix_bbl );  return m3_to_ham( m3, 1, prefix_ham ); }
double nhill::uom::vol::bbl_to_cuin( double bbl, double prefix_bbl /*= 1*/, double prefix_cuin /*= 1*/ ) { return bbl * prefix_bbl * cuin_per_bbl / prefix_cuin; }
double nhill::uom::vol::bbl_to_cuft( double bbl, double prefix_bbl /*= 1*/, double prefix_cuft /*= 1*/ ) { return bbl * prefix_bbl * cuft_per_bbl / prefix_cuft; }
double nhill::uom::vol::bbl_to_cuyd( double bbl, double prefix_bbl /*= 1*/, double prefix_cuyd /*= 1*/ ) { return bbl * prefix_bbl * cuyd_per_bbl / prefix_cuyd; }
double nhill::uom::vol::bbl_to_cumi( double bbl, double prefix_bbl /*= 1*/, double prefix_cumi /*= 1*/ ) { return bbl * prefix_bbl * cumi_per_bbl / prefix_cumi; }
double nhill::uom::vol::bbl_to_acft( double bbl, double prefix_bbl /*= 1*/, double prefix_acft /*= 1*/ ) { return bbl * prefix_bbl * acft_per_bbl / prefix_acft; }
double nhill::uom::vol::bbl_to_bbl( double bbl, double prefix_bbl /*= 1*/, double prefix_bbl_out /*= 1*/ ) { return bbl * prefix_bbl / prefix_bbl_out; }

double nhill::uom::vol::cf_to_boe( double cf, double prefix_cf /*= 1*/, double prefix_boe /*= 1*/, double boe_per_cf /*= boe_per_cf_default*/ ) { return cf * prefix_cf * boe_per_cf / prefix_boe; }

double nhill::uom::vol::boe_to_cf( double boe, double prefix_boe /*= 1*/, double prefix_cf /*= 1*/, double cf_per_boe /*= cf_per_boe_default*/ ) { return boe * prefix_boe * cf_per_boe / prefix_cf ; }
