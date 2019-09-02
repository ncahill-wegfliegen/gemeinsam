#pragma once

#include "port.h"
#include <cstdint>

// http://en.cppreference.com/w/cpp/error/errno_macros
// http://www.cplusplus.com/reference/cerrno/errno/

namespace nhill
{
namespace buffer
{
/// <summary>Allocate a buffer with the given size.
/// <para>Every element of the buffer is set to the null character '\0'.</para>
/// <para>You must call nhill::buf::free do deallocate this buffer.</para>
/// </summary>
/// <param name="buffer">The buffer to be allocated.  If not null, then the method returns EINVAL.</param>
/// <param name="bufsz">The size of the new buffer.  If zero, then the method returns EINVAL.</param>
/// <returns>Zero if successful; othersize, an error (errno).</returns>
/// <example>This example shows how to call the nhill::buf::alloc method.
///     <code>
///         char* buf = nullptr;
///         size_t bufsz = 16;
///         nhill::buf::alloc( buf, bufsz);
///     </code>
/// </example>
NHILL_UTIL_PORT_FUNCTION size_t alloc( char*& buf, size_t bufsz );

/// <summary>Deallocate a buffer that was allocated with the nhill::buf::alloc method.</summary>
/// <param name="buffer">The buffer to be deallocated.  If the buffer is null, then nothing happens.</param>
/// <returns>Zero if successful; othersize, an error (errno).</returns>
NHILL_UTIL_PORT_FUNCTION size_t free( char*& buf );

/// <summary>Clear the buffer.  Every character in the buffer is set to '\0'.</summary>
/// <param name="buffer">The buffer to be cleared.  If the buffer is null, then the method returns EINVAL.</param>
/// <param name="bufsz">The size of the buffer.  If the size of the buffer is zero, then the method returnes EINVAL.</param>
/// <returns>Zero if successful; othersize, an error (errno).</returns>
/// <example>This example shows how to call the nhill::buf::clear method.
///     <code>
///         size_t bufsz = 3;
///         char* buf = new char[3];
///         nhill::buf::clear( buf, bufsz );
///         delete[] buf;
///     </code>
/// </example>
NHILL_UTIL_PORT_FUNCTION void clear( char*& buf, size_t bufsz );

/// <summary>Clear the buffer range.  Every character in the buffer is set to '\0'.</summary>
/// <param name="begin">The beginning of the buffer to be cleared.  If begin is null, then the method returns EINVAL.</param>
/// <param name="end">The end of the buffer.  If the difference between the end and begin is zero then the method returns EINVAL.</param>
/// <returns>Zero if successful; othersize, an error (errno).</returns>
/// <example>This example shows how to call the nhill::buf::clear method.
///     <code>
///         char buf[3] = "AB";
///         nhill::buf::clear_range( buf, buf + strlen( buf ) );
///     </code>
/// </example>
NHILL_UTIL_PORT_FUNCTION void clear_range( char* begin, char* end );

/// <summary>Clear the character array buffer.  Every character in the buffer is set to '\0'.</summary>
/// <param name="buffer">The buffer to be cleared.  If begin is null, then the method returns EINVAL.</param>
/// <param name="bufsz">The size of the buffer.  If the size of the buffer is zero, then the method returnes EINVAL.</param>
/// <returns>Zero if successful; othersize, an error (errno).</returns>
/// <example>This example shows how to call the nhill::buf::clear method.
///     <code>
///         char buf[3] = SL("AB");
///         size_t bufsz = _countof( buf );
///         nhill::buf::clear_array( buf, bufsz );
///     </code>
/// </example>
NHILL_UTIL_PORT_FUNCTION void clear_array( char buf[], size_t bufsz );

/// <summary>Copy the contents of source (including the terminating null character) into the destination.
/// <para>The destination string must be large enough to hold the source string and its terminating null character.</para>
/// <summary>
/// <param name="dest">The destination buffer.</summary>
/// <param name="destsz">The size of the destination.  It must be large enough to hold the source (including null terminator).</param>
/// <returns>Zero if successful; othersize, an error (errno).  See the Microsoft documentation for strcpy_s for more details.</returns>
NHILL_UTIL_PORT_FUNCTION size_t copy( char*& dest, size_t destsz, const char* src, size_t count = SIZE_MAX );

/// <summary>Copy the source into the destination.  
/// <para>Reallocate the destination so that it is just large enough to accomodate the source.</para>
/// <para>NOTE: the destination must be nullptr or it must have been allocated with either the nhill::buf::alloc or nhill::buf::setx method.</para>
/// </summary>
/// <param name="dest">The destination.</param>
/// <param name="src">The source.  If the source is null, then the method returns EINVAL.</param>
/// <returns>Zero if successful; othersize, an error (errno).</returns>
NHILL_UTIL_PORT_FUNCTION size_t copyx( char*& dest, size_t destsz, const char* src, size_t count = SIZE_MAX );


}
}