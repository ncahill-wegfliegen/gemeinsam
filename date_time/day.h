#pragma once

#include "port.h"
#include "../utility/compare.h"
#include <cstdint>

namespace nhill { class Year; enum class Month : std::int8_t; }

namespace nhill
{

/// <summary>The day of the month.  Must be between 1 and 31, inclusive.</summary>
class NHILL_DATETIME_PORT_CLASS Day
{
public:
   using underlying_type = uint8_t;

   Day() noexcept;
   Day(int uday, Month mn, const Year& yr);

   explicit Day( int uday );
   Day& operator=(int uday);

   Day( const Day& other ) noexcept;
   Day& operator=(const Day& other) noexcept;

   Day( Day&& other ) noexcept;
   Day& operator=(Day&& other) noexcept;

   ~Day() noexcept;

   /// <summary>Cast the day object to an integer in the interval [1,28-31] depending on month an year.</summary>
   explicit operator int() const noexcept;

   int value() const;
   void value(int uday);
   void value(int uday, Month mn, const Year& yr);

	void clear();

private:
   underlying_type value_; // unit based value
};

}


namespace nhill
{

NHILL_DATETIME_PORT_FUNCTION int to_uday(const Day& dy);
NHILL_DATETIME_PORT_FUNCTION int to_zday(const Day& dy);

/// <summary>Get the current day of the month from the system time.</summary>
/// <exception cref="std::exception">Thrown if the call to get the system time returns an error.</exception>
NHILL_DATETIME_PORT_FUNCTION Day current_day();

NHILL_DATETIME_PORT_FUNCTION Day& pre_increment(Day& dy, Month mn, const Year& yr);
NHILL_DATETIME_PORT_FUNCTION Day& pre_decrement(Day& dy, Month mn, const Year& yr);
NHILL_DATETIME_PORT_FUNCTION Day post_increment(Day& dy, Month mn, const Year& yr);
NHILL_DATETIME_PORT_FUNCTION Day post_decrement(Day& dy, Month mn, const Year& yr);

template<> inline NHILL_DATETIME_PORT_FUNCTION
int compare(const Day& dy1, const Day& dy2) noexcept;

NHILL_DATETIME_PORT_FUNCTION bool operator==(const Day& dy1, const Day& dy2) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator!=(const Day& dy1, const Day& dy2) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator< (const Day& dy1, const Day& dy2) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator<=(const Day& dy1, const Day& dy2) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator> (const Day& dy1, const Day& dy2) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator>=(const Day& dy1, const Day& dy2) noexcept;

}