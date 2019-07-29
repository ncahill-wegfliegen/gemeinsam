#include "abbreviation.h"

using namespace std;

nhill::text::Abbreviation::Abbreviation()
{
}

nhill::text::Abbreviation::Abbreviation( string_view value )
   :value_{value}
{
}

nhill::text::Abbreviation::Abbreviation( const Abbreviation& other)
   : value_{other.value_}
{
}

auto nhill::text::Abbreviation::operator=( const Abbreviation& other )->Abbreviation &
{
   value_ = other.value_;
   return *this;
}

nhill::text::Abbreviation::Abbreviation( Abbreviation&& other ) noexcept
   : value_{move(other.value_)}
{
}

auto nhill::text::Abbreviation::operator=( Abbreviation&& other ) noexcept->Abbreviation &
{
   value_ = move( other.value_ );
   return *this;
}

nhill::text::Abbreviation::~Abbreviation()
{
}

auto nhill::text::Abbreviation::value() const->string
{
   return value_;
}

void nhill::text::Abbreviation::value( string_view value)
{
   value_ = value;
}

auto nhill::text::Abbreviation::get_string() const->string
{
   return value();
}

void nhill::text::Abbreviation::set_string( const string& value)
{
   this->value( value );
}
