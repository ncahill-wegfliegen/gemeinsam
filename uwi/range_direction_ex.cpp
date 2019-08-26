#include "range_direction_ex.h"

template<>
const nhill::text::Bundle_container<nhill::uwi::dls::Range_direction>& nhill::text::bundle_container<nhill::uwi::dls::Range_direction>()
{
	using namespace nhill::uwi::dls;

	static const Bundle_container<Range_direction> bundles{
		{ Range_direction::none, { {Text::string, "none"}, {Text::label, ""}, {Text::description, "None"} }},
		{ Range_direction::E	, { {Text::string, "E"}, {Text::label, "East"}, {Text::description, "East"} }},
		{ Range_direction::W , { {Text::string, "W"}, {Text::label, "West"}, {Text::description, "West"} }},
	};

	return bundles;
}

char nhill::uwi::dls::to_char( Range_direction rdg)
{
	switch( rdg )
	{
	case nhill::uwi::dls::Range_direction::E: return 'E';
	case nhill::uwi::dls::Range_direction::W: return 'W';
	default: return '\0';
	}
}

auto nhill::uwi::dls::to_range_direction( char c )->Range_direction
{
	switch( c )
	{
	case 'e':
	case 'E':
		return Range_direction::E;

	case 'w':
	case 'W':
		return Range_direction::W;

	default: return Range_direction::none;
	}
}

bool nhill::uwi::dls::is_valid_range_direction( char c )
{
	return c == 'E' || c == 'W';
}
