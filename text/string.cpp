#include "string.h"

using namespace std;

nhill::text::String::String()
{
}

nhill::text::String::String( string_view value )
   :value_{value}
{
}

nhill::text::String::String( const String& other)
   : value_{other.value_}
{
}

auto nhill::text::String::operator=( const String& other )->String &
{
   value_ = other.value_;
   return *this;
}

nhill::text::String::String( String&& other ) noexcept
   : value_{move(other.value_)}
{
}

auto nhill::text::String::operator=( String&& other ) noexcept->String &
{
   value_ = move( other.value_ );
   return *this;
}

nhill::text::String::~String()
{
}

auto nhill::text::String::value() const->string
{
   return value_;
}

void nhill::text::String::value( string_view value)
{
   value_ = value;
}

auto nhill::text::String::get_string() const->string
{
   return value();
}

void nhill::text::String::set_string( const string& value)
{
   this->value( value );
}
