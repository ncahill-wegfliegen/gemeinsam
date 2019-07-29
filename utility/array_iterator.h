#pragma once

#include "array_const_iterator.h"

namespace nhill
{

template<typename T>
class Array_iterator : public Array_const_iterator<T>
{
public:
   using base = Array_const_iterator<T>;
   using iterator_catetory = std::random_access_iterator_tag;

   using value_type = T;
   using difference_type = ptrdiff_t;
   using pointer = T *;
   using reference = T &;

   Array_iterator();
   explicit Array_iterator( pointer ptr, size_t size, size_t offset = 0 );

   reference operator*() const;
   pointer operator->() const;

   Array_iterator& operator++();
   Array_iterator operator++( int );

   Array_iterator& operator--();
   Array_iterator operator--( int );

   Array_iterator& operator+=( const ptrdiff_t offset );
   Array_iterator operator+( const ptrdiff_t offset ) const;

   Array_iterator& operator-=( const ptrdiff_t offset );
   Array_iterator operator-( const ptrdiff_t offset ) const;
   ptrdiff_t operator-( const base& right ) const;

   reference operator[]( const ptrdiff_t offset ) const;

   pointer unwrapped() const;
};

}


template<typename T> inline
nhill::Array_iterator<T>::Array_iterator()
{ // construct with null pointer
}

template<typename T> inline 
nhill::Array_iterator<T>::Array_iterator( pointer ptr, size_t size, size_t offset )
   : base{ptr, size, offset}
{
}

template<typename T> inline
 auto nhill::Array_iterator<T>::operator*() const->reference
{ // return designated object
   return const_cast<reference>(base::operator*());
}

template<typename T> inline
auto nhill::Array_iterator<T>::operator->() const->pointer
{ // return pointer to class object
   return const_cast<pointer>(base::operator->());
}

template<typename T> inline
auto nhill::Array_iterator<T>::operator++()->Array_iterator &
{ // preincrement
   ++* static_cast<base*>(this);
   return *this;
}

template<typename T> inline
auto nhill::Array_iterator<T>::operator++( int )->Array_iterator
{ // postincrement
   Array_iterator tmp = *this;
   ++(*this);
   return tmp;
}

template<typename T> inline
auto nhill::Array_iterator<T>::operator--()->Array_iterator &
{ // predecrement
   --(*static_cast<base*>(this));
   return *this;
}

template<typename T> inline
auto nhill::Array_iterator<T>::operator--( int )->Array_iterator
{ // postdecrement
   Array_iterator tmp = *this;
   --(*this);
   return tmp;
}

template<typename T> inline
auto nhill::Array_iterator<T>::operator+=( const ptrdiff_t offset )->Array_iterator &
{ // increment by integer
   *static_cast<base*>(this) += offset;
   return *this;
}

template<typename T> inline
auto nhill::Array_iterator<T>::operator+( const ptrdiff_t offset ) const->Array_iterator
{ // return this + integer
   Array_iterator tmp = *this;
   return tmp += offset;
}

template<typename T> inline
auto nhill::Array_iterator<T>::operator-=( const ptrdiff_t offset )->Array_iterator &
{ // decrement by integer
   return *this += -offset;
}

template<typename T> inline
auto nhill::Array_iterator<T>::operator-( const ptrdiff_t offset ) const->Array_iterator
{ // return this - integer
   Array_iterator tmp = *this;
   return tmp -= offset;
}

template<typename T> inline
auto nhill::Array_iterator<T>::operator-( const base& right ) const->ptrdiff_t
{ // return difference of iterators
   return *static_cast<const base*>(this) - right;
}

template<typename T> inline
auto nhill::Array_iterator<T>::operator[]( const ptrdiff_t offset ) const->reference
{ // subscript
   return *(*this + offset);
}

template<typename T> inline
auto nhill::Array_iterator<T>::unwrapped() const->pointer
{
   return const_cast<pointer>(base::unwrapped());
}

