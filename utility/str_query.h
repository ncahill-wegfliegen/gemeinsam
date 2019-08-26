#pragma once

#include "port.h"
#include <string_view>

namespace nhill
{
namespace str
{

NHILL_UTIL_PORT_FUNCTION bool is_integer( std::string_view s );
NHILL_UTIL_PORT_FUNCTION bool is_integer( std::string_view s, size_t len_must_be );
NHILL_UTIL_PORT_FUNCTION bool is_integer( std::string_view s, size_t len_min, size_t len_max );

}
}
