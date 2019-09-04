#include "gsXmlPoolBundle.h"
#include "gsXmlField.h"
#include "gsXmlPool.h"
#include "gsXmlUtility.h"
#include "gsXmlIO.h"
#include "gs/str/utf.h"
#include "gs/lf/Util.h"
#include "gs/enum/area.h"
#include "gs/util/type.h"

namespace gs
{
namespace xml
{
tinyxml2::XMLError write( const std::tstring& path, const gs::pool::Bundle& poolBundle )
{
    return gs::xml::write<gs::pool::Bundle>( path, poolBundle, SL( "PoolBundle" ) );
}

tinyxml2::XMLError read( gs::pool::Bundle& poolBundle, const std::tstring& path )
{
    return gs::xml::read<gs::pool::Bundle>( poolBundle, path, SL( "PoolBundle" ) );
}

tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::pool::Bundle& poolBundle, const std::tstring& elementName /*= SL( "" )*/ )
{
    std::tstring elementNameLocal = elementName;
    if( elementNameLocal.empty() )
        elementNameLocal = SL( "PoolBundle" );

    tinyxml2::XMLElement* ePoolEx = doc.NewElement( str::utf8( elementNameLocal ).c_str() );

    tinyxml2::XMLElement* e = nullptr;

    e = make_element( doc, poolBundle.Area );
    ePoolEx->LinkEndChild( e );

    e = make_element( doc, poolBundle.Field );
    ePoolEx->LinkEndChild( e );

    e = make_element( doc, poolBundle.Pool );
    ePoolEx->LinkEndChild( e );

    return ePoolEx;
}

tinyxml2::XMLError from_handle( gs::pool::Bundle& poolBundle, tinyxml2::XMLHandle hPoolBundle )
{
    tinyxml2::XMLError retrn = tinyxml2::XML_NO_ERROR;
    tinyxml2::XMLError error = tinyxml2::XML_NO_ERROR;

    // It has to have an area, but the field and pool could be empty

    Area area;
    error = from_parent_handle( area, hPoolBundle );
    if( error == tinyxml2::XML_NO_ERROR )
        poolBundle.Area = area;
    else
        retrn = error;

    gs::Field field;
    error = from_parent_handle( field, hPoolBundle );
    if( error == tinyxml2::XML_NO_ERROR )
        poolBundle.Field = field ;

    gs::Pool pool;
    error = from_parent_handle( pool, hPoolBundle );
    if( error == tinyxml2::XML_NO_ERROR )
        poolBundle.Pool = pool ;

    return retrn;
}

tinyxml2::XMLError from_parent_handle( gs::pool::Bundle& poolBundle, tinyxml2::XMLHandle hParent, const std::tstring& childName /*= SL( "" )*/ )
{
    // If no name is provided, then just use the class name as the element name.
    std::tstring elementName = childName;
    if( elementName.empty() )
        elementName = type::ToName( poolBundle );

    tinyxml2::XMLHandle handle = hParent.FirstChildElement( str::utf8( elementName ).c_str() );

    return from_handle( poolBundle, handle );
}

}
}