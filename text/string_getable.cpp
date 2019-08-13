#include "string_getable.h"
#include "../utility/str.h"

nhill::text::String_getable::~String_getable()
{
}

int nhill::text::compare( const String_getable& left, const String_getable& right )
{
   return str::compare_truncated<char>( left.get_string(), right.get_string() );
}

bool nhill::text::operator<(const String_getable& left, const String_getable& right)
{
   return nhill::text::compare(left, right) < 0;
}

bool nhill::text::operator<=(const String_getable& left, const String_getable& right)
{
   return nhill::text::compare(left, right) <= 0;
}

bool nhill::text::operator>(const String_getable& left, const String_getable& right)
{
   return nhill::text::compare(left, right) > 0;
}

bool nhill::text::operator>=(const String_getable& left, const String_getable& right)
{
   return nhill::text::compare(left, right) >= 0;
}
