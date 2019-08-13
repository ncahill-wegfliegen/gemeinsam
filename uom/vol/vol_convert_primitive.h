#pragma once

#include "../port.h"

// http://en.wikipedia.org/wiki/Conversion_of_units#Volume

namespace nhill
{
namespace uom
{
namespace vol
{
NHILL_UOM_PORT_PARAMETER extern const double cf_per_boe_default;
NHILL_UOM_PORT_PARAMETER extern const double boe_per_cf_default;

NHILL_UOM_PORT_PARAMETER extern const double m3_per_cuin;
NHILL_UOM_PORT_PARAMETER extern const double m3_per_cuft;
NHILL_UOM_PORT_PARAMETER extern const double m3_per_cuyd;
NHILL_UOM_PORT_PARAMETER extern const double m3_per_cumi;
NHILL_UOM_PORT_PARAMETER extern const double m3_per_acft;
NHILL_UOM_PORT_PARAMETER extern const double m3_per_bbl ;

NHILL_UOM_PORT_PARAMETER extern const double cuin_per_m3  ;
NHILL_UOM_PORT_PARAMETER extern const double cuin_per_cuft;
NHILL_UOM_PORT_PARAMETER extern const double cuin_per_cuyd;
NHILL_UOM_PORT_PARAMETER extern const double cuin_per_cumi;
NHILL_UOM_PORT_PARAMETER extern const double cuin_per_acft;
NHILL_UOM_PORT_PARAMETER extern const double cuin_per_bbl ;

NHILL_UOM_PORT_PARAMETER extern const double cuft_per_m3;
NHILL_UOM_PORT_PARAMETER extern const double cuft_per_cuin;
NHILL_UOM_PORT_PARAMETER extern const double cuft_per_cuyd;
NHILL_UOM_PORT_PARAMETER extern const double cuft_per_cumi;
NHILL_UOM_PORT_PARAMETER extern const double cuft_per_acft;
NHILL_UOM_PORT_PARAMETER extern const double cuft_per_bbl ;

NHILL_UOM_PORT_PARAMETER extern const double cuyd_per_m3  ;
NHILL_UOM_PORT_PARAMETER extern const double cuyd_per_cuin;
NHILL_UOM_PORT_PARAMETER extern const double cuyd_per_cuft;
NHILL_UOM_PORT_PARAMETER extern const double cuyd_per_cumi;
NHILL_UOM_PORT_PARAMETER extern const double cuyd_per_acft;
NHILL_UOM_PORT_PARAMETER extern const double cuyd_per_bbl ;

NHILL_UOM_PORT_PARAMETER extern const double cumi_per_m3  ;
NHILL_UOM_PORT_PARAMETER extern const double cumi_per_cuin;
NHILL_UOM_PORT_PARAMETER extern const double cumi_per_cuft;
NHILL_UOM_PORT_PARAMETER extern const double cumi_per_cuyd;
NHILL_UOM_PORT_PARAMETER extern const double cumi_per_acft;
NHILL_UOM_PORT_PARAMETER extern const double cumi_per_bbl ;

NHILL_UOM_PORT_PARAMETER extern const double acft_per_m3  ;
NHILL_UOM_PORT_PARAMETER extern const double acft_per_cuin;
NHILL_UOM_PORT_PARAMETER extern const double acft_per_cuft;
NHILL_UOM_PORT_PARAMETER extern const double acft_per_cuyd;
NHILL_UOM_PORT_PARAMETER extern const double acft_per_cumi;
NHILL_UOM_PORT_PARAMETER extern const double acft_per_bbl ;

NHILL_UOM_PORT_PARAMETER extern const double bbl_per_m3  ;
NHILL_UOM_PORT_PARAMETER extern const double bbl_per_cuin;
NHILL_UOM_PORT_PARAMETER extern const double bbl_per_cuft;
NHILL_UOM_PORT_PARAMETER extern const double bbl_per_cuyd;
NHILL_UOM_PORT_PARAMETER extern const double bbl_per_cumi;
NHILL_UOM_PORT_PARAMETER extern const double bbl_per_acft;



NHILL_UOM_PORT_FUNCTION double m3_to_m3  ( double m3, double prefix_m3 = 1, double prefix_m3_out = 1 );
NHILL_UOM_PORT_FUNCTION double m3_to_ham ( double m3, double prefix_m3 = 1, double prefix_ham    = 1 );
NHILL_UOM_PORT_FUNCTION double m3_to_cuin( double m3, double prefix_m3 = 1, double prefix_cuin   = 1 );
NHILL_UOM_PORT_FUNCTION double m3_to_cuft( double m3, double prefix_m3 = 1, double prefix_cuft   = 1 );
NHILL_UOM_PORT_FUNCTION double m3_to_cuyd( double m3, double prefix_m3 = 1, double prefix_cuyd   = 1 );
NHILL_UOM_PORT_FUNCTION double m3_to_cumi( double m3, double prefix_m3 = 1, double prefix_cumi   = 1 );
NHILL_UOM_PORT_FUNCTION double m3_to_acft( double m3, double prefix_m3 = 1, double prefix_acft   = 1 );
NHILL_UOM_PORT_FUNCTION double m3_to_bbl ( double m3, double prefix_m3 = 1, double prefix_bbl    = 1 );

NHILL_UOM_PORT_FUNCTION double ham_to_m3  ( double ham, double prefix_ham = 1, double prefix_m3      = 1 );
NHILL_UOM_PORT_FUNCTION double ham_to_ham ( double ham, double prefix_ham = 1, double prefix_ham_out = 1 );
NHILL_UOM_PORT_FUNCTION double ham_to_cuin( double ham, double prefix_ham = 1, double prefix_cuin    = 1 );
NHILL_UOM_PORT_FUNCTION double ham_to_cuft( double ham, double prefix_ham = 1, double prefix_cuft    = 1 );
NHILL_UOM_PORT_FUNCTION double ham_to_cuyd( double ham, double prefix_ham = 1, double prefix_cuyd    = 1 );
NHILL_UOM_PORT_FUNCTION double ham_to_cumi( double ham, double prefix_ham = 1, double prefix_cumi    = 1 );
NHILL_UOM_PORT_FUNCTION double ham_to_acft( double ham, double prefix_ham = 1, double prefix_acft    = 1 );
NHILL_UOM_PORT_FUNCTION double ham_to_bbl ( double ham, double prefix_ham = 1, double prefix_bbl     = 1 );

NHILL_UOM_PORT_FUNCTION double cuin_to_m3  ( double cuin, double prefix_cuin = 1, double prefix_m3       = 1 );
NHILL_UOM_PORT_FUNCTION double cuin_to_ham ( double cuin, double prefix_cuin = 1, double prefix_ham      = 1 );
NHILL_UOM_PORT_FUNCTION double cuin_to_cuin( double cuin, double prefix_cuin = 1, double prefix_cuin_out = 1 );
NHILL_UOM_PORT_FUNCTION double cuin_to_cuft( double cuin, double prefix_cuin = 1, double prefix_cuft     = 1 );
NHILL_UOM_PORT_FUNCTION double cuin_to_cuyd( double cuin, double prefix_cuin = 1, double prefix_cuyd     = 1 );
NHILL_UOM_PORT_FUNCTION double cuin_to_cumi( double cuin, double prefix_cuin = 1, double prefix_cumi     = 1 );
NHILL_UOM_PORT_FUNCTION double cuin_to_acft( double cuin, double prefix_cuin = 1, double prefix_acft     = 1 );
NHILL_UOM_PORT_FUNCTION double cuin_to_bbl ( double cuin, double prefix_cuin = 1, double prefix_bbl      = 1 );

NHILL_UOM_PORT_FUNCTION double cuft_to_m3  ( double cuft, double prefix_cuft = 1, double prefix_m3       = 1 );
NHILL_UOM_PORT_FUNCTION double cuft_to_ham ( double cuft, double prefix_cuft = 1, double prefix_ham      = 1 );
NHILL_UOM_PORT_FUNCTION double cuft_to_cuin( double cuft, double prefix_cuft = 1, double prefix_cuin     = 1 );
NHILL_UOM_PORT_FUNCTION double cuft_to_cuft( double cuft, double prefix_cuft = 1, double prefix_cuft_out = 1 );
NHILL_UOM_PORT_FUNCTION double cuft_to_cuyd( double cuft, double prefix_cuft = 1, double prefix_cuyd     = 1 );
NHILL_UOM_PORT_FUNCTION double cuft_to_cumi( double cuft, double prefix_cuft = 1, double prefix_cumi     = 1 );
NHILL_UOM_PORT_FUNCTION double cuft_to_acft( double cuft, double prefix_cuft = 1, double prefix_acft     = 1 );
NHILL_UOM_PORT_FUNCTION double cuft_to_bbl ( double cuft, double prefix_cuft = 1, double prefix_bbl      = 1 );

NHILL_UOM_PORT_FUNCTION double cuyd_to_m3  ( double cuyd, double prefix_cuyd = 1, double prefix_m3       = 1 );
NHILL_UOM_PORT_FUNCTION double cuyd_to_ham ( double cuyd, double prefix_cuyd = 1, double prefix_ham      = 1 );
NHILL_UOM_PORT_FUNCTION double cuyd_to_cuin( double cuyd, double prefix_cuyd = 1, double prefix_cuin     = 1 );
NHILL_UOM_PORT_FUNCTION double cuyd_to_cuft( double cuyd, double prefix_cuyd = 1, double prefix_cuft     = 1 );
NHILL_UOM_PORT_FUNCTION double cuyd_to_cuyd( double cuyd, double prefix_cuyd = 1, double prefix_cuyd_out = 1 );
NHILL_UOM_PORT_FUNCTION double cuyd_to_cumi( double cuyd, double prefix_cuyd = 1, double prefix_cumi     = 1 );
NHILL_UOM_PORT_FUNCTION double cuyd_to_acft( double cuyd, double prefix_cuyd = 1, double prefix_acft     = 1 );
NHILL_UOM_PORT_FUNCTION double cuyd_to_bbl ( double cuyd, double prefix_cuyd = 1, double prefix_bbl      = 1 );

NHILL_UOM_PORT_FUNCTION double cumi_to_m3   ( double cumi, double prefix_cumi = 1, double prefix_m3       = 1 );
NHILL_UOM_PORT_FUNCTION double cumi_to_ham  ( double cumi, double prefix_cumi = 1, double prefix_ham      = 1 );
NHILL_UOM_PORT_FUNCTION double cumi_to_cuin ( double cumi, double prefix_cumi = 1, double prefix_cuin     = 1 );
NHILL_UOM_PORT_FUNCTION double cumi_to_cuft ( double cumi, double prefix_cumi = 1, double prefix_cuft     = 1 );
NHILL_UOM_PORT_FUNCTION double cumi_to_cuyd ( double cumi, double prefix_cumi = 1, double prefix_cuyd     = 1 );
NHILL_UOM_PORT_FUNCTION double cumi_to_cumi ( double cumi, double prefix_cumi = 1, double prefix_cumi_out = 1 );
NHILL_UOM_PORT_FUNCTION double cumi_to_acft ( double cumi, double prefix_cumi = 1, double prefix_acft     = 1 );
NHILL_UOM_PORT_FUNCTION double cumi_to_bbl  ( double cumi, double prefix_cumi = 1, double prefix_bbl      = 1 );

NHILL_UOM_PORT_FUNCTION double acft_to_m3  ( double acft, double prefix_acft = 1, double prefix_m3       = 1 );
NHILL_UOM_PORT_FUNCTION double acft_to_ham ( double acft, double prefix_acft = 1, double prefix_ham      = 1 );
NHILL_UOM_PORT_FUNCTION double acft_to_cuin( double acft, double prefix_acft = 1, double prefix_cuin     = 1 );
NHILL_UOM_PORT_FUNCTION double acft_to_cuft( double acft, double prefix_acft = 1, double prefix_cuft     = 1 );
NHILL_UOM_PORT_FUNCTION double acft_to_cuyd( double acft, double prefix_acft = 1, double prefix_cuyd     = 1 );
NHILL_UOM_PORT_FUNCTION double acft_to_cumi( double acft, double prefix_acft = 1, double prefix_cumi     = 1 );
NHILL_UOM_PORT_FUNCTION double acft_to_acft( double acft, double prefix_acft = 1, double prefix_acft_out = 1 );
NHILL_UOM_PORT_FUNCTION double acft_to_bbl ( double acft, double prefix_acft = 1, double prefix_bbl      = 1 );

NHILL_UOM_PORT_FUNCTION double bbl_to_m3  ( double bbl, double prefix_bbl = 1, double prefix_m3      = 1 );
NHILL_UOM_PORT_FUNCTION double bbl_to_ham ( double bbl, double prefix_bbl = 1, double prefix_ham     = 1 );
NHILL_UOM_PORT_FUNCTION double bbl_to_cuin( double bbl, double prefix_bbl = 1, double prefix_cuin    = 1 );
NHILL_UOM_PORT_FUNCTION double bbl_to_cuft( double bbl, double prefix_bbl = 1, double prefix_cuft    = 1 );
NHILL_UOM_PORT_FUNCTION double bbl_to_cuyd( double bbl, double prefix_bbl = 1, double prefix_cuyd    = 1 );
NHILL_UOM_PORT_FUNCTION double bbl_to_cumi( double bbl, double prefix_bbl = 1, double prefix_cumi    = 1 );
NHILL_UOM_PORT_FUNCTION double bbl_to_acft( double bbl, double prefix_bbl = 1, double prefix_acft    = 1 );
NHILL_UOM_PORT_FUNCTION double bbl_to_bbl ( double bbl, double prefix_bbl = 1, double prefix_bbl_out = 1 );

NHILL_UOM_PORT_FUNCTION double cf_to_boe( double cf, double prefix_cf = 1, double prefix_boe = 1, double boe_per_cf = boe_per_cf_default );

NHILL_UOM_PORT_FUNCTION double boe_to_cf( double boe, double prefix_boe = 1, double prefix_cf = 1, double cf_per_boe = cf_per_boe_default );

}
}
}