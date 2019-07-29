#pragma once

#include "methods.h"
#include <istream>

namespace nhill
{

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
std::istream& operator>>( std::istream& is, Enum& e )
{
    std::string s;
    is >> s;
    nhill::from_string<Enum>( e, s.c_str() );
    return is;
}

}