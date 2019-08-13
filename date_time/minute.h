#pragma once

#include "port.h"
#include "../utility/compare.h"
#include <cstdint>

namespace nhill
{

class NHILL_DATETIME_PORT_CLASS Minute
{
public:
   using underlying_type = uint8_t;

   Minute() noexcept;

   explicit Minute(int min) noexcept;
   Minute& operator=(int min) noexcept;

   Minute(const Minute&) noexcept;
   Minute& operator=(const Minute&) noexcept;

   Minute(Minute&&) noexcept;
   Minute& operator=(Minute&&) noexcept;

   ~Minute() noexcept;

   explicit operator int() const noexcept;

   int value() const noexcept;
   void value(int min);

   static constexpr int first{ 0 };
   static constexpr int last{ 59 };

   void clear();
   static Minute current();

private:
   underlying_type min_{ first };
};

}

namespace nhill
{

NHILL_DATETIME_PORT_FUNCTION Minute& operator++(Minute&); // pre-increment: ++min
NHILL_DATETIME_PORT_FUNCTION Minute& operator--(Minute&); // pre-decrement: --min

NHILL_DATETIME_PORT_FUNCTION Minute operator++(Minute&, int); // post-increment: min++
NHILL_DATETIME_PORT_FUNCTION Minute operator--(Minute&, int); // post-decrement: min--

template<> NHILL_DATETIME_PORT_FUNCTION
int compare(const Minute&, const Minute&) noexcept;

NHILL_DATETIME_PORT_FUNCTION bool operator==(const Minute&, const Minute&) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator!=(const Minute&, const Minute&) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator< (const Minute&, const Minute&) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator<=(const Minute&, const Minute&) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator> (const Minute&, const Minute&) noexcept;
NHILL_DATETIME_PORT_FUNCTION bool operator>=(const Minute&, const Minute&) noexcept;

}
