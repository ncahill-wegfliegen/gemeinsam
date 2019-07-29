#include "press_convert.h"
#include "press_convert_primitive.h"

template<>
double nhill::uom::convert( Prefix dst_prefix, Press dst_uom, double src_value, Prefix src_prefix, Press src_uom )
{
   double dst_value = 0;
   double dst_factor = to_factor( dst_prefix );

   switch( src_uom )
   {
   case Press::Pa:
   {
      double src_factor = to_factor( src_prefix );
      switch( dst_uom )
      {
      case Press::Pa: dst_value = press::Pa_to_Pa( src_value, src_factor, dst_factor ); break;
      case Press::bar: dst_value = press::Pa_to_bar( src_value, src_factor, dst_factor ); break;
      case Press::at: dst_value = press::Pa_to_at( src_value, src_factor ); break;
      case Press::atm: dst_value = press::Pa_to_atm( src_value, src_factor ); break;
      case Press::torr: dst_value = press::Pa_to_torr( src_value, src_factor ); break;
      case Press::psia:dst_value = press::Pa_to_psia( src_value, src_factor ); break;
      case Press::psig: dst_value = press::Pa_to_psig( src_value, src_factor ); break;
      }
      break;
   }

   case Press::bar:
   {
      double src_factor = to_factor( src_prefix );
      switch( dst_uom )
      {
      case Press::Pa: dst_value = press::bar_to_Pa( src_value, src_factor, dst_factor ); break;
      case Press::bar: dst_value = press::bar_to_bar( src_value, src_factor, dst_factor ); break;
      case Press::at: dst_value = press::bar_to_at( src_value, src_factor ); break;
      case Press::atm: dst_value = press::bar_to_atm( src_value, src_factor ); break;
      case Press::torr: dst_value = press::bar_to_torr( src_value, src_factor ); break;
      case Press::psia:dst_value = press::bar_to_psia( src_value, src_factor ); break;
      case Press::psig: dst_value = press::bar_to_psig( src_value, src_factor ); break;
      }
      break;
   }

   case Press::at:
      switch( dst_uom )
      {
      case Press::Pa: dst_value = press::at_to_Pa( src_value, dst_factor ); break;
      case Press::bar: dst_value = press::at_to_bar( src_value, dst_factor ); break;
      case Press::at: dst_value = src_value; break;
      case Press::atm: dst_value = press::at_to_atm( src_value ); break;
      case Press::torr: dst_value = press::at_to_torr( src_value ); break;
      case Press::psia:dst_value = press::at_to_psia( src_value ); break;
      case Press::psig: dst_value = press::at_to_psig( src_value ); break;
      }
      break;

   case Press::atm:
      switch( dst_uom )
      {
      case Press::Pa: dst_value = press::atm_to_Pa( src_value, dst_factor ); break;
      case Press::bar: dst_value = press::atm_to_bar( src_value, dst_factor ); break;
      case Press::at: dst_value = press::atm_to_at( src_value ); break;
      case Press::atm: dst_value = src_value; break;
      case Press::torr: dst_value = press::atm_to_torr( src_value ); break;
      case Press::psia:dst_value = press::atm_to_psia( src_value ); break;
      case Press::psig: dst_value = press::atm_to_psig( src_value ); break;
      }
      break;

   case Press::torr:
      switch( dst_uom )
      {
      case Press::Pa: dst_value = press::torr_to_Pa( src_value, dst_factor ); break;
      case Press::bar: dst_value = press::torr_to_bar( src_value, dst_factor ); break;
      case Press::at: dst_value = press::torr_to_at( src_value ); break;
      case Press::atm: dst_value = press::torr_to_atm( src_value ); break;
      case Press::torr: dst_value = src_value; break;
      case Press::psia:dst_value = press::torr_to_psia( src_value ); break;
      case Press::psig: dst_value = press::torr_to_psig( src_value ); break;
      }
      break;

   case Press::psia:
      switch( dst_uom )
      {
      case Press::Pa: dst_value = press::psia_to_Pa( src_value, dst_factor ); break;
      case Press::bar: dst_value = press::psia_to_bar( src_value, dst_factor ); break;
      case Press::at: dst_value = press::psia_to_at( src_value ); break;
      case Press::atm: dst_value = press::psia_to_atm( src_value ); break;
      case Press::torr: dst_value = press::psia_to_torr( src_value ); break;
      case Press::psia:dst_value = src_value; break;
      case Press::psig: dst_value = press::psia_to_psig( src_value ); break;
      }
      break;

   case Press::psig:
      switch( dst_uom )
      {
      case Press::Pa: dst_value = press::psig_to_Pa( src_value, dst_factor ); break;
      case Press::bar: dst_value = press::psig_to_bar( src_value, dst_factor ); break;
      case Press::at: dst_value = press::psig_to_at( src_value ); break;
      case Press::atm: dst_value = press::psig_to_atm( src_value ); break;
      case Press::torr: dst_value = press::psig_to_torr( src_value ); break;
      case Press::psia:dst_value = press::psig_to_psia( src_value ); break;
      case Press::psig: dst_value = src_value; break;
      }
      break;
   }
   return dst_value;
}
