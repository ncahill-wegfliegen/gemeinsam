#include "code.h"

using namespace std;

nhill::text::Code::Code()
{
}

nhill::text::Code::Code( string_view value )
   :value_{ value }
{
}

nhill::text::Code::Code( const Code& other )
   : value_{ other.value_ }
{
}

auto nhill::text::Code::operator=( const Code& other )->Code &
{
   value_ = other.value_;
   return *this;
}

nhill::text::Code::Code( Code&& other ) noexcept
   : value_{ move( other.value_ ) }
{
}

auto nhill::text::Code::operator=( Code&& other ) noexcept->Code &
{
   value_ = move( other.value_ );
   return *this;
}

nhill::text::Code::~Code()
{
}

auto nhill::text::Code::value() const->string
{
   return value_;
}

void nhill::text::Code::value( string_view value )
{
   value_ = value;
}

auto nhill::text::Code::get_string() const->string
{
   return value();
}

void nhill::text::Code::set_string( const string& value )
{
   this->value( value );
}
