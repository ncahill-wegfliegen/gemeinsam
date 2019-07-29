#include "coded.h"

using namespace std;

nhill::text::Coded::Coded()
{
}

nhill::text::Coded::Coded( const Coded& other)
   : value_{ other.value_}
{
}

auto nhill::text::Coded::operator=( const Coded& other )->Coded &
{
   value_ = other.value_;
   return *this;
}

nhill::text::Coded::Coded( Coded&& other) noexcept
   : value_{move(other.value_)}
{
}

auto nhill::text::Coded::operator=( Coded&& other) noexcept ->Coded & 
{
   value_ = move( other.value_ );
   return *this;
}

nhill::text::Coded::~Coded()
{
}

auto nhill::text::Coded::value() const->string
{
   return value_;
}

auto nhill::text::Coded::get_string() const->string
{
   return value();
}
