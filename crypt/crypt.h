#pragma once

#include "port.h"
#include <string>
#include <string_view>

namespace nhill
{
namespace crypt
{

NHILL_CRYPT_PORT_FUNCTION std::string encrypt( std::string_view s );
NHILL_CRYPT_PORT_FUNCTION std::string decrypt( std::string_view s );

}
}
