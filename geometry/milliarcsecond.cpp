#include "milliarcsecond.h"

nhill::Milliarcsecond::Milliarcsecond( unsigned int value /*= 0*/)
   : value_{static_cast<value_type>(value)}
{
}

auto nhill::Milliarcsecond::operator=( unsigned int value )->Milliarcsecond &
{
   value_ = static_cast<value_type>(value);
   return *this;
}

nhill::Milliarcsecond::Milliarcsecond( const Milliarcsecond & ) = default;
auto nhill::Milliarcsecond::operator=( const Milliarcsecond & )->Milliarcsecond & = default;

nhill::Milliarcsecond::Milliarcsecond( Milliarcsecond && ) noexcept = default;
auto nhill::Milliarcsecond::operator=( Milliarcsecond && ) noexcept->Milliarcsecond & = default;

nhill::Milliarcsecond::~Milliarcsecond() = default;

nhill::Milliarcsecond::operator unsigned int() const
{
   return value();
}

unsigned int nhill::Milliarcsecond::value() const
{
   return value_;
}

void nhill::Milliarcsecond::clear()
{
   value_ = 0;
}
