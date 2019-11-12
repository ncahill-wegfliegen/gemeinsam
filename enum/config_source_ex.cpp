#include "config_source_ex.h"

template<>
const nhill::text::Bundle_container<nhill::config::Source>& nhill::text::bundle_container<nhill::config::Source>()
{
	using namespace nhill::config;

	static const Bundle_container<Source> bundles{
		{ Source::none,	{ "NONE", "NONE", "none", "None", "None"}},
		//
		{ Source::txt,   { {Text::string, "txt"	}, {Text::label, "Gov't Text File" } } },
		{ Source::mysql, { {Text::string, "mysql"	}, {Text::label, "MySql Database"  } } },
		{ Source::xml  , { {Text::string, "xml"	}, {Text::label, "XML Database"  } } },
	};

	return bundles;
}


