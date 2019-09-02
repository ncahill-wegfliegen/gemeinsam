#pragma once

#include "info_item.h"
#include "../enum/core/values.h"
#include "../enum/core/int.h"

namespace nhill
{

template<> inline
nhill::version::Info_item begin()
{
	return nhill::version::Info_item::none;
}

template<> inline
nhill::version::Info_item end()
{
	int i{ to_int( nhill::version::Info_item::special_build ) };
	++i;
	return to_enum<nhill::version::Info_item>(i);
}

}


