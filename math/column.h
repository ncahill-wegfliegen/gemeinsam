#pragma once

#include "array.h"

namespace nhill
{
namespace math
{

template<typename T, typename enable_if::is_math_type<T>* = nullptr>
using Column = Array<T>;

}
}
