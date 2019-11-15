#pragma once

#include "../geometry/pnt.h"
#include "../geometry/pnt_container.h"
#include <vector>
#include <memory>
#include <map>
#include <type_traits>
#include <functional>

namespace nhill
{
namespace segment
{

class Segment_base;
class Segment_indexed;
class Segment_stepped;
template<typename Id_> class Table;

enum class Type { indexed, stepped };

template<typename Derived_segment, std::enable_if<std::is_base_of_v< Segment_base, Derived_segment>>* = nullptr>
using Derived_container = std::vector<Derived_segment>;




//using Stepped_pool = std::vector<Segment_stepped_container>;
//using Stepped_cptr_pool = std::vector<Segment_stepped_cptr>;


using Key = unsigned long;
using Value_container = std::vector<double>;
using Point = nhill::geometry::Pnt<double>;
using Point_container = nhill::geometry::Pnt_container<double>;

template<typename Id_>
struct Types
{
   using Id = Id_;
   using Id_container = std::vector<Id_>;
   using Table = nhill::segment::Table<Id_>;
};

}
}
