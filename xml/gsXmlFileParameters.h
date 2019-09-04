#pragma once

#include "gsXmlPort.h"
#include "gs/bll/file/Parameters.h"
#include "tixml/tixml2.h"
#include "gs/tstring.h"
#include <memory>


namespace gs
{
namespace xml
{
gsXmlPortFunction tinyxml2::XMLError write( const std::tstring& path, const gs::file::Parameters& param );
gsXmlPortFunction tinyxml2::XMLError read( std::unique_ptr<gs::file::Parameters>& param, const std::tstring& path );
gsXmlPortFunction tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::file::Parameters& param, const std::tstring& elementName = SL( "" ) );
gsXmlPortFunction tinyxml2::XMLError from_handle( std::unique_ptr<gs::file::Parameters>& param, tinyxml2::XMLHandle handle );
gsXmlPortFunction tinyxml2::XMLError from_parent_handle( std::unique_ptr<gs::file::Parameters>& param, tinyxml2::XMLHandle hParent, const std::tstring& childName = SL( "" ) );
}
}
