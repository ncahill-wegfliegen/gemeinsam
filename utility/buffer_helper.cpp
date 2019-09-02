#include "buffer_helper.h"
#include <cerrno>
#include <algorithm>

size_t nhill::buffer::alloc( char*& buf, size_t bufsz )
{
    if( buf != nullptr || bufsz <= 0 )
        return 0;

    // Create a new buffer and initialize all elements to the null character.
    buf = new char[ bufsz ]();
    return bufsz;
}

size_t nhill::buffer::free( char*& buf )
{
    if( buf == nullptr )
        return 0;

    delete[] buf;
    buf = nullptr;
    return 0;
}

void nhill::buffer::clear( char*& buf, size_t bufsz )
{
    if( buf == nullptr || bufsz <= 0 )
        return;

	 std::fill_n( buf, bufsz, '\0' );
}

void nhill::buffer::clear_range( char* begin, char* end )
{
    if( begin == nullptr || (end - begin) == 0 )
        return;

    std::fill( begin, end, '\0' );
}

void nhill::buffer::clear_array( char buf[], size_t bufsz )
{
    if( buf == nullptr || bufsz <= 0 )
        return;

    std::fill_n( &buf[0], bufsz, '\0' );
}

size_t nhill::buffer::copy( char*& dest, size_t destsz, const char* src, size_t count )
{
	clear( dest, destsz );
	size_t len{ (std::min)(destsz - 1, count) };
	std::copy( src, src + len, dest );
   return len + 1;
}

size_t nhill::buffer::copyx( char*& dest, size_t destsz, const char* src, size_t count )
{
	 if( count + 1 != destsz )
	 {
		 free( dest );
		 destsz = alloc( dest, count + 1 );
	 }

    return copy( dest, destsz, src );
}
