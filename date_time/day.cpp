#include "day.h"
#include "month.h"
#include "year.h"
#include "core.h"
#include "../enum/core/values.h"
#include <ctime>
#include <stdexcept>
#include <sstream>

nhill::Day::Day() noexcept
   : value_{1U}
{
}

nhill::Day::Day(int uday, Month mn, const Year & yr)
{
   value(uday, mn, yr);
}

nhill::Day::Day( int uday )
   : Day{ uday, Month::jan, Year{2000} }
{
}

auto nhill::Day::operator=(int uday)->Day &
{
   value(uday, Month::jan, Year{ 2000 });
   return *this;
}

nhill::Day::Day(const Day & other) noexcept = default;
auto nhill::Day::operator=(const Day & other) noexcept->Day & = default;

nhill::Day::Day(Day && other) noexcept = default;
auto nhill::Day::operator=(Day && other) noexcept->Day & = default;

nhill::Day::~Day() = default;


nhill::Day::operator int() const noexcept
{
   return value();
}

int nhill::Day::value() const
{
   return value_;
}

void nhill::Day::value(int uday)
{
   value(uday, Month::jan, Year{ 2000 });
}

void nhill::Day::value(int uday, Month mn, const Year & yr)
{
   uday = restrict_uday(uday, to_umonth(mn), is_leap(yr));
   value_ = static_cast<underlying_type>(uday);
}

int nhill::to_uday(const Day & dy)
{
   return dy.value();
}

int nhill::to_zday(const Day & dy)
{
   return to_uday(dy) - 1;
}

auto nhill::current_day()->Day
{
   return Day{ current_uday() };
}


auto nhill::pre_increment(Day& dy, Month mn, const Year & yr)->Day &
{
   int uday{ increment_uday(to_uday(dy), to_umonth(mn), is_leap(yr)) };
   dy.value(uday, mn, yr);
   return dy;
}

auto nhill::pre_decrement(Day& dy, Month mn, const Year & yr)->Day &
{
   int uday{ decrement_uday(to_uday(dy), to_umonth(mn), is_leap(yr) ) };
   dy.value(uday, mn, yr);
   return dy;
}

auto nhill::post_increment(Day& dy, Month mn, const Year & yr)->Day
{
   Day tmp{ dy };
   pre_increment(dy, mn, yr);
   return tmp;
}

auto nhill::post_decrement(Day& dy, Month mn, const Year & yr)->Day
{
   Day tmp{ dy };
   pre_decrement(dy, mn, yr);
   return tmp;
}


template<> inline
int nhill::compare( const Day & dy1, const Day & dy2 ) noexcept
{
   return compare<int>( dy1.value(), dy2.value() );
}

bool nhill::operator==( const Day & dy1, const Day & dy2 ) noexcept
{
   return compare( dy1, dy2) == 0;
}

bool nhill::operator!=( const Day & dy1, const Day & dy2 ) noexcept
{
   return compare( dy1, dy2 ) != 0;
}

bool nhill::operator<( const Day & dy1, const Day & dy2 ) noexcept
{
   return compare( dy1, dy2 ) < 0;
}

bool nhill::operator<=( const Day & dy1, const Day & dy2 ) noexcept
{
   return compare( dy1, dy2 ) <= 0;
}

bool nhill::operator>( const Day & dy1, const Day & dy2 ) noexcept
{
   return compare( dy1, dy2 ) > 0;
}

bool nhill::operator>=( const Day & dy1, const Day & dy2 ) noexcept
{
   return compare( dy1, dy2 ) >= 0;
}
