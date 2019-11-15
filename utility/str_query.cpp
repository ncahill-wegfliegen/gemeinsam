#include "str_query.h"
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

namespace
{

bool unchecked_is_integer( string_view s )
{
	auto itr{ find_if_not( s.cbegin(), s.cend(), ::isdigit ) };
	return itr == s.cend();
}

}

bool nhill::str::is_uint( string_view s )
{
	size_t len{ s.length() };
	if( len == 0 )
	{
		return false;
	}

	return unchecked_is_integer( s );
}

bool nhill::str::is_uint( string_view s, size_t len_must_be )
{
	size_t len{ s.length() };
	if( len != len_must_be )
	{
		return false;
	}

	return unchecked_is_integer( s );
}

bool nhill::str::is_uint( string_view s, size_t len_min, size_t len_max )
{
	size_t len{ s.length() };
	if( len < len_min || len_max < len )
	{
		return false;
	}

	return unchecked_is_integer( s );
}
