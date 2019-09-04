#pragma once

#include "port.h"
#include "core/make_element.h"
#include "core/from_handle.h"
#include "core/from_parent_handle.h"
#include "core/read.h"
#include "core/write.h"
#include "../geometry/rect.h"

namespace nhill
{
namespace xml
{

template<> GS_XML_PORT_FUNCTION
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const nhill::geometry::Rect<>& rect, std::string element_name );

template<> GS_XML_PORT_FUNCTION
tinyxml2::XMLError from_handle( nhill::geometry::Rect<>& rect, tinyxml2::XMLHandle handle );

}
}