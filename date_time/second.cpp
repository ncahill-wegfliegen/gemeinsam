#include "second.h"
#include "core.h"
#include "../math/compare.h"
#include "../enum/core/int.h"

using namespace std;

nhill::Second::Second() noexcept = default;

nhill::Second::Second(int sec) noexcept
{
   this->value(sec);
}
auto nhill::Second::operator=(int sec) noexcept->Second &
{
   this->value(sec);
   return *this;
}

nhill::Second::Second(const Second &)  noexcept = default;
auto nhill::Second::operator=(const Second &) noexcept->Second & = default;

nhill::Second::Second(Second &&) noexcept = default;
auto nhill::Second::operator=(Second &&) noexcept->Second & = default;

nhill::Second::~Second() noexcept = default;

nhill::Second::operator int() const  noexcept
{
   return value();
}

int nhill::Second::value() const noexcept
{
   return static_cast<int>(sec_);
}

void nhill::Second::value(int sec) noexcept
{
   validate_second(sec);
   sec_ = static_cast<underlying_type>(sec);
}

void nhill::Second::clear()
{
   value(first);
}

auto nhill::Second::current()->Second
{
   return Second{ current_second() };
}

auto nhill::operator++(Second & sec)->Second &
{
   sec.value(sec.value() + 1);
   return sec;
}

auto nhill::operator--(Second & sec)->Second &
{
   sec.value(sec.value() - 1);
   return sec;
}

auto nhill::operator++(Second & sec, int)->Second
{
   Second tmp{ sec };
   ++sec;
   return tmp;
}

auto nhill::operator--(Second & sec, int)->Second
{
   Second tmp{ sec };
   --sec;
   return tmp;
}

template<>
auto nhill::compare(const Second& a, const Second& b) noexcept->Compare
{
   return to_enum<Compare>( math::compare<int,int>(a.value(), b.value()) );
}

bool nhill::operator==(const Second & a, const Second & b) noexcept
{
   return compare<const Second&>(a, b) == Compare::equal;
}

bool nhill::operator!=(const Second &a, const Second & b) noexcept
{
   return !(a == b);
}

bool nhill::operator<(const Second &a, const Second & b) noexcept
{
   return compare<const Second&>(a, b) == Compare::less;
}

bool nhill::operator<=(const Second &a, const Second & b) noexcept
{
   return (a < b) || (a == b);
}

bool nhill::operator>(const Second &a, const Second & b) noexcept
{
   return compare<const Second&>(a, b) == Compare::greater;
}

bool nhill::operator>=(const Second &a, const Second & b) noexcept
{
   return (a > b ) || (a == b);
}

