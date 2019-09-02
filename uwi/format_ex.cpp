#include "format_ex.h"

template<> inline
const nhill::text::Bundle_container<nhill::uwi::Format>& nhill::text::bundle_container<nhill::uwi::Format>()
{
	using namespace nhill::uwi;
	static const Bundle_container<Format> bundles{
		{ Format::none,{ "NA", "N/A", "none", "", "None" } },
		//
		{ Format::sort         ,{ { Text::string, "sort"			 }, { Text::label, "Sort"				} } },
		{ Format::plain        ,{ { Text::string, "plain"			 }, { Text::label, "Plain"				} } },
		{ Format::plain_dressed,{ { Text::string, "plain_dressed"}, { Text::label, "Plain Dressed"  } } },
		{ Format::full         ,{ { Text::string, "full"			 }, { Text::label, "Full"				} } },
		{ Format::full_dressed ,{ { Text::string, "full_dressed" }, { Text::label, "Full Dressed"   } } },
	};

	return bundles;
}
