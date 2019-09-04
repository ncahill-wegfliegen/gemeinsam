#pragma once

#include "gsXmlPort.h"
#include "tixml/tixml2.h"
#include "gs/text/CodeName.h"
#include "gs/tstring.h"

//namespace tinyxml2
//{
//class XMLElement;
//class XMLHandle;
//class XMLDocument;
//enum XMLError;
//}
//
namespace gs
{

namespace xml
{
//gsXmlPortFunction tinyxml2::XMLError write( const std::tstring& path, const gs::CodeName& codeName, const std::tstring& rootName = SL("") );
//gsXmlPortFunction tinyxml2::XMLError read( gs::CodeName& codeName, const std::tstring& path, const std::tstring& rootName = SL( "" ) );
gsXmlPortFunction tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::CodeName& codeName, const std::tstring& elementName = SL( "" ) );
gsXmlPortFunction tinyxml2::XMLError from_handle( gs::CodeName& codeName, tinyxml2::XMLHandle hCodeName );
//gsXmlPortFunction tinyxml2::XMLError from_parent_handle( gs::CodeName& codeName, tinyxml2::XMLHandle hParent, const std::tstring& childName = SL( "" ) );
}
}

