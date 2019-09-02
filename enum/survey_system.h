#pragma once

// Define the collection of strings for an enumeration that is NOT continuous.
// The enumeration class MUST define the 'count' field.
// http://www.jakeshirley.com/c-macro-defined-enums/

#include <cstdint>

namespace nhill
{

enum class Survey_system : std::uint8_t
{
   none,
   dls, // Dominion Land Survey: AB, SK, MB & Peace River block of BC
   nts, // National Topographic Series: BC excluding Peace River block
   fps, // Federal Permit System: Northwest Territory, Yukon Territory, Arctic Offshore, East and West Coast Offshore areas and Hudson Bay and Hudson Straight
   geo, // Geodetic Coordinates or Latitude and Longitude: ON, QB, and Maratimes
	api, // American Petroleum Institute: US
	other,
};

}

