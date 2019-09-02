#pragma once

#include <cstdint>

namespace nhill
{

enum class Product : std::int8_t
{
    none = -1,
    gas = 0,
    oil,
    water,
    condensate,
};

}

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "core/text/bundle_container.h"
#include "core/values.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_ENUM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::Product>& nhill::text::bundle_container<nhill::Product>();
#pragma endregion

#pragma region Values
template<> inline nhill::Product nhill::begin() { return Product::none; }
template<> inline nhill::Product nhill::end() { return to_enum<nhill::Product>( to_int( Product::condensate ) + 1 ); }
#pragma endregion


#include "core/text/methods.h"
#include "core/text/stream_in.h"
#include "core/text/stream_out.h"
#pragma endregion


#pragma region Additional Extensions
namespace nhill
{
NHILL_ENUM_PORT_FUNCTION void to_color( nhill::Product product, int& r, int& g, int& b );
}
#pragma endregion
