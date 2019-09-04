#pragma once

#include "gsXmlPort.h"
#include "gs/bll/overlay/Layer.h"
#include "tixml/tixml2.h"
#include "gs/tstring.h"
#include <vector>


namespace gs
{
namespace xml
{
gsXmlPortFunction tinyxml2::XMLError write( const std::tstring& path, const gs::overlay::Layer& layer );
gsXmlPortFunction tinyxml2::XMLError read( gs::overlay::Layer& layer, const std::tstring& path );
gsXmlPortFunction tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::overlay::Layer& layer, const std::tstring& elementName = SL( "" ) );
gsXmlPortFunction tinyxml2::XMLError from_handle( gs::overlay::Layer& layer, tinyxml2::XMLHandle handle );
gsXmlPortFunction tinyxml2::XMLError from_parent_handle( gs::overlay::Layer& layer, tinyxml2::XMLHandle hParent, const std::tstring& childName = SL( "" ) );
}
}
