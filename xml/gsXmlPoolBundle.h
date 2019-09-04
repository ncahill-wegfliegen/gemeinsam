#pragma once

#include "gsXmlPort.h"
#include "gs/bll/pool/bundle.h"
#include "gs/tstring.h"
#include "tixml/tixml2.h"


namespace gs
{
namespace xml
{
gsXmlPortFunction tinyxml2::XMLError write( const std::tstring& path, const gs::pool::Bundle& poolBundle);
gsXmlPortFunction tinyxml2::XMLError read( gs::pool::Bundle& poolBundle, const std::tstring& path );
gsXmlPortFunction tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::pool::Bundle& poolBundle, const std::tstring& elementName = SL( "" ) );
gsXmlPortFunction tinyxml2::XMLError from_handle( gs::pool::Bundle& poolBundle, tinyxml2::XMLHandle hPoolBundle );
gsXmlPortFunction tinyxml2::XMLError from_parent_handle( gs::pool::Bundle& poolBundle, tinyxml2::XMLHandle hParent, const std::tstring& childName = SL( "" ) );

}
}

