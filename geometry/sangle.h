#pragma once

#include "port.h"
#include <string_view>

namespace nhill
{

struct SAngle
{
   float degree;
   float arcminute;
   float arcsecond;
};

}

namespace nhill
{

NHILL_GMTRY_PORT_CLASS auto to_sangle( std::string_view str )->SAngle;

}

