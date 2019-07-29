#include "arcminute.h"


nhill::Arcminute::Arcminute()
   : value_{0}
{
}

nhill::Arcminute::Arcminute( unsigned int value )
   : value_{0}
{
   this->value( value );
}

auto nhill::Arcminute::operator=( unsigned int value )->Arcminute &
{
   this->value( value );
   return *this;
}

nhill::Arcminute::Arcminute( const Arcminute & ) = default;
auto nhill::Arcminute::operator=( const Arcminute & )->Arcminute & = default;

nhill::Arcminute::Arcminute( Arcminute && ) noexcept = default;
auto nhill::Arcminute::operator=( Arcminute && ) noexcept->Arcminute & = default;

nhill::Arcminute::~Arcminute() = default;

nhill::Arcminute::operator unsigned int() const
{
   return value();
}

auto nhill::Arcminute::value() const->unsigned int
{
   return value_;
}

void nhill::Arcminute::value( unsigned value, unsigned* arcdeg /*= nullptr*/ )
{
   value_ = adjust_arcminute<unsigned>( value, arcdeg );
}

void nhill::Arcminute::clear()
{
   value_ = 0;
}

auto nhill::operator+( const Arcminute& a, const Arcminute& b ) noexcept->Arcminute
{
   return {a.value() + b.value()};
}

auto nhill::operator-( const Arcminute& a, const Arcminute& b ) noexcept->Arcminute
{
   return {a.value() - b.value()};
}

auto nhill::add( const Arcminute& a, const Arcminute& b, unsigned* arcdeg /*= nullptr*/ ) noexcept->Arcminute
{
   return {adjust_arcminute<unsigned>( a.value() + b.value(), arcdeg )};
}

auto nhill::substract( const Arcminute& a, const Arcminute& b, unsigned* arcdeg /*= nullptr*/ ) noexcept->Arcminute
{
   return {adjust_arcminute<unsigned>( a.value() - b.value(), arcdeg )};
}

bool nhill::operator==( const Arcminute & a, const Arcminute & b ) noexcept
{
   return a.value() == b.value();
}

bool nhill::operator!=( const Arcminute & a, const Arcminute & b ) noexcept
{
   return !(a == b);
}

bool nhill::operator>( const Arcminute & a, const Arcminute & b ) noexcept
{
   return a.value() > b.value();
}

bool nhill::operator<( const Arcminute & a, const Arcminute & b ) noexcept
{
   return a.value() < b.value();
}

bool nhill::operator>=( const Arcminute & a, const Arcminute & b ) noexcept
{
   return (a > b) || (a == b);
}

bool nhill::operator<=( const Arcminute & a, const Arcminute & b ) noexcept
{
   return (a < b) || (a == b);
}
