#include "../temp/temp_convert.h"
#include "../temp/temp_convert_primitive.h"

template<>
double nhill::uom::convert( Prefix dst_prefix, Temp dst_uom, double src_value, Prefix src_prefix, Temp src_uom )
{
   double dst_value = 0;
   double dst_factor = to_factor( dst_prefix );

   switch( src_uom )
   {
   case Temp::K:
   {
      double src_factor = to_factor( src_prefix );
      switch( dst_uom )
      {
      case Temp::K:  dst_value = temp::K_to_K( src_value, src_factor, dst_factor ); break;
      case Temp::degC: dst_value = temp::K_to_degC( src_value, src_factor ); break;
      case Temp::degF: dst_value = temp::K_to_degF( src_value, src_factor ); break;
      case Temp::degR: dst_value = temp::K_to_degR( src_value, src_factor ); break;
      }
      break;
   }

   case Temp::degC:
      switch( dst_uom )
      {
      case Temp::K:  dst_value = temp::degC_to_K( src_value, dst_factor ); break;
      case Temp::degC: dst_value = src_value; break;
      case Temp::degF: dst_value = temp::degC_to_degF( src_value ); break;
      case Temp::degR: dst_value = temp::degC_to_degR( src_value ); break;
      }
      break;

   case Temp::degF:
      switch( dst_uom )
      {
      case Temp::K:  dst_value = temp::degF_to_K( src_value, dst_factor ); break;
      case Temp::degC: dst_value = temp::degF_to_degC( src_value ); break;
      case Temp::degF: dst_value = src_value; break;
      case Temp::degR: dst_value = temp::degF_to_degR( src_value ); break;
      }
      break;

   case Temp::degR:
      switch( dst_uom )
      {
      case Temp::K:  dst_value = temp::degR_to_K( src_value, dst_factor ); break;
      case Temp::degC: dst_value = temp::degR_to_degC( src_value ); break;
      case Temp::degF: dst_value = temp::degR_to_degF( src_value ); break;
      case Temp::degR: dst_value = src_value; break;
      }
      break;
   }
   return dst_value;
}
