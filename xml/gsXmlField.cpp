#include "gsXmlField.h"
#include "gsXmlCodeName.h"
#include "gs/str/utf.h"
#include "gs/util/type.h"
#include "tixml/tixml2.h"


namespace gs
{
namespace xml
{

tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::Field& field, const std::tstring& elementName /*= SL( "" )*/ )
{
    std::tstring elementNameLocal = elementName;
    if( elementNameLocal.empty() )
        elementNameLocal = SL( "Field" );

    tinyxml2::XMLElement* element = make_element( doc, dynamic_cast<const CodeName&>(field), elementNameLocal );
    
    return element;
}

tinyxml2::XMLError from_handle( gs::Field& field, tinyxml2::XMLHandle hField )
{
    tinyxml2::XMLError error = from_handle( dynamic_cast<CodeName&>(field), hField );
    return error;
}

}
}