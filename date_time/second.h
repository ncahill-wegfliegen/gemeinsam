#pragma once

#include "port.h"
#include "../utility/compare.h"
#include <cstdint>

namespace nhill
{

class NHILL_DATETIME_PORT_CLASS Second
{
public:
   using underlying_type = uint8_t;

   Second() noexcept;

   Second(int sec) noexcept;
   Second& operator=(int sec) noexcept;

   Second(const Second&) noexcept;
   Second& operator=(const Second&) noexcept;

   Second(Second&&) noexcept;
   Second& operator=(Second&&) noexcept;

   ~Second() noexcept;

   operator int() const noexcept;

   int value() const noexcept;
   void value(int sec) noexcept;

   static constexpr int first{ 0 };
   static constexpr int last{ 59 };

   void clear();
   static Second current();

private:
   underlying_type sec_{ first };
};

}

namespace nhill
{

NHILL_DATETIME_PORT_FUNCTION Second& operator++(Second&); // pre-increment: ++min
NHILL_DATETIME_PORT_FUNCTION Second& operator--(Second&); // pre-decrement: --min

NHILL_DATETIME_PORT_FUNCTION Second operator++(Second&, int); // post-increment: min++
NHILL_DATETIME_PORT_FUNCTION Second operator--(Second&, int); // post-decrement: min--

template<> NHILL_DATETIME_PORT_FUNCTION
int compare(const Second&, const Second&) noexcept;

NHILL_DATETIME_PORT_FUNCTION bool operator==(const Second&, const Second&) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator!=(const Second&, const Second&) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator< (const Second&, const Second&) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator<=(const Second&, const Second&) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator> (const Second&, const Second&) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator>=(const Second&, const Second&) noexcept;

}
