#pragma once

#include "int.h"
#include <type_traits>

namespace nhill
{

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
Enum increment( Enum e, Enum end = Enum::end )
{
   int ie = to_int( e );
   return ( ie >= to_int( end ) - 1 ) ? Enum::end : to_enum<Enum>(ie + 1 );
}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
Enum decrement( Enum e, Enum begin = Enum::begin )
{
   int ie = to_int( e );
   return ( ie <= to_int( begin ) ) ? Enum::end : to_enum<Enum>( ie - 1 );
}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
Enum cycle_increment( Enum e, Enum begin = Enum::begin, Enum end = Enum::end )
{
   Enum next = increment( e, end );
   return (next == Enum::end) ? begin : next;
}

template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
Enum cycle_decrement( Enum e, Enum begin = Enum::begin, Enum end = Enum::end )
{
   Enum previous = decrement( e, begin );
   return (previous == Enum::end) ? decrement( end ) : previous;
}

/// <summary>Pre-increment, ++e. Increments the value of the object and returns a reference to the result.</summary>
template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
Enum& operator++( Enum& e )
{
   e = increment( e );
   return e;
}

/// <summary>Pre-decrement, --e. Decrements the value of the object and returns a reference to the result.</summary>
template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
Enum& operator--( Enum& e )
{
   e = decrement( e );
   return e;
}

/// <summary>Post-increment, e++. Creates a copy of the object, increments the value of the object and returns the copy from before the increment.</summary>
template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
Enum operator++( Enum& e, int )
{
   Enum tmp{ e };
   ++e;
   return tmp;
}

/// <summary>Post-decrement, e--. Creates a copy of the object, decrements the value of the object and returns the copy from before the decrement.</summary>
template<typename Enum, std::enable_if_t<std::is_enum_v<Enum>>* = nullptr>
Enum operator--( Enum& e, int )
{
   Enum tmp{ e };
   --e;
   return tmp;
}

}
