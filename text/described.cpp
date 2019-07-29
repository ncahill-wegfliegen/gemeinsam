#include "described.h"

using namespace std;

nhill::text::Described::Described()
{
}

nhill::text::Described::Described( const Described& other)
   : value_{ other.value_}
{
}

auto nhill::text::Described::operator=( const Described& other )->Described &
{
   value_ = other.value_;
   return *this;
}

nhill::text::Described::Described( Described&& other) noexcept
   : value_{move(other.value_)}
{
}

auto nhill::text::Described::operator=( Described&& other) noexcept ->Described & 
{
   value_ = move( other.value_ );
   return *this;
}

nhill::text::Described::~Described()
{
}

auto nhill::text::Described::value() const->string
{
   return value_;
}

auto nhill::text::Described::get_string() const->string
{
   return value();
}
