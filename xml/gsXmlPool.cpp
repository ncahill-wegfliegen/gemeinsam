#include "gsXmlPool.h"
#include "gsXmlCodeName.h"
#include "gs/str/utf.h"
#include "gs/util/type.h"
#include "tixml/tixml2.h"


namespace gs
{
namespace xml
{

tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::Pool& pool, const std::tstring& elementName /*= SL( "" )*/ )
{
    std::tstring elementNameLocal = elementName;
    if( elementNameLocal.empty() )
        elementNameLocal = SL( "Pool" );

    tinyxml2::XMLElement* element = make_element( doc, dynamic_cast<const CodeName&>(pool), elementNameLocal );

    return element;
}

tinyxml2::XMLError from_handle( gs::Pool& pool, tinyxml2::XMLHandle hPool )
{
    tinyxml2::XMLError error = from_handle( dynamic_cast<CodeName&>(pool), hPool );
    return error;
}

}
}