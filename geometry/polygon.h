#pragma once

#include "pnt.h"
#include <vector>
#include <initializer_list>

namespace nhill
{
namespace geometry
{

template<typename T>
class Polygon : public std::vector<Pnt<T>>
{
   static_assert(std::is_arithmetic_v<T>, "The template parameter must be an arithmetic type (i.e., either integral or floating point type).");

public:
   using value_type = T;
   using Pnt = Pnt<T>;
   using base = std::vector<Pnt>;

   Polygon();

   Polygon( std::initializer_list<Pnt> );
   Polygon& operator=( std::initializer_list<Pnt> );

   Polygon( const Polygon& );
   Polygon& operator=( const Polygon& );

   Polygon( Polygon&& );
   Polygon& operator=( Polygon&& );

   ~Polygon();
};

}
}

#pragma region Methods
namespace nhill
{
namespace geometry
{

template<typename T>
bool is_closed( const Polygon<T>& polygon )
{
   using namespace nhill::math;

   if( polygon.size() < 2 )
   {
      return true;
   }
   else
   {
      return polygon.back() == polygon.front();
   }
}

template<typename T>
void close( Polygon<T>& polygon )
{
   if( !is_closed( polygon ) )
   {
      polygon.push_back( polygon.front() );
   }
}

}
}
#pragma endregion


#pragma region Definitions
template<typename T> inline 
nhill::geometry::Polygon<T>::Polygon()
{
}

template<typename T>
inline nhill::geometry::Polygon<T>::Polygon( std::initializer_list<Pnt> init_list )
   : base{init_list}
{
}

template<typename T> inline 
auto nhill::geometry::Polygon<T>::operator=( std::initializer_list<Pnt> init_list )->Polygon &
{
   base::operator=( init_list );
   return *this;
}

template<typename T> inline
nhill::geometry::Polygon<T>::Polygon( const Polygon& ) = default;

template<typename T> inline
auto nhill::geometry::Polygon<T>::operator=( const Polygon& )->Polygon & = default;

template<typename T> inline
nhill::geometry::Polygon<T>::Polygon( Polygon&& ) = default;

template<typename T> inline
auto nhill::geometry::Polygon<T>::operator=( Polygon&& )->Polygon & = default;

template<typename T> inline
nhill::geometry::Polygon<T>::~Polygon() = default;
#pragma endregion