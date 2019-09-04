#include "gsXmlUwiKeyCollection.h"
#include "gsXmlUwiKey.h"
#include "gsXmlUtility.h"
#include "gsXmlIO.h"
#include "gs/path.h"
#include "gs/str/utf.h"
#include "gs/lf/Util.h"

namespace gs
{
namespace xml
{

static const tchar* elementNameDefault = SL( "UwiKeyCollection" );

tinyxml2::XMLError write( const std::tstring& path, const std::vector<gs::uwi::key>& keyCollection )
{
    tinyxml2::XMLError error = gs::xml::is_valid_path( path );
    if( error != tinyxml2::XML_NO_ERROR )
    {
        LogError( std::tstring( SL( "Invalid path=" ) ) + path );
        return error;
    }

    tinyxml2::XMLDocument doc;

    doc.LinkEndChild( gs::xml::make_declaration( doc ) );
    doc.LinkEndChild( make_element( doc, keyCollection ) );

    error = doc.SaveFile( str::utf8( path ).c_str() );
    return error;
}

tinyxml2::XMLError read( std::vector<gs::uwi::key>& keyCollection, const std::tstring& path )
{
    std::tstring rootName = elementNameDefault;

    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError error = gs::xml::make_document( doc, path );
    if( error != tinyxml2::XML_NO_ERROR )
        return error;

    tinyxml2::XMLHandle hRoot = gs::xml::make_root_handle( doc, rootName );
    error = from_handle( keyCollection, hRoot );
    if( error != tinyxml2::XML_NO_ERROR )
        LogError( std::tstring( SL( "Failed to extract the Object " ) ) + rootName );

    return error;
}

tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const std::vector<gs::uwi::key>& keyCollection, const std::tstring& elementName /*= SL( "" )*/ )
{
    std::tstring elementNameLocal = elementName;
    if( elementNameLocal.empty() )
        elementNameLocal = elementNameDefault;

    tinyxml2::XMLElement* element = doc.NewElement( str::utf8( elementNameLocal ).c_str() );

    tinyxml2::XMLElement* child = nullptr;
    for( const gs::uwi::key& key : keyCollection )
    {
        child = gs::xml::make_element( doc, key );
        element->LinkEndChild( child );
    }


    return element;
}

tinyxml2::XMLError from_handle( std::vector<gs::uwi::key>& keyCollection, tinyxml2::XMLHandle handle )
{
    keyCollection.clear();
    tinyxml2::XMLError retrn = tinyxml2::XML_NO_ERROR;
    tinyxml2::XMLError error = tinyxml2::XML_NO_ERROR;


    for( tinyxml2::XMLNode* node = handle.FirstChild().ToElement(); node != nullptr; node = node->NextSibling() )
    {
        gs::uwi::key key;
        error = from_handle( key, node );
        if( error == tinyxml2::XML_NO_ERROR )
            keyCollection.push_back( key );
        else
            retrn = error;
    }

    return retrn;
}

tinyxml2::XMLError from_parent_handle( std::vector<gs::uwi::key>& keyCollection, tinyxml2::XMLHandle hParent, const std::tstring& childName /*= SL( "" )*/ )
{
    // If no name is provided, then just use the class name as the element name.
    std::tstring elementName = childName;
    if( elementName.empty() )
        elementName = type::ToName( keyCollection );

    tinyxml2::XMLHandle handle = hParent.FirstChildElement( str::utf8( elementName ).c_str() );

    return from_handle( keyCollection, handle );
}


}
}
