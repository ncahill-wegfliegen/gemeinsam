#pragma once

#include "compare.h"
#include "../enum/core/int.h"
#include <string>
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <ostream>

namespace nhill
{

template<size_t N>
class Strn
{
public:
	enum class Pad{left,right };

   Strn( char c = '\0', Pad pad = Pad::right );

   Strn( const char* s, char c = '\0', Pad pad = Pad::right );
   Strn& operator=( const char* );

   Strn( const Strn& );
   Strn& operator=( const Strn& );

   Strn( Strn&& ) noexcept;
   Strn& operator=( Strn&& ) noexcept;

   virtual ~Strn();

   operator const char* () const;
   constexpr size_t size() const; // N + 1

   void clear();
   /// <summary>Validate the string length (less than this size). Null is valid (i.e., length 0).</summary>
   virtual bool is_valid( const char* s, std::string* error_msg = nullptr ); 

protected:
	void fill( char c, Pad pad = Pad::left );
	
	///  <summary>Assumes that either the string is null, or the string size is less than or equal to N.
   ///     <para>i.e., validation has already been done.</para>
   /// </summary>
   void set( const char* s );

private:
   char s_[N+1]{}; // The buffer
	char c_{ '\0' }; // The fill character
	Pad pad_{ Pad::right };// Use the fill character to pad the left/right of the buffer/
};

}

#pragma region Operators
namespace nhill
{

template<size_t N, size_t M>
Compare compare( const Strn<N>& a, const Strn<M>& b )
{
   return to_enum<Compare>( strcmp( a, b ) );
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
nhill::Strn<N>::Strn( char c, Pad pad )
	: s_{}
	, c_{ c }
	, pad_{ pad }
{
	clear();
}

template<size_t N>
nhill::Strn<N>::Strn( const char* s, char c, Pad pad )
	: s_{}
	, c_{ c }
	, pad_{ pad }
{
   operator=( s );
}

template<size_t N>
auto nhill::Strn<N>::operator=( const char* s )->Strn &
{
   std::string error_msg;
   if( !is_valid( s, &error_msg) )
   {
      throw std::invalid_argument( error_msg.c_str() );
   }

   set( s );

   return *this;
}

template<size_t N>
nhill::Strn<N>::Strn( const Strn& other )
{
	c_ = other.c_;
	pad_ = other.pad_;
   set( other.s_ );
}

template<size_t N>
auto nhill::Strn<N>::operator=( const Strn& other )->Strn &
{
	c_ = other.c_;
	pad_ = other.pad_;
	set( other.s_ );
   return *this;
}

template<size_t N>
nhill::Strn<N>::Strn( Strn&& other ) noexcept
{
	c_ = other.c_;
	pad_ = other.pad_;
	set( other.s_ );
}

template<size_t N>
auto nhill::Strn<N>::operator=( Strn&& other ) noexcept->Strn &
{
	c_ = other.c_;
	pad_ = other.pad_;
	set( other.s_ );
   return *this;
}

template<size_t N>
nhill::Strn<N>::~Strn() = default;

template<size_t N>
nhill::Strn<N>::operator const char* () const
{
   return s_;
}

template<size_t N>
inline constexpr size_t nhill::Strn<N>::size() const
{
   return sizeof s_;
}

template<size_t N>
void nhill::Strn<N>::clear()
{
   std::fill( s_, s_ + N, c_ );
	s_[N] = '\0';
}

template<size_t N>
inline bool nhill::Strn<N>::is_valid( const char* s, std::string* error_msg)
{
   if( s == nullptr )
   {
      return true;
   }

   if( size() <= strlen( s ) )
   {
      if( error_msg != nullptr )
      {
         *error_msg = "This string \"" + std::string{ s } +"\" is too long to copy into a location exception.";
      }
      return false;
   }

   return true;
}

template<size_t N>
inline void  nhill::Strn<N>::fill( char c, Pad pad )
{
	c_ = c;
	pad_ = pad;
}


template<size_t N>
inline void nhill::Strn<N>::set( const char* s )
{
   clear();
   if( s != nullptr )
   {
		size_t slen{ strlen( s ) };
		switch( pad_ )
		{
		case Pad::left:
			std::copy( s, s + slen, s_ + N - slen );
			break;

		case Pad::right:
			std::copy( s, s + slen, s_ );
			break;
		}
   }
}

#pragma endregion