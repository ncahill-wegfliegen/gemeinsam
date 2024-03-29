#include "minute.h"
#include "core.h"
#include "../math/compare.h"
#include "../enum/core/int.h"

using namespace std;

nhill::Minute::Minute() noexcept = default;

nhill::Minute::Minute(int min) noexcept
{
   this->value(min);
}
auto nhill::Minute::operator=(int min) noexcept->Minute &
{
   this->value(min);
   return *this;
}

nhill::Minute::Minute(const Minute &)  noexcept = default;
auto nhill::Minute::operator=(const Minute &) noexcept->Minute & = default;

nhill::Minute::Minute(Minute &&) noexcept = default;
auto nhill::Minute::operator=(Minute &&) noexcept->Minute & = default;

nhill::Minute::~Minute() noexcept = default;

nhill::Minute::operator int() const  noexcept
{
   return value();
}

int nhill::Minute::value() const noexcept
{
   return static_cast<int>(min_);
}

void nhill::Minute::value(int min)
{
   validate_minute(min);
   min_ = static_cast<underlying_type>(min);
}

void nhill::Minute::clear()
{
   value(first);
}

auto nhill::Minute::current()->Minute
{
   return Minute{ current_minute() };
}

auto nhill::operator++(Minute & min)->Minute &
{
   min.value(min.value() + 1);
   return min;
}

auto nhill::operator--(Minute & min)->Minute &
{
   min.value(min.value() - 1);
   return min;
}

auto nhill::operator++(Minute & min, int)->Minute
{
   Minute tmp{ min };
   ++min;
   return tmp;
}

auto nhill::operator--(Minute & min, int)->Minute
{
   Minute tmp{ min };
   --min;
   return tmp;
}

template<>
auto nhill::compare(const Minute& a, const Minute& b) noexcept->Compare
{
   return to_enum<Compare>( math::compare<int,int>(a.value(), b.value()) );
}

bool nhill::operator==(const Minute & a, const Minute & b) noexcept
{
   return compare<const Minute&>(a, b) == Compare::equal;
}

bool nhill::operator!=(const Minute &a, const Minute & b) noexcept
{
   return !(a == b);
}

bool nhill::operator<(const Minute &a, const Minute & b) noexcept
{
   return compare<const Minute&>(a, b) == Compare::less;
}

bool nhill::operator<=(const Minute &a, const Minute & b) noexcept
{
   return (a < b) || (a == b);
}

bool nhill::operator>(const Minute &a, const Minute & b) noexcept
{
   return compare<const Minute&>(a, b) == Compare::greater;
}

bool nhill::operator>=(const Minute &a, const Minute & b) noexcept
{
   return (a > b) || (a == b);
}
