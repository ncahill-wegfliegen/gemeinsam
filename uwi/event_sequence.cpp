#include "event_sequence.h"
#include "../enum/core/int.h"
#include <algorithm>
#include <string>

using namespace std;

nhill::uwi::dls::Event_sequence::Event_sequence()
{
   clear();
}

nhill::uwi::dls::Event_sequence::Event_sequence( char c )
{
   value(c);
}

auto nhill::uwi::dls::Event_sequence::operator=( char c )->Event_sequence &
{
   value( c );
   return *this;
}

nhill::uwi::dls::Event_sequence::Event_sequence( std::string_view s)
{
	value( s );
}

auto nhill::uwi::dls::Event_sequence::operator=( std::string_view s)->Event_sequence &
{
	value( s );
	return *this;
}

nhill::uwi::dls::Event_sequence::Event_sequence( int i )
{
   value( i );
}

auto nhill::uwi::dls::Event_sequence::operator=( int i )->Event_sequence &
{
   value( i );
   return *this;
}

nhill::uwi::dls::Event_sequence::Event_sequence( const Event_sequence& other ) = default;
auto nhill::uwi::dls::Event_sequence::operator=( const Event_sequence& other )->Event_sequence & = default;

nhill::uwi::dls::Event_sequence::Event_sequence( Event_sequence&& other ) noexcept = default;
auto nhill::uwi::dls::Event_sequence::operator=( Event_sequence&& other ) noexcept->Event_sequence & = default;

nhill::uwi::dls::Event_sequence::~Event_sequence() = default;

void nhill::uwi::dls::Event_sequence::clear()
{
   s_ = "0";
}

char nhill::uwi::dls::Event_sequence::value() const
{
   return s_[0];
}

void nhill::uwi::dls::Event_sequence::value( char c)
{
   if( !is_valid( c ) )
   {
      throw invalid_argument( "The character '" + string( 1, c ) + "' is not a valid event sequence: it must be either a digit [0,2-9] or a capital letter [A-Z]" );
   }

	char s[]{ c, '\0' };
   s_ = s;
}

string nhill::uwi::dls::Event_sequence::str() const
{
	return s_.str();
}

void nhill::uwi::dls::Event_sequence::value( std::string_view s)
{
	if( s.length() != 1 )
	{
		throw invalid_argument( "The string '" + string{ s } +"' is not a valid event sequence; it must be a single character." );
	}

	value( s[0] );
}


int nhill::uwi::dls::Event_sequence::integer() const
{
   if( !isdigit( value() ) )
   {
      throw logic_error( "The location exception \"" + string( 1, value() ) + "\" cannot be converted to an integer." );
   }

   return static_cast<int>(value() - '0');
}

void nhill::uwi::dls::Event_sequence::value( int i)
{
   if( !is_valid( i ) )
   {
      throw invalid_argument( "The integer '" + to_string( i ) + "' is not a valid event sequence: it must be either 0 or between 2 and 9" );
   }

	char c{ '0' + static_cast<char>(i)};
	value( c );
}


bool nhill::uwi::dls::Event_sequence::is_valid( char c )
{
   return is_valid_event_sequence( c );
}

bool nhill::uwi::dls::Event_sequence::is_valid( int i )
{
   return is_valid_event_sequence( i );
}

template<>
auto nhill::compare( const uwi::dls::Event_sequence& a, const uwi::dls::Event_sequence& b )->Compare
{
   if( a.value() < b.value() )
   {
      return Compare::less;
   }
   else if( a.value() == b.value() )
   {
      return Compare::equal;
   }
   else
   {
      return Compare::greater;
   }
}

bool nhill::uwi::dls::is_valid_event_sequence( char c )
{
   // The event sequence must be either a digit (except 1) or a capital letter
   if( (isdigit( c ) && c != '1') || ('A' <= c && c <= 'Z') )
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool nhill::uwi::dls::is_valid_event_sequence( int i )
{
   if( (i == 0) || (2 <= i && i <= 9) )
   {
      return true;
   }
   else
   {
      return false;
   }
}

ostream& nhill::uwi::dls::operator<<( ostream& out, const Event_sequence& es )
{
   return out << es.value();
}

bool nhill::uwi::dls::operator==( const Event_sequence& a, const Event_sequence& b )
{
   return compare<const Event_sequence&>( a, b ) == Compare::equal;
}

bool nhill::uwi::dls::operator!=( const Event_sequence& a, const Event_sequence& b )
{
   return !(a == b);
}

bool nhill::uwi::dls::operator<( const Event_sequence& a, const Event_sequence& b )
{
   return compare<const Event_sequence&>( a, b ) == Compare::less;
}

bool nhill::uwi::dls::operator>( const Event_sequence& a, const Event_sequence& b )
{
   return compare<const Event_sequence&>( a, b ) == Compare::greater;
}

bool nhill::uwi::dls::operator<=( const Event_sequence& a, const Event_sequence& b )
{
   return !(a > b);
}

bool nhill::uwi::dls::operator>=( const Event_sequence& a, const Event_sequence& b )
{
   return !(a < b);
}

