#include "a2d_convert.h"
#include "a2d_convert_primitive.h"

template<>
double nhill::uom::convert( Prefix dst_prefix, A2d dst_uom, double src_value, Prefix src_prefix, A2d src_uom )
{
   double dst_value = 0;
   double dst_factor = to_factor( dst_prefix );

   switch( src_uom )
   {
   case A2d::m2:
   {
      double src_factor = to_factor( src_prefix );
      switch( dst_uom )
      {
      case A2d::m2: dst_value = a2d::m2_to_m2( src_value, src_factor, dst_factor ); break;
      case A2d::sqft: dst_value = a2d::m2_to_sqft( src_value, src_factor ); break;
      case A2d::ha: dst_value = a2d::m2_to_ha( src_value, src_factor ); break;
      case A2d::ac: dst_value = a2d::m2_to_ac( src_value, src_factor ); break;
      }
      break;
   }

   case A2d::sqft:
      switch( dst_uom )
      {
      case A2d::m2:  dst_value = a2d::sqft_to_m2( src_value, dst_factor ); break;
      case A2d::sqft: dst_value = src_value; break;
      case A2d::ha: dst_value = a2d::sqft_to_ha( src_value ); break;
      case A2d::ac: dst_value = a2d::sqft_to_ac( src_value ); break;
      }
      break;

   case A2d::ha:
      switch( dst_uom )
      {
      case A2d::m2:  dst_value = a2d::ha_to_m2( src_value, dst_factor ); break;
      case A2d::sqft: dst_value = a2d::ha_to_sqft( src_value ); break;
      case A2d::ha: dst_value = src_value; break;
      case A2d::ac: dst_value = a2d::ha_to_ac( src_value ); break;
      }
      break;

   case A2d::ac:
      switch( dst_uom )
      {
      case A2d::m2:  dst_value = a2d::ac_to_m2( src_value, dst_factor ); break;
      case A2d::sqft: dst_value = a2d::ac_to_sqft( src_value ); break;
      case A2d::ha: dst_value = a2d::ac_to_ha( src_value ); break;
      case A2d::ac: dst_value = src_value; break;
      }
      break;

   }
   return dst_value;
}
