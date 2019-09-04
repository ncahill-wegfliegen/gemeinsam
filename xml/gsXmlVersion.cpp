#include "gsXmlVersion.h"
#include "gsXmlUtility.h"
#include "gsXmlIO.h"
#include "gs/path.h"
#include "gs/str/utf.h"
#include "gs/lf/Util.h"

namespace gs
{
namespace xml
{

static const tchar* elementNameDefault = SL( "Version" );

tinyxml2::XMLError write( const std::tstring& path, const gs::versn::Version& version )
{
    tinyxml2::XMLError error = gs::xml::is_valid_path( path );
    if( error != tinyxml2::XML_NO_ERROR )
    {
        LogError( std::tstring( SL( "Invalid path=" ) ) + path );
        return error;
    }

    tinyxml2::XMLDocument doc;

    doc.LinkEndChild( gs::xml::make_declaration( doc ) );
    doc.LinkEndChild( make_element( doc, version ) );

    error = doc.SaveFile( str::utf8( path ).c_str() );
    return error;
}

tinyxml2::XMLError read( gs::versn::Version& version, const std::tstring& path )
{
    std::tstring rootName = elementNameDefault;

    tinyxml2::XMLDocument doc;
    tinyxml2::XMLError error = gs::xml::make_document( doc, path );
    if( error != tinyxml2::XML_NO_ERROR )
        return error;

    tinyxml2::XMLHandle hRoot = gs::xml::make_root_handle( doc, rootName );
    error = from_handle( version, hRoot );
    if( error != tinyxml2::XML_NO_ERROR )
        LogError( std::tstring( SL( "Failed to extract the Object " ) ) + rootName );

    return error;
}

tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::versn::Version& version, const std::tstring& elementName /*= SL( "" )*/ )
{
    std::tstring elementNameLocal = elementName;
    if( elementNameLocal.empty() )
        elementNameLocal = elementNameDefault;

    tinyxml2::XMLElement* element = doc.NewElement( str::utf8( elementNameLocal ).c_str() );

    tinyxml2::XMLElement* child = nullptr;

    child = gs::xml::make_element( doc, version.Major, SL( "Major" ) );
    element->LinkEndChild( child );

    child = gs::xml::make_element( doc, version.Minor, SL( "Minor" ) );
    element->LinkEndChild( child );

    child = gs::xml::make_element( doc, version.Build, SL( "Build" ) );
    element->LinkEndChild( child );

    child = gs::xml::make_element( doc, version.Revision, SL( "Revision" ) );
    element->LinkEndChild( child );


    return element;
}

tinyxml2::XMLError from_handle( gs::versn::Version& version, tinyxml2::XMLHandle handle )
{
    tinyxml2::XMLError retrn = tinyxml2::XML_NO_ERROR;
    tinyxml2::XMLError error = tinyxml2::XML_NO_ERROR;

    int value;
    error = gs::xml::from_parent_handle( value, handle, SL( "Major" ) );
    if( error == tinyxml2::XML_NO_ERROR )
        version.Major = value;
    else
        retrn = error;

    error = gs::xml::from_parent_handle( value, handle, SL( "Minor" ) );
    if( error == tinyxml2::XML_NO_ERROR )
        version.Minor = value;
    else
        retrn = error;

    error = gs::xml::from_parent_handle( value, handle, SL( "Build" ) );
    if( error == tinyxml2::XML_NO_ERROR )
        version.Build = value;
    else
        retrn = error;

    error = gs::xml::from_parent_handle( value, handle, SL( "Revision" ) );
    if( error == tinyxml2::XML_NO_ERROR )
        version.Revision = value;
    else
        retrn = error;


    return retrn;
}

tinyxml2::XMLError from_parent_handle( gs::versn::Version& version, tinyxml2::XMLHandle hParent, const std::tstring& childName /*= SL( "" )*/ )
{
    // If no name is provided, then just use the class name as the element name.
    std::tstring elementName = childName;
    if( elementName.empty() )
        elementName = type::ToName( version );

    tinyxml2::XMLHandle handle = hParent.FirstChildElement( str::utf8( elementName ).c_str() );

    return from_handle( version, handle );
}


}
}
