#pragma once

#include "gsXmlPort.h"
#include "gs/bll/file/Data.h"
#include "tixml/tixml2.h"
#include "gs/tstring.h"


namespace gs
{
namespace xml
{
gsXmlPortFunction tinyxml2::XMLError write( const std::tstring& path, const gs::file::Data& param );
gsXmlPortFunction tinyxml2::XMLError read( gs::file::Data& param, const std::tstring& path );
gsXmlPortFunction tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::file::Data& param, const std::tstring& elementName = SL( "" ) );
gsXmlPortFunction tinyxml2::XMLError from_handle( gs::file::Data& param, tinyxml2::XMLHandle handle );
gsXmlPortFunction tinyxml2::XMLError from_parent_handle( gs::file::Data& param, tinyxml2::XMLHandle hParent, const std::tstring& childName = SL( "" ) );
}
}
