#pragma once

#include "methods.h"
#include <ostream>

namespace nhill
{

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
std::ostream& operator<<( std::ostream& os, Enum e )
{
    return os << nhill::to_string<Enum>( e );
}

}