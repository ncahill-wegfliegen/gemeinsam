#include "press_convert_primitive.h"

NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::Pa_per_bar  { 1E5        }          ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::Pa_per_at   { 98066.5    }          ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::Pa_per_atm  { 101325.01  }          ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::Pa_per_torr { 133.32237  }          ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::Pa_per_psia { 6894.75728 }          ;

NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::bar_per_Pa   { 0.00001      }       ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::bar_per_at   { 0.980665     }       ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::bar_per_atm  { 1.0132501    }       ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::bar_per_torr { 0.0013332237 }       ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::bar_per_psia { 0.0689475728 }       ;

NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::at_per_Pa   { 0.00001019716213 }    ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::at_per_bar  { 1.019716213      }    ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::at_per_atm  { 1.0332275548     }    ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::at_per_torr { 0.0013595098224  }    ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::at_per_psia { 0.07030695783    }    ;

NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::atm_per_Pa   { 0.0000098692316931 } ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::atm_per_bar  { 0.98692316931      } ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::atm_per_at   { 0.96784100984      } ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::atm_per_torr { 0.0013157893594    } ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::atm_per_psia { 0.068045957064     } ;

NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::torr_per_Pa   { 0.0075006167382 }   ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::torr_per_bar  { 750.06167382    }   ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::torr_per_at   { 735.55923136    }   ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::torr_per_atm  { 760.00006601    }   ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::torr_per_psia { 51.71493186     }   ;

NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::psia_per_Pa   { 0.00014503773801 }  ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::psia_per_bar  { 14.503773801     }  ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::psia_per_at   { 14.223343334     }  ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::psia_per_atm  { 14.695950254     }  ;
NHILL_UOM_PORT_PARAMETER const double nhill::uom::press::psia_per_torr { 0.019336774971   }  ;

double nhill::uom::press::Pa_to_Pa( double Pa, double prefix_Pa /*= 1*/, double prefix_Pa_out /*= 1*/ ) { return Pa * prefix_Pa / prefix_Pa_out; }
double nhill::uom::press::Pa_to_bar( double Pa, double prefix_Pa /*= 1*/, double prefix_bar /*= 1*/ ) { return Pa * prefix_Pa * bar_per_Pa / prefix_bar; }
double nhill::uom::press::Pa_to_at( double Pa, double prefix_Pa /*= 1*/ ) { return Pa * prefix_Pa * at_per_Pa; }
double nhill::uom::press::Pa_to_atm( double Pa, double prefix_Pa /*= 1*/ ) { return Pa * prefix_Pa * atm_per_Pa; }
double nhill::uom::press::Pa_to_torr( double Pa, double prefix_Pa /*= 1*/ ) { return Pa * prefix_Pa * torr_per_Pa; }
double nhill::uom::press::Pa_to_psia( double Pa, double prefix_Pa /*= 1*/ ) { return Pa * prefix_Pa * psia_per_Pa; }
double nhill::uom::press::Pa_to_psig( double Pa, double prefix_Pa /*= 1*/ ) { return psia_to_psig( Pa_to_psia( Pa*prefix_Pa ) ); }

double nhill::uom::press::bar_to_Pa( double bar, double prefix_bar /*= 1*/, double prefix_Pa /*= 1*/ ) { return bar * prefix_bar * Pa_per_bar / prefix_Pa; }
double nhill::uom::press::bar_to_bar( double bar, double prefix_bar /*= 1*/, double prefix_bar_out /*= 1*/ ) { return bar * prefix_bar / prefix_bar_out; }
double nhill::uom::press::bar_to_at( double bar, double prefix_bar /*= 1*/ ) { return bar * prefix_bar * at_per_bar; }
double nhill::uom::press::bar_to_atm( double bar, double prefix_bar /*= 1*/ ) { return bar * prefix_bar * atm_per_bar; }
double nhill::uom::press::bar_to_torr( double bar, double prefix_bar /*= 1*/ ) { return bar * prefix_bar* torr_per_bar; }
double nhill::uom::press::bar_to_psia( double bar, double prefix_bar /*= 1*/ ) { return bar * prefix_bar* psia_per_bar; }
double nhill::uom::press::bar_to_psig( double bar, double prefix_bar /*= 1*/ ) { return psia_to_psig( bar_to_psia( bar*prefix_bar ) ); }

double nhill::uom::press::at_to_Pa( double at, double prefix_Pa /*= 1*/ ) { return at * Pa_per_at / prefix_Pa; }
double nhill::uom::press::at_to_bar( double at, double prefix_bar /*= 1*/ ) { return at * bar_per_at / prefix_bar; }
double nhill::uom::press::at_to_atm( double at ) { return at * atm_per_at; }
double nhill::uom::press::at_to_torr( double at ) { return at * torr_per_at; }
double nhill::uom::press::at_to_psia( double at ) { return at * psia_per_at; }
double nhill::uom::press::at_to_psig( double at ) { return psia_to_psig( at_to_psia( at ) ); }

double nhill::uom::press::atm_to_Pa( double atm, double prefix_Pa /*= 1*/ ) { return atm * Pa_per_atm / prefix_Pa; }
double nhill::uom::press::atm_to_bar( double atm, double prefix_bar /*= 1*/ ) { return atm * bar_per_atm / prefix_bar; }
double nhill::uom::press::atm_to_at( double atm ) { return atm * at_per_atm; }
double nhill::uom::press::atm_to_torr( double atm ) { return atm * torr_per_atm; }
double nhill::uom::press::atm_to_psia( double atm ) { return atm * psia_per_atm; }
double nhill::uom::press::atm_to_psig( double atm ) { return psia_to_psig( atm_to_psia( atm ) ); }

double nhill::uom::press::torr_to_Pa( double torr, double prefix_Pa /*= 1*/ ) { return torr * Pa_per_torr / prefix_Pa; }
double nhill::uom::press::torr_to_bar( double torr, double prefix_bar /*= 1*/ ) { return torr * bar_per_torr / prefix_bar; }
double nhill::uom::press::torr_to_at( double torr ) { return torr * at_per_torr; }
double nhill::uom::press::torr_to_atm( double torr ) { return torr * atm_per_torr; }
double nhill::uom::press::torr_to_psia( double torr ) { return torr * psia_per_torr; }
double nhill::uom::press::torr_to_psig( double torr ) { return psia_to_psig( torr_to_psia( torr ) ); }

double nhill::uom::press::psia_to_Pa( double psia, double prefix_Pa /*= 1*/ ) { return psia * Pa_per_psia / prefix_Pa; }
double nhill::uom::press::psia_to_bar( double psia, double prefix_bar /*= 1*/ ) { return psia * bar_per_psia / prefix_bar; }
double nhill::uom::press::psia_to_at( double psia ) { return psia * at_per_psia; }
double nhill::uom::press::psia_to_atm( double psia ) { return psia * atm_per_psia; }
double nhill::uom::press::psia_to_torr( double psia ) { return psia * torr_per_psia; }
double nhill::uom::press::psia_to_psig( double psia ) { return psia - atm_per_psia; }

double nhill::uom::press::psig_to_Pa( double psig, double prefix_Pa /*= 1*/ ) { return psia_to_Pa( psig_to_psia( psig ), prefix_Pa ) ; }
double nhill::uom::press::psig_to_bar( double psig, double prefix_bar /*= 1*/ ) { return psia_to_bar( psig_to_psia( psig ), prefix_bar ); }
double nhill::uom::press::psig_to_at( double psig ) { return psia_to_at( psig_to_psia( psig ) ); }
double nhill::uom::press::psig_to_atm( double psig ) { return psia_to_atm( psig_to_psia( psig ) ); }
double nhill::uom::press::psig_to_torr( double psig ) { return psia_to_torr( psig_to_psia( psig ) ); }
double nhill::uom::press::psig_to_psia( double psig ) { return psig + atm_per_psia; }
