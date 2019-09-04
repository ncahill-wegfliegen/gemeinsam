#include "gsXmlCodeName.h"
#include "gsXmlUtility.h"
#include "gsXmlText.h"
#include "gs/str/utf.h"
#include "gs/lf/Util.h"
#include "gs/text/CodeName.h"
#include "gs/util/type.h"

namespace gs
{
namespace xml
{
//tinyxml2::XMLError write( const std::tstring& path, const CodeName& codeName, const std::tstring& rootName /*= SL( "" )*/ )
//{
//    // If no name is provided, then just use the class name as the element name.
//    std::tstring elementName = rootName;
//    if( elementName.empty() )
//        elementName = SL("CodeName");
//
//    tinyxml2::XMLError error = util::is_valid_path( path );
//    if( error != tinyxml2::XML_NO_ERROR )
//    {
//        LogError( std::tstring( SL( "Invalid path=" ) ) + path );
//        return error;
//    }
//
//    tinyxml2::XMLDocument doc;
//
//    doc.LinkEndChild( util::make_declaration( doc ) );
//    doc.LinkEndChild( make_element( doc, codeName, elementName ) );
//
//    error = doc.SaveFile( str::utf8( path ).c_str() );
//    return error;
//}
//
//tinyxml2::XMLError read( CodeName& codeName, const std::tstring& path, const std::tstring& rootName /*= SL( "" )*/ )
//{
//    // If no name is provided, then just use the class name as the element name.
//    std::tstring rootNameLocal = rootName;
//    if( rootNameLocal.empty() )
//        rootNameLocal = SL( "CodeName" );
//
//    tinyxml2::XMLDocument doc;
//    tinyxml2::XMLError error = util::make_document( doc, path );
//    if( error != tinyxml2::XML_NO_ERROR )
//        return error;
//
//    tinyxml2::XMLHandle hRoot = util::make_root_handle( doc, rootNameLocal );
//    error = from_handle( codeName, hRoot );
//    if( error != tinyxml2::XML_NO_ERROR )
//        LogError( std::tstring( SL( "Failed to extract the object " ) ) + rootNameLocal );
//
//    return error;
//}

tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const CodeName& codeName, const std::tstring& elementName /*= SL( "" )*/ )
{
    // If no name is provided, then just use the class name as the element name.
    std::tstring elementNameLocal = elementName;
    if( elementNameLocal.empty() )
        elementNameLocal = SL( "CodeName" );
    
    tinyxml2::XMLElement* eCodeName = doc.NewElement( str::utf8( elementNameLocal ).c_str() );

    tinyxml2::XMLElement* e = nullptr;
    
    e = make_element( doc, codeName.Code, SL("Code") );
    eCodeName->LinkEndChild( e );

    e = make_element( doc, codeName.Name, SL("Name") );
    eCodeName->LinkEndChild( e );

    return eCodeName;
}

tinyxml2::XMLError from_handle( CodeName& codeName, tinyxml2::XMLHandle hCodeName )
{
    tinyxml2::XMLError retrn = tinyxml2::XML_NO_ERROR;
    tinyxml2::XMLError error = tinyxml2::XML_NO_ERROR;

    Code code;
    error = text::from_parent_handle( code, hCodeName, SL("Code") );
    if( error == tinyxml2::XML_NO_ERROR )
        codeName.Code = code;
    else
        retrn = error;

    Name name;
    error = text::from_parent_handle( name, hCodeName, SL( "Name" ) );
    if( error == tinyxml2::XML_NO_ERROR )
        codeName.Name = name;
    else
        retrn = error;

    return retrn;
}

//tinyxml2::XMLError from_parent_handle( gs::CodeName& codeName, tinyxml2::XMLHandle hParent, const std::tstring& childName /*= SL( "" )*/ )
//{
//    // If no name is provided, then just use the class name as the element name.
//    std::tstring elementName = childName;
//    if( elementName.empty() )
//        elementName = type::ToName( codeName );
//
//    tinyxml2::XMLHandle handle = hParent.FirstChildElement( str::utf8( elementName ).c_str() );
//
//    return from_handle( codeName, handle );
//}

}
}