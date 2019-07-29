#include "named.h"

using namespace std;

nhill::text::Named::Named()
{
}

nhill::text::Named::Named( const Named& other)
   : value_{ other.value_}
{
}

auto nhill::text::Named::operator=( const Named& other )->Named &
{
   value_ = other.value_;
   return *this;
}

nhill::text::Named::Named( Named&& other) noexcept
   : value_{move(other.value_)}
{
}

auto nhill::text::Named::operator=( Named&& other) noexcept ->Named & 
{
   value_ = move( other.value_ );
   return *this;
}

nhill::text::Named::~Named()
{
}

auto nhill::text::Named::value() const->string
{
   return value_;
}

auto nhill::text::Named::get_string() const->string
{
   return value();
}
