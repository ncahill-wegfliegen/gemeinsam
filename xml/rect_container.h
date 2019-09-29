#pragma once

#include "port.h"
#include "core/make_element.h"
#include "core/from_handle.h"
#include "core/from_parent_handle.h"
#include "core/read.h"
#include "core/write.h"
#include "../geometry/rect_container.h"

namespace nhill
{
namespace xml
{

template<> NHILL_XML_PORT_FUNCTION
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const nhill::geometry::Rect_container& rects, std::string element_name );

template<> NHILL_XML_PORT_FUNCTION
tinyxml2::XMLError from_handle( nhill::geometry::Rect_container& rects, tinyxml2::XMLHandle handle );

}
}