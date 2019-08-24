#pragma once

#include <type_traits>

namespace nhill
{

enum class Compare
{
   //none = -3, // Unkown

   //less_or_equal = -2, // Less than or equal to

   less = -1, // Less than
   equal = 0, // Equal to
   greater = 1, // Greater than

   //greater_or_equal = 2, // Greater than or equal to

   // Or if you prefer, you can use the abbreviations
   //xx = none, // Unknown
   //lte = less_or_equal, // Less than or equal to
   lt = less, // Less than
   eq = equal, // Equal to
   gt = greater, // Greater than
   //gte = greater_or_equal, // Greater than or equal to

};

using Cmp = Compare;

//template<typename T> inline
//int compare(T a, T b) noexcept
//{
//   return (a < b) ? -1 : (a > b);
//}

/// <summary>This comparison method must be overriden for every particular type.</summary>
/// <remarks>For arithmetic types, use nhill::math::compare.</remarks>
template<typename T, typename std::enable_if_t<!std::is_arithmetic_v<T>>* = nullptr> inline
Compare compare( T a, T b ) noexcept
{
   return Compare::equal;
}

}
