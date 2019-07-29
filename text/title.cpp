#include "title.h"

using namespace std;

nhill::text::Title::Title()
{
}

nhill::text::Title::Title( string_view value )
   :value_{value}
{
}

nhill::text::Title::Title( const Title& other)
   : value_{other.value_}
{
}

auto nhill::text::Title::operator=( const Title& other )->Title &
{
   value_ = other.value_;
   return *this;
}

nhill::text::Title::Title( Title&& other ) noexcept
   : value_{move(other.value_)}
{
}

auto nhill::text::Title::operator=( Title&& other ) noexcept->Title &
{
   value_ = move( other.value_ );
   return *this;
}

nhill::text::Title::~Title()
{
}

auto nhill::text::Title::value() const->string
{
   return value_;
}

void nhill::text::Title::value( string_view value)
{
   value_ = value;
}

auto nhill::text::Title::get_string() const->string
{
   return value();
}

void nhill::text::Title::set_string( const string& value)
{
   this->value( value );
}
