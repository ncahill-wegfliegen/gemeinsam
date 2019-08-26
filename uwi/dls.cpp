#include "dls.h"
#include "range_direction_ex.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

namespace
{
constexpr char dash{'-'};
constexpr char slash{'/'};
}

nhill::uwi::Dls::Dls() = default;

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

   oss << twp;
   oss << m;
   oss << rg;
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

bool nhill::uwi::dls::is_sort( std::string_view str, Dls* dls )
{
	if( dls != nullptr )
	{
		dls->clear();
	}

	// The string must be the same length as the sort format
	if( str.size() != len_sort )
	{
		return false;
	}
	
	// 01234567890123 index
	// TTTMDRRSSLLXXE
	// 12345678901234 count

	Dls::Location_exception le;
	Dls::Legal_subdivision lsd;
	Dls::Section sc;
	Dls::Township twp;
	Dls::Range rg;
	Dls::Meridian m;
	Dls::Event_sequence es;

	try
	{
	}
	catch( exception e )
	{

	}

	//string s;

	//// The first three charactes must be the township
	//s = str.substr( 0, 3 );
	//int twp{ atoi( s.c_str() ) };
	//if( !is_valid_township( twp ) )
	//{
	//	return false;
	//}

	//// The fourth character is the meridian
	//s = str.substr( 3, 1 );
	//int m{ atoi( s.c_str() ) };
	//if( !is_valid_meridian( m ) )
	//{
	//	return false;
	//}

	//// The fifth character is the range direction
	//s = str.substr( 4, 1 );
	//Range_direction rgd{ to_enum<Range_direction>( atoi( s.c_str() ) )};
	//if( rgd == Range_direction::none )
	//{
	//	return false;
	//}

	//// Can only be East of the first meridian
	//if( rgd == Range_direction::E && m != 1 ) 
	//{
	//	return false;
	//}

	//// The sixth and seventh characters are the range
	//s = str.substr( 5, 2 );
	//int rg{ atoi( s.c_str() ) };
	//if( !is_valid_range( rg) )
	//{
	//	return false;
	//}

	//// The eighth and ninth characters are the section
	//s = str.substr( 7, 2 );
	//int sc{ atoi( s.c_str() ) };
	//if( !is_valid_section( sc ) )
	//{
	//	return false;
	//}

	//// The tenth and eleventh characters are the legal subdivision
	//s = str.substr( 9, 2 );
	//int lsd{ atoi( s.c_str() ) };
	//if( !is_valid_legal_subdivision( lsd ) )
	//{
	//	return false;
	//}

	//// The twelfth and thirteenth characters are the location exception
	//s = str.substr( 11, 2 );
	//string le{ s };
	//if( !is_valid_location_exception( le.c_str() ) )
	//{
	//	return false;
	//}

	//// The fourteenth character is the event sequence
	//s = str.substr( 13, 1 );
	//char es{ s[0] };
	//if( !is_valid_event_sequence( es ) )
	//{
	//	return true;
	//}

	//// The string must be the sort format for a DLS uwi
	//if( dls != nullptr )
	//{
	//	dls->le = le.c_str();
	//	dls->lsd = lsd;
	//	dls->sc = sc;
	//	dls->twp = twp;
	//	dls->rg = rg;
	//	dls->m = (rgd == Range_direction::E ? -1 : m);
	//	dls->es = es;
	//}

	return true;
}

bool nhill::uwi::dls::is_plain( std::string_view str, Dls* dls )
{
	if( dls != nullptr )
	{
		dls->clear();
	}

	// The string must be the same length as the plain format
	if( str.size() != len_plain && str.size() != len_plain_rgd )
	{
		return false;
	}
	bool has_rgd{ str.size() == len_plain_rgd };

	// 0123456789012    01234567890123
	// XXLLSSTTTRRME or XXLLSSTTTRRDME

	string s;
	size_t p{ 0 }; // The position at which to start the substring

	// location excepton
	s = str.substr( p, 2 );
	string le{ s };
	if( !is_valid_location_exception( le.c_str() ) )
	{
		return false;
	}
	p += 2;

	// legal subdivision
	s = str.substr( 6, 2 );
	int lsd{ atoi( s.c_str() ) };
	if( !is_valid_legal_subdivision( lsd ) )
	{
		return false;
	}
	p += 2;

	// section
	s = str.substr( p, 2 );
	int sc{ atoi( s.c_str() ) };
	if( !is_valid_section( sc ) )
	{
		return false;
	}
	p += 2;

	// township
	s = str.substr( p, 3 );
	int twp{ atoi( s.c_str() ) };
	if( !is_valid_township( twp ) )
	{
		return false;
	}
	p += 3;

	// range
	s = str.substr( p, 2 );
	int rg{ atoi( s.c_str() ) };
	if( !is_valid_range( rg ) )
	{
		return false;
	}
	p += 2;

	// range direction
	Range_direction rgd{ Range_direction::W};
	if( has_rgd )
	{
		s = str.substr( p, 1 );
		if( !is_valid_range_direction( s[0] ) )
		{
			return false;
		}
		rgd = to_range_direction( s[0] );
		p += 1;
	}

	// meridian
	s = str.substr( p, 1 );
	int m{ atoi( s.c_str() ) };
	if( !is_valid_meridian( m ) )
	{
		return false;
	}
	p += 1;

	// range direction can only be east for the first meridian
	if( rgd == Range_direction::E )
	{
		if( m != 1 )
		{
			return false;
		}
		m = -1; // change 1 to -1 for E
	}

	// event sequence
	s = str.substr( p, 1 );
	char es{ s[0] };
	if( !is_valid_event_sequence( es ) )
	{
		return false;
	}

	// It is plain format
	if( dls != nullptr )
	{
		dls->le = le.c_str();
		dls->lsd = lsd;
		dls->sc = sc;
		dls->twp = twp;
		dls->rg = rg;
		dls->m = m;
		dls->es = es;
	}

	return true;
}

bool nhill::uwi::dls::is_plain_rgd( std::string_view str, Dls* dls )
{
	if( dls != nullptr )
	{
		dls->clear();
	}

	// The string must be the same length as this format
	if( str.size() != len_full  )
	{
		return false;
	}

	// 0123456789012345
	// 1XXLLSSTTTRRDM0E

	string s;

	// survey system
	s = str.substr( 0, 1 );
	if( s[0] != '1' )
	{
		return false;
	}

	// location exception
	s = str.substr( 1, 2 );
	string le{ s };
	if( !is_valid_location_exception( s.c_str() ) )
	{
		return false;
	}

	// legal subdivision
	s = str.substr( 3, 2 );
	int lsd{ atoi( s.c_str() ) };
	if( !is_valid_legal_subdivision( lsd ) )
	{
		return false;
	}


	return bool();
}

bool nhill::uwi::dls::is_full( std::string_view str, Dls* dls )
{
	return bool();
}

bool nhill::uwi::dls::is_plain_dressed( std::string_view str, Dls* dls )
{
	return bool();
}

bool nhill::uwi::dls::is_full_dressed( std::string_view str, Dls* dls )
{
	return bool();
}
