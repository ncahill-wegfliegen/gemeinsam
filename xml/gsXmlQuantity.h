#pragma once

#include "gsXmlUtility.h"
#include "gsXmlIO.h"
#include "gs/str/utf.h"
#include "gs/enum/uom/PrefixEx.h"
#include "gs/uom/quantity.h"
#include "gs/util/type.h"
#include "tixml/tixml2.h"



namespace gs
{
namespace xml
{

template<typename UnitOfMeasurement>
tinyxml2::XMLError write( const std::tstring& path, const gs::uom::Quantity<UnitOfMeasurement>& object )
{
    std::tstring unitOfMeasurement = gs::type::ToName<UnitOfMeasurement>();
    std::tstring measurement = unitOfMeasurement.erase( 0, 6 );// get rid of "UnitOf"
    std::tostringstream rootName;
    rootName << SL( "QuantityOf" ) << measurement;
    return gs::xml::write<gs::uom::Quantity<UnitOfMeasurement>>( path, object, rootName.str() );
}

template<typename UnitOfMeasurement>
/// <summary>Read the Value of the text from the given file.  This assumes that the text is the only element in the file.</summary>
/// <param name="text">The std::tstring object into which the element will be read.</param>
/// <param name="path">The file from which to read the text.</param>
/// <returns>True if the read operation is successful; otherwise, false.</returns>
tinyxml2::XMLError read( gs::uom::Quantity<UnitOfMeasurement>& object, const std::tstring& path )
{
    std::tstring unitOfMeasurement = gs::type::ToName<UnitOfMeasurement>();
    std::tstring measurement = unitOfMeasurement.erase( 0, 6 );// get rid of "UnitOf"
    std::tostringstream rootName;
    rootName << SL( "QuantityOf" ) << measurement;
    return gs::xml::read<gs::uom::Quantity<UnitOfMeasurement>>( object, path, rootName.str() );
}

template<typename UnitOfMeasurement>
/// <summary>Create an xml output element for the given quantity.</summary>
/// <param name="quantity">The given quantity.</param>
/// <param name="elementName">The name of the quantity element.  If empty, then the Length type name is used.</param>
/// <returns>The xml output element.</returns>
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::uom::Quantity<UnitOfMeasurement>& quantity, const std::tstring& elementName = SL( "" ) )
{
    std::tstring elementNameLocal = elementName;
    if( elementNameLocal.empty() )
        elementNameLocal = SL("Quantity");

    tinyxml2::XMLElement* element = doc.NewElement( str::utf8( elementNameLocal ).c_str() );

    tinyxml2::XMLElement* e = nullptr;
    e = gs::xml::make_element( doc, static_cast<double>(quantity), SL( "Value" ) );
    element->LinkEndChild( e );

    gs::uom::prefix prefix = quantity.Prefix;
    e = make_element( doc, prefix);
    element->LinkEndChild( e );

    UnitOfMeasurement unit = quantity.Unit;
    e = make_element( doc, unit );
    element->LinkEndChild( e );


    return element;
}


template<typename UnitOfMeasurement>
/// <summary>Read the quantity from the xml input handle.</summary>
/// <param name="quantity">The Length object into which the element will be read.</param>
/// <param name="hLength">The xml input handle for the quantity element.</param>
/// <returns>True if the read operation is successful; otherwise, false.</returns>
/// <example>
/// The handle should refer to an xml element that looks like 
///   <code>
///     &lt;ElementName&gt;
///         &lt;UnitOfMeasurementPrefix&gt;kilo&lt;/UnitOfMeasurementPrefix&gt;
///         &lt;UnitOfLength&gt;metre&lt;/UnitOfLength&gt;
///         &lt;Value&gt;15.6&lt;/Value&gt;
///     &lt;/ElementName&gt;
///   </code>
/// </example>
tinyxml2::XMLError from_handle( std::unique_ptr<gs::uom::Quantity<UnitOfMeasurement>>& quantity, tinyxml2::XMLHandle hLength )
{
    tinyxml2::XMLError error = tinyxml2::XML_NO_ERROR;

    // The Value of the quantity being read in from the xml handle.
    double value;
    error = from_parent_handle( value, hLength, SL( "Value" ) );
    if( error != tinyxml2::XML_NO_ERROR )
        return error;

    // The prefix of the quantity being read in from the xml handle.
    gs::uom::prefix prefix;
    error = from_parent_handle( prefix, hLength );
    if( error != tinyxml2::XML_NO_ERROR )
        return error;

    // The unit of the quantity being read in from the xml handle.
    UnitOfMeasurement uom;
    error = from_parent_handle( uom, hLength );
    if( error != tinyxml2::XML_NO_ERROR )
        return error;

    // make the quanity
    quantity = std::make_unique<gs::uom::Quantity<UnitOfMeasurement>>( gs::uom::PrefixedUnitOfMeasurement<UnitOfMeasurement>( prefix, uom ), value );

    return tinyxml2::XML_NO_ERROR;
}

template<typename UnitOfMeasurement>
tinyxml2::XMLError from_parent_handle( std::unique_ptr<gs::uom::Quantity<UnitOfMeasurement>>& quantity, tinyxml2::XMLHandle hParent, const std::tstring& childName = SL( "" ) )
{
    // If no name is provided, then just use the class name as the element name.
    std::tstring elementNameLocal = childName;
    if( elementNameLocal.empty() )
        elementNameLocal = SL( "Quantity" );

    tinyxml2::XMLHandle hChild = hParent.FirstChildElement( str::utf8( elementNameLocal ).c_str() );

    return from_handle( quantity, hChild );
}


}
}
