#pragma once

#include <cstdint>

namespace nhill
{

/// <summary>3D cartesian coordinates: (x, y, z).</summary>
enum class Coord_cart3 : std::int8_t
{
   x,
   y,
   z,
};

}

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "../port.h"
#include "../core/text/bundle_container.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_ENUM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::Coord_cart3>& nhill::text::bundle_container<nhill::Coord_cart3>();
#pragma endregion

#include "../core/text/methods.h"
#include "../core/text/stream_in.h"
#include "../core/text/stream_out.h"
#pragma endregion
