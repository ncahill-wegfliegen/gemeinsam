#pragma once

#include "port.h"
#include "../utility/compare.h"
#include <cstdint>
#include <string>

namespace nhill
{
namespace uwi
{

class NHILL_UWI_PORT_CLASS Dls
{
public:
   enum class Rgd{ E, W }; // range direction East/West

   Dls();
   Dls( const char* le, int lsd, int sc, int twp, int rg, int m, int es, Rgd rgd = Rgd::W  );
   Dls( int le, int lsd, int sc, int twp, int rg, int m, int es, Rgd rgd = Rgd::W );

   Dls( const Dls& );
   Dls& operator=( const Dls& );

   Dls( Dls&& ) noexcept;
   Dls& operator=( Dls&& ) noexcept;

   ~Dls();

   const char* clocation_exception() const;
   void location_exception( const char* );

   int location_exception() const;
   void location_exception( int );

   int legal_subdivision() const;
   void legal_subdivision( int );

   int section() const;
   void section( int );

   int township() const;
   void township( int );

   int range() const;
   void range( int );

   Rgd range_direction() const;
   void range_direction( Rgd );

   int meridian() const;
   void meridian( int );

   char cevent_sequence() const;
   void event_sequence( char );

   int event_sequence() const;
   void event_sequence( int );



   const char* cle() const;
   void le( const char* );

   int le() const;
   void le( int );

   int lsd() const;
   void lsd( int );

   int sc() const;
   void sc( int );

   int twp() const;
   void twp( int );

   int rg() const;
   void rg( int );

   Rgd rgd() const;
   void rgd( Rgd );

   int m() const;
   void m( int );

   char ces() const;
   void es( char );

   int es() const;
   void es( int );

   void clear();

   std::string sort() const;
   std::string plain( bool range_direction = false ) const;
   std::string full() const;
   std::string plain_dressed() const;
   std::string full_dressed() const;

private:
   using value_type = uint8_t;

   char       le_[3]{"00"};   // location exception
   value_type lsd_  {0};      // legal subdivision
   value_type sc_   {0};      // section
   value_type twp_  {0};      // township
   value_type rg_   {0};      // range
   Rgd		  rgd_  {Rgd::W}; // range direction East/West
   value_type m_    {0};      // meridian
   char       es_   {'0'};    // event sequence

};

}
}


namespace nhill
{

template<> NHILL_UWI_PORT_CLASS inline
Compare compare( const uwi::Dls& a, const uwi::Dls& b ) noexcept;

namespace uwi
{

NHILL_UWI_PORT_CLASS bool operator==( const Dls& a, const Dls& b );
NHILL_UWI_PORT_CLASS bool operator!=( const Dls& a, const Dls& b );

NHILL_UWI_PORT_CLASS bool operator<( const Dls& a, const Dls& b );
NHILL_UWI_PORT_CLASS bool operator>( const Dls& a, const Dls& b );

NHILL_UWI_PORT_CLASS bool operator<=( const Dls& a, const Dls& b );
NHILL_UWI_PORT_CLASS bool operator>=( const Dls& a, const Dls& b );

NHILL_UWI_PORT_CLASS char to_char( Dls::Rgd rgd );
NHILL_UWI_PORT_CLASS Dls::Rgd to_dls_range_direction( char c );

}
}