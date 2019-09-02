#include "location_exception.h"
#include "../enum/core/int.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <gsl/gsl_assert>

using namespace std;

nhill::uwi::dls::Location_exception::Location_exception()
{
   clear();
}

nhill::uwi::dls::Location_exception::Location_exception( std::string_view s)
{
   value( s );
}

auto nhill::uwi::dls::Location_exception::operator=( std::string_view s )->Location_exception &
{
   value( s );
   return *this;
}

nhill::uwi::dls::Location_exception::Location_exception( int i )
{
   value( i );
}

auto nhill::uwi::dls::Location_exception::operator=( int i )->Location_exception &
{
   value( i );
   return *this;
}

nhill::uwi::dls::Location_exception::Location_exception( const Location_exception& other ) = default;
auto nhill::uwi::dls::Location_exception::operator=( const Location_exception& other )->Location_exception & = default;

nhill::uwi::dls::Location_exception::Location_exception( Location_exception&& other ) noexcept = default;
auto nhill::uwi::dls::Location_exception::operator=( Location_exception&& other ) noexcept->Location_exception & = default;

nhill::uwi::dls::Location_exception::~Location_exception() = default;

string nhill::uwi::dls::Location_exception::value() const noexcept
{
	return s_.str();
}

void nhill::uwi::dls::Location_exception::value( std::string_view s)
{
   string error_msg;
   if( !is_valid( s, &error_msg ) )
   {
      throw invalid_argument( error_msg.c_str() );
   }

   if( s.length() == 0 )
   {
      clear();
   }
   else if (s.length() == 1 )
   {
		char tmp[3]{ '0', s[0], '\0' };
		set_unchecked(tmp);
   }
   else // must be length 2
   {
		char tmp[3]{ s[0], s[1], '\0' };
		set_unchecked( tmp );
	}
}

int nhill::uwi::dls::Location_exception::integer() const
{
   if( !isdigit( s_[0] ) || !isdigit( s_[1] ) )
   {
      throw logic_error( "The location exception '" + string{ value() } +"' cannot is not an integer." );
   }
   
   return stoi(value());
}

void nhill::uwi::dls::Location_exception::value( int i)
{
   string error_msg;
   if( !is_valid( i, &error_msg ) )
   {
      throw invalid_argument( error_msg.c_str() );
   }

   ostringstream oss;
   oss << setfill( '0' ) << setw( 2 ) << i;
	set_unchecked( oss.str() );
}

void nhill::uwi::dls::Location_exception::clear()
{
	set_unchecked( "00" );
}

bool nhill::uwi::dls::Location_exception::is_valid( std::string_view s, string* error_msg )
{
   return is_valid_location_exception( s, error_msg );
}

bool nhill::uwi::dls::Location_exception::is_valid( int i, std::string* error_msg )
{
   return is_valid_location_exception( i, error_msg );
}

void nhill::uwi::dls::Location_exception::set_unchecked( std::string_view s )
{
	if( s.length() != 2 )
	{
		throw invalid_argument( "The string '" + string{ s } +"' is cannot be a DLS location because it is not of length 2." );
	}
	s_.assign( s.data(), s.length() );
}

template<>
auto nhill::compare( const uwi::dls::Location_exception& a, const uwi::dls::Location_exception& b )->Compare
{
	return to_enum<Compare>( a.value().compare( b.value() ) );
}

bool nhill::uwi::dls::is_valid_location_exception( std::string_view s, std::string* error_msg )
{
   // If the string is empty
   if( s.length() == 0 )
   {
      return true;
   }

   // If the string is too long (must be less than 3 characters)
   if( 3 <= s.length() )
   {
      if( error_msg != nullptr )
      {
         *error_msg = "This string \"" + string{ s } + "\" is too long to copy into a location exception: it must be less than two characters.";
      }
      return false;
   }

   // If the string contains a single character
   if( s.length() == 1 )
   {
      char c{ s[0] };
      if( isdigit( c ) )
      {
         if( c != '1' )
         {
            return true;
         }
      }

      if( error_msg != nullptr )
      {
         *error_msg = "This character \"" + string(1,c) +"\" is not a valid location exception: it must be either '0' or between '2' and '9'.";
      }
      return false;
   }

   // At this point we know that the string must be two characters

   // Validate the characters in the string
   const char c0{ s[0] };
   const char c1{ s[1] };

   // If both characters are integers
   if( isdigit( c0 ) && isdigit( c1 ) )
   {
      char tmp[]{ c0, c1, '\0' };
      int i{ atoi( tmp ) };
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
      if( 'A' <= c0 && c0 <= 'H' )
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

bool nhill::uwi::dls::is_valid_location_exception( int i, std::string* error_msg )
{
   if( (i == 0) || (2 <= i && i <= 99) )
   {
      return true;
   }
   else
   {
      if( error_msg != nullptr )
      {
         *error_msg = "The integer \"" + to_string( i ) + "\" is not a valid location exception: it must be either '0' or between '2' and '99'";
      }
      return false;
   }
}

ostream& nhill::uwi::dls::operator<<( ostream& out, const Location_exception& le )
{
   return out << le.value();
}

istream& nhill::uwi::dls::operator>>( istream& in, Location_exception& le )
{
   string s;
   in >> s;
   le = s;
   return in;
}

bool nhill::uwi::dls::operator==( const Location_exception& a, const Location_exception& b )
{
   return compare<const Location_exception&>( a, b ) == Compare::equal;
}

bool nhill::uwi::dls::operator!=( const Location_exception& a, const Location_exception& b )
{
   return !(a == b);
}

bool nhill::uwi::dls::operator<( const Location_exception& a, const Location_exception& b )
{
   return compare<const Location_exception&>( a, b ) == Compare::less;
}

bool nhill::uwi::dls::operator>( const Location_exception& a, const Location_exception& b )
{
   return compare<const Location_exception&>( a, b ) == Compare::greater;
}

bool nhill::uwi::dls::operator<=( const Location_exception& a, const Location_exception& b )
{
   return !(a > b);
}

bool nhill::uwi::dls::operator>=( const Location_exception& a, const Location_exception& b )
{
   return !(a < b);
}
