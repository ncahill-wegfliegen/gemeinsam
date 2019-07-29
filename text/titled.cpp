#include "titled.h"

using namespace std;

nhill::text::Titled::Titled()
{
}

nhill::text::Titled::Titled( const Titled& other)
   : value_{ other.value_}
{
}

auto nhill::text::Titled::operator=( const Titled& other )->Titled &
{
   value_ = other.value_;
   return *this;
}

nhill::text::Titled::Titled( Titled&& other) noexcept
   : value_{move(other.value_)}
{
}

auto nhill::text::Titled::operator=( Titled&& other) noexcept ->Titled & 
{
   value_ = move( other.value_ );
   return *this;
}

nhill::text::Titled::~Titled()
{
}

auto nhill::text::Titled::value() const->string
{
   return value_;
}

auto nhill::text::Titled::get_string() const->string
{
   return value();
}
