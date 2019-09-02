#pragma once

#include "int.h"
#include <iterator>
#include <type_traits>

namespace nhill
{

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
Enum begin()
{
	throw std::exception( "Not implemented.  Must be specialed for each enumeration." );
}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
Enum end()
{
	throw std::exception( "Not implemented.  Must be specialed for each enumeration." );
}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
/// <summary>The enumeration collection allows iteration over strongly typed enumerations.
/// <para>The enumeration values must be continuous.</para>
/// </summary>
/// <example>This example shows how to use the values class to iterate over all of the values in the nhill::Area enumeration:
///     <code>
///         for( auto area : nhill::Values&lt;nhill::Area&gt;( nhill::Area::none ) )
///         {
///             ...
///         }
///     </code>
/// </example>
class Values
{
public:
   /// <summary>Iterate over all of the enumeration values from the beginning.</summary>
   Values()
      : start_at( nhill::begin<Enum>() )
   {
   }
   /// <summary>Iterate over all of the enumeration values starting after the given enumeration Value.</summary>
   /// <param name="start_after">Start the iteration at the first Value after the given enumeration Value.</param>
   Values( Enum start_after )
   {
      int i = nhill::to_int( start_after );
      i++;
      start_at = nhill::to_enum<Enum>( i );
   }
   ~Values()
   {
   }

#pragma region iteration
public:
   class iterator : public std::iterator < std::input_iterator_tag, Enum >
   {
   public:
      iterator( const iterator& rhs ) : e( rhs.e ) {}
      explicit iterator( Enum e ) : e( e ) {}
      ~iterator() {}

   public:
      iterator & operator=( const iterator& rhs ) { e = rhs.e; return *this; }
      friend bool operator==( const iterator& lhs, const iterator& rhs ) { return lhs.e == rhs.e; }
      friend bool operator!=( const iterator& lhs, const iterator& rhs ) { return lhs.e != rhs.e; }
      friend void swap( const iterator& lhs, const iterator& rhs ) { std::swap( lhs.value, rhs.value ); }
      Enum operator*() const { return e; }
      const Enum* operator->()const { return &e; }
      iterator& operator++()
      {
         int i = nhill::to_int( e );
         ++i;
         e = nhill::to_enum<Enum>( i );
         return *this;
      }
      iterator operator++( int )
      {
         iterator itr( *this );
         ++*this;
         return itr;
      }

   private:
      Enum e;
   };

public:
   typename nhill::Values<Enum>::iterator begin() { return typename nhill::Values<Enum>::iterator( start_at  ); }
   typename nhill::Values<Enum>::iterator end()   { return typename nhill::Values<Enum>::iterator( nhill::end<Enum>() ); }
#pragma endregion

private:
   Enum start_at;
};

}
