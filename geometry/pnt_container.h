#pragma once

#include <vector>

namespace nhill
{
namespace geometry
{

template<typename T> 
struct Pnt;

template<typename T>
using Pnt_container = std::vector<Pnt<T>>;

}
}
