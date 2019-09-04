#pragma once

#include "gsXmlPort.h"
#include "gs/bll/uwi/key.h"
#include "tixml/tixml2.h"
#include "gs/tstring.h"
#include <vector>


namespace gs
{
namespace xml
{
gsXmlPortFunction tinyxml2::XMLError write( const std::tstring& path, const std::vector<gs::uwi::key>& keyCollection );
gsXmlPortFunction tinyxml2::XMLError read( std::vector<gs::uwi::key>& keyCollection, const std::tstring& path );
gsXmlPortFunction tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const std::vector<gs::uwi::key>& keyCollection, const std::tstring& elementName = SL( "" ) );
gsXmlPortFunction tinyxml2::XMLError from_handle( std::vector<gs::uwi::key>& keyCollection, tinyxml2::XMLHandle handle );
gsXmlPortFunction tinyxml2::XMLError from_parent_handle( std::vector<gs::uwi::key>& keyCollection, tinyxml2::XMLHandle hParent, const std::tstring& childName = SL( "" ) );
}
}
