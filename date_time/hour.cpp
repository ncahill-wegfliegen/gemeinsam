#include "hour.h"
#include "core.h"

using namespace std;

nhill::Hour::Hour() noexcept = default;

nhill::Hour::Hour(int hr) noexcept
{
   this->value(hr);
}
auto nhill::Hour::operator=(int hr) noexcept->Hour &
{
   this->value(hr);
   return *this;
}

nhill::Hour::Hour(const Hour &)  noexcept = default;
auto nhill::Hour::operator=(const Hour &) noexcept->Hour & = default;

nhill::Hour::Hour(Hour &&) noexcept = default;
auto nhill::Hour::operator=(Hour &&) noexcept->Hour & = default;

nhill::Hour::~Hour() noexcept = default;

nhill::Hour::operator int() const  noexcept
{
   return value();
}

int nhill::Hour::value() const noexcept
{
   return static_cast<int>(hr_);
}

void nhill::Hour::value(int hr)
{
   validate_hour(hr);
   hr_ = static_cast<underlying_type>( hr );
}

void nhill::Hour::clear()
{
   value(first);
}

auto nhill::Hour::current()->Hour
{
   return Hour{ current_hour() };
}

auto nhill::operator++(Hour & hr)->Hour &
{
   hr.value(hr.value() + 1);
   return hr;
}

auto nhill::operator--(Hour & hr)->Hour &
{
   hr.value(hr.value() - 1);
   return hr;
}

auto nhill::operator++(Hour & hr, int)->Hour
{
   Hour tmp{ hr };
   ++hr;
   return tmp;
}

auto nhill::operator--(Hour & hr, int)->Hour
{
   Hour tmp{ hr };
   --hr;
   return tmp;
}

template<>
int nhill::compare(const Hour& a, const Hour& b) noexcept
{
   return compare<int>(a.value(), b.value());
}

bool nhill::operator==(const Hour & a , const Hour & b) noexcept
{
   return compare<const Hour&>(a,b) == 0;
}

bool nhill::operator!=(const Hour &a, const Hour & b) noexcept
{
   return compare<const Hour&>(a, b) != 0;
}

bool nhill::operator<(const Hour &a, const Hour & b) noexcept
{
   return compare<const Hour&>(a, b) < 0;
}

bool nhill::operator<=(const Hour &a, const Hour & b) noexcept
{
   return compare<const Hour&>(a, b) <= 0;
}

bool nhill::operator>(const Hour &a, const Hour & b) noexcept
{
   return compare<const Hour&>(a, b) > 0;
}

bool nhill::operator>=(const Hour &a, const Hour & b) noexcept
{
   return compare<const Hour&>(a, b) >= 0;
}
