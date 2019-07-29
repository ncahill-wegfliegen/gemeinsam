#include "abbreviated.h"

using namespace std;

nhill::text::Abbreviated::Abbreviated()
{
}

nhill::text::Abbreviated::Abbreviated( const Abbreviated& other)
   : value_{ other.value_}
{
}

auto nhill::text::Abbreviated::operator=( const Abbreviated& other )->Abbreviated &
{
   value_ = other.value_;
   return *this;
}

nhill::text::Abbreviated::Abbreviated( Abbreviated&& other) noexcept
   : value_{move(other.value_)}
{
}

auto nhill::text::Abbreviated::operator=( Abbreviated&& other) noexcept ->Abbreviated & 
{
   value_ = move( other.value_ );
   return *this;
}

nhill::text::Abbreviated::~Abbreviated()
{
}

auto nhill::text::Abbreviated::value() const->string
{
   return value_;
}

auto nhill::text::Abbreviated::get_string() const->string
{
   return value();
}
