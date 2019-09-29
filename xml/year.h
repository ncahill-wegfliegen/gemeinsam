#pragma once

#include "port.h"
#include "core/make_element.h"
#include "core/from_handle.h"
#include "core/from_parent_handle.h"
#include "core/read.h"
#include "core/write.h"
#include "../date_time/year.h"

namespace nhill
{
namespace xml
{

template<> NHILL_XML_PORT_FUNCTION
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const nhill::Year& year, std::string element_name );

template<> NHILL_XML_PORT_FUNCTION
tinyxml2::XMLError from_handle( nhill::Year& year, tinyxml2::XMLHandle handle );

}
}