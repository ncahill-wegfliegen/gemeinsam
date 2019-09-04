#pragma once

#include "port.h"
#include "core/make_element.h"
#include "core/from_handle.h"
#include "core/from_parent_handle.h"
#include "core/read.h"
#include "core/write.h"
#include "../geometry/pnt3.h"

namespace nhill
{
namespace xml
{

template<> GS_XML_PORT_FUNCTION
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const nhill::geometry::Pnt3<>& pnt, std::string element_name );

template<> GS_XML_PORT_FUNCTION
tinyxml2::XMLError from_handle( nhill::geometry::Pnt3<>& pnt, tinyxml2::XMLHandle handle );

}
}