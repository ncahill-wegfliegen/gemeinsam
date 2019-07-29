#include "name.h"

using namespace std;

nhill::text::Name::Name()
{
}

nhill::text::Name::Name( string_view value )
   :value_{value}
{
}

nhill::text::Name::Name( const Name& other)
   : value_{other.value_}
{
}

auto nhill::text::Name::operator=( const Name& other )->Name &
{
   value_ = other.value_;
   return *this;
}

nhill::text::Name::Name( Name&& other ) noexcept
   : value_{move(other.value_)}
{
}

auto nhill::text::Name::operator=( Name&& other ) noexcept->Name &
{
   value_ = move( other.value_ );
   return *this;
}

nhill::text::Name::~Name()
{
}

auto nhill::text::Name::value() const->string
{
   return value_;
}

void nhill::text::Name::value( string_view value)
{
   value_ = value;
}

auto nhill::text::Name::get_string() const->string
{
   return value();
}

void nhill::text::Name::set_string( const string& value)
{
   this->value( value );
}
