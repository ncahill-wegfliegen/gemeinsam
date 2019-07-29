#include "label.h"

using namespace std;

nhill::text::Label::Label()
{
}

nhill::text::Label::Label( string_view value )
   :value_{value}
{
}

nhill::text::Label::Label( const Label& other)
   : value_{other.value_}
{
}

auto nhill::text::Label::operator=( const Label& other )->Label &
{
   value_ = other.value_;
   return *this;
}

nhill::text::Label::Label( Label&& other ) noexcept
   : value_{move(other.value_)}
{
}

auto nhill::text::Label::operator=( Label&& other ) noexcept->Label &
{
   value_ = move( other.value_ );
   return *this;
}

nhill::text::Label::~Label()
{
}

auto nhill::text::Label::value() const->string
{
   return value_;
}

void nhill::text::Label::value( string_view value)
{
   value_ = value;
}

auto nhill::text::Label::get_string() const->string
{
   return value();
}

void nhill::text::Label::set_string( const string& value)
{
   this->value( value );
}
