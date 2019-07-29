#pragma once

namespace nhill
{

template<typename T> inline
int compare(T a, T b) noexcept
{
   return (a < b) ? -1 : (a > b);
}

}
