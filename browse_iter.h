#pragma once

#include "browse.h"
#include <vector>

namespace nhill
{

/// <summary>A container view that allows you to browse any container that implements either a random-access (e.g., vector, deque, and array) or bidrectional (e.g., forward_list and list) iterator.</summary>
template<typename T, typename Iterator, typename std::enable_if_t<std::is_base_of<std::bidirectional_iterator_tag, typename Iterator::iterator_category>::value>* = nullptr>
class Browse_iter : public Browse<T>
{
public:
   using iterator = Iterator;
   using base = Browse<T>;

   Browse_iter( iterator begin,  iterator end );
   Browse_iter( const Browse_iter& ) = delete;
   Browse_iter& operator=( const Browse_iter& ) = delete;
   Browse_iter( Browse_iter&& ) = delete;
   Browse_iter& operator=( Browse_iter&& ) = delete;
   virtual ~Browse_iter();

   virtual typename base::reference first   () override;
   virtual typename base::reference previous() override;
   virtual typename base::reference next    () override;
   virtual typename base::reference last    () override;

   virtual typename base::const_reference cfirst   () const override;
   virtual typename base::const_reference cprevious() const override;
   virtual typename base::const_reference cnext    () const override;
   virtual typename base::const_reference clast    () const override;

   bool is_first() const override;
   bool is_last () const override;

private:
     const iterator first_;
     const iterator last_;
   mutable iterator current_;
};

}

#pragma region Definitions
template<typename Value_base, typename Iterator, typename std::enable_if_t<std::is_base_of<std::bidirectional_iterator_tag, typename Iterator::iterator_category>::value >* ef> inline
nhill::Browse_iter<Value_base, Iterator, ef>::Browse_iter(  iterator begin,  iterator end )
   : first_{ begin }
   , last_{ --end }
   , current_{ begin }
{
}

template<typename Value_base, typename Iterator, typename std::enable_if_t<std::is_base_of<std::bidirectional_iterator_tag, typename Iterator::iterator_category>::value >* ef> inline
nhill::Browse_iter<Value_base, Iterator, ef>::~Browse_iter() = default;

template<typename Value_base, typename Iterator, typename std::enable_if_t<std::is_base_of<std::bidirectional_iterator_tag, typename Iterator::iterator_category>::value >* ef> inline
auto nhill::Browse_iter<Value_base, Iterator, ef>::first() ->typename base::reference
{
   current_ = first_;
   return *first_;
}

template<typename Value_base, typename Iterator, typename std::enable_if_t<std::is_base_of<std::bidirectional_iterator_tag, typename Iterator::iterator_category>::value >* ef> inline
auto nhill::Browse_iter<Value_base, Iterator, ef>::previous() ->typename base::reference
{
   if( current_ != first_ )
   {
      --current_;
   }
   return *current_;
}

template<typename Value_base, typename Iterator, typename std::enable_if_t<std::is_base_of<std::bidirectional_iterator_tag, typename Iterator::iterator_category>::value >* ef> inline
auto nhill::Browse_iter<Value_base, Iterator, ef>::next() ->typename base::reference
{
   if( current_ != last_ )
   {
      ++current_;
   }
   return *current_;
}

template<typename Value_base, typename Iterator, typename std::enable_if_t<std::is_base_of<std::bidirectional_iterator_tag, typename Iterator::iterator_category>::value >* ef> inline
auto nhill::Browse_iter<Value_base, Iterator, ef>::last() ->typename base::reference
{
   current_ = last_;
   return *last_;
}

template<typename Value_base, typename Iterator, typename std::enable_if_t<std::is_base_of<std::bidirectional_iterator_tag, typename Iterator::iterator_category>::value >* ef> inline
auto nhill::Browse_iter<Value_base, Iterator, ef>::cfirst() const ->typename base::const_reference
{
   current_ = first_;
   return *first_;
}

template<typename Value_base, typename Iterator, typename std::enable_if_t<std::is_base_of<std::bidirectional_iterator_tag, typename Iterator::iterator_category>::value >* ef> inline
auto nhill::Browse_iter<Value_base, Iterator, ef>::cprevious() const ->typename base::const_reference
{
   if( current_ != first_ )
   {
      --current_;
   }
   return *current_;
}

template<typename Value_base, typename Iterator, typename std::enable_if_t<std::is_base_of<std::bidirectional_iterator_tag, typename Iterator::iterator_category>::value >* ef> inline
auto nhill::Browse_iter<Value_base, Iterator, ef>::cnext() const ->typename base::const_reference
{
   if( current_ != last_ )
   {
      ++current_;
   }
   return *current_;
}

template<typename Value_base, typename Iterator, typename std::enable_if_t<std::is_base_of<std::bidirectional_iterator_tag, typename Iterator::iterator_category>::value >* ef> inline
auto nhill::Browse_iter<Value_base, Iterator, ef>::clast() const ->typename base::const_reference
{
   current_ = last_;
   return *last_;
}

template<typename Value_base, typename Iterator, typename std::enable_if_t<std::is_base_of<std::bidirectional_iterator_tag, typename Iterator::iterator_category>::value >* ef> inline
bool nhill::Browse_iter<Value_base, Iterator, ef>::is_first() const
{
   return current_ == first_;
}

template<typename Value_base, typename Iterator, typename std::enable_if_t<std::is_base_of<std::bidirectional_iterator_tag, typename Iterator::iterator_category>::value >* ef> inline
bool nhill::Browse_iter<Value_base, Iterator, ef>::is_last() const
{
   return current_ == last_;
}
#pragma endregion
