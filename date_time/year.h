#pragma once

#include "port.h"
#include "../utility/compare.h"
#include <cstdint>

namespace nhill
{

class NHILL_DATETIME_PORT_CLASS Year
{
public:
   using underlying_type = int16_t;

   Year() noexcept;

   explicit Year(int year);
   Year& operator=(int year);

   Year(const Year&) noexcept;
   Year& operator=(const Year&) noexcept;

   Year(Year&&) noexcept;
   Year& operator=(Year&&) noexcept;

   ~Year() noexcept;

   explicit operator int() const noexcept;

   int value() const noexcept;
   void value(int year);

   static const int default_value{ 1 };

   void clear();

private:
   underlying_type value_;
};

}


namespace nhill
{

NHILL_DATETIME_PORT_FUNCTION Year current_year();
NHILL_DATETIME_PORT_FUNCTION bool is_leap(const Year&) noexcept;

NHILL_DATETIME_PORT_FUNCTION Year& operator++( Year& ); //  pre-increment ++yr
NHILL_DATETIME_PORT_FUNCTION Year& operator--( Year& ); //  pre-decrement --yr

NHILL_DATETIME_PORT_FUNCTION Year operator++(Year&, int); // post-increment yr++
NHILL_DATETIME_PORT_FUNCTION Year operator--(Year&, int); // post-decrement yr--

template<> inline NHILL_DATETIME_PORT_FUNCTION
Compare compare( const Year& yr1, const Year& yr2 ) noexcept;

NHILL_DATETIME_PORT_FUNCTION bool operator==(const Year& yr1, const Year& yr2) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator!=(const Year& yr1, const Year& yr2) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator< (const Year& yr1, const Year& yr2) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator<=(const Year& yr1, const Year& yr2) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator> (const Year& yr1, const Year& yr2) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator>=(const Year& yr1, const Year& yr2) noexcept;

}