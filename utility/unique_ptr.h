#pragma once

#include <memory>

namespace nhill
{

template<typename T>
void copy( std::unique_ptr<T>& dst, const std::unique_ptr<T>& src )
{
   if( src == nullptr )
   {
      dst = nullptr;
   }
   else // src is not null
   {
      if( dst == nullptr )
      {
         dst = std::make_unique<T>( *src );
      }
      else // dst is not null
      {
         *dst = *src;
      }
   }
}

template<typename T>
std::unique_ptr<T> copy( const std::unique_ptr<T>& src )
{
   return ( src == nullptr ) ? nullptr : std::make_unique<T>( *src );
}

}