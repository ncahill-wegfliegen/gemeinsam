#include "stringed.h"

using namespace std;

nhill::text::Stringed::Stringed()
{
}

nhill::text::Stringed::Stringed( const Stringed& other)
   : value_{ other.value_}
{
}

auto nhill::text::Stringed::operator=( const Stringed& other )->Stringed &
{
   value_ = other.value_;
   return *this;
}

nhill::text::Stringed::Stringed( Stringed&& other) noexcept
   : value_{move(other.value_)}
{
}

auto nhill::text::Stringed::operator=( Stringed&& other) noexcept ->Stringed & 
{
   value_ = move( other.value_ );
   return *this;
}

nhill::text::Stringed::~Stringed()
{
}

auto nhill::text::Stringed::value() const->string
{
   return value_;
}

auto nhill::text::Stringed::get_string() const->string
{
   return value();
}
