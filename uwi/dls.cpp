#include "dls.h"
#include "range_direction_ex.h"
#include "format.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

namespace
{
using namespace nhill::uwi;
using namespace nhill::uwi::dls;

constexpr char dash{'-'};
constexpr char slash{'/'};

bool is_valid_range_direction_and_meridian( std::string_view s, Dls::Meridian& m )
{
   // 01
   // DM

   if( s.length() != 2 )
   {
      return false;
   }

   // Validate the range direction
   Range_direction rgd{ to_range_direction( s[0] ) };
   if( rgd == Range_direction::none )
   {
      return false;
   }

   int i{ (static_cast<int>(s[1]) - static_cast<int>('0')) };
   if( rgd == Range_direction::E )
   {
      // The range direction is East, then the only allowed value for the meridian is 1
      if( i != 1 )
      {
         return false;
      }
      // Use -1 for the meridian to indicate East
      i = -1;
   }

   try
   {
      // Validate the meridian
      m = i;
   }
   catch( exception )
   {
      return false;
   }

   return true;
}

}

nhill::uwi::Dls::Dls() = default;

nhill::uwi::Dls::Dls( const Location_exception& le, const Legal_subdivision& lsd, const Section& sc, const Township& twp, const Range& rg, const Meridian& m, const Event_sequence& es )
   : le{le}
   , lsd{lsd}
   , sc{sc}
   , twp{twp}
   , rg{rg}
   , m{m}
   , es{es}
{
}

nhill::uwi::Dls::Dls( const Dls& ) = default;
auto nhill::uwi::Dls::operator=( const Dls& )->Dls & = default;

nhill::uwi::Dls::Dls( Dls&& ) noexcept = default;
auto nhill::uwi::Dls::operator=( Dls&& ) noexcept->Dls & = default;

nhill::uwi::Dls::~Dls() = default;

void nhill::uwi::Dls::clear()
{
   le.clear();
   lsd.clear();
   sc.clear();
   twp.clear();
   rg.clear();
   m.clear();
   es.clear();
}

string nhill::uwi::Dls::sort() const
{
   ostringstream oss;

	oss << to_int( Survey_system::dls );
	oss << rgd();
	oss << m;
	oss << rg;
   oss << twp;
	oss << sc;
   oss << lsd;
   oss << le;
   oss << es;
   
   return oss.str();
}

string nhill::uwi::Dls::plain( bool range_direction ) const
{
   ostringstream oss;

   oss << le;
   oss << lsd;
   oss << sc;
   oss << twp;
   oss << rg;
   if( range_direction )
   {
      oss << rgd();
   }
   oss << m;
   oss << es;

   return oss.str();
}

string nhill::uwi::Dls::full() const
{
   ostringstream oss;

   oss << 1;
   oss << le;
   oss << lsd;
   oss << sc;
   oss << twp;
   oss << rg;
   oss << rgd();
   oss << m;
   oss << 0;
   oss << es;

   return oss.str();
}

string nhill::uwi::Dls::plain_dressed() const
{
   ostringstream oss;

   oss << le;
   oss << slash;
   oss << lsd;
   oss << dash;
   oss << sc;
   oss << dash;
   oss << twp;
   oss << dash;
   oss << rg;
   oss << rgd();
   oss << m;
   oss << slash;
   oss << es;

   return oss.str();
}

string nhill::uwi::Dls::full_dressed() const
{
   ostringstream oss;

   oss << 1; // survey system
   oss << le;
   oss << slash;
   oss << lsd;
   oss << dash;
   oss << sc;
   oss << dash;
   oss << twp;
   oss << dash;
   oss << rg;
   oss << rgd();
   oss << m;
   oss << slash;
   oss << 0; // padding character
   oss << es;

   return oss.str();
}

string nhill::uwi::Dls::to_string( Format fmt ) const
{
	switch( fmt )
	{
	case Format::sort: return sort();
	case Format::plain: return plain();
	case Format::plain_no_rgd: return plain(false);
	case Format::plain_dressed: return plain_dressed();
	case Format::full: return full();
	case Format::full_dressed: return full_dressed();
	default: return {};
	}
}

auto nhill::uwi::Dls::range_direction() const->Range_direction
{
   return m.range_direction();
}

char nhill::uwi::Dls::rgd() const
{
   return to_char( range_direction() );
}

template<> inline
auto nhill::compare( const uwi::Dls& a, const uwi::Dls& b ) noexcept -> Compare
{
   if( a.twp < b.twp )
   {
      return Compare::less;
   }
   else if( a.twp == b.twp )
   {
      if( a.m < b.m )
      {
         return Compare::less;
      }
      else if( a.m == b.m )
      {
         if( a.rg < b.rg )
         {
            return Compare::less;
         }
         else if( a.rg == b.rg )
         {
            if( a.sc < b.sc )
            {
               return Compare::less;
            }
            else if( a.sc == b.sc )
            {
               if( a.lsd < b.lsd )
               {
                  return Compare::less;
               }
               else if( a.lsd == b.lsd )
               {
                  if( a.le < b.le )
                  {
                     return Compare::less;
                  }
                  else if( a.le == b.le )
                  {
                     if( a.es < b.es )
                     {
                        return Compare::less;
                     }
                     else if( a.es == b.es )
                     {
                        return Compare::equal;
                     }
                  }
               }
            }
         }
      }
   }

   return Compare::greater;
}

bool nhill::uwi::operator==( const Dls& a, const Dls& b )
{
   return a.le == b.le
      && a.lsd == b.lsd
      && a.sc == b.sc
      && a.twp == b.twp
      && a.rg == b.rg
      && a.m  == b.m 
      && a.es == b.es;
}

bool nhill::uwi::operator!=( const Dls& a, const Dls& b )
{
   return !(a == b);
}

bool nhill::uwi::operator<( const Dls& a, const Dls& b )
{
   return compare<const Dls&>(a,b) == Compare::less;
}

bool nhill::uwi::operator>( const Dls& a, const Dls& b )
{
   return compare<const Dls&>(a,b) == Compare::greater;
}

bool nhill::uwi::operator<=( const Dls& a, const Dls& b )
{
   return (a == b) || (a < b);
}

bool nhill::uwi::operator>=( const Dls& a, const Dls& b )
{
   return (a == b) || (a > b);
}

bool nhill::uwi::dls::is_sort( std::string_view s, Dls* dls )
{
   if( dls != nullptr )
   {
      dls->clear();
   }

   // The string must be the same length as the sort format
   if( s.size() != len_sort )
   {
      return false;
   }

	// 1DMRRTTTSSLLXXE  
	// 012345678901234

	if( s[0] != '1' )
	{
		return false;
	}

   Dls::Meridian m;
   if( !is_valid_range_direction_and_meridian( s.substr(1,2), m) )
   {
      return false;
   }

   Dls::Location_exception le;
   Dls::Legal_subdivision lsd;
   Dls::Section sc;
   Dls::Township twp;
   Dls::Range rg;
   Dls::Event_sequence es;

   // Validation is done when setting values
   try
   {
      lsd = s.substr( 10, 2 );
      sc  = s.substr(  8, 2 );
      twp = s.substr(  5, 3 );
      rg  = s.substr(  3, 2 );
      es  = s[14];
      le = s.substr( 12, 2 );
   }
   catch( exception )
   {
      return false;
   }

   // Pass the parameters to output (if necessary)
   if( dls != nullptr )
   {
      dls->le  = le;
      dls->lsd = lsd;
      dls->sc  = sc;
      dls->twp = twp;
      dls->rg  = rg;
      dls->m   = m;
      dls->es  = es;
   }

   return true;
}

bool nhill::uwi::dls::is_plain( std::string_view s, Dls* dls )
{
   if( dls != nullptr )
   {
      dls->clear();
   }

   // The string must be the same length as the plain format
   if( s.size() != len_plain && s.size() != len_plain_rgd )
   {
      return false;
   }

   // 0123456789012    01234567890123
   // XXLLSSTTTRRME or XXLLSSTTTRRDME

   bool has_rgd{ s.size() == len_plain_rgd };
   Dls::Meridian m;
   if( has_rgd )
   {
      Dls::Meridian m;
      if( !is_valid_range_direction_and_meridian( s.substr( 11, 2 ), m ) )
      {
         return false;
      }
   }

   Dls::Location_exception le;
   Dls::Legal_subdivision lsd;
   Dls::Section sc;
   Dls::Township twp;
   Dls::Range rg;
   Dls::Event_sequence es;

   // Validation is done when setting values
   try
   {
      lsd = s.substr( 2, 2 );
      sc  = s.substr( 4, 2 );
      twp = s.substr( 6, 3 );
      rg  = s.substr( 9, 2 );
      if( has_rgd )
      {
         // meridian is already validated and set
         es = s[13];
      }
      else
      {
         m = s.substr( 11, 1 );
         es = s[12];
      }
      le = s.substr( 0, 2 );
   }
   catch( exception )
   {
      return false;
   }

   // Pass the parameters to output (if necessary)
   if( dls != nullptr )
   {
      dls->le  = le;
      dls->lsd = lsd;
      dls->sc  = sc;
      dls->twp = twp;
      dls->rg  = rg;
      dls->m   = m;
      dls->es  = es;
   }

   return true;
}

bool nhill::uwi::dls::is_full( std::string_view s, Dls* dls )
{
   if( dls != nullptr )
   {
      dls->clear();
   }

   // The string must be the same length as this format
   if( s.size() != len_full )
   {
      return false;
   }

   // 0123456789012345
   // 1XXLLSSTTTRRDM0E

   if( s[0] != '1' || s[14] != '0' )
   {
      return false;
   }

   Dls::Meridian m;
   if( !is_valid_range_direction_and_meridian( s.substr( 12, 2 ), m ) )
   {
      return false;
   }

   Dls::Location_exception le;
   Dls::Legal_subdivision lsd;
   Dls::Section sc;
   Dls::Township twp;
   Dls::Range rg;
   Dls::Event_sequence es;

   // Validation is done when setting values
   try
   {
      lsd = s.substr( 3, 2 );
      sc  = s.substr( 5, 2 );
      twp = s.substr( 7, 3 );
      rg  = s.substr( 10, 2 );
      es  = s[15];
      le = s.substr( 1, 2 );
   }
   catch( exception )
   {
      return false;
   }

   // Pass the parameters to output (if necessary)
   if( dls != nullptr )
   {
      dls->le  = le;
      dls->lsd = lsd;
      dls->sc  = sc;
      dls->twp = twp;
      dls->rg  = rg;
      dls->m   = m;
      dls->es  = es;
   }

   return true;
}

bool nhill::uwi::dls::is_plain_dressed( std::string_view s, Dls* dls )
{
   if( dls != nullptr )
   {
      dls->clear();
   }

   // The string must be the same length as this format
   if( s.size() != len_plain_dressed )
   {
      return false;
   }

   // 0123456789012345678
   // XX/LL-SS-TTT-RRDM/E

   // Slashes and dashes are in the correct locations
   if( s[2] != slash || s[5] != dash || s[8] != dash || s[12] != dash || s[17] != slash )
   {
      return false;
   }

   // Validate and set the meridian
   Dls::Meridian m;
   if( !is_valid_range_direction_and_meridian( s.substr( 15, 2 ), m ) )
   {
      return false;
   }

   Dls::Location_exception le;
   Dls::Legal_subdivision lsd;
   Dls::Section sc;
   Dls::Township twp;
   Dls::Range rg;
   Dls::Event_sequence es;

   // Validation is done when setting values
   try
   {
      lsd = s.substr(  3, 2 );
      sc  = s.substr(  6, 2 );
      twp = s.substr(  9, 3 );
      rg  = s.substr( 13, 2 );
      es  = s[18];
      le = s.substr( 0, 2 );
   }
   catch( exception )
   {
      return false;
   }

   // Pass the parameters to output (if necessary)
   if( dls != nullptr )
   {
      dls->le  = le;
      dls->lsd = lsd;
      dls->sc  = sc;
      dls->twp = twp;
      dls->rg  = rg;
      dls->m   = m;
      dls->es  = es;
   }

   return true;
}

bool nhill::uwi::dls::is_full_dressed( std::string_view s, Dls* dls )
{
   if( dls != nullptr )
   {
      dls->clear();
   }

   // The string must be the same length as this format
   if( s.size() != len_full_dressed )
   {
      return false;
   }

   //           1         2
   // 012345678901234567890
   // 1XX/LL-SS-TTT-RRDM/0E


   if( s[0] != '1' || s[3] != slash || s[6] != dash || s[9] != dash || s[13] != dash || s[18] != slash || s[19] != '0' )
   {
      return false;
   }

   // Validate and set the meridian
   Dls::Meridian m;
   if( !is_valid_range_direction_and_meridian( s.substr( 16, 2 ), m ) )
   {
      return false;
   }

   Dls::Location_exception le;
   Dls::Legal_subdivision lsd;
   Dls::Section sc;
   Dls::Township twp;
   Dls::Range rg;
   Dls::Event_sequence es;

   // Validation is done when setting values
   try
   {
      lsd = s.substr( 4, 2 );
      sc  = s.substr( 7, 2 );
      twp = s.substr( 10, 3 );
      rg  = s.substr( 14, 2 );
      es  = s[20];
      le = s.substr( 1, 2 );
   }
   catch( exception )
   {
      return false;
   }

   // Pass the parameters to output (if necessary)
   if( dls != nullptr )
   {
      dls->le  = le;
      dls->lsd = lsd;
      dls->sc  = sc;
      dls->twp = twp;
      dls->rg  = rg;
      dls->m   = m;
      dls->es  = es;
   }

   return true;
}

bool nhill::uwi::dls::is_valid_dls( std::string_view str, Dls* dls )
{
   if( is_plain( str, dls ) )
   {
      return true;
   }
   else if( is_full_dressed( str, dls ) )
   {
      return true;
   }
   else if( is_sort( str, dls ) )
   {
      return true;
   }
   else if( is_full( str, dls ) )
   {
      return true;
   }
   else if( is_plain_dressed( str, dls ) )
   {
      return true;
   }
   else
   {
      return false;
   }
}

auto nhill::uwi::dls::parse_sort( std::string_view s )->Dls
{
	// 1DMRRTTTSSLLXXE  
	// 012345678901234

	try
	{
		Dls dls;

		dls.lsd = s.substr( 10, 2 );
		dls.sc = s.substr( 8, 2 );
		dls.twp = s.substr( 5, 3 );
		dls.rg = s.substr( 3, 2 );
		dls.es = s[14];
		dls.le = s.substr( 12, 2 );

		return dls;
	}
	catch( exception e)
	{
		throw e;
	}
}

auto nhill::uwi::dls::parse_plain( std::string_view s )->Dls
{
	try
	{
		Dls dls;

		dls.sc  = s.substr( 4, 2 );
		dls.twp = s.substr( 6, 3 );
		dls.rg  = s.substr( 9, 2 );
		if( s.size() == len_plain_rgd ) // Has range direction
		{
			dls.es = s[13];
		}
		else
		{
			dls.m = s.substr( 11, 1 );
			dls.es = s[12];
		}
		dls.le  = s.substr( 0, 2 );
		dls.lsd = s.substr( 2, 2 );

		return dls;
	}
	catch( exception e)
	{
		throw e;
	}
}
