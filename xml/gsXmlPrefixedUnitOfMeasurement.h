#pragma once

#include "gsXmlUtility.h"
#include "gsXmlIO.h"
#include "gs/enum/uom/Prefix.h"
#include "gs/str/utf.h"
#include "gs/uom/puom.h"
#include "gs/util/type.h"
#include "tixml/tixml2.h"

namespace gs
{
namespace xml
{

template<typename UnitOfMeasurement>
tinyxml2::XMLError write( const std::tstring& path, const gs::uom::PrefixedUnitOfMeasurement<UnitOfMeasurement>& object )
{
    std::tstring rootName;
    rootName.reserve( 256 );
    rootName = SL( "Prefixed" );
    rootName += gs::type::ToName<UnitOfMeasurement>();
    return gs::xml::write<gs::uom::PrefixedUnitOfMeasurement<UnitOfMeasurement>>( path, object, rootName );
}

template<typename UnitOfMeasurement>
/// <summary>Read the value of the text from the given file.  This assumes that the text is the only element in the file.</summary>
/// <param name="text">The std::tstring object into which the element will be read.</param>
/// <param name="path">The file from which to read the text.</param>
/// <returns>True if the read operation is successful; otherwise, false.</returns>
tinyxml2::XMLError read( gs::uom::PrefixedUnitOfMeasurement<UnitOfMeasurement>& object, const std::tstring& path )
{
    std::tstring rootName;
    rootName.reserve( 256 );
    rootName = SL( "Prefixed" );
    rootName += gs::type::ToName<UnitOfMeasurement>();
    return gs::xml::read<gs::uom::PrefixedUnitOfMeasurement<UnitOfMeasurement>>( object, path, rootName );
}


template<typename UnitOfMeasurement>
/// <summary>Create an xml output element for the given punit.</summary>
/// <param name="punit">The given punit.</param>
/// <param name="elementName">The name of the punit element.  If empty, then the Length type name is used.</param>
/// <returns>The xml output element.</returns>
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::uom::PrefixedUnitOfMeasurement<UnitOfMeasurement>& punit, const std::tstring& elementName = SL( "" ) )
{
    std::tstring elementNameLocal = elementName;
    if( elementNameLocal.empty() )
        elementNameLocal = SL("PrefixedUnitOfMeasurement");

    tinyxml2::XMLElement* element = doc.NewElement( str::utf8( elementNameLocal ).c_str() );
    tinyxml2::XMLElement* e = nullptr;
    
    e = make_element<gs::uom::prefix>( doc, punit.Prefix );
    element->LinkEndChild( e );

    e = make_element<UnitOfMeasurement>( doc, punit.Unit );
    element->LinkEndChild( e );

    return element;
}


template<typename UnitOfMeasurement>
/// <summary>Read the punit from the xml input handle.</summary>
/// <param name="punit">The Length object into which the element will be read.</param>
/// <param name="hLength">The xml input handle for the punit element.</param>
/// <returns>True if the read operation is successful; otherwise, false.</returns>
/// <example>
/// The handle should refer to an xml element that looks like 
///   <code>
///     &lt;ElementName&gt;
///         &lt;UnitOfMeasurementPrefix&gt;kilo&lt;/UnitOfMeasurementPrefix&gt;
///         &lt;UnitOfLength&gt;metre&lt;/UnitOfLength&gt;
///         &lt;value&gt;15.6&lt;/value&gt;
///     &lt;/ElementName&gt;
///   </code>
/// </example>
tinyxml2::XMLError from_handle( gs::uom::PrefixedUnitOfMeasurement<UnitOfMeasurement>& puom, tinyxml2::XMLHandle hPrefixedUnit )
{
    tinyxml2::XMLError error = tinyxml2::XML_NO_ERROR;

    // The prefix of the puom being read in from the xml handle.
    gs::uom::prefix prefixFrom;
    error = from_parent_handle<gs::uom::prefix>( prefixFrom, hPrefixedUnit );
    if( error != tinyxml2::XML_NO_ERROR )
        return error;

    // The unit of the puom being read in from the xml handle.
    UnitOfMeasurement unitFrom;
    error = from_parent_handle<UnitOfMeasurement>( unitFrom, hPrefixedUnit );
    if( error != tinyxml2::XML_NO_ERROR )
        return error;

    puom = gs::uom::PrefixedUnitOfMeasurement<UnitOfMeasurement>( prefixFrom, unitFrom );

    return tinyxml2::XML_NO_ERROR;
}

template<typename UnitOfMeasurement>
tinyxml2::XMLError  from_parent_handle( gs::uom::PrefixedUnitOfMeasurement<UnitOfMeasurement>& puom, tinyxml2::XMLHandle hParent, const std::tstring& childName = SL( "" ) )
{
    // If no name is provided, then just use the class name as the element name.
    std::tstring elementName = childName;
    if( elementName.empty() )
        elementName = SL( "PrefixedUnitOfMeasurement" );

    tinyxml2::XMLHandle handle = hParent.FirstChildElement( str::utf8( elementName ).c_str() );

    return from_handle( puom, handle );
}


}
}
