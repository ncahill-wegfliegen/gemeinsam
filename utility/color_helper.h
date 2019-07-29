#pragma once

#include "port.h"
#include "color.h"
#include <cstdint>
#include <string>
#include <string_view>

#pragma 
namespace nhill
{


NHILL_UTIL_PORT_FUNCTION void clear( Color& c );
NHILL_UTIL_PORT_FUNCTION std::string to_string( const Color& c );
NHILL_UTIL_PORT_FUNCTION bool parse( Color& c, std::string_view s );
NHILL_UTIL_PORT_FUNCTION uint32_t to_rgb( const Color& c );
NHILL_UTIL_PORT_FUNCTION bool from_rgb( Color& c, uint32_t );
NHILL_UTIL_PORT_FUNCTION bool is_valid_color_component( int x );
NHILL_UTIL_PORT_FUNCTION double distance( const Color& c1, const Color& c2 );

}

