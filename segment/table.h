#pragma once

#include "segment_types.h"

namespace nhill
{
namespace segment
{

template<typename Id_>
class Table : public Types<Id_>
{
   using Inner_table = std::map<Key, Id_container>;

public:
   Table() noexcept;
   Table( const Table& ) noexcept;
   Table( Table&& ) noexcept;
   ~Table() noexcept;

public:
   Table& operator=( const Table& ) noexcept;
   Table& operator=( Table&& ) noexcept;

public:
   Key find_available_key() const;

   Key add( const Id& id );
   Key add( const Id_container& ids );
   Key add( const Id_container& ids1, const Id_container& ids2 );

   const Id_container& ids( const Key& key ) const;

private:
   Inner_table * table_;
};

}
}

#pragma region Definitions
template<typename Id_> inline 
nhill::segment::Table<Id_>::Table() noexcept
   : table_{ new Inner_table{} }
{
}

template<typename Id_> inline 
nhill::segment::Table<Id_>::Table( const Table & other ) noexcept
   : table_{ new Inner_table{*other.table_} }
{
}

template<typename Id_>
inline nhill::segment::Table<Id_>::Table( Table && other ) noexcept
   : table_{ other.table_ }
{
   other.table_ = nullptr;
}

template<typename Id_>
inline nhill::segment::Table<Id_>::~Table() noexcept
{
   delete table_;
}

template<typename Id_> inline 
auto nhill::segment::Table<Id_>::operator=( const Table & other ) noexcept->Table &
{
   *table_ = *other.table_;

   return *this;
}

template<typename Id_> inline 
auto nhill::segment::Table<Id_>::operator=( Table && other ) noexcept->Table &
{
   delete table_;
   table_ = other.table_;
   other.table_ = nullptr;

   return *this;
}

template<typename Id_> inline
auto nhill::segment::Table<Id_>::find_available_key() const->Key
{
   Key key{ 0 };

   for( ; true ; ++key )
   {
      auto itr = table_->find( key );
      if( itr == table_->end() )
      {
         break;
      }
   }

   return key;
}

template<typename Id_> inline 
auto nhill::segment::Table<Id_>::add( const Id & id )->Key
{
   return add( { {id} } );
}

template<typename Id_> inline
auto nhill::segment::Table<Id_>::add( const Id_container & ids )->Key
{
   Key key{ find_available_key() };
   
   table_->emplace( key, ids );

   return key;
}

template<typename Id_> inline 
auto nhill::segment::Table<Id_>::add( const Id_container & ids1, const Id_container & ids2 )->Key
{
   Key key{ find_available_key() };

   Id_container ids{ ids1 };
   ids.insert( ids.end(), ids2.begin(), ids2.end() );

   table_->emplace( key, ids );

   return key;
}

template<typename Id_> inline 
auto nhill::segment::Table<Id_>::ids( const Key & key ) const->const Id_container &
{
   return table_->at( key );
}

#pragma endregion