#include "../a2d/a2d_convert_primitive.h"


// http://www.usefulinformation.eu/c_factor/area.html

NHILL_UOM_PORT_PARAMETER const double nhill::uom::a2d::sqft_per_m2{ 10.7639104 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::a2d::sqft_per_ha{ 107639.104 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::a2d::sqft_per_ac{ 43560 };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::a2d::m2_per_ha   { 10000 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::a2d::m2_per_ac   { 4046.856422 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::a2d::m2_per_sqft { 1.0 / nhill::uom::a2d::sqft_per_m2 };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::a2d::ac_per_m2   { 1.0 / nhill::uom::a2d::m2_per_ac };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::a2d::ac_per_sqft { 1.0 / nhill::uom::a2d::sqft_per_ac };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::a2d::ac_per_ha   { 2.4710538 };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::a2d::ha_per_m2   { 0.0001 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::a2d::ha_per_sqft { 1.0 / nhill::uom::a2d::sqft_per_ha };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::a2d::ha_per_ac   { 1.0 / nhill::uom::a2d::ac_per_ha };

double nhill::uom::a2d::m2_to_m2( double m2, double prefix_m /*= 1*/, double prefix_m_dest /*= 1*/ ) { return (m2*prefix_m*prefix_m) / (prefix_m_dest*prefix_m_dest); }
double nhill::uom::a2d::m2_to_sqft( double m2, double prefix_m /*= 1*/ ) { return (m2*prefix_m*prefix_m) * sqft_per_m2; }
double nhill::uom::a2d::m2_to_ha( double m2, double prefix_m /*= 1*/ ) { return  (m2*prefix_m*prefix_m) * ha_per_m2; }
double nhill::uom::a2d::m2_to_ac( double m2, double prefix_m /*= 1*/ ) { return  (m2*prefix_m*prefix_m) * ac_per_m2; }

double nhill::uom::a2d::sqft_to_m2( double sqft, double prefix_m /*= 1*/ ) { return sqft * m2_per_sqft / (prefix_m*prefix_m); }
double nhill::uom::a2d::sqft_to_ha( double sqft ) { return sqft * ha_per_sqft; }
double nhill::uom::a2d::sqft_to_ac( double sqft ) { return sqft * ac_per_sqft; }

double nhill::uom::a2d::ha_to_m2( double ha, double prefix_m /*= 1*/ ) { return ha * m2_per_ha / (prefix_m*prefix_m); }
double nhill::uom::a2d::ha_to_sqft( double ha ) { return ha * sqft_per_ha; }
double nhill::uom::a2d::ha_to_ac( double ha ) { return ha * ac_per_ha; }

double nhill::uom::a2d::ac_to_m2( double ac, double prefix_m /*= 1*/ ) { return ac * m2_per_ac / (prefix_m*prefix_m); }
double nhill::uom::a2d::ac_to_sqft( double ac ) { return ac * sqft_per_ac; }
double nhill::uom::a2d::ac_to_ha( double ac ) { return ac * ha_per_ac; }
