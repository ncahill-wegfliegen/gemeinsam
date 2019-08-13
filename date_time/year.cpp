#include "year.h"
#include "core.h"
#include <ctime>
#include <exception>
#include <memory>
#include <limits>
#include <sstream>

using namespace std;

nhill::Year::Year() noexcept
   : value_{default_value}
{
}

nhill::Year::Year( int year )
{
   value(year);
}

auto nhill::Year::operator=(int year)->Year &
{
   value_ = static_cast<underlying_type>(year);
   return *this;
}

nhill::Year::Year(const Year &) noexcept = default;
auto nhill::Year::operator=(const Year &) noexcept->Year & = default;

nhill::Year::Year(Year &&) noexcept = default;
auto nhill::Year::operator=(Year &&) noexcept->Year & = default;

nhill::Year::~Year() noexcept = default;

nhill::Year::operator int() const noexcept
{
   return static_cast<int>(value_);
}

int nhill::Year::value() const noexcept
{
   return value_;
}

void nhill::Year::value(int year)
{
   if (year < numeric_limits<underlying_type>::min() || numeric_limits<underlying_type>::max() < year)
   {
      ostringstream msg;
      msg << "Invalid year=" << year << ".  Must be in the range [" << numeric_limits<underlying_type>::min() << ", " << numeric_limits<underlying_type>::max() << "].";
      throw invalid_argument(msg.str());
   }
   
   value_ = year;
}

void nhill::Year::clear()
{
	value_ = default_value;
}

auto nhill::current_year()->Year
{
   return Year{ current_iyear() };
}

bool nhill::is_leap(const Year & year) noexcept
{
   return is_leap_year( year.value() );
}

auto nhill::operator++(Year& year)->Year &
{
   year.value(year.value() + 1);
   return year;
}

auto nhill::operator--(Year& year)->Year &
{
   year.value(year.value() - 1);
   return year;
}

auto nhill::operator++(Year& year, int)->Year
{
   Year tmp{ year };
   ++year;
   return tmp;
}

auto nhill::operator--(Year& year, int)->Year
{
   Year tmp{ year };
   --year;
   return tmp;
}

template<> inline
int nhill::compare( const Year& yr1, const Year& yr2 ) noexcept
{
   return compare<int>( static_cast<int>(yr1), static_cast<int>(yr2) );
}

bool nhill::operator==( const Year & yr1, const Year & yr2 ) noexcept
{
   return compare(yr1, yr2) == 0;
}

bool nhill::operator!=( const Year & yr1, const Year & yr2 ) noexcept
{
   return compare( yr1, yr2 ) != 0;
}

bool nhill::operator<( const Year & yr1, const Year & yr2 ) noexcept
{
   return compare( yr1, yr2 ) < 0;
}

bool nhill::operator<=( const Year & yr1, const Year & yr2 ) noexcept
{
   return compare( yr1, yr2 ) <= 0;
}

bool nhill::operator>( const Year & yr1, const Year & yr2 ) noexcept
{
   return compare( yr1, yr2 ) > 0;
}

bool nhill::operator>=( const Year & yr1, const Year & yr2 ) noexcept
{
   return compare( yr1, yr2 ) >= 0;
}


