#pragma once

#include "port.h"
#include <string>
#include <functional>

namespace nhill
{
namespace text
{

/// <summary>The interface for any object that has a getable name.</summary>
class NHILL_TEXT_PORT_CLASS String_getable
{
public:
   virtual ~String_getable();
   virtual std::string get_string() const = 0;
};

NHILL_TEXT_PORT_FUNCTION int compare( const String_getable& left, const String_getable& right );

NHILL_TEXT_PORT_FUNCTION bool operator< ( const String_getable& left, const String_getable& right );
NHILL_TEXT_PORT_FUNCTION bool operator<=( const String_getable& left, const String_getable& right );
NHILL_TEXT_PORT_FUNCTION bool operator> ( const String_getable& left, const String_getable& right );
NHILL_TEXT_PORT_FUNCTION bool operator>=( const String_getable& left, const String_getable& right );

}
}

template<>
struct std::less<nhill::text::String_getable>
{
   bool operator()( const nhill::text::String_getable& left, const nhill::text::String_getable& right )
   {
      return nhill::text::compare( left, right ) < 0;
   }
};

template<>
struct std::less_equal<nhill::text::String_getable>
{
   bool operator()( const nhill::text::String_getable& left, const nhill::text::String_getable& right )
   {
      return nhill::text::compare( left, right ) <= 0;
   }
};

template<>
struct std::greater<nhill::text::String_getable>
{
   bool operator()( const nhill::text::String_getable& left, const nhill::text::String_getable& right )
   {
      return nhill::text::compare( left, right ) > 0;
   }
};

template<>
struct std::greater_equal<nhill::text::String_getable>
{
   bool operator()( const nhill::text::String_getable& left, const nhill::text::String_getable& right )
   {
      return nhill::text::compare( left, right ) >= 0;
   }
};
