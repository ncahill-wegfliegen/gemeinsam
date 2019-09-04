#pragma once

#include "gsXmlPort.h"
#include "gs\pnt.h"
#include "gs\tstring.h"
#include "tixml\tixml2.h"


namespace gs
{
namespace xml
{
gsXmlPortFunction tinyxml2::XMLError write( const std::tstring& path, const gs::Pnt& pnt2 );
gsXmlPortFunction tinyxml2::XMLError read( gs::Pnt& pnt2, const std::tstring& path );
gsXmlPortFunction tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::Pnt& pnt2, const std::tstring& elementName = SL( "" ) );
gsXmlPortFunction tinyxml2::XMLError from_handle( gs::Pnt& pnt2, tinyxml2::XMLHandle handle );
gsXmlPortFunction tinyxml2::XMLError from_parent_handle( gs::Pnt& pnt2, tinyxml2::XMLHandle hParent, const std::tstring& childName = SL( "" ) );
}
}
