#pragma once

#include <vector>

namespace nhill
{
namespace geometry
{

template<typename T>
struct Rect;

template<typename T = double>
using RectT_container = std::vector<Rect<T>>;

using Rect_container = RectT_container<double>;
using Rectf_container = RectT_container<float>;
using Recti_container = RectT_container<int>;
using Rectu_container = RectT_container<unsigned>;

}
}
