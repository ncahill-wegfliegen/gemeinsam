#include "gsXmlFileGridInfo.h"
#include "gsXmlFileParameters.h"
#include "gsXmlUtility.h"
#include "gsXmlIO.h"
#include "gs/path.h"
#include "gs/str/utf.h"
#include "gs/lf/Util.h"

namespace gs
{
namespace xml
{

static const tchar* elementNameDefault = SL( "FileGridInfoParameters" );

tinyxml2::XMLError write( const std::tstring& path, const gs::file::GridInfo& param )
{
    tinyxml2::XMLError error = gs::xml::is_valid_path( path );
    if( error != tinyxml2::XML_NO_ERROR )
    {
        LogError( std::tstring( SL( "Invalid path=" ) ) + path );
        return error;
    }

    tinyxml2::XMLDocument doc;

    doc.LinkEndChild( gs::xml::make_declaration( doc ) );
    doc.LinkEndChild( make_element( doc, param ) );

    error = doc.SaveFile( str::utf8( path ).c_str() );
    return error;
}

tinyxml2::XMLError read( gs::file::GridInfo& param, const std::tstring& path )
{
    std::tstring rootName = elementNameDefault;

    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError error = gs::xml::make_document( doc, path );
    if( error != tinyxml2::XML_NO_ERROR )
        return error;

    tinyxml2::XMLHandle hRoot = gs::xml::make_root_handle( doc, rootName );
    error = from_handle( param, hRoot );
    if( error != tinyxml2::XML_NO_ERROR )
        LogError( std::tstring( SL( "Failed to extract the Object " ) ) + rootName );

    return error;
}

tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::file::GridInfo& param, const std::tstring& elementName /*= SL( "" )*/ )
{
    std::tstring elementNameLocal = elementName;
    if( elementNameLocal.empty() )
        elementNameLocal = elementNameDefault;

    tinyxml2::XMLElement* element = doc.NewElement( str::utf8( elementNameLocal ).c_str() );

    //tinyxml2::XMLElement* child = nullptr;

    //child = gs::xml::make_element( doc, param.Path, SL( "RowFirst" ) );
    //element->LinkEndChild( child );


    return element;
}

tinyxml2::XMLError from_handle( gs::file::GridInfo& param, tinyxml2::XMLHandle handle )
{
    tinyxml2::XMLError retrn = tinyxml2::XML_NO_ERROR;
    tinyxml2::XMLError error = tinyxml2::XML_NO_ERROR;

    //int rowFirst;
    //error = gs::xml::from_parent_handle( rowFirst, handle, SL( "RowFirst" ) );
    //if( error == tinyxml2::XML_NO_ERROR )
    //    param.RowFirst = rowFirst;
    //else
    //    retrn = error;


    return retrn;
}

tinyxml2::XMLError from_parent_handle( gs::file::GridInfo& param, tinyxml2::XMLHandle hParent, const std::tstring& childName /*= SL( "" )*/ )
{
    // If no name is provided, then just use the class name as the element name.
    std::tstring elementName = childName;
    if( elementName.empty() )
        elementName = type::ToName( param );

    tinyxml2::XMLHandle handle = hParent.FirstChildElement( str::utf8( elementName ).c_str() );

    return from_handle( param, handle );
}


}
}
