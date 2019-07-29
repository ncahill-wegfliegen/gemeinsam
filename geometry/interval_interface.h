#pragma once

#include "..\math\compare.h"
#include <sstream>
#include <vector>

namespace nhill
{
namespace geometry
{

/// <summary>The base class for intervals.</summary>
/// <remarks>The template parameter 'T' is the type of the interval.</remarks>
template<typename T>
class Interval_interface
{
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type (i.e., either integral or floating point type).");

public:
#pragma region Aliases   
   using value_type = T; // Interval type
   using ref = Interval_interface<T> &;
   using cref = const Interval_interface<T> &;
   using ptr = Interval_interface<T> *;
   using cptr = const Interval_interface<T>*;
   using uptr = std::unique_ptr<Interval_interface<T>>;
#pragma endregion

#pragma region Constructors, Assignments, Destructor
   Interval_interface( const Interval_interface& );
   Interval_interface& operator=( const Interval_interface& );

   Interval_interface( Interval_interface&& );
   Interval_interface& operator=( Interval_interface&& );

   virtual ~Interval_interface();
#pragma endregion

#pragma region Properties
   /// <summary>Get the first point of the interval (must be less than or equal to the second point).</summary>
   virtual T a() const = 0;
   /// <summary>Get the second point of the interval (must be greater than or equal to the first point).</summary>
   virtual T b() const = 0;
#pragma endregion

#pragma region Methods
   virtual void set( T a, T b ) = 0;
   virtual bool is_valid( T value ) const = 0;

   /// <summary>Is this an empty interval?</summary>
   /// <returns>True if the first point, 'a', is equal to the second point, 'b'.<para>False if the first point, 'a', is not equal to the second point, 'b'.</para></returns>
   bool is_empty() const;

   /// <summary>The end points of the interval are valid if <paramref name="a"/> is less than or equal to <paramref name="b"/>.</summary>
   /// <param name="a">The lower end point of the interval.</param>
   /// <param name="b">The upper end point of the interval.</param>
   /// <returns>True if the lower end point, <paramref name="a"/>, is less than or equal to the upper end point, <paramref name="b"/>; otherwise, false.</returns>
   static bool is_valid( T a, T b );
#pragma endregion

protected:
   Interval_interface();
   static void validate( T a, T b );
};

}
}


#pragma region Aliases
namespace nhill
{
namespace geometry
{




template<typename T>
using Interval_interface_cptr_pair = std::pair<typename Interval_interface<T>::cptr, typename Interval_interface<T>::cptr>;

template<typename T>
using Interval_interface_cref_pair = std::pair<typename Interval_interface<T>::cref, typename Interval_interface<T>::cref>;

template<typename T>
using Interval_interface_uptr_pair = std::pair<typename Interval_interface<T>::uptr, typename Interval_interface<T>::uptr>;



template<typename T>
auto interval1( const Interval_interface_cptr_pair<T>& pair )->typename Interval_interface<T>::cptr
{
   return pair.first;
}

template<typename T>
auto interval2( const Interval_interface_cptr_pair<T>& pair ) -> typename Interval_interface<T>::cptr
{
   return pair.second;
}

template<typename T>
auto interval1( const Interval_interface_cref_pair<T>& pair )->typename Interval_interface<T>::cref
{
   return pair.first;
}

template<typename T>
auto interval2( const Interval_interface_cref_pair<T>& pair ) -> typename Interval_interface<T>::cref
{
   return pair.second;
}


template<typename T>
using Interval_interface_ptr_container = std::vector< typename Interval_interface<T>::ptr >;

template<typename T>
using Interval_interface_cptr_container = std::vector< typename Interval_interface<T>::cptr >;

template<typename T>
using Interval_interface_uptr_container = std::vector< typename Interval_interface<T>::uptr >;


}
}
#pragma endregion


#pragma region Definitions
template<typename T> inline
nhill::geometry::Interval_interface<T>::Interval_interface() = default;

template<typename T> inline
nhill::geometry::Interval_interface<T>::Interval_interface( const Interval_interface& ) = default;

template<typename T> inline
auto nhill::geometry::Interval_interface<T>::operator=( const Interval_interface& ) ->Interval_interface & = default;

template<typename T> inline
nhill::geometry::Interval_interface<T>::Interval_interface( Interval_interface&& ) = default;

template<typename T> inline
auto nhill::geometry::Interval_interface<T>::operator=( Interval_interface&& )->Interval_interface & = default;

template<typename T> inline
nhill::geometry::Interval_interface<T>::~Interval_interface() = default;

template<typename T> inline
bool nhill::geometry::Interval_interface<T>::is_valid( T a, T b )
{
   return nhill::math::less_or_equal<T, T>( a, b);
}

template<typename T> inline 
bool nhill::geometry::Interval_interface<T>::is_empty() const
{
   return nhill::math::equal<T,T>( a(), b() );
}

template<typename T> inline
void nhill::geometry::Interval_interface<T>::validate( T a, T b )
{
   if (!is_valid( a, b ))
   {
      std::ostringstream msg;
      msg << "File: " << __FILE__ << ". Function: " << __func__ << ". Line: " << __LINE__ << ". Message: Invalid interval (a,b)=(" << a << ", " << b << "). Condition: 'a' must be less than or equal to 'b'.";
      throw std::logic_error( msg.str() );
   }
}
#pragma endregion