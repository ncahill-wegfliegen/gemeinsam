#include "buffer.h"
#include "buffer_helper.h"
#include "../enum/core/int.h"
#include <stdexcept>
#include <string>

using namespace std;

nhill::Buffer::Buffer()
	: buf_{new char[1]}
	, sz_{1}
{
}

nhill::Buffer::Buffer( string_view s)
	: buf_{nullptr}
	, sz_{0}
{
	assign( s );
}

auto nhill::Buffer::operator=( string_view s)->Buffer &
{
	assign( s );
	return *this;
}

nhill::Buffer::Buffer( const Buffer& other )
	: buf_{ nullptr }
	, sz_{ 0 }
{
	assign( other.c_str() );
}

auto nhill::Buffer::operator=( const Buffer& other )->Buffer &
{
	assign( other.c_str() );
	return *this;
}

nhill::Buffer::Buffer( Buffer&& other ) noexcept
	: buf_{other.buf_}
	, sz_{other.sz_}
{
	other.buf_ = nullptr;
	other.sz_ = 0;
}

auto nhill::Buffer::operator=( Buffer&& other ) noexcept->Buffer &
{
	delete[] buf_;

	buf_ = other.buf_;
	sz_ = other.sz_;

	other.buf_ = nullptr;
	other.sz_ = 0;

	return *this;
}

nhill::Buffer::~Buffer()
{
	buffer::free( buf_ );
}

auto nhill::Buffer::assign( string_view s )->Buffer &
{
	if( s.length() == 0 )
	{
		if( length() != 0 )
		{
			buffer::free(buf_);
			sz_ = buffer::alloc( buf_, 1 );
			clear();
		}
	}
	else
	{
		sz_ = buffer::copyx( buf_, sz_, s.data(), s.length() );
	}
	return *this;
}

auto nhill::Buffer::at( size_type pos )->reference
{
	if( !is_valid( pos ) )
	{
		throw out_of_range( "The index '" + to_string( pos ) + "' is out of range [0," + to_string( length() ) + "]." );
	}
	return buf_[pos];
}

auto nhill::Buffer::at( size_type pos ) const->const_reference
{
	if( !is_valid( pos ) )
	{
		throw out_of_range( "The index '" + to_string( pos ) + "' is out of range [0," + to_string( length() ) + "]." );
	}
	return buf_[pos];
}

auto nhill::Buffer::operator[]( size_type pos )->reference
{
	return buf_[pos];
}

auto nhill::Buffer::operator[]( size_type pos ) const->const_reference
{
	return buf_[pos];
}

auto nhill::Buffer::front()->reference
{
	if( empty() )
	{
		throw out_of_range( "The buffer is empty." );
	}
	return buf_[0];
}

auto nhill::Buffer::front() const->const_reference
{
	if( empty() )
	{
		throw out_of_range( "The buffer is empty." );
	}
	return buf_[0];
}

auto nhill::Buffer::back()->reference
{
	if( empty() )
	{
		throw out_of_range( "The buffer is empty." );
	}
	return buf_[length() - 1];
}

auto nhill::Buffer::back() const->const_reference
{
	if( empty() )
	{
		throw out_of_range( "The buffer is empty." );
	}
	return buf_[length() - 1];
}

const char* nhill::Buffer::c_str() const
{
	return buf_;
}

auto nhill::Buffer::begin() noexcept->iterator
{
	return buf_;
}

auto nhill::Buffer::begin() const noexcept->const_iterator
{
	return buf_;
}

auto nhill::Buffer::cbegin() const noexcept->const_iterator
{
	return buf_;
}

auto nhill::Buffer::end() noexcept->iterator
{
	return buf_ + length();
}

auto nhill::Buffer::end() const noexcept->const_iterator
{
	return buf_ + length();
}

auto nhill::Buffer::cend() const noexcept->const_iterator
{
	return buf_ + length();
}

auto nhill::Buffer::rbegin() noexcept->iterator
{
	return buf_ + length() - 1;
}

auto nhill::Buffer::rbegin() const noexcept->const_iterator
{
	return buf_ + length() - 1;
}

auto nhill::Buffer::crbegin() const noexcept->const_iterator
{
	return buf_ + length() - 1;
}

auto nhill::Buffer::rend() noexcept->iterator
{
	return buf_ - 1;
}

auto nhill::Buffer::rend() const noexcept->const_iterator
{
	return buf_ - 1;
}

auto nhill::Buffer::crend() const noexcept->const_iterator
{
	return buf_ - 1;
}

bool nhill::Buffer::empty() const noexcept
{
	return 0 == length();
}

size_t nhill::Buffer::size() const noexcept
{
	return sz_;
}

size_t nhill::Buffer::length() const noexcept
{
	return sz_ - 1;
}

void nhill::Buffer::clear() noexcept
{
	fill( begin(), end(), '\0' );
}

bool nhill::Buffer::is_valid( size_type pos ) const
{
	if( length() == 0 )
	{
		return false;
	}
	else
	{
		return 0 <= pos && pos < size();
	}
}




template<> inline
auto nhill::compare( const Buffer& a, const Buffer& b )->Compare
{
	return to_enum<Compare>( strcmp( a.c_str(), b.c_str() ) );
}

bool nhill::operator==( const Buffer& a, const Buffer& b )
{
	return compare<const Buffer&>(a,b) == Compare::equal;
}

bool nhill::operator!=( const Buffer& a, const Buffer& b )
{
	return !( a == b);
}

bool nhill::operator<( const Buffer& a, const Buffer& b )
{
	return compare<const Buffer&>( a, b ) == Compare::less;
}

bool nhill::operator>( const Buffer& a, const Buffer& b )
{
	return compare<const Buffer&>( a, b ) == Compare::greater;
}

bool nhill::operator<=( const Buffer& a, const Buffer& b )
{
	return !(a > b);
}

bool nhill::operator>=( const Buffer& a, const Buffer& b )
{
	return !(a < b);
}

ostream& nhill::operator<<( ostream& out, const Buffer& buf )
{
	return out << buf.c_str();
}
