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

