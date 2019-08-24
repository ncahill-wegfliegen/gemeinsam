#include "dls.h"
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

nhill::uwi::Dls::Dls( const char* le, int lsd, int sc, int twp, int rg, int m, int es, Rgd rgd )
{
   this->le ( le  );
   this->lsd( lsd );
   this->sc ( sc  );
   this->twp( twp );
   this->rg ( rg  );
   this->rgd( rgd );
   this->m  ( m   );
   this->es ( es  );
}

nhill::uwi::Dls::Dls( int le, int lsd, int sc, int twp, int rg, int m, int es, Rgd rgd )
{
   this->le ( le  );
   this->lsd( lsd );
   this->sc ( sc  );
   this->twp( twp );
   this->rg ( rg  );
   this->rgd( rgd );
   this->m  ( m   );
   this->es ( es  );
}

nhill::uwi::Dls::Dls( const Dls& ) = default;
auto nhill::uwi::Dls::operator=( const Dls& )->Dls & = default;

nhill::uwi::Dls::Dls( Dls&& ) noexcept = default;
auto nhill::uwi::Dls::operator=( Dls&& ) noexcept->Dls & = default;

nhill::uwi::Dls::~Dls() = default;

const char* nhill::uwi::Dls::clocation_exception() const
{
   return cle();
}

void nhill::uwi::Dls::location_exception( const char* value)
{
   le( value );
}

int nhill::uwi::Dls::location_exception() const
{
   return le();
}

void nhill::uwi::Dls::location_exception( int value)
{
   le( value );
}

int nhill::uwi::Dls::legal_subdivision() const
{
   return lsd();
}

void nhill::uwi::Dls::legal_subdivision( int value)
{
   lsd( value );
}

int nhill::uwi::Dls::section() const
{
   return sc();
}

void nhill::uwi::Dls::section( int value)
{
   sc(value);
}

int nhill::uwi::Dls::township() const
{
   return twp();
}

void nhill::uwi::Dls::township( int value)
{
   twp( value );
}

int nhill::uwi::Dls::range() const
{
   return rg();
}

void nhill::uwi::Dls::range( int value)
{
   rg( value );
}

auto nhill::uwi::Dls::range_direction() const->Rgd
{
   return rgd();
}

void nhill::uwi::Dls::range_direction( Rgd value)
{
   rgd( value );
}

int nhill::uwi::Dls::meridian() const
{
   return m();
}

void nhill::uwi::Dls::meridian( int value)
{
   m( value );
}

char nhill::uwi::Dls::cevent_sequence() const
{
   return ces();
}

void nhill::uwi::Dls::event_sequence( char value )
{
   es( value );
}

int nhill::uwi::Dls::event_sequence() const
{
   return es();
}

void nhill::uwi::Dls::event_sequence( int value)
{
   es( value );
}

const char* nhill::uwi::Dls::cle() const
{
   return le_;
}

void nhill::uwi::Dls::le( const char* value)
{
   if( value == nullptr || strlen(value) == 0 )
   {
      le_[0] = '\0';
      le_[1] = '\0';
   }
   else
   {
      switch( strlen( value ) )
      {
      case 0:
      {
         le_[0] = '\0';
         le_[1] = '\0';
         break;
      }
      case 1:
      {
         le_[0] = '0';
         le_[1] = value[0];
         break;
      }
      case 2:
      {
         le_[0] = value[0];
         le_[1] = value[1];
         break;
      }
      }
   }

   le_[2] = '\0';
}

int nhill::uwi::Dls::le() const
{
   return atoi(cle());
}

void nhill::uwi::Dls::le( int value)
{
   le( to_string( value ).c_str() );
}

int nhill::uwi::Dls::lsd() const
{
   return static_cast<int>(lsd_);
}

void nhill::uwi::Dls::lsd( int value)
{
   lsd_ = static_cast<value_type>(value);
}

int nhill::uwi::Dls::sc() const
{
   return static_cast<int>(sc_);
}

void nhill::uwi::Dls::sc( int value)
{
   sc_ = static_cast<value_type>(value);
}

int nhill::uwi::Dls::twp() const
{
   return static_cast<int>(twp_);
}

void nhill::uwi::Dls::twp( int value)
{
   twp_ = static_cast<value_type>(value);
}

int nhill::uwi::Dls::rg() const
{
   return static_cast<int>(rg_);
}

void nhill::uwi::Dls::rg( int value)
{
   rg_ = static_cast<value_type>(value);
}

auto nhill::uwi::Dls::rgd() const->Rgd
{
   return rgd_;
}

void nhill::uwi::Dls::rgd( Rgd value)
{
   rgd_ = value;
}

int nhill::uwi::Dls::m() const
{
   return static_cast<int>(m_);
}

void nhill::uwi::Dls::m( int value)
{
   m_ = static_cast<value_type>(value);
}

char nhill::uwi::Dls::ces() const
{
   return es_;
}

