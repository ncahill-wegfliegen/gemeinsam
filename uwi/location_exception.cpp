#include "location_exception.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <gsl/gsl_assert>

using namespace std;

nhill::uwi::dls::Location_exception::Location_exception()
   : base{ "00" }
{
}

nhill::uwi::dls::Location_exception::Location_exception( const char* s)
{
   string error_msg;
   if( !is_valid( s, &error_msg ) )
   {
      throw invalid_argument( error_msg.c_str() );
   }

   base::set( s );
}

auto nhill::uwi::dls::Location_exception::operator=( const char* s )->Location_exception &
{
   base::operator=( s );
   return *this;
}

nhill::uwi::dls::Location_exception::Location_exception( int i)
{
   operator=( i );
}

auto nhill::uwi::dls::Location_exception::operator=( int i )->Location_exception &
{
   string error_msg;
   if( !is_valid( i, &error_msg ) )
   {
      throw invalid_argument( error_msg.c_str() );
   }

   ostringstream oss;
   oss << setw( 2 ) << setfill( '0' ) << i;
   base::set( oss.str().c_str() );
   
   return *this;
}

nhill::uwi::dls::Location_exception::Location_exception( const Location_exception& other ) = default;
auto nhill::uwi::dls::Location_exception::operator=( const Location_exception& other )->Location_exception & = default;

nhill::uwi::dls::Location_exception::Location_exception( Location_exception&& other ) noexcept = default;
auto nhill::uwi::dls::Location_exception::operator=( Location_exception&& other ) noexcept->Location_exception & = default;

nhill::uwi::dls::Location_exception::~Location_exception() = default;


nhill::uwi::dls::Location_exception::operator const char* () const
{
   return base::operator const char* ();
}

nhill::uwi::dls::Location_exception::operator int() const
{
   const char* const s{ base::operator const char* () };
   const char c0{ s[0] };
   const char c1{ s[1] };

   if( !isdigit( c0 ) && !isdigit( c1 ) )
   {
      throw logic_error( "The location exception \"" + string{ s } +"\" cannot be converted to an integer." );
   }

   return atoi( s );
}

constexpr size_t nhill::uwi::dls::Location_exception::size() const
{
   return base::size();
}

void nhill::uwi::dls::Location_exception::clear()
{
   base::clear();
}

bool nhill::uwi::dls::Location_exception::is_valid( const char* s, string* error_msg )
{
   if( s == nullptr )
   {
      return true;
   }

   // Validate string length (less than or equal to two)
   if( !base::is_valid( s, error_msg ) )
   {
      return false;
   }

   // The location exception must be two characters
   if( strlen( s ) != 2 )
   {
      if( error_msg != nullptr )
      {
         *error_msg = "The string \"" + string{ s } +"\" is not a valid location exception: it must be two characters.";
      }
      return false;
   }

   // Validate the characters in the string
   const char c0{ s[0] };
   const char c1{ s[1] };

   // If both characters are integers
   if( isdigit( c0 ) && isdigit( c1 ) )
   {
      int i{ atoi( s ) };
      if( 0 <= i && i != 1 && i <= 99 )
      {
         return true;
      }

      if( error_msg != nullptr )
      {
         *error_msg = "The string \"" + string{ s } +"\" is not a valid location exception: it must be either '00' or between '02' and '99'";
      }
      return false;
   }

   // If both characters are alphas, then it is oil sands
   if( isalpha( c0 ) && isalpha( c1 ) )
   {
      if('A' <= c0 && c0 <= 'H' )
      {
         // The first character is okay.  
         // Check the second character.
         if( 'A' <= c1 && c1 <= 'Z' )
         {
            // But it cannot be 'I' or 'O'
            if( c1 != 'I' && c1 != 'O' )
            {
               return true;
            }
         }
      }

      if( error_msg != nullptr )
      {
         *error_msg = "The string \"" + string{ s } +"\" is not a valid location exception for an oil sand evaluation drill hole.";
      }
      return false;
   }

   // If the first character is a quadrant {A, B, C, D} and the second character is a digit
   if( c0 == 'A' || c0 == 'B' || c0 == 'C' || c0 == 'D' )
   {
      if( (c1 == '0') || ('2' <= c1 && c1 <= '9') )
      {
         return true;
      }

      if( error_msg != nullptr )
      {
         *error_msg = "The string \"" + string{ s } +"\" is not a valid location exception for a quadrant.";
      }
      return false;
   }

   // If the first character is a road allowance {S, W} and the second character is a digit
   if( c0 == 'S' || c0 == 'W' )
   {
      if( (c1 == '0') || ('2' <= c1 && c1 <= '9') )
      {
         return true;
      }

      if( error_msg != nullptr )
      {
         *error_msg = "The string \"" + string{ s } +"\" is not a valid location exception for a road allowance.";
      }
      return false;
   }

   // If the first character is a water source {F, O} and the second character is a digit
   if( c0 == 'F' || c0 == 'O' )
   {
      if( (c1 != '0') && ('1' <= c1 && c1 <= '9') )
      {
         return true;
      }

      if( error_msg != nullptr )
      {
         *error_msg = "The string \"" + string{ s } +"\" is not a valid location exception for a road allowance.";
      }
      return false;
   }

   // Not a location exception
   if( error_msg != nullptr )
   {
      *error_msg = "The string \"" + string{ s } +"\" is not a location exception.";
   }
   return true;
}

bool nhill::uwi::dls::Location_exception::is_valid( int i, std::string* error_msg )
{
   if( (i == 0) || (2 <= i && i <= 99) )
   {
      return true;
   }
   else
   {
      if( error_msg != nullptr )
      {
         *error_msg = "The integer \"" + to_string( i ) +"\" is not a valid location exception: it must be either '0' or between '2' and '99'";
      }
      return false;
   }
}
