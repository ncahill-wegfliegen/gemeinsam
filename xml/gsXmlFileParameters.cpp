#include "gsXmlFileParameters.h"
#include "gsXmlFileData.h"
#include "gsXmlFileSurferGrid.h"
#include "gsXmlFileGridInfo.h"
#include "gsXmlFileGridInfoBlank.h"
#include "gsXmlText.h"
#include "gsXmlUtility.h"
#include "gsXmlIO.h"
#include "gs/enum/file/Type.h"
#include "gs/path.h"
#include "gs/str/utf.h"
#include "gs/lf/Util.h"

namespace gs
{
namespace xml
{

static const tchar* elementNameDefault = SL( "FileParameters" );

tinyxml2::XMLError write( const std::tstring& path, const gs::file::Parameters& param )
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

tinyxml2::XMLError read( std::unique_ptr<gs::file::Parameters>& param, const std::tstring& path )
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

tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::file::Parameters& param, const std::tstring& elementName /*= SL( "" )*/ )
{
    std::tstring elementNameLocal = elementName;
    if( elementNameLocal.empty() )
        elementNameLocal = elementNameDefault;

    tinyxml2::XMLElement* element = doc.NewElement( str::utf8( elementNameLocal ).c_str() );

    tinyxml2::XMLElement* child = nullptr;

    child = gs::xml::make_element( doc, param.FileType, SL("FileType") );
    element->LinkEndChild( child );

    child = gs::xml::make_element( doc, param.Path, SL( "Path" ) );
    element->LinkEndChild( child );

    switch( param.FileType )
    {
    case gs::file::Type::Data: child = gs::xml::make_element( doc, dynamic_cast<const gs::file::Data&>(param), SL( "Parameters" ) ); break;
    case gs::file::Type::SurferGrid: child = gs::xml::make_element( doc, dynamic_cast<const gs::file::SurferGrid&>(param), SL( "Parameters" ) ); break;
    case gs::file::Type::GeoScoutGridInfo: child = gs::xml::make_element( doc, dynamic_cast<const gs::file::GridInfo& >(param), SL( "Parameters" ) ); break;
    case gs::file::Type::GeoScoutGridInfoBlank: child = gs::xml::make_element( doc, dynamic_cast<const gs::file::GridInfoBlank& >(param), SL( "Parameters" ) ); break;
    }
    if( child != nullptr )
        element->LinkEndChild( child );

    return element;
}

tinyxml2::XMLError from_handle( std::unique_ptr<gs::file::Parameters>& param, tinyxml2::XMLHandle handle )
{
    tinyxml2::XMLError retrn = tinyxml2::XML_NO_ERROR;
    tinyxml2::XMLError error = tinyxml2::XML_NO_ERROR;

    gs::file::Type fileType;
    error = gs::xml::from_parent_handle( fileType, handle, SL( "FileType" ) );
    if( error != tinyxml2::XML_NO_ERROR )
        return error;


    switch( fileType )
    {
    case gs::file::Type::Data:
    {
        gs::file::Data fileData;
        error = gs::xml::from_parent_handle( fileData, handle, SL( "Parameters" ) );
        if( error == tinyxml2::XML_NO_ERROR )
            param = fileData.make_unique();
        else
            retrn = error;
    }
    break;

    case gs::file::Type::SurferGrid:
    {
        gs::file::SurferGrid fileSurferGrid;
        error = gs::xml::from_parent_handle( fileSurferGrid, handle, SL( "Parameters" ) );
        if( error == tinyxml2::XML_NO_ERROR )
            param = fileSurferGrid.make_unique();
        else
            retrn = error;
    }
    break;

    case gs::file::Type::GeoScoutGridInfo:
    {
        gs::file::GridInfo fileGridInfo;
        error = gs::xml::from_parent_handle( fileGridInfo, handle, SL( "Parameters" ) );
        if( error == tinyxml2::XML_NO_ERROR )
            param = fileGridInfo.make_unique();
        else
            retrn = error;
    }
    break;

    case gs::file::Type::GeoScoutGridInfoBlank:
    {
        gs::file::GridInfoBlank fileGridInfoBlank;
        error = gs::xml::from_parent_handle( fileGridInfoBlank, handle, SL( "Parameters" ) );
        if( error == tinyxml2::XML_NO_ERROR )
            param = fileGridInfoBlank.make_unique();
        else
            retrn = error;
    }
    break;

    default:
        retrn = tinyxml2::XML_NO_TEXT_NODE;
        break;

    }

    if( retrn != tinyxml2::XML_NO_ERROR )
        return retrn;

    std::tstring path;
    error = gs::xml::text::from_parent_handle( path, handle, SL( "Path" ) );
    if( error == tinyxml2::XML_NO_ERROR )
        param->Path = path;
    //else
    //    retrn = error;

    return retrn;
}

tinyxml2::XMLError from_parent_handle( std::unique_ptr<gs::file::Parameters>& param, tinyxml2::XMLHandle hParent, const std::tstring& childName /*= SL( "" )*/ )
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
