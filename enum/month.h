#pragma once

#include <cstdint>

namespace nhill
{

enum class Month : std::int8_t
{
   jan = 1,
   feb,
   mar,
   apr,
   may,
   jun,
   jul,
   aug,
   sep,
   oct,
   nov,
   dec,

   end,
   begin = jan,
};

}

#pragma region Extensions: to_code, to_abbreviation, etc.; stream operators << and >>.
#include "port.h"
#include "core/text/bundle_container.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_ENUM_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::Month>& nhill::text::bundle_container<nhill::Month>();
#pragma endregion

#include "core/text/methods.h"
#include "core/text/stream_in.h"
#include "core/text/stream_out.h"
#pragma endregion


#pragma region Additional Extensions
#include "../utility/compare.h"
namespace nhill
{
// Move all of these methods to the enumeration extentsions
NHILL_ENUM_PORT_FUNCTION int to_zmonth( Month em );
NHILL_ENUM_PORT_FUNCTION int to_umonth( Month em );

NHILL_ENUM_PORT_FUNCTION Month from_zmonth( int zmonth );
NHILL_ENUM_PORT_FUNCTION Month from_umonth( int umonth );

NHILL_ENUM_PORT_FUNCTION Month current_month();

template<> NHILL_ENUM_PORT_FUNCTION
Compare compare<Month>( Month mn1, Month mn2 ) noexcept;

NHILL_ENUM_PORT_FUNCTION bool operator==( Month mn1, Month mn2 );
NHILL_ENUM_PORT_FUNCTION bool operator!=( Month mn1, Month mn2 );
NHILL_ENUM_PORT_FUNCTION bool operator< ( Month mn1, Month mn2 );
NHILL_ENUM_PORT_FUNCTION bool operator<=( Month mn1, Month mn2 );
NHILL_ENUM_PORT_FUNCTION bool operator> ( Month mn1, Month mn2 );
NHILL_ENUM_PORT_FUNCTION bool operator>=( Month mn1, Month mn2 );
}
#pragma endregion
