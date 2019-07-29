#include "bundle.h"
#include <algorithm>
#include <ctype.h>
#include <stdexcept>

using namespace std;

namespace
{

bool is_empty_or_all_whitespace( string_view s )
{
   if( s.size() == 0 )
   {
      return true;
   }
   else
   {
      auto itr{ find_if_not( s.cbegin(), s.cend(), isspace ) };
      return itr == s.cend(); // if we reach the end, then every character is whitespace
   }
}

}

const string nhill::text::Bundle::empty_string_{ "" };

nhill::text::Bundle::Bundle( string_view string )
{
   if( is_empty_or_all_whitespace( string ) )
   {
      throw invalid_argument( "The string parameter cannot be empty." );
   }

   bundle_.emplace( Text::string, string );
}

nhill::text::Bundle::Bundle( string_view code, string_view abbreviation, string_view string, string_view label, string_view description )
{
   if( is_empty_or_all_whitespace( string ) )
   {
      throw invalid_argument( "The string parameter cannot be empty." );
   }

   bundle_.emplace( Text::code, code );
   bundle_.emplace( Text::abbreviation, abbreviation );
   bundle_.emplace( Text::string, string );
   bundle_.emplace( Text::label, label );
   bundle_.emplace( Text::description, description );
}

nhill::text::Bundle::Bundle( initializer_list<pair<const Text, std::string>> init_list )
{
   map<Text, std::string> temp_bundle;

   for( const auto& [type,text] : init_list )
   {
      temp_bundle.emplace( type, text );
   }

   auto itr{ temp_bundle.find( Text::string ) };
   if( itr == temp_bundle.end() || is_empty_or_all_whitespace(itr->second ) )
   {
      throw invalid_argument( "The string parameter cannot be empty." );
   }

   bundle_ = move( temp_bundle );
}

nhill::text::Bundle::Bundle( const Bundle& other ) = default;
auto nhill::text::Bundle::operator=( const Bundle& other )->Bundle & = default;

nhill::text::Bundle::Bundle( Bundle&& other ) noexcept
   : bundle_{ move( other.bundle_ ) }
{
}

auto nhill::text::Bundle::operator=( Bundle&& other) noexcept->Bundle &
{
   bundle_ = move( other.bundle_ );
   return *this;
}

nhill::text::Bundle::~Bundle() = default;

const std::string& nhill::text::Bundle::code() const
{
   if( contains( Text::code ) )
   {
      return bundle_.at( Text::code );
   }
   else
   {
      return empty_string_;
   }
}

void nhill::text::Bundle::code( std::string_view value )
{
   bundle_[Text::code] = value;
}

const std::string& nhill::text::Bundle::abbreviation() const
{
   if( contains( Text::abbreviation ) )
   {
      return bundle_.at( Text::abbreviation );
   }
   else
   {
      return empty_string_;
   }
}

void nhill::text::Bundle::abbreviation( std::string_view value )
{
   bundle_[Text::abbreviation] = value;
}

const std::string& nhill::text::Bundle::string() const
{
   return bundle_.at( Text::string );
}

void nhill::text::Bundle::string( std::string_view value )
{
   bundle_[Text::string] = value;
}

const std::string& nhill::text::Bundle::label() const
{
   if( contains( Text::label ) )
   {
      return bundle_.at( Text::label );
   }
   else
   {
      return empty_string_;
   }
}

void nhill::text::Bundle::label( std::string_view value )
{
   bundle_[Text::label] = value;
}

const std::string& nhill::text::Bundle::description() const
{
   if( contains( Text::description ) )
   {
      return bundle_.at( Text::description );
   }
   else
   {
      return empty_string_;
   }
}

void nhill::text::Bundle::description( std::string_view value )
{
   bundle_[Text::description] = value;
}

const std::string& nhill::text::Bundle::text( Text type ) const
{
   switch( type )
   {
   case Text::code: return code();
   case Text::abbreviation: return abbreviation();
   case Text::string: return string();
   case Text::label: return label();
   case Text::description: return description();
   default: return empty_string_;
   }
}

void nhill::text::Bundle::text( Text type, std::string_view text)
{
   switch( type )
   {
   case nhill::text::Text::code: code( text ); break;
   case nhill::text::Text::abbreviation: abbreviation( text ); break;
   case nhill::text::Text::string: string( text ); break;
   case nhill::text::Text::label: label( text ); break;
   case nhill::text::Text::description: description( text ); break;
   }
}

bool nhill::text::Bundle::contains( Text type ) const
{
   auto itr{ bundle_.find( type ) };
   return itr != bundle_.cend();
}
