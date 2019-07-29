#pragma once

#include "bundle_container.h"
#include <string>

namespace nhill
{

/// <summary>The code associated with the enumeration item. May return an empty string, but never returns null.</summary>
template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
const std::string& to_code( Enum e )
{
    return nhill::text::bundle_container<Enum>().code( e );
}

/// <summary>The abbreviation associated with the enumeration item. May return an empty string, but never returns null.</summary>
template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
const std::string & to_abbreviation( Enum e )
{
    return nhill::text::bundle_container<Enum>().abbreviation( e );
}

/// <summary>The string associated with the enumeration item. May return an empty string, but never returns null.<para>The string must be identical to the enumeration item.</para></summary>
template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
const std::string & to_string( Enum e )
{
    return nhill::text::bundle_container<Enum>().string( e );
}

/// <summary>The label associated with the enumeration item. May return an empty string, but never returns null.</summary>
template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
const std::string & to_label( Enum e )
{
    return nhill::text::bundle_container<Enum>().label( e );
}

/// <summary>The description associated with the enumeration item. May return an empty string, but never returns null.</summary>
template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
const std::string & to_description( Enum e )
{
    return nhill::text::bundle_container<Enum>().description( e );
}

/// <summary>The text associated with the enumeration item. May return an empty string, but never returns null.</summary>
template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
const std::string & to_text( Enum e, nhill::text::Text type )
{
    return nhill::text::bundle_container<Enum>()( e, type );
}


template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
bool from_code( Enum & e, std::string_view value )
{
   const nhill::text::Bundle_container<Enum>& bundles = nhill::text::bundle_container<Enum>();

   auto item = std::find_if(
      bundles.cbegin(),
      bundles.cend(),
      [&value]( const auto& p ) { return nhill::str::compare_truncated( p->second.code(), value ) == 0; }
   );

   if( item == bundles.cend() )
   {
      return false;
   }

   e = item->first;
   return true;
}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
bool from_string( Enum& e, std::string_view value )
{
    const nhill::text::Bundle_container<Enum>& bundles = nhill::text::bundle_container<Enum>();

    auto item = std::find_if(
       bundles.begin(),
       bundles.end(),
       [&value]( const auto& p ) { return nhill::str::compare_truncated( p.second.string(), value ) == 0; }
    );

    if( item == bundles.end() )
    {
        return false;
    }

    e = item->first;
    return true;
}


template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
bool from_description( Enum& e, std::string_view value )
{
    const nhill::text::Bundle_container<Enum>& bundles = nhill::text::bundle_container<Enum>();

    auto item = std::find_if(
       bundles.begin(),
       bundles.end(),
       [&value]( const auto& p ) { return nhill::str::compare_truncated( p->second.description(), value ) == 0; }
    );

    if( item == bundles.end() )
    {
        return false;
    }

    e = item->first;
    return true;
}

}


