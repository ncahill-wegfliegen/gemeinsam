#include "event_sequence.h"
#include <algorithm>

using namespace std;

nhill::uwi::dls::Event_sequence::Event_sequence()
   : base{ "0" }
{
}

nhill::uwi::dls::Event_sequence::Event_sequence( const char* s )
{
   string error_msg;
   if( !is_valid( s, &error_msg ) )
   {
      throw invalid_argument( error_msg.c_str() );
   }

   base::set( s );
}

auto nhill::uwi::dls::Event_sequence::operator=( const char* s )->Event_sequence &
{
   base::operator=( s );
   return *this;
}

nhill::uwi::dls::Event_sequence::Event_sequence( int i )
{
   operator=( i );
}

auto nhill::uwi::dls::Event_sequence::operator=( int i )->Event_sequence &
{
   string error_msg;
   if( !is_valid( i, &error_msg ) )
   {
      throw invalid_argument( error_msg.c_str() );
   }

   base::set( to_string(i).c_str());

   return *this;
}

nhill::uwi::dls::Event_sequence::Event_sequence( const Event_sequence& other ) = default;
auto nhill::uwi::dls::Event_sequence::operator=( const Event_sequence& other )->Event_sequence & = default;

nhill::uwi::dls::Event_sequence::Event_sequence( Event_sequence&& other ) noexcept = default;
auto nhill::uwi::dls::Event_sequence::operator=( Event_sequence&& other ) noexcept->Event_sequence & = default;

nhill::uwi::dls::Event_sequence::~Event_sequence() = default;


nhill::uwi::dls::Event_sequence::operator const char* () const
{
   return base::operator const char* ();
}

nhill::uwi::dls::Event_sequence::operator int() const
{
   const char* const s{ base::operator const char* () };
   const char c0{ s[0] };

   if( !isdigit( c0 )  )
   {
      throw logic_error( "The location exception \"" + string{ s } +"\" cannot be converted to an integer." );
   }

   return atoi( s );
}

constexpr size_t nhill::uwi::dls::Event_sequence::size() const
{
   return base::size();
}

void nhill::uwi::dls::Event_sequence::clear()
{
   base::clear();
}

bool nhill::uwi::dls::Event_sequence::is_valid( const char* s, string* error_msg )
{
   // Validate string length (less than or equal to two)
   if( !base::is_valid( s, error_msg ) )
   {
      return false;
   }

   // The event sequence must be either a digit (except 1) or a capital letter
   const char c{ s[0] };
   if( isdigit( c ) || ( 'A' <= c && c <= 'Z'))
   {
      return true;
   }

   if( error_msg != nullptr )
   {
      *error_msg = "The character \"" + string{ s } + "\" is not a valid event sequence: it must be either a digit (except 1) or a capital letter.";
   }

   return false;
}

bool nhill::uwi::dls::Event_sequence::is_valid( int i, std::string* error_msg )
{
   if( (i == 0) || (2 <= i && i <= 9) )
   {
      return true;
   }
   else
   {
      if( error_msg != nullptr )
      {
         *error_msg = "The integer \"" + to_string( i ) + "\" is not a valid event sequence: it must be either '0' or between '2' and '9'.";
      }
      return false;
   }
}

