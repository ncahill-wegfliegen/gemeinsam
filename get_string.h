#pragma once

#include <string>
#include <string_view>
#include <type_traits>

namespace nhill
{

template<typename Item>
std::string get_string( size_t pos, const Item& item )
{
	static_assert(false && "This template must be specialized for each Item type.");
}

template<typename Item>
void set_string( size_t pos, Item& item, std::string_view str )
{
	static_assert(false && "This template must be specialized for each Item type.");
}

}
