#include "temp_convert_primitive.h"

double nhill::uom::temp::K_to_K( double K, double prefix_K /*= 1*/, double prefix_K_out /*= 1*/ )
{
   return K * prefix_K / prefix_K_out;
}

double nhill::uom::temp::K_to_degC( double K, double prefix_K /*= 1*/ )
{
   return (K*prefix_K) - 273.15;
}

double nhill::uom::temp::K_to_degF( double K, double prefix_K /*= 1*/ )
{
   return (K *prefix_K * 9.0 / 5.0) - 459.67;
}

double nhill::uom::temp::K_to_degR( double K, double prefix_K /*= 1*/ )
{
   return K * prefix_K*9.0 / 5.0;
}



double nhill::uom::temp::degC_to_K( double degC, double prefix_K /*= 1*/ )
{
   return (degC + 273.15) / prefix_K;
}

double nhill::uom::temp::degC_to_degF( double degC )
{
   return (degC * 9.0 / 5.0) + 32.0;
}

double nhill::uom::temp::degC_to_degR( double degC )
{
   return (degC + 273.15)*9.0 / 5.0;
}



double nhill::uom::temp::degF_to_K( double degF, double prefix_K /*= 1*/ )
{
   return ((degF + 459.67) * 5.0 / 9.0) / prefix_K;
}

double nhill::uom::temp::degF_to_degC( double degF )
{
   return (degF - 32.0)*5.0 / 9.0;
}

double nhill::uom::temp::degF_to_degR( double degF )
{
   return degF + 459.67;
}



double nhill::uom::temp::degR_to_K( double degR, double prefix_K /*= 1*/ )
{
   return (degR*5.0 / 9.0) / prefix_K;
}

double nhill::uom::temp::degR_to_degC( double degR )
{
   return (degR - 491.67)*5.0 / 9.0;
}

double nhill::uom::temp::degR_to_degF( double degR )
{
   return degR - 459.67;
}