void nhill::uwi::Dls::es( char value)
{
   es_ = value;
}

int nhill::uwi::Dls::es() const
{
   return static_cast<int>(es_ - '0');
}

void nhill::uwi::Dls::es( int value)
{
   es_ = static_cast<char>(value) + '0';
}

void nhill::uwi::Dls::clear()
{
   le_[0] = '0';
   le_[1] = '0';
   le_[2] = '\0';
   lsd_ = 0;
   sc_  = 0;
   twp_ = 0;
   rg_  = 0;
   rgd_ = Rgd::W;
   m_   = 0;
   es_  = '0';
}

string nhill::uwi::Dls::sort() const
{
   ostringstream oss;

   oss.fill( '0' );
   
   oss << setw( 3 ) << twp();
   oss << m();
   oss << setw( 2 ) << rg();
   oss << setw( 2 ) << sc();
   oss << setw( 2 ) << lsd();
   oss << le();
   oss << ces();
   
   return oss.str();
}

string nhill::uwi::Dls::plain( bool range_direction ) const
{
   ostringstream oss;

   oss.fill( '0' );

   oss << cle();
   oss << setw( 2 ) << lsd();
   oss << setw( 2 ) << sc ();
   oss << setw( 3 ) << twp();
   oss << setw( 2 ) << rg ();
   if( range_direction )
   {
      oss << to_char( rgd() );
   }
   oss << m ();
   oss << ces();

   return oss.str();
}

string nhill::uwi::Dls::full() const
{
   ostringstream oss;

   oss.fill( '0' );

   oss << 1;
   oss << cle();
   oss << setw( 2 ) << lsd();
   oss << setw( 2 ) << sc();
   oss << setw( 3 ) << twp();
   oss << setw( 2 ) << rg();
   oss << to_char( rgd() );
   oss << m();
   oss << 0;
   oss << ces();

   return oss.str();
}

string nhill::uwi::Dls::plain_dressed() const
{
   ostringstream oss;

   oss.fill( '0' );

   oss << cle();
   oss << slash;
   oss << setw( 2 ) << lsd();
   oss << dash;
   oss << setw( 2 ) << sc();
   oss << dash;
   oss << setw( 3 ) << twp();
   oss << dash;
   oss << setw( 2 ) << rg();
   oss << to_char( rgd() );
   oss << m();
   oss << slash;
   oss << ces();

   return oss.str();
}

string nhill::uwi::Dls::full_dressed() const
{
   ostringstream oss;

   oss.fill( '0' );

   oss << 1; // survey system
   oss << cle();
   oss << slash;
   oss << setw( 2 ) << lsd();
   oss << dash;
   oss << setw( 2 ) << sc();
   oss << dash;
   oss << setw( 3 ) << twp();
   oss << dash;
   oss << setw( 2 ) << rg();
   oss << to_char( rgd() );
   oss << m();
   oss << slash;
   oss << 0; // padding character
   oss << ces();

   return oss.str();
}

template<> inline
auto nhill::compare( const uwi::Dls& a, const uwi::Dls& b ) noexcept -> Compare
{
   if( a.twp() < b.twp() )
   {
      return Compare::less;
   }
   else if( a.twp() == b.twp() )
   {
      if( a.m() < b.m() )
      {
         return Compare::less;
      }
      else if( a.m() == b.m() )
      {
         if( a.rg() < b.rg() )
         {
            return Compare::less;
         }
         else if( a.rg() == b.rg() )
         {
            if( a.sc() < b.sc() )
            {
               return Compare::less;
            }
            else if( a.sc() == b.sc() )
            {
               if( a.lsd() < b.lsd() )
               {
                  return Compare::less;
               }
               else if( a.lsd() == b.lsd() )
               {
                  if( strcmp( a.cle(), b.cle() ) < 0 )
                  {
                     return Compare::less;
                  }
                  else if( strcmp( a.cle(), b.cle() ) == 0 )
                  {
                     if( a.ces() < b.ces() )
                     {
                        return Compare::less;
                     }
                     else if( a.ces() == b.ces() )
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
   return strcmp(a.cle(), b.cle()) == 0
      && a.lsd() == b.lsd()
      && a.sc () == b.sc ()
      && a.twp() == b.twp()
      && a.rg () == b.rg ()
      && a.m  () == b.m  ()
      && a.rgd() == b.rgd()
      && a.ces () == b.ces ();
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

char nhill::uwi::to_char( Dls::Rgd rgd )
{
   switch( rgd )
   {
   case nhill::uwi::Dls::Rgd::E: return 'E';
   case nhill::uwi::Dls::Rgd::W: return 'W';
   default: return '\0';
   }
}

auto nhill::uwi::to_dls_range_direction( char c )->Dls::Rgd
{
   switch( c )
   {
   case 'E':
   case 'e':
   return Dls::Rgd::E;

   case 'W':
   case 'w':
   return Dls::Rgd::W;

   default:
   return Dls::Rgd::W;
   }
}
