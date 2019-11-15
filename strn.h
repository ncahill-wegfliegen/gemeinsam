#pragma once

#include "compare.h"
#include "../enum/core/int.h"
#include <string>
#include <cstring>
#include <algorithm>
#include <ostream>

namespace nhill
{

template<size_t N>
class Strn
{
	static_assert( 0 < N, "The size of an 'Strn' object must be greater than zero.");

public:
	using value_type = char;
	using size_type = size_t;
	using difference_type = ptrdiff_t;
	using pointer = char*;
	using const_pointer = const char*;
	using reference = const char&;
	using const_reference = const char&;
	using iterator = char*;
	using const_iterator = const char*;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	static constexpr size_t npos{ std::string::npos };

   Strn();

   Strn( const char* s, size_t n = npos );
   Strn& operator=( const char* );

   Strn( const Strn& );
   Strn& operator=( const Strn& );

   Strn( Strn&& ) noexcept;
   Strn& operator=( Strn&& ) noexcept;

   ~Strn();

	iterator begin() noexcept;
	const_iterator begin() const noexcept;

	iterator end() noexcept;
	const_iterator end() const noexcept;

	reverse_iterator rbegin() noexcept;
	const_reverse_iterator rbegin() const noexcept;

	reverse_iterator rend() noexcept;
	const_reverse_iterator rend() const noexcept;

	const_iterator cbegin() const noexcept;

	const_iterator cend() const noexcept;

	const_reverse_iterator crbegin() const noexcept;

	const_reverse_iterator crend() const noexcept;

	/// <summary>Returns the size of the internal buffer (i.e., the value of template paratemer, N).</summary>
	constexpr size_t size() const;

	/// <summary>Returns the number of non-null characeters in the buffer (may be less than the size).</summary>
	size_t length() const;

	void clear() noexcept;

	bool empty() const noexcept;

	reference operator[]( size_type pos );
	const_reference operator[]( size_type pos ) const;

	reference at( size_type pos );
	const_reference at( size_type pos ) const;

	reference back();
	const_reference back() const;

	reference front();
	const_reference front() const;

	Strn& operator += (const char* s);
	Strn& operator += ( char );

	Strn& append( const char* s, size_type n = npos);

	void push_back( char c );

	Strn& assign( const char* s, size_type n = npos );

	std::string str() const noexcept;

	/// <summary>Returns a pointer to the start of the internal buffer.  Not null terminated.</summary>
	const char* data() const noexcept;

private:
	/// <summary>The internal buffer.</summary>
   char s_[N]{};
};

}

#pragma region Operators
namespace nhill
{

template<size_t N, size_t M>
Compare compare( const Strn<N>& a, const Strn<M>& b )
{
   return to_enum<Compare>( strncmp( a, b, N ) );
}

template<size_t N, size_t M>
bool operator==( const Strn<N>& a, const Strn<M>& b )
{
   return compare<N, M>( a, b ) == Compare::equal;
}

template<size_t N, size_t M>
bool operator!=( const Strn<N>& a, const Strn<M>& b )
{
   return !(a == b);
}

template<size_t N, size_t M>
bool operator<( const Strn<N>& a, const Strn<M>& b )
{
   return compare<N,M>( a, b ) == Compare::less;
}

template<size_t N, size_t M>
bool operator>( const Strn<N>& a, const Strn<M>& b )
{
   return compare<N, M>( a, b ) == Compare::greater;
}

template<size_t N, size_t M>
bool operator<=( const Strn<N>& a, const Strn<M>& b )
{
   return (a == b) || (a < b);
}

template<size_t N, size_t M>
bool operator>=( const Strn<N>& a, const Strn<M>& b )
{
   return (a == b) || (a > b);
}

template<size_t N>
std::ostream& operator<<( std::ostream& out, const Strn<N>& str )
{
	return out << static_cast<const char*>(str);
}


}
#pragma endregion

#pragma region Defintions

template<size_t N>
nhill::Strn<N>::Strn()
{
	clear();
}

template<size_t N>
nhill::Strn<N>::Strn( const char* s, size_t n )
{
   assign( s, n );
}

template<size_t N>
auto nhill::Strn<N>::operator=( const char* s )->Strn &
{
	assign( s );
	return *this;
}

template<size_t N>
nhill::Strn<N>::Strn( const Strn& other )
{
	assign( other.s_, N );
}

template<size_t N>
auto nhill::Strn<N>::operator=( const Strn& other )->Strn &
{
	assign( other.s_, N );
   return *this;
}

template<size_t N>
nhill::Strn<N>::Strn( Strn&& other ) noexcept
{
	assign( other.s_, N );
}

template<size_t N>
auto nhill::Strn<N>::operator=( Strn&& other ) noexcept->Strn &
{
	assign( other.s_, N );
	return *this;
}

template<size_t N>
nhill::Strn<N>::~Strn() = default;

template<size_t N>
inline constexpr size_t nhill::Strn<N>::size() const
{
   return N;
}

template<size_t N>
inline size_t nhill::Strn<N>::length() const
{
	auto itr{ std::find( cbegin(), cend(), '\0' ) };

	if( itr == cend() )
	{
		return size();
	}
	else
	{
		return std::distance( cbegin(), itr );
	}
}

template<size_t N>
inline auto nhill::Strn<N>::begin() noexcept->iterator
{
	return s_;
}

template<size_t N>
inline auto nhill::Strn<N>::begin() const noexcept->const_iterator
{
	return s_;
}

template<size_t N>
inline auto nhill::Strn<N>::end() noexcept->iterator
{
	return s_ + N;
}

template<size_t N>
inline auto nhill::Strn<N>::end() const noexcept->const_iterator
{
	return s_ + N;
}

template<size_t N>
inline auto nhill::Strn<N>::rbegin() noexcept->reverse_iterator
{
	return std::make_reverse_iterator<iterator>( s_ + N - 1);
}

template<size_t N>
inline auto nhill::Strn<N>::rbegin() const noexcept->const_reverse_iterator
{
	return std::make_reverse_iterator<const_iterator>(s_ + N - 1);
}

template<size_t N>
inline auto nhill::Strn<N>::rend() noexcept->reverse_iterator
{
	return std::make_reverse_iterator<iterator>( s_ - 1);
}

template<size_t N>
inline auto nhill::Strn<N>::rend() const noexcept->const_reverse_iterator
{
	return std::make_reverse_iterator<const_iterator>( s_ - 1 );
}

template<size_t N>
inline auto nhill::Strn<N>::crbegin() const noexcept->const_reverse_iterator
{
	return  std::make_reverse_iterator<const_iterator>( s_ + N - 1);
}

template<size_t N>
inline auto nhill::Strn<N>::crend() const noexcept->const_reverse_iterator
{
	return  std::make_reverse_iterator<const_iterator>( s_ + N -1);
}

template<size_t N>
inline auto nhill::Strn<N>::cbegin() const noexcept->const_iterator
{
	return s_;
}

template<size_t N>
inline auto nhill::Strn<N>::cend() const noexcept->const_iterator
{
	return s_ + N;
}

template<size_t N>
void nhill::Strn<N>::clear() noexcept
{
   std::fill( begin(), end(), '\0' );
}

template<size_t N>
inline bool nhill::Strn<N>::empty() const noexcept
{
	return length() == 0;
}

template<size_t N>
inline auto nhill::Strn<N>::operator[]( size_type pos )->reference
{
	return s_[pos];
}

template<size_t N>
inline auto nhill::Strn<N>::operator[]( size_type pos ) const->const_reference
{
	return s_[pos];
}

template<size_t N>
inline auto nhill::Strn<N>::at( size_type pos )->reference
{
	if( N <= pos )
	{
		throw std::out_of_range( "The position '" + std::to_string( pos ) + " is out of range [0, " + std::to_string( N-1 ) + "]." );
	}
	return s_[pos];
}

template<size_t N>
inline auto nhill::Strn<N>::at( size_type pos ) const->const_reference
{
	if( N <= pos )
	{
		throw std::out_of_range( "The position '" + std::to_string( pos ) + " is out of range [0, " + std::to_string( N-1 ) + "]." );
	}
	return s_[pos];
}

template<size_t N>
inline auto nhill::Strn<N>::back()->reference
{
	return s_[N-1];
}

template<size_t N>
inline auto nhill::Strn<N>::back() const->const_reference
{
	return s_[N - 1];
}

template<size_t N>
inline auto nhill::Strn<N>::front()->reference
{
	return s_[0];
}

template<size_t N>
inline auto nhill::Strn<N>::front() const->const_reference
{
	return s_[0];
}

template<size_t N>
inline auto nhill::Strn<N>::operator+=( const char* s )->Strn &
{
	return *this;
}

template<size_t N>
inline auto nhill::Strn<N>::operator+=( char )->Strn &
{
	return *this;
}

template<size_t N>
inline auto nhill::Strn<N>::append( const char* s, size_type n )->Strn &
{
	return *this;
}

template<size_t N>
inline void nhill::Strn<N>::push_back( char c )
{
}

template<size_t N>
inline auto nhill::Strn<N>::assign( const char* s, size_type n )->Strn &
{
	clear();

	if( s == nullptr )
	{
		return *this;
	}

	if( n != npos )
	{
		n = (std::min)(n, N);
		std::copy( s, s + n, s_ );
	}
	else
	{
		n = (std::min)(strlen(s), N);
		std::copy( s, s + n, s_ );
	}

	return *this;
}

template<size_t N>
inline std::string nhill::Strn<N>::str() const noexcept
{
	std::string s( N, '\0' );
	std::copy( s_, s_ + N, s.begin() );
	return s;
}

template<size_t N>
inline const char* nhill::Strn<N>::data() const noexcept
{
	return s_;
}

#pragma endregion
