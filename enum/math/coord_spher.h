#pragma once

#include <cstdint>

namespace nhill
{

/// <summary>Spherical coordinates: (ρ, Ɵ, Φ).</summary>
enum class Coord_shper : std::int8_t
{
   r, // radial coordinate (rho)
   t, // azimuthal coordinate (theta)
   p, // polar coordinate (phi)
};

}

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "..\port.h"
#include "..\core\text\bundle_container.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_ENUM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::Coord_shper>& nhill::text::bundle_container<nhill::Coord_shper>();
#pragma endregion

#include "..\core\text\methods.h"
#include "..\core\text\stream_in.h"
#include "..\core\text\stream_out.h"
#pragma endregion
