#include "gsXmlFileData.h"
#include "gsXmlPrefixedUnitOfMeasurement.h"
#include "gsXmlUtility.h"
#include "gsXmlIO.h"
#include "gs/path.h"
#include "gs/str/utf.h"
#include "gs/lf/Util.h"

namespace gs
{
namespace xml
{

static const tchar* elementNameDefault = SL( "FileDataParameters" );

tinyxml2::XMLError write( const std::tstring& path, const gs::file::Data& param )
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

tinyxml2::XMLError read( gs::file::Data& param, const std::tstring& path )
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

tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::file::Data& param, const std::tstring& elementName /*= SL( "" )*/ )
{
    std::tstring elementNameLocal = elementName;
    if( elementNameLocal.empty() )
        elementNameLocal = elementNameDefault;

    tinyxml2::XMLElement* element = doc.NewElement( str::utf8( elementNameLocal ).c_str() );

    tinyxml2::XMLElement* child = nullptr;

    child = gs::xml::make_element( doc, param.RowFirst, SL("RowFirst") );
    element->LinkEndChild( child );

    child = gs::xml::make_element( doc, param.ColumnX, SL( "ColumnX" ) );
    element->LinkEndChild( child );

    child = gs::xml::make_element( doc, param.ColumnY , SL( "ColumnY" ) );
    element->LinkEndChild( child );

    child = gs::xml::make_element( doc, param.ColumnZ, SL( "ColumnZ" ) );
    element->LinkEndChild( child );

    child = gs::xml::make_element( doc, param.PuomX, SL( "PuomX" ) );
    element->LinkEndChild( child );

    child = gs::xml::make_element( doc, param.PuomY, SL( "PuomY" ) );
    element->LinkEndChild( child );

    child = gs::xml::make_element( doc, param.PuomZ, SL( "PuomZ" ) );
    element->LinkEndChild( child );

    child = gs::xml::make_element( doc, param.Delimiter, SL( "Delimiter" ) );
    element->LinkEndChild( child );

    return element;
}

tinyxml2::XMLError from_handle( gs::file::Data& param, tinyxml2::XMLHandle handle )
{
    tinyxml2::XMLError retrn = tinyxml2::XML_NO_ERROR;
    tinyxml2::XMLError error = tinyxml2::XML_NO_ERROR;

    int rowFirst;
    error = gs::xml::from_parent_handle( rowFirst, handle, SL( "RowFirst" ) );
    if( error == tinyxml2::XML_NO_ERROR )
        param.RowFirst = rowFirst;
    else
        retrn = error;

    int columnX;
    error = gs::xml::from_parent_handle( columnX, handle, SL( "ColumnX" ) );
    if( error == tinyxml2::XML_NO_ERROR )
        param.ColumnX = columnX;
    else
        retrn = error;

    int columnY;
    error = gs::xml::from_parent_handle( columnY, handle, SL( "ColumnY" ) );
    if( error == tinyxml2::XML_NO_ERROR )
        param.ColumnY = columnY;
    else
        retrn = error;

    int columnZ;
    error = gs::xml::from_parent_handle( columnZ, handle, SL( "ColumnZ" ) );
    if( error == tinyxml2::XML_NO_ERROR )
        param.ColumnZ = columnZ;
    else
        retrn = error;

    gs::uom::len::puom puomX;
    error = gs::xml::from_parent_handle( puomX, handle, SL( "PuomX" ) );
    if( error == tinyxml2::XML_NO_ERROR )
        param.PuomX = puomX;
    else
        retrn = error;

    gs::uom::len::puom puomY;
    error = gs::xml::from_parent_handle( puomY, handle, SL( "PuomY" ) );
    if( error == tinyxml2::XML_NO_ERROR )
        param.PuomY = puomY;
    else
        retrn = error;

    gs::uom::len::puom puomZ;
    error = gs::xml::from_parent_handle( puomZ, handle, SL( "PuomZ" ) );
    if( error == tinyxml2::XML_NO_ERROR )
        param.PuomZ = puomZ;
    else
        retrn = error;

    return retrn;
}

tinyxml2::XMLError from_parent_handle( gs::file::Data& param, tinyxml2::XMLHandle hParent, const std::tstring& childName /*= SL( "" )*/ )
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
