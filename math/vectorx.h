#pragma once

#include "nhill/enable_if.h"
#include <memory>


namespace nhill
{
namespace math
{













template<typename T, typename nhill::enable_if::is_arithmetic_type<T>* = nullptr>
class VectorX
{
public:
   using value_type = T;
   using size_type = size_t;
   using different_type = ptrdiff_t;
   using pointer = T *;
   using const_pointer = const T*;
   using reference = T &;
   using const_reference = const T &;

   Vector

private:
   std::unique_ptr<T[]> elements_;
};

}}
