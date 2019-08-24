#pragma once

#include "compare.h"
#include "../enum/core/int.h"
#include <string>
#include <stdexcept>
#include <sstream>
#include <algorithm>

namespace nhill
{

template<size_t N>
class Strn
{
public:
   Strn();

   Strn( const char* s );
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
   ///  <summary>Assumes that either the string is null, or the string size is less than or equal to N.
   ///     <para>i.e., validation has already been done.</para>
   /// </summary>
   void set( const char* s );

private:
   char s_[N+1]{};
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
   return compare( a, b ) == Compare::equal;
}

template<size_t N, size_t M>
bool operator!=( const Strn<N>& a, const Strn<M>& b )
{
   return !(a == b);
}

template<size_t N, size_t M>
bool operator<( const Strn<N>& a, const Strn<M>& b )
{
   return compare( a, b ) == Compare::less;
}

template<size_t N, size_t M>
bool operator>( const Strn<N>& a, const Strn<M>& b )
{
   return compare( a, b ) == Compare::greater;
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

}
#pragma endregion

#pragma region Defintions

template<size_t N>
nhill::Strn<N>::Strn() = default;

template<size_t N>
nhill::Strn<N>::Strn( const char* s )
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
   set( other.s_ );
}

template<size_t N>
auto nhill::Strn<N>::operator=( const Strn& other )->Strn &
{
   set( other.s_ );
   return *this;
}

template<size_t N>
nhill::Strn<N>::Strn( Strn&& other ) noexcept
{
   set( other.s_ );
}

template<size_t N>
auto nhill::Strn<N>::operator=( Strn&& other ) noexcept->Strn &
{
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
   std::fill( s_, s_ + size(), '\0' );
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
inline void nhill::Strn<N>::set( const char* s )
{
   clear();
   if( s != nullptr )
   {
      std::copy( s, s + strlen( s ), s_ );
   }
}

#pragma endregion