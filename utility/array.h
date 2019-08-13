#pragma once

#include "array_iterator.h"
#include <algorithm>
#include <iterator>
#include <gsl/gsl_assert>


namespace nhill
{

template <class T>
class Array
{ // fixed size array of values
public:
   using value_type      = T;
   using size_type       = size_t;
   using difference_type = ptrdiff_t;
   using pointer         = T *;
   using const_pointer   = const T*;
   using reference       = T &;
   using const_reference = const T &;

   using iterator       = Array_iterator<T>;
   using const_iterator = Array_const_iterator<T>;

   using reverse_iterator       = std::reverse_iterator<iterator>;
   using const_reverse_iterator = std::reverse_iterator<const_iterator>;

   Array( size_t size );
   Array( std::initializer_list<T> init_list );
   Array& operator=( std::initializer_list<T> init_list );
   Array( const Array& );
   Array& operator=( const Array& );
   Array( Array&& ) noexcept;
   Array& operator=( Array&& );
   ~Array();

   void fill( const T& _Value );

   void swap( Array& other );

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

   T* unchecked_begin() noexcept;

   const T* unchecked_begin() const noexcept;

   T* unchecked_end() noexcept;

   const T* unchecked_end() const noexcept;

   size_type size() const noexcept;

   size_type max_size() const noexcept;

   bool empty() const noexcept;

   reference at( size_type pos );

   const_reference at( size_type pos ) const;

   reference operator[]( size_type pos ) noexcept;

   const_reference operator[]( size_type pos ) const noexcept;

   reference front() noexcept;

   const_reference front() const noexcept;

   reference back() noexcept;

   const_reference back() const noexcept;

   T* data() noexcept;

   const T* data() const noexcept;

   void range_exception( size_t pos) const;

private:
   T* elements_;
   size_t size_;
};


}



template <class T> inline
nhill::Array<T>::Array( size_t size)
   : elements_{new T[size]{} }
   , size_{size}
{
}

template <class T> inline
nhill::Array<T>::Array( std::initializer_list<T> init_list )
   : Array(init_list.size())
{
   operator=( init_list );
}

template <class T> inline
auto nhill::Array<T>::operator=( std::initializer_list<T> init_list )->Array&
{
   Expects( size_ == init_list.size() );
   std::copy( init_list.begin(), init_list.end(), begin() );
   return *this;
}

template <class T> inline
nhill::Array<T>::Array( const Array& other )
   : Array{other.size_}
{
   operator=( other );
}

template <class T> inline
auto nhill::Array<T>::operator=( const Array& other )->Array&
{
   Expects( size_ == other.size_ );
   std::copy( other.cbegin(), other.cend(), begin() );
   return *this;
}

template <class T> inline
nhill::Array<T>::Array( Array&& ) noexcept = default;

template <class T> inline
auto nhill::Array<T>::operator=( Array&& other ) ->Array &
{
   Expects( size_ == other.size_ );
   elements_ = std::move( other.elements_ );
   size_ = std::move( other.size_ );
   return *this;
}

template <class T> inline
nhill::Array<T>::~Array()
{
   delete[] elements_;
   elements_ = nullptr;
   size_ = 0;
}

template <class T> inline
void nhill::Array<T>::fill( const T& value )
{ // assign value to all elements
   for( size_t i{0} ; i < size_ ; ++i )
   {
      elements_[i] = value;
   }
}

template <class T> inline
void nhill::Array<T>::swap( Array& other )
{ // swap contents with other
   Expects( size_ == other.size_ );
   _Swap_ranges_unchecked( elements_, elements_ + size_, other.elements_ );
}

template <class T> inline
auto nhill::Array<T>::begin() noexcept->iterator
{ // return iterator for beginning of mutable sequence
   return iterator{elements_, size_, 0};
}

template <class T> inline
auto nhill::Array<T>::begin() const noexcept->const_iterator
{ // return iterator for beginning of nonmutable sequence
   return const_iterator{elements_, size_, 0};
}

template <class T> inline
auto nhill::Array<T>::end() noexcept->iterator
{ // return iterator for end of mutable sequence
   return iterator{elements_, size_, size_};
}

template <class T> inline
auto nhill::Array<T>::end() const noexcept->const_iterator
{ // return iterator for beginning of nonmutable sequence
   return const_iterator{elements_, size_, size_};
}

template <class T> inline
auto nhill::Array<T>::rbegin() noexcept->reverse_iterator
{ // return iterator for beginning of reversed mutable sequence
   return reverse_iterator{end()};
}

template <class T> inline
auto nhill::Array<T>::rbegin() const noexcept->const_reverse_iterator
{ // return iterator for beginning of reversed nonmutable sequence
   return const_reverse_iterator{end()};
}

template <class T> inline
auto nhill::Array<T>::rend() noexcept->reverse_iterator
{ // return iterator for end of reversed mutable sequence
   return reverse_iterator{begin()};
}

template <class T> inline
auto nhill::Array<T>::rend() const noexcept->const_reverse_iterator
{ // return iterator for end of reversed nonmutable sequence
   return const_reverse_iterator{begin()};
}

template <class T> inline
auto nhill::Array<T>::cbegin() const noexcept->const_iterator
{ // return iterator for beginning of nonmutable sequence
   return begin();
}

template <class T> inline
auto nhill::Array<T>::cend() const noexcept->const_iterator
{ // return iterator for end of nonmutable sequence
   return end();
}

template <class T> inline
auto nhill::Array<T>::crbegin() const noexcept->const_reverse_iterator
{ // return iterator for beginning of reversed nonmutable sequence
   return rbegin();
}

template <class T> inline
auto nhill::Array<T>::crend() const noexcept->const_reverse_iterator
{ // return iterator for end of reversed nonmutable sequence
   return rend();
}

template <class T> inline
auto nhill::Array<T>::unchecked_begin() noexcept->T*
{ // return plain pointer to beginning of mutable sequence
   return elements_;
}

template <class T> inline
auto nhill::Array<T>::unchecked_begin() const noexcept->const T*
{ // return plain pointer to beginning of nonmutable sequence
   return elements_;
}

template <class T> inline
auto nhill::Array<T>::unchecked_end() noexcept->T*
{ // return plain pointer to end of mutable sequence
   return elements_ + size_;
}

template <class T> inline
auto nhill::Array<T>::unchecked_end() const noexcept->const T*
{ // return plain pointer to end of nonmutable sequence
   return elements_ + size_;
}

template <class T> inline
auto nhill::Array<T>::size() const noexcept->size_type
{ // return length of sequence
   return size_;
}

template <class T> inline
auto nhill::Array<T>::max_size() const noexcept->size_type
{ // return maximum possible length of sequence
   return size_;
}

template <class T> inline
auto nhill::Array<T>::empty() const noexcept->bool
{ // test if sequence is empty
   return false;
}

template <class T> inline 
auto nhill::Array<T>::at( size_type pos )->reference
{ // subscript mutable sequence with checking
   if( size_ <= pos )
   {
      range_exception( pos );
   }

   return elements_[pos];
}

template <class T> inline
auto nhill::Array<T>::at( size_type pos ) const->const_reference
{ // subscript nonmutable sequence with checking
   if( size_ <= pos )
   {
      range_exception( pos );
   }

   return elements_[pos];
}

template <class T> inline
auto nhill::Array<T>::operator[]( size_type pos ) noexcept->reference
{ // strengthened
   //subscript mutable sequence
   #if _ITERATOR_DEBUG_LEVEL != 0
   _STL_VERIFY( pos < size_, "array subscript out of range" );
   #endif // _ITERATOR_DEBUG_LEVEL != 0

   return elements_[pos];
}

template <class T> inline
auto nhill::Array<T>::operator[]( size_type pos ) const noexcept->const_reference
{ // strengthened
   // subscript nonmutable sequence
   #if _ITERATOR_DEBUG_LEVEL != 0
   _STL_VERIFY( pos < size_, "array subscript out of range" );
   #endif // _ITERATOR_DEBUG_LEVEL != 0

   return elements_[pos];
}

template <class T> inline
auto nhill::Array<T>::front() noexcept->reference
{ // strengthened
   // return first element of mutable sequence
   return elements_[0];
}

template <class T> inline
auto nhill::Array<T>::front() const noexcept->const_reference
{ // strengthened
   // return first element of nonmutable sequence
   return elements_[0];
}

template <class T> inline
auto nhill::Array<T>::back() noexcept->reference
{ // strengthened
   //return last element of mutable sequence
   return elements_[size_ - 1];
}

template <class T> inline
auto nhill::Array<T>::back() const noexcept->const_reference
{ // strengthened
   // return last element of nonmutable sequence
   return elements_[size_ - 1];
}

template <class T> inline
auto nhill::Array<T>::data() noexcept->T*
{ // return pointer to mutable data array
   return elements_;
}

template <class T> inline
auto nhill::Array<T>::data() const noexcept->const T*
{ // return pointer to nonmutable data array
   return elements_;
}

template <class T> inline
void nhill::Array<T>::range_exception( size_t pos ) const
{ // report an out_of_range error
   std::out_of_range( "Invalid Array<T> subscript: " + std::to_string(pos) + " is out of range [0, " + std::to_string(size_) + ")." );
}

