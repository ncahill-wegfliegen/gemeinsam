#pragma once

#include <cstdint>

namespace nhill
{
enum class Delim : std::int8_t
{
   none = 0,
   tab,
   comma,
   space,
   colon,
   semicolon,
   other,

   // used for iteration
   end,
   begin = none,
};
}


#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "core/text/bundle_container.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_ENUM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::Delim>& nhill::text::bundle_container<nhill::Delim>();
#pragma endregion

#include "core/text/methods.h"
#include "core/text/stream_in.h"
#include "core/text/stream_out.h"
#pragma endregion


#pragma region Additional Extensions
#include "../utility/chr.h"
namespace nhill
{

template<typename Char = char>
Char to_char( Delim e )
{
   using namespace nhill::chr;
   switch( e )
   {
   case Delim::none:        return null     <Char>();
   case Delim::tab:         return tab      <Char>();
   case Delim::comma:       return comma    <Char>();
   case Delim::space:       return space    <Char>();
   case Delim::colon:       return colon    <Char>();
   case Delim::semicolon:   return semicolon<Char>();
   case Delim::other:       return pipe     <Char>();
   default:                 return null     <Char>();
   }
}

template<typename Char = char>
Delim from_char( Char c )
{
   using namespace nhill::chr;
   switch( c )
   {
   case null     <Char>() : return Delim::none;
   case tab      <Char>() : return Delim::tab;
   case comma    <Char>() : return Delim::comma;
   case space    <Char>() : return Delim::space;
   case colon    <Char>() : return Delim::colon;
   case semicolon<Char>() : return Delim::semicolon;
   default: return Delim::other;
   }

   //using namespace nhill::chr;
   //if( c == tab<Char>() )
   //{
   //   return Delim::tab;
   //}
   //else if( c == comma<Char>() )
   //{
   //   return Delim::comma;
   //}
   //else if( c == space<Char>() )
   //{
   //   return Delim::space;
   //}
   //else if( c == colon<Char>() )
   //{
   //   return Delim::colon;
   //}
   //else if( c == semicolon<Char>() )
   //{
   //   return Delim::semicolon;
   //}
   //else if( c == pipe<Char>() )
   //{
   //   return Delim::pipe;
   //}
   //else
   //{
   //   return Delim::none;
   //}
}

}
#pragma endregion
