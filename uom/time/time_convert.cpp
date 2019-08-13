#include "../time/time_convert.h"
#include "../time/time_convert_primitive.h"

template<>
double nhill::uom::convert( Prefix dst_prefix, Time dst_uom, double src_value, Prefix src_prefix, Time src_uom )
{
   double dst_value = 0;
   double dst_factor = to_factor( dst_prefix );

   switch( src_uom )
   {
   case Time::s:
      switch( dst_uom )
      {
      case Time::s:   dst_value = time::s_to_s( src_value, to_factor( src_prefix ), dst_factor );  break;
      case Time::min: dst_value = time::s_to_min( src_value, dst_factor ); break;
      case Time::h:   dst_value = time::s_to_h( src_value, dst_factor ); break;
      case Time::d:   dst_value = time::s_to_d( src_value, dst_factor ); break;
      case Time::wk:  dst_value = time::s_to_wk( src_value, dst_factor ); break;
      case Time::mo:  dst_value = time::s_to_mo( src_value, dst_factor ); break;
      case Time::yr:  dst_value = time::s_to_yr( src_value, dst_factor ); break;
      }
      break;

   case Time::min:
      switch( dst_uom )
      {
      case Time::s:   dst_value = time::min_to_s( src_value, dst_factor ); break;
      case Time::min: dst_value = src_value; break;
      case Time::h:   dst_value = time::min_to_h( src_value ); break;
      case Time::d:   dst_value = time::min_to_d( src_value ); break;
      case Time::wk:  dst_value = time::min_to_wk( src_value ); break;
      case Time::mo:  dst_value = time::min_to_mo( src_value ); break;
      case Time::yr:  dst_value = time::min_to_yr( src_value ); break;
      }
      break;

   case Time::h:
      switch( dst_uom )
      {
      case Time::s:   dst_value = time::h_to_s( src_value, dst_factor ); break;
      case Time::min: dst_value = time::h_to_min( src_value ); break;
      case Time::h:   dst_value = src_value ; break;
      case Time::d:   dst_value = time::h_to_d( src_value ); break;
      case Time::wk:  dst_value = time::h_to_wk( src_value ); break;
      case Time::mo:  dst_value = time::h_to_mo( src_value ); break;
      case Time::yr:  dst_value = time::h_to_yr( src_value ); break;
      }
      break;

   case Time::d:
      switch( dst_uom )
      {
      case Time::s:   dst_value = time::d_to_s( src_value, dst_factor ); break;
      case Time::min: dst_value = time::d_to_min( src_value ); break;
      case Time::h:   dst_value = time::d_to_h( src_value ) ; break;
      case Time::d:   dst_value = src_value; break;
      case Time::wk:  dst_value = time::d_to_wk( src_value ); break;
      case Time::mo:  dst_value = time::d_to_mo( src_value ); break;
      case Time::yr:  dst_value = time::d_to_yr( src_value ); break;
      }
      break;

   case Time::wk:
      switch( dst_uom )
      {
      case Time::s:   dst_value = time::wk_to_s( src_value, dst_factor ); break;
      case Time::min: dst_value = time::wk_to_min( src_value ); break;
      case Time::h:   dst_value = time::wk_to_h( src_value ) ; break;
      case Time::d:   dst_value = time::wk_to_d( src_value ); break;
      case Time::wk:  dst_value = src_value; break;
      case Time::mo:  dst_value = time::wk_to_mo( src_value ); break;
      case Time::yr:  dst_value = time::wk_to_yr( src_value ); break;
      }
      break;

   case Time::mo:
      switch( dst_uom )
      {
      case Time::s:   dst_value = time::mo_to_s( src_value, dst_factor ); break;
      case Time::min: dst_value = time::mo_to_min( src_value ); break;
      case Time::h:   dst_value = time::mo_to_h( src_value ) ; break;
      case Time::d:   dst_value = time::mo_to_d( src_value ); break;
      case Time::wk:  dst_value = time::mo_to_wk( src_value ); break;
      case Time::mo:  dst_value = src_value; break;
      case Time::yr:  dst_value = time::mo_to_yr( src_value ); break;
      }
      break;

   case Time::yr:
      switch( dst_uom )
      {
      case Time::s:   dst_value = time::yr_to_s( src_value, dst_factor ); break;
      case Time::min: dst_value = time::yr_to_min( src_value ); break;
      case Time::h:   dst_value = time::yr_to_h( src_value ) ; break;
      case Time::d:   dst_value = time::yr_to_d( src_value ); break;
      case Time::wk:  dst_value = time::yr_to_wk( src_value ); break;
      case Time::mo:  dst_value = time::yr_to_mo( src_value ); break;
      case Time::yr:  dst_value = src_value; break;
      }
      break;
   }

   return dst_value;
}
