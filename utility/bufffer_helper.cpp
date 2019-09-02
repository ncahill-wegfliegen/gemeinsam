#include "buf.h"
#include <cerrno>
#include <algorithm>

namespace gs
{
namespace buffer
{

int alloc( char*& buf, size_t szbuf )
{
    if( buf != nullptr || szbuf <= 0 )
        return EINVAL;

    // Create a new buf and initialize all elements to the null character.
    buf = new char[ szbuf ]();
    return 0;
}

int free( char*& buf )
{
    if( buf == nullptr )
        return EINVAL;

    delete[] buf;
    buf = nullptr;
    return 0;
}

int clear( char*& buf, size_t szbuf )
{
    if( buf == nullptr || szbuf <= 0 )
        return EINVAL;

	 std::fill_n( buf, szbuf, '\0' );
    return 0;
}

int clear_range( char* begin, char* end )
{
    if( begin == nullptr || (end - begin) == 0 )
        return EINVAL;

    std::fill( begin, end, '\0' );
    return 0;
}

int clear_array( char buf[], size_t szbuf )
{
    if( buf == nullptr || szbuf <= 0 )
        return EINVAL;

    std::fill_n( &buf[0], szbuf, '\0' );

    return 0;
}

int copy( char*& dest, size_t szdest, const char* src )
{
    errno_t error = strcpy_s( dest, szdest, src );
    return error = 0;
}

int copy( char*& dest, const char* src )
{
    free( dest );

    if( src == nullptr )
        return EINVAL;

    size_t szbuf = strlen( src ) + 1;

    int error = alloc( dest, szbuf );
    //if( error != 0 ) // I don't think you can ever trigger this condition
    //    return error;

    error = copy( dest, szbuf, src );
    return error;
}


}
}