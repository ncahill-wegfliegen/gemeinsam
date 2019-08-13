#include "../len/len_convert.h"
#include "../len/len_convert_primitive.h"

template<>
double nhill::uom::convert( Prefix dst_prefix, Length dst_uom, double src_value, Prefix src_prefix, Length src_uom )
{
   double dst_value = 0;
   double dst_factor = to_factor( dst_prefix );

   switch( src_uom )
   {
   case Len::m:
   {
      double src_factor = to_factor( src_prefix );
      switch( dst_uom )
      {
      case Len::m: dst_value = len::m_to_m( src_value, src_factor, dst_factor ); break;
      case Len::in: dst_value = len::m_to_in( src_value, src_factor ); break;
      case Len::ft: dst_value = len::m_to_ft( src_value, src_factor ); break;
      case Len::yd: dst_value = len::m_to_yd( src_value, src_factor ); break;
      case Len::mi: dst_value = len::m_to_mi( src_value, src_factor ); break;
      }
      break;
   }

   case Len::in:
      switch( dst_uom )
      {
      case Len::m: dst_value = len::in_to_m( src_value, dst_factor ); break;
      case Len::in: dst_value = src_value; break;
      case Len::ft: dst_value = len::in_to_ft( src_value ); break;
      case Len::yd: dst_value = len::in_to_yd( src_value ); break;
      case Len::mi: dst_value = len::in_to_mi( src_value ); break;
      }
      break;

   case Len::ft:
      switch( dst_uom )
      {
      case Len::m: dst_value = len::ft_to_m( src_value, dst_factor ); break;
      case Len::in: dst_value = len::ft_to_in( src_value ); break;
      case Len::ft: dst_value = src_value; break;
      case Len::yd: dst_value = len::ft_to_yd( src_value ); break;
      case Len::mi: dst_value = len::ft_to_mi( src_value ); break;
      }
      break;

   case Len::yd:
      switch( dst_uom )
      {
      case Len::m: dst_value = len::yd_to_m( src_value, dst_factor ); break;
      case Len::in: dst_value = len::yd_to_in( src_value ); break;
      case Len::ft: dst_value = len::yd_to_ft( src_value ); break;
      case Len::yd: dst_value = src_value; break;
      case Len::mi: dst_value = len::yd_to_mi( src_value ); break;
      }
      break;

   case Len::mi:
      switch( dst_uom )
      {
      case Len::m: dst_value = len::mi_to_m( src_value, dst_factor ); break;
      case Len::in: dst_value = len::mi_to_in( src_value ); break;
      case Len::ft: dst_value = len::mi_to_ft( src_value ); break;
      case Len::yd: dst_value = len::mi_to_yd( src_value ); break;
      case Len::mi: dst_value = src_value; break;
      }
      break;

   }
   return dst_value;
}

