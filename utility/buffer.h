#pragma once

#include "port.h"
#include "compare.h"
#include <string_view>
#include <ostream>

namespace nhill
{

class NHILL_UTIL_PORT_CLASS Buffer final
{
public:
	using value_type = char;
	using size_type = size_t;
	using difference_type = ptrdiff_t;
	using pointer = char*;
	using const_pointer = const char*;
	using reference = char&;
	using const_reference = const char&;

	using iterator = char*;
	using const_iterator = const char*;

	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	Buffer();

	Buffer( std::string_view );
	Buffer& operator=( std::string_view );

	Buffer( const Buffer& );
	Buffer& operator=( const Buffer& );

	Buffer( Buffer&& ) noexcept;
	Buffer& operator=( Buffer&& ) noexcept;

	~Buffer();

	/// <summary>The internal buffer will be resized to hold the string.</summary>
	Buffer& assign( std::string_view );

	reference at( size_type pos );
	const_reference at( size_type pos ) const;

	reference operator[]( size_type pos );
	const_reference operator[]( size_type pos ) const;

	reference front();
	const_reference front() const;

	reference back();
	const_reference back() const;

	/// <summary>Returns a non-modifiable standard C character array version of the string (null terminated).
	///    <para>It may be length 0, but it never returns a nullptr.</para>
	/// </summary>
	const char* c_str() const;

	iterator begin() noexcept;
	const_iterator begin() const noexcept;
	const_iterator cbegin() const noexcept;

	iterator end() noexcept;
	const_iterator end() const noexcept;
	const_iterator cend() const noexcept;

	iterator rbegin() noexcept;
	const_iterator rbegin() const noexcept;
	const_iterator crbegin() const noexcept;

	iterator rend() noexcept;
	const_iterator rend() const noexcept;
	const_iterator crend() const noexcept;

	bool empty() const noexcept;

	/// <summary>The size of the internal buffer (number of characters plus the null terminator).
	///    <para>The size is at least one (never zero).</para>
	/// </summary>
	size_t size() const noexcept;
	/// <summary>The number of characters not including the null terminator.</summary>
	size_t length() const noexcept;

	void clear() noexcept;

	bool is_valid( size_type pos ) const;

private:
	/// <summary>The buffer is an array of characters.</summary>
	char* buf_;
	/// <summary>The size of the buffer (number of characters plus the null terminator).</summary>
	size_t sz_;

};

}


namespace nhill
{

template<> NHILL_UTIL_PORT_FUNCTION inline
Compare compare( const Buffer& a, const Buffer& b );

NHILL_UTIL_PORT_FUNCTION bool operator==( const Buffer& a, const Buffer& b );
NHILL_UTIL_PORT_FUNCTION bool operator!=( const Buffer& a, const Buffer& b );

NHILL_UTIL_PORT_FUNCTION bool operator<( const Buffer& a, const Buffer& b );
NHILL_UTIL_PORT_FUNCTION bool operator>( const Buffer& a, const Buffer& b );

NHILL_UTIL_PORT_FUNCTION bool operator<=( const Buffer& a, const Buffer& b );
NHILL_UTIL_PORT_FUNCTION bool operator>=( const Buffer& a, const Buffer& b );

NHILL_UTIL_PORT_FUNCTION std::ostream& operator<<( std::ostream& out, const Buffer& buf );

}