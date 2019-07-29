#pragma once

#include "pnt.h"
#include "polar.h"
#include "vector.h"
#include "vector_polar.h"
#include "convert_vector.h"
#include "convert_pnt.h"

namespace nhill
{
namespace geometry
{

template<typename T>
Pnt<T> operator+( const Pnt<T>& p, const Vector<T>& v )
{
   Pnt<T> tmp{p};
   tmp += v;
   return tmp;
}

template<typename T>
Pnt<T> operator+( const Vector<T>& v, const Pnt<T>& p )
{
   return p + v;
}

template<typename T>
Pnt<T>& operator+=( Pnt<T>& p, const Vector<T>& v )
{
   p.x += v.x();
   p.y += v.y();

   return p;
}



template<typename T>
Polar<T> operator+( const Polar<T>& p, const Vector_polar<T>& v )
{
   Polar<T> tmp{p};
   tmp += v;
   return tmp;
}

template<typename T>
Polar<T> operator+( const Vector_polar<T>& v, const Polar<T>& p )
{
   return p + v;
}

template<typename T>
Polar<T>& operator+=( Polar<T>& p, const Vector_polar<T>& v )
{
   Pnt<T> cp{to_cartesian<T,T>( p )}; // cartesian point
   Vector<T> cv{to_cartesian<T,T>( v )}; // cartesian vector

   p = to_polar<T, T>( cp + cv );

   return p;
}


template<typename T>
Vector<T> operator-( const Pnt<T>& a, const Pnt<T>& b )
{
   Pnt<T> diff{a.x() - b.x(), a.y() - b.y()};
   return {diff.x, diff.y};
}

template<typename T>
Vector_polar<T> operator-( const Polar<T>& a, const Polar<T>& b )
{
   Pnt<T> ca{to_cartesian<T,T>( a )};
   Pnt<T> cb{to_cartesian<T,T>( b )};

   return to_polar<T,T>( ca - cb );
}


}
}
