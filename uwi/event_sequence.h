#pragma once

#include "port.h"
#include "../utility/compare.h"
#include <ostream>

namespace nhill
{
namespace uwi
{
namespace dls
{

class NHILL_UWI_PORT_CLASS Event_sequence 
{
public:
   Event_sequence();

   Event_sequence( char );
   Event_sequence& operator=( char );

   Event_sequence( int );
   Event_sequence& operator=( int );

   Event_sequence( const Event_sequence& );
   Event_sequence& operator=( const Event_sequence& );

   Event_sequence( Event_sequence&& ) noexcept;
   Event_sequence& operator=( Event_sequence&& ) noexcept;

   ~Event_sequence();

   operator char () const;
   operator int() const;

	char value() const;
	void value( char );

	int ivalue() const;
	void value( int );

   void clear();

   static bool is_valid( char c );
   static bool is_valid( int i );

private:
	char c_{};
};

}
}
}

namespace nhill
{

template<> NHILL_UWI_PORT_FUNCTION inline
Compare compare( const uwi::dls::Event_sequence& a, const uwi::dls::Event_sequence& b );

namespace uwi
{
namespace dls
{

NHILL_UWI_PORT_FUNCTION bool is_valid_event_sequence( char c );
NHILL_UWI_PORT_FUNCTION bool is_valid_event_sequence( int i );

NHILL_UWI_PORT_FUNCTION std::ostream& operator<<( std::ostream& out, const Event_sequence& es );

NHILL_UWI_PORT_FUNCTION bool operator==( const Event_sequence& a, const Event_sequence& b );
NHILL_UWI_PORT_FUNCTION bool operator!=( const Event_sequence& a, const Event_sequence& b );

NHILL_UWI_PORT_FUNCTION bool operator<( const Event_sequence& a, const Event_sequence& b );
NHILL_UWI_PORT_FUNCTION bool operator>( const Event_sequence& a, const Event_sequence& b );

NHILL_UWI_PORT_FUNCTION bool operator<=( const Event_sequence& a, const Event_sequence& b );
NHILL_UWI_PORT_FUNCTION bool operator>=( const Event_sequence& a, const Event_sequence& b );

}
}
}
