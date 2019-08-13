#include "../len/len_convert_primitive.h"

NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::in_per_ft { 12 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::ft_per_yd { 3 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::ft_per_mi { 5280 };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::m_per_in { 0.0254 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::m_per_ft { 0.3048 };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::m_per_yd { nhill::uom::len::m_per_ft * nhill::uom::len::ft_per_yd };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::m_per_mi { nhill::uom::len::m_per_ft * nhill::uom::len::ft_per_mi };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::ft_per_m  { 1.0 / nhill::uom::len::m_per_ft };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::ft_per_in { 1.0 / nhill::uom::len::in_per_ft };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::in_per_m  { 1.0 / nhill::uom::len::m_per_in };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::in_per_yd { nhill::uom::len::in_per_ft * nhill::uom::len::ft_per_yd };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::in_per_mi { nhill::uom::len::in_per_ft *nhill::uom::len::ft_per_mi };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::yd_per_m  { 1.0 / nhill::uom::len::m_per_yd };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::yd_per_in { 1.0 / nhill::uom::len::in_per_yd };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::yd_per_ft { 1.0 / nhill::uom::len::ft_per_yd };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::yd_per_mi { nhill::uom::len::ft_per_mi / nhill::uom::len::ft_per_yd };

NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::mi_per_m  { 1.0 / nhill::uom::len::m_per_mi };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::mi_per_in { 1.0 / nhill::uom::len::in_per_mi };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::mi_per_ft { 1.0 / nhill::uom::len::ft_per_mi };
NHILL_UOM_PORT_PARAMETER const double nhill::uom::len::mi_per_yd { nhill::uom::len::ft_per_yd / nhill::uom::len::ft_per_mi };

double nhill::uom::len::m_to_m( double m, double prefix_m /*= 1*/, double prefix_m_out /*= 1*/ ) { return (m*prefix_m) / prefix_m_out; }
double nhill::uom::len::m_to_in( double m, double prefix_m /*= 1*/ ) { return (m*prefix_m) * in_per_m; }
double nhill::uom::len::m_to_ft( double m, double prefix_m /*= 1*/ ) { return (m*prefix_m) * ft_per_m; }
double nhill::uom::len::m_to_yd( double m, double prefix_m /*= 1*/ ) { return (m*prefix_m) * yd_per_m; }
double nhill::uom::len::m_to_mi( double m, double prefix_m /*= 1*/ ) { return (m*prefix_m) * mi_per_m; }

double nhill::uom::len::in_to_m( double in, double prefix_m /*= 1*/ ) { return (in * m_per_in) / prefix_m ; }
double nhill::uom::len::in_to_ft( double in ) { return in * ft_per_in; }
double nhill::uom::len::in_to_yd( double in ) { return in * yd_per_in; }
double nhill::uom::len::in_to_mi( double in ) { return in * mi_per_in; }

double nhill::uom::len::ft_to_m( double ft, double prefix_m /*= 1*/ ) { return (ft * m_per_ft) / prefix_m; }
double nhill::uom::len::ft_to_in( double ft ) { return ft * in_per_ft; }
double nhill::uom::len::ft_to_yd( double ft ) { return ft * yd_per_ft; }
double nhill::uom::len::ft_to_mi( double ft ) { return ft * mi_per_ft; }

double nhill::uom::len::yd_to_m( double yd, double prefix_m /*= 1*/ ) { return (yd * m_per_yd) / prefix_m; }
double nhill::uom::len::yd_to_in( double yd ) { return yd * in_per_yd; }
double nhill::uom::len::yd_to_ft( double yd ) { return yd * ft_per_yd; }
double nhill::uom::len::yd_to_mi( double yd ) { return yd * mi_per_yd; }

double nhill::uom::len::mi_to_m( double mi, double prefix_m /*= 1*/ ) { return (mi * m_per_mi) / prefix_m; }
double nhill::uom::len::mi_to_in( double mi ) { return mi * in_per_mi; }
double nhill::uom::len::mi_to_ft( double mi ) { return mi * ft_per_mi; }
double nhill::uom::len::mi_to_yd( double mi ) { return mi * yd_per_mi; }
