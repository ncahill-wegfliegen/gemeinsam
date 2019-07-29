#include "description.h"

using namespace std;

nhill::text::Description::Description()
{
}

nhill::text::Description::Description( string_view value )
   :value_{value}
{
}

nhill::text::Description::Description( const Description& other)
   : value_{other.value_}
{
}

auto nhill::text::Description::operator=( const Description& other )->Description &
{
   value_ = other.value_;
   return *this;
}

nhill::text::Description::Description( Description&& other ) noexcept
   : value_{move(other.value_)}
{
}

auto nhill::text::Description::operator=( Description&& other ) noexcept->Description &
{
   value_ = move( other.value_ );
   return *this;
}

nhill::text::Description::~Description()
{
}

auto nhill::text::Description::value() const->string
{
   return value_;
}

void nhill::text::Description::value( string_view value)
{
   value_ = value;
}

auto nhill::text::Description::get_string() const->string
{
   return value();
}

void nhill::text::Description::set_string( const string& value)
{
   this->value( value );
}
