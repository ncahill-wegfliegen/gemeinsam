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
#include "../enum/core/text/bundle_container.h"

#pragma region Specialize bundle_container: do not use directly; use text methods to_code, to_abbreviation, etc. instead.
template<> NHILL_DATETIME_PORT_FUNCTION
const nhill::text::Bundle_container<nhill::Month>& nhill::text::bundle_container<nhill::Month>();
#pragma endregion

#include "../enum/core/text/methods.h"
#include "../enum/core/text/stream_in.h"
#include "../enum/core/text/stream_out.h"
#pragma endregion


#pragma region Additional Extensions
#include "../utility/compare.h"
namespace nhill
{

NHILL_DATETIME_PORT_FUNCTION int to_zmonth( Month em );
NHILL_DATETIME_PORT_FUNCTION int to_umonth( Month em );

NHILL_DATETIME_PORT_FUNCTION Month zmonth_to_month( int zmonth );
NHILL_DATETIME_PORT_FUNCTION Month umonth_to_month( int umonth );

NHILL_DATETIME_PORT_FUNCTION Month current_month();

template<> inline NHILL_DATETIME_PORT_FUNCTION
int compare( const Month& mn1, const Month& mn2 ) noexcept;

NHILL_DATETIME_PORT_FUNCTION bool operator==( Month mn1, Month mn2 );
NHILL_DATETIME_PORT_FUNCTION bool operator!=( Month mn1, Month mn2 );
NHILL_DATETIME_PORT_FUNCTION bool operator< ( Month mn1, Month mn2 );
NHILL_DATETIME_PORT_FUNCTION bool operator<=( Month mn1, Month mn2 );
NHILL_DATETIME_PORT_FUNCTION bool operator> ( Month mn1, Month mn2 );
NHILL_DATETIME_PORT_FUNCTION bool operator>=( Month mn1, Month mn2 );
}
#pragma endregion
