#include "../vol/vol_convert.h"
#include "../vol/vol_convert_primitive.h"
#include "../prefix_category.h"


NHILL_UOM_PORT_PARAMETER double nhill::uom::vol::cf_per_boe = nhill::uom::vol::cf_per_boe_default;

namespace
{
double cube_root_of_factor( nhill::uom::Prefix prefix, nhill::uom::Vol uom )
{
   using namespace nhill;
   using namespace nhill::uom;

   double factor = to_factor( prefix );

   // Only m3 need adjustment
   if( uom != Vol::m3 )
      return factor;

   // If the prefix is None, then no adjustment is required
   if( prefix == Prefix::none )
      return factor;

   // Only non-SI prefixes require adjustment
   if( to_category( prefix ) == Prefix_category::si )
      return factor;

   // Take the cube root of the factor
   switch( prefix )
   {
   case Prefix::e3:
   case Prefix::M:
      factor = 10;
      break;

   case Prefix::e6:
   case Prefix::MM:
      factor = 100;
      break;

   case Prefix::e9:
   case Prefix::B:
      factor = 1000;
      break;
   }

   return factor;
}
}

template<>
double nhill::uom::convert( Prefix dst_prefix, Vol dst_uom, double src_value, Prefix src_prefix, Vol src_uom )
{
   double dst_value = 0;
   double dst_factor = cube_root_of_factor( dst_prefix, dst_uom );
   double src_factor = cube_root_of_factor( src_prefix, src_uom );

   switch( src_uom )
   {
   case Vol::m3:
      switch( dst_uom )
      {
      case Vol::m3:   dst_value = vol::m3_to_m3( src_value, src_factor, dst_factor ); break;
      case Vol::ham:  dst_value = vol::m3_to_ham( src_value, src_factor, dst_factor ); break;
      case Vol::cuin: dst_value = vol::m3_to_cuin( src_value, src_factor, dst_factor ); break;
      case Vol::cuft: dst_value = vol::m3_to_cuft( src_value, src_factor, dst_factor ); break;
      case Vol::cuyd: dst_value = vol::m3_to_cuyd( src_value, src_factor, dst_factor ); break;
      case Vol::cumi: dst_value = vol::m3_to_cumi( src_value, src_factor, dst_factor ); break;
      case Vol::acft: dst_value = vol::m3_to_acft( src_value, src_factor, dst_factor ); break;
      case Vol::bbl:
      case Vol::rb:
      case Vol::stb:
      case Vol::boe:  dst_value = vol::m3_to_bbl( src_value, src_factor, dst_factor ); break;
      case Vol::cf:
      case Vol::rcf:
      case Vol::scf:  dst_value = vol::m3_to_cuft( src_value, src_factor, dst_factor ); break;
      }
      break;

   case Vol::ham:
      switch( dst_uom )
      {
      case Vol::m3:   dst_value = vol::ham_to_m3( src_value, src_factor, dst_factor ); break;
      case Vol::ham:  dst_value = vol::ham_to_ham( src_value, src_factor, dst_factor ); break;
      case Vol::cuin: dst_value = vol::ham_to_cuin( src_value, src_factor, dst_factor ); break;
      case Vol::cuft: dst_value = vol::ham_to_cuft( src_value, src_factor, dst_factor ); break;
      case Vol::cuyd: dst_value = vol::ham_to_cuyd( src_value, src_factor, dst_factor ); break;
      case Vol::cumi: dst_value = vol::ham_to_cumi( src_value, src_factor, dst_factor ); break;
      case Vol::acft: dst_value = vol::ham_to_acft( src_value, src_factor, dst_factor ); break;
      case Vol::bbl:
      case Vol::rb:
      case Vol::stb:
      case Vol::boe:  dst_value = vol::ham_to_bbl( src_value, src_factor, dst_factor ); break;
      case Vol::cf:
      case Vol::rcf:
      case Vol::scf:  dst_value = vol::ham_to_cuft( src_value, src_factor, dst_factor ); break;
      }
      break;

   case Vol::cuin:
      switch( dst_uom )
      {
      case Vol::m3:   dst_value = vol::cuin_to_m3( src_value, src_factor, dst_factor ); break;
      case Vol::ham:  dst_value = vol::cuin_to_ham( src_value, src_factor, dst_factor ); break;
      case Vol::cuin: dst_value = vol::cuin_to_cuin( src_value, src_factor, dst_factor ); break;
      case Vol::cuft: dst_value = vol::cuin_to_cuft( src_value, src_factor, dst_factor ); break;
      case Vol::cuyd: dst_value = vol::cuin_to_cuyd( src_value, src_factor, dst_factor ); break;
      case Vol::cumi: dst_value = vol::cuin_to_cumi( src_value, src_factor, dst_factor ); break;
      case Vol::acft: dst_value = vol::cuin_to_acft( src_value, src_factor, dst_factor ); break;
      case Vol::bbl:
      case Vol::rb:
      case Vol::stb:
      case Vol::boe:  dst_value = vol::cuin_to_bbl( src_value, src_factor, dst_factor ); break;
      case Vol::cf:
      case Vol::rcf:
      case Vol::scf:  dst_value = vol::cuin_to_cuft( src_value, src_factor, dst_factor ); break;
      }
      break;
   case Vol::cuft:
      switch( dst_uom )
      {
      case Vol::m3:   dst_value = vol::cuft_to_m3( src_value, src_factor, dst_factor ); break;
      case Vol::ham:  dst_value = vol::cuft_to_ham( src_value, src_factor, dst_factor ); break;
      case Vol::cuin: dst_value = vol::cuft_to_cuin( src_value, src_factor, dst_factor ); break;
      case Vol::cuft: dst_value = vol::cuft_to_cuft( src_value, src_factor, dst_factor ); break;
      case Vol::cuyd: dst_value = vol::cuft_to_cuyd( src_value, src_factor, dst_factor ); break;
      case Vol::cumi: dst_value = vol::cuft_to_cumi( src_value, src_factor, dst_factor ); break;
      case Vol::acft: dst_value = vol::cuft_to_acft( src_value, src_factor, dst_factor ); break;
      case Vol::bbl:
      case Vol::rb:
      case Vol::stb:
      case Vol::boe:  dst_value = vol::cuft_to_bbl( src_value, src_factor, dst_factor ); break;
      case Vol::cf:
      case Vol::rcf:
      case Vol::scf:  dst_value = vol::cuft_to_cuft( src_value, src_factor, dst_factor ); break;
      }
      break;
   case Vol::cuyd:
      switch( dst_uom )
      {
      case Vol::m3:   dst_value = vol::cuyd_to_m3( src_value, src_factor, dst_factor ); break;
      case Vol::ham:  dst_value = vol::cuyd_to_ham( src_value, src_factor, dst_factor ); break;
      case Vol::cuin: dst_value = vol::cuyd_to_cuin( src_value, src_factor, dst_factor ); break;
      case Vol::cuft: dst_value = vol::cuyd_to_cuft( src_value, src_factor, dst_factor ); break;
      case Vol::cuyd: dst_value = vol::cuyd_to_cuyd( src_value, src_factor, dst_factor ); break;
      case Vol::cumi: dst_value = vol::cuyd_to_cumi( src_value, src_factor, dst_factor ); break;
      case Vol::acft: dst_value = vol::cuyd_to_acft( src_value, src_factor, dst_factor ); break;
      case Vol::bbl:
      case Vol::rb:
      case Vol::stb:
      case Vol::boe:  dst_value = vol::cuyd_to_bbl( src_value, src_factor, dst_factor ); break;
      case Vol::cf:
      case Vol::rcf:
      case Vol::scf:  dst_value = vol::cuyd_to_cuft( src_value, src_factor, dst_factor ); break;
      }
      break;
   case Vol::cumi:
      switch( dst_uom )
      {
      case Vol::m3:   dst_value = vol::cumi_to_m3( src_value, src_factor, dst_factor ); break;
      case Vol::ham:  dst_value = vol::cumi_to_ham( src_value, src_factor, dst_factor ); break;
      case Vol::cuin: dst_value = vol::cumi_to_cuin( src_value, src_factor, dst_factor ); break;
      case Vol::cuft: dst_value = vol::cumi_to_cuft( src_value, src_factor, dst_factor ); break;
      case Vol::cuyd: dst_value = vol::cumi_to_cuyd( src_value, src_factor, dst_factor ); break;
      case Vol::cumi: dst_value = vol::cumi_to_cumi( src_value, src_factor, dst_factor ); break;
      case Vol::acft: dst_value = vol::cumi_to_acft( src_value, src_factor, dst_factor ); break;
      case Vol::bbl:
      case Vol::rb:
      case Vol::stb:
      case Vol::boe:  dst_value = vol::cumi_to_bbl( src_value, src_factor, dst_factor ); break;
      case Vol::cf:
      case Vol::rcf:
      case Vol::scf:  dst_value = vol::cumi_to_cuft( src_value, src_factor, dst_factor ); break;
      }
      break;
   case Vol::acft:
      switch( dst_uom )
      {
      case Vol::m3:   dst_value = vol::acft_to_m3( src_value, src_factor, dst_factor ); break;
      case Vol::ham:  dst_value = vol::acft_to_ham( src_value, src_factor, dst_factor ); break;
      case Vol::cuin: dst_value = vol::acft_to_cuin( src_value, src_factor, dst_factor ); break;
      case Vol::cuft: dst_value = vol::acft_to_cuft( src_value, src_factor, dst_factor ); break;
      case Vol::cuyd: dst_value = vol::acft_to_cuyd( src_value, src_factor, dst_factor ); break;
      case Vol::cumi: dst_value = vol::acft_to_cumi( src_value, src_factor, dst_factor ); break;
      case Vol::acft: dst_value = vol::acft_to_acft( src_value, src_factor, dst_factor ); break;
      case Vol::bbl:
      case Vol::rb:
      case Vol::stb:
      case Vol::boe:  dst_value = vol::acft_to_bbl( src_value, src_factor, dst_factor ); break;
      case Vol::cf:
      case Vol::rcf:
      case Vol::scf:  dst_value = vol::acft_to_cuft( src_value, src_factor, dst_factor ); break;
      }
      break;
   case Vol::bbl:
   case Vol::rb:
   case Vol::stb:
      switch( dst_uom )
      {
      case Vol::m3:   dst_value = vol::bbl_to_m3( src_value, src_factor, dst_factor ); break;
      case Vol::ham:  dst_value = vol::bbl_to_ham( src_value, src_factor, dst_factor ); break;
      case Vol::cuin: dst_value = vol::bbl_to_cuin( src_value, src_factor, dst_factor ); break;
      case Vol::cuft: dst_value = vol::bbl_to_cuft( src_value, src_factor, dst_factor ); break;
      case Vol::cuyd: dst_value = vol::bbl_to_cuyd( src_value, src_factor, dst_factor ); break;
      case Vol::cumi: dst_value = vol::bbl_to_cumi( src_value, src_factor, dst_factor ); break;
      case Vol::acft: dst_value = vol::bbl_to_acft( src_value, src_factor, dst_factor ); break;
      case Vol::bbl:
      case Vol::rb:
      case Vol::stb:
      case Vol::boe:  dst_value = vol::bbl_to_bbl( src_value, src_factor, dst_factor ); break;
      case Vol::cf:
      case Vol::rcf:
      case Vol::scf:  std::invalid_argument( "Cannot convert from stb to scf." );
      }
      break;
   case Vol::boe:
      switch( dst_uom )
      {
      case Vol::m3:   dst_value = vol::bbl_to_m3( src_value, src_factor, dst_factor ); break;
      case Vol::ham:  dst_value = vol::bbl_to_ham( src_value, src_factor, dst_factor ); break;
      case Vol::cuin: dst_value = vol::bbl_to_cuin( src_value, src_factor, dst_factor ); break;
      case Vol::cuft: dst_value = vol::bbl_to_cuft( src_value, src_factor, dst_factor ); break;
      case Vol::cuyd: dst_value = vol::bbl_to_cuyd( src_value, src_factor, dst_factor ); break;
      case Vol::cumi: dst_value = vol::bbl_to_cumi( src_value, src_factor, dst_factor ); break;
      case Vol::acft: dst_value = vol::bbl_to_acft( src_value, src_factor, dst_factor ); break;
      case Vol::bbl:
      case Vol::rb:
      case Vol::stb:
      case Vol::boe:  dst_value = vol::bbl_to_bbl( src_value, src_factor, dst_factor ); break;
      case Vol::cf:
      case Vol::rcf:
      case Vol::scf:  dst_value = vol::boe_to_cf( src_value, src_factor, dst_factor, vol::cf_per_boe ); break;
      }
      break;
   case Vol::cf:
   case Vol::rcf:
   case Vol::scf:
      switch( dst_uom )
      {
      case Vol::m3:   dst_value = vol::cuft_to_m3( src_value, src_factor, dst_factor ); break;
      case Vol::ham:  dst_value = vol::cuft_to_ham( src_value, src_factor, dst_factor ); break;
      case Vol::cuin: dst_value = vol::cuft_to_cuin( src_value, src_factor, dst_factor ); break;
      case Vol::cuft: dst_value = vol::cuft_to_cuft( src_value, src_factor, dst_factor ); break;
      case Vol::cuyd: dst_value = vol::cuft_to_cuyd( src_value, src_factor, dst_factor ); break;
      case Vol::cumi: dst_value = vol::cuft_to_cumi( src_value, src_factor, dst_factor ); break;
      case Vol::acft: dst_value = vol::cuft_to_acft( src_value, src_factor, dst_factor ); break;
      case Vol::bbl:
      case Vol::rb:
      case Vol::stb:  std::invalid_argument( "Cannot convert from scf to stb." );
      case Vol::boe:  dst_value = vol::cf_to_boe( src_value, src_factor, dst_factor, 1.0 / vol::cf_per_boe ); break;
      case Vol::cf:
      case Vol::rcf:
      case Vol::scf:  dst_value = vol::cuft_to_cuft( src_value, src_factor, dst_factor ); break;
      }
      break;
   }

   return dst_value;
}

