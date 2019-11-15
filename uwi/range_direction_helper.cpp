#include "range_direction_helper.h"

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
	case 'E': return Range_direction::E;
	case 'W': return Range_direction::W;
	default : return Range_direction::none;
	}
}

bool nhill::uwi::dls::is_valid_range_direction( char c )
{
	return c == 'E' || c == 'W';
}

