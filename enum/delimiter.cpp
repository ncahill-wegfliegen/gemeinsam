#include "delimiter.h"

nhill::Delimiter::Delimiter() noexcept
   : enum_{ Delim::none }
   , other_char_{ chr::pipe<char>() }
{
}

nhill::Delimiter::Delimiter( Delim enum_, char other_char /*= chr::pipe<char>()*/ ) noexcept
   : enum_{ enum_ }
   , other_char_{ other_char }
{
}

nhill::Delimiter::~Delimiter()
{
}

nhill::Delim nhill::Delimiter::get_enum() const noexcept
{
   return enum_;
}

void nhill::Delimiter::set_enum( Delim value ) noexcept
{
   enum_ = value;
}

char nhill::Delimiter::get_char() const noexcept
{
   switch( enum_ )
   {
   case Delim::none:
   case Delim::tab:
   case Delim::comma:
   case Delim::space:
   case Delim::colon:
   case Delim::semicolon:
      return to_char<char>( enum_ );

   case Delim::other:
      return other_char_;

   default:
      return chr::null<char>();
   }
}

void nhill::Delimiter::set_char( char value ) noexcept
{
   using namespace nhill::chr;

   switch( value )
   {
   case null     <char>() : enum_ = Delim::none     ; break;
   case tab      <char>() : enum_ = Delim::tab      ; break;
   case comma    <char>() : enum_ = Delim::comma    ; break;
   case space    <char>() : enum_ = Delim::space    ; break;
   case colon    <char>() : enum_ = Delim::colon    ; break;
   case semicolon<char>() : enum_ = Delim::semicolon; break;
   default:
      enum_ = Delim::other;
      other_char_ = value;
      break;
   }
}
