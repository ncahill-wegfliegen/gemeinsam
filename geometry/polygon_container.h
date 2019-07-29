#pragma once

#include <vector>

namespace nhill
{
namespace geometry
{

template<typename T>
class Polygon;

template<typename T>
using Polygon_container = std::vector<Polygon<T>>;

}
}
