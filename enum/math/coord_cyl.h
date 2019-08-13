#pragma once

#include <cstdint>

namespace nhill
{

/// <summary>Spherical coordinates: (ρ, Ɵ, z).</summary>
enum class Coord_cyl : std::int8_t
{
   r, // radial coordinate
   t, // azimuthal coordinate (theta)
   z, // height
};

}

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "../port.h"
#include "../core/text/bundle_container.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_ENUM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::Coord_cyl>& nhill::text::bundle_container<nhill::Coord_cyl>();
#pragma endregion

#include "../core/text/methods.h"
#include "../core/text/stream_in.h"
#include "../core/text/stream_out.h"
#pragma endregion
