#pragma once

#include "port.h"
#include "../math/sign.h"
#include <string_view>

namespace nhill
{
namespace geometry
{

class UAngle
{
public:
   nhill::math::Sign sign;
   unsigned int      arcdegree;
   unsigned int      arcminute;
   unsigned int      arcsecond;
   unsigned int      milliarcsecond;
};

}
}

namespace nhill
{
namespace geometry
{

NHILL_GMTRY_PORT_FUNCTION UAngle to_uangle( std::string_view str, char* sign_sym = nullptr );

}
}