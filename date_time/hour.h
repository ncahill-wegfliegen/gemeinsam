#pragma once

#include "port.h"
#include "../utility/compare.h"
#include <cstdint>

namespace nhill
{

class NHILL_DATETIME_PORT_CLASS Hour
{
public:
   using underlying_type = uint8_t;

   Hour() noexcept;

   explicit Hour(int hr) noexcept;
   Hour& operator=(int hr) noexcept;

   Hour(const Hour&) noexcept;
   Hour& operator=(const Hour&) noexcept;

   Hour(Hour&&) noexcept;
   Hour& operator=(Hour&&) noexcept;

   ~Hour() noexcept;

   explicit operator int() const noexcept;

   int value() const noexcept;
   void value(int);

   static constexpr int first{  0 };
   static constexpr int last { 23 };

   void clear();
   static Hour current();

private:
   underlying_type hr_{first};
};

}

namespace nhill
{

NHILL_DATETIME_PORT_FUNCTION Hour& operator++(Hour&); // pre-increment: ++hr
NHILL_DATETIME_PORT_FUNCTION Hour& operator--(Hour&); // pre-decrement: --hr

NHILL_DATETIME_PORT_FUNCTION Hour operator++(Hour&, int); // post-increment: hr++
NHILL_DATETIME_PORT_FUNCTION Hour operator--(Hour&, int); // post-decrement: hr--

template<> NHILL_DATETIME_PORT_FUNCTION
int compare(const Hour&, const Hour&) noexcept;

NHILL_DATETIME_PORT_FUNCTION bool operator==(const Hour&, const Hour&) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator!=(const Hour&, const Hour&) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator< (const Hour&, const Hour&) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator<=(const Hour&, const Hour&) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator> (const Hour&, const Hour&) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator>=(const Hour&, const Hour&) noexcept;

}
