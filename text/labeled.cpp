#include "labeled.h"

using namespace std;

nhill::text::Labeled::Labeled()
{
}

nhill::text::Labeled::Labeled( const Labeled& other)
   : value_{ other.value_}
{
}

auto nhill::text::Labeled::operator=( const Labeled& other )->Labeled &
{
   value_ = other.value_;
   return *this;
}

nhill::text::Labeled::Labeled( Labeled&& other) noexcept
   : value_{move(other.value_)}
{
}

auto nhill::text::Labeled::operator=( Labeled&& other) noexcept ->Labeled & 
{
   value_ = move( other.value_ );
   return *this;
}

nhill::text::Labeled::~Labeled()
{
}

auto nhill::text::Labeled::value() const->string
{
   return value_;
}

auto nhill::text::Labeled::get_string() const->string
{
   return value();
}
