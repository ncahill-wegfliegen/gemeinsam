#pragma once

#include "gsXmlPort.h"
#include "gs/bll/overlay/Group.h"
#include "tixml/tixml2.h"
#include "gs/tstring.h"
#include <vector>


namespace gs
{
namespace xml
{
gsXmlPortFunction tinyxml2::XMLError write( const std::tstring& path, const gs::overlay::Group& group );
gsXmlPortFunction tinyxml2::XMLError read( gs::overlay::Group& group, const std::tstring& path );
gsXmlPortFunction tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::overlay::Group& group, const std::tstring& elementName = SL( "" ) );
gsXmlPortFunction tinyxml2::XMLError from_handle( gs::overlay::Group& group, tinyxml2::XMLHandle handle );
gsXmlPortFunction tinyxml2::XMLError from_parent_handle( gs::overlay::Group& group, tinyxml2::XMLHandle hParent, const std::tstring& childName = SL( "" ) );
}
}
