#pragma once

#include <vector>

namespace nhill
{
namespace geometry
{

template<typename T>
struct Pnt3;

template<typename T = double>
using Pnt3_container = std::vector<Pnt3<T>>;

}
}
