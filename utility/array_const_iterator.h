#pragma once

#include "enable_if.h"
#include <gsl\gsl_assert>
#include <memory>

namespace nhill
{

template<typename T>
class Array_const_iterator
{
public:
   using iterator_category = std::random_access_iterator_tag;

   using value_type = T;
   using difference_type = ptrdiff_t;
   using pointer = const T*;
   using reference = const T &;

   Array_const_iterator();
   explicit Array_const_iterator( pointer ptr, size_t size, size_t offset = 0 );

   reference operator*() const; // return reference to object
   pointer operator->() const; // return pointer to object

   Array_const_iterator& operator++(); // preincrement
   Array_const_iterator& operator++( int ); // postincrement

   Array_const_iterator& operator--(); // predecrement
   Array_const_iterator& operator--( int ); // postdecrement

   void verify_offset( const ptrdiff_t offset ) const noexcept;

   Array_const_iterator& operator+=( const ptrdiff_t offset ); // increment by integer
   Array_const_iterator operator+( const ptrdiff_t offset ) const; // return this + integer

   Array_const_iterator& operator-=( const ptrdiff_t offset ); // decrement by integer
   Array_const_iterator operator-( const ptrdiff_t offset ) const; // return this - integer
   ptrdiff_t operator-( const Array_const_iterator& right ) const; // return difference between iterators

   reference operator[]( const ptrdiff_t offset ) const; // subscrip

   bool operator==( const Array_const_iterator& right ) const; 
   bool operator!=( const Array_const_iterator& right ) const;

   bool operator<( const Array_const_iterator& right ) const;
   bool operator>( const Array_const_iterator& right ) const;

   bool operator<=( const Array_const_iterator& right ) const;
   bool operator>=( const Array_const_iterator& right ) const;

   void compatible( const Array_const_iterator& right ) const; // test for compatible iterator

   pointer unwrapped() const;
   void verify_with( const Array_const_iterator& last ) const noexcept;
   void seek_to( pointer itr );

private:
   pointer ptr_; // beginning of array
   size_t size_; // the size of the array (i.e., number of elements)
   size_t index_; // offset into array
};

}

#pragma region Definitions
template<typename T>
inline nhill::Array_const_iterator<T>::Array_const_iterator()
   : ptr_{nullptr}
   , size_{0}
   , index_{0}
{
}

template<typename T>
inline nhill::Array_const_iterator<T>::Array_const_iterator( pointer ptr, size_t size, size_t offset )
   : ptr_{ptr}
   , size_{size}
   , index_{offset}
{
}

template<typename T>
inline auto nhill::Array_const_iterator<T>::operator*() const->reference
{
   return *operator->();
}

template<typename T>
inline auto nhill::Array_const_iterator<T>::operator->() const->pointer
{
   Expects( ptr_ != nullptr );
   Expects( index_ < size_ );
   return ptr_ + index_;
}

template<typename T>
inline auto nhill::Array_const_iterator<T>::operator++()->Array_const_iterator &
{
   Expects( ptr_ != nullptr );
   Expects( index_ < size_ );
   ++index_;
   return *this;
}

template<typename T>
inline auto nhill::Array_const_iterator<T>::operator++( int )->Array_const_iterator &
{
   Array_const_iterator tmp{*this};
   ++(*this);
   return tmp;
}

template<typename T>
inline auto nhill::Array_const_iterator<T>::operator--()->Array_const_iterator &
{
   Expects( ptr_ != nullptr );
   Expects( index_ != 0 );
   --index_;
   return *this;
}

template<typename T>
inline auto nhill::Array_const_iterator<T>::operator--( int )->Array_const_iterator &
{
   Array_const_iterator tmp = *this;
   --(*this);
   return tmp;
}


template<typename T>
inline void nhill::Array_const_iterator<T>::verify_offset( const ptrdiff_t offset ) const noexcept
{
   if( offset != 0)
   {
      Expects( ptr_ != nullptr );
   }

   if( offset < 0 )
   {
      #pragma warning(suppress : 4146) // unary minus operator applied to unsigned type, result still unsigned
      Expects( -static_cast<size_t>(offset) <= index_ );
   }

   if( offset > 0)
   {
      Expects( static_cast<size_t>(offset) <= (size_ - index_) );
   }
}

template<typename T>
inline auto nhill::Array_const_iterator<T>::operator+=( const ptrdiff_t offset )->Array_const_iterator &
{
   verify_offset( offset );
   index_ += offset;
   return *this;
}

template<typename T>
inline auto nhill::Array_const_iterator<T>::operator+( const ptrdiff_t offset ) const->Array_const_iterator
{
   Array_const_iterator tmp{*this};
   return tmp += offset;
}

template<typename T>
inline auto nhill::Array_const_iterator<T>::operator-=( const ptrdiff_t offset )->Array_const_iterator &
{
   return *this += -offset;
}

template<typename T>
inline auto nhill::Array_const_iterator<T>::operator-( const ptrdiff_t offset ) const->Array_const_iterator
{
   Array_const_iterator tmp{*this};
   return tmp -= offset;
}

template<typename T>
inline auto nhill::Array_const_iterator<T>::operator-( const Array_const_iterator& right ) const->ptrdiff_t
{
   compatible( right );
   return static_cast<ptrdiff_t>(index_ - right.index_);
}

template<typename T>
inline auto nhill::Array_const_iterator<T>::operator[]( const ptrdiff_t offset ) const->reference
{
   return *(*this + offset);
}

template<typename T>
inline bool nhill::Array_const_iterator<T>::operator==( const Array_const_iterator& right ) const
{
   compatible( right );
   return index_ == right.index_;
}

template<typename T>
inline bool nhill::Array_const_iterator<T>::operator!=( const Array_const_iterator& right ) const
{
   return !(*this == right);
}

template<typename T>
inline bool nhill::Array_const_iterator<T>::operator<( const Array_const_iterator& right ) const
{
   compatible( right );
   return index_ < right.index_;
}

template<typename T>
inline bool nhill::Array_const_iterator<T>::operator>( const Array_const_iterator& right ) const
{
   return right < *this;
}

template<typename T>
inline bool nhill::Array_const_iterator<T>::operator<=( const Array_const_iterator& right ) const
{
   return !(right < *this);
}

template<typename T>
inline bool nhill::Array_const_iterator<T>::operator>=( const Array_const_iterator& right ) const
{
   return !(*this < right);
}

template<typename T>
inline void nhill::Array_const_iterator<T>::compatible( const Array_const_iterator& right ) const
{
   Expects( ptr_ == right.ptr_ );
}

template<typename T>
inline auto nhill::Array_const_iterator<T>::unwrapped() const->pointer
{
   return ptr_ + index_;
}

template<typename T>
inline void nhill::Array_const_iterator<T>::verify_with( const Array_const_iterator& last ) const noexcept
{
   Expects( *this <= last );
}

template<typename T>
inline void nhill::Array_const_iterator<T>::seek_to( pointer itr )
{
   index_ = static_cast<size_t>(itr - ptr_);
}
#pragma endregion



namespace nhill
{
   
template<typename T>
Array_const_iterator<T> operator+( ptrdiff_t offset, Array_const_iterator<T> next )
{
   return next += offset;
}

}