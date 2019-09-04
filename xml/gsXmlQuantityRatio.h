#pragma once

#include "gsXmlUtility.h"
#include "gsXmlIO.h"
#include "xmlQuantity.h"
#include "gs/str/utf.h"
#include "gs/enum/uom/PrefixEx.h"
#include "gs/uom/quantityratio.h"
#include "gs/util/type.h"
#include "tixml/tixml2.h"



namespace gs
{
namespace xml
{

template<typename uomNumerator, typename uomDenominator>
tinyxml2::XMLError write( const std::tstring& path, const gs::uom::QuantityRatio<uomNumerator,uomDenominator>& object )
{
    std::tstring strUomNum = gs::type::ToName<uomNumerator>();
    strUomNum = strUomNum.erase( 0, 6 );// get rid of "UnitOf"

    std::tstring strUomDen = gs::type::ToName<uomDenominator>();
    strUomDen = strUomDen.erase( 0, 6 );// get rid of "UnitOf"

    std::tostringstream rootName;
    rootName << SL( "QuantityRatioOf" ) << strUomNum << SL("And") << strUomDen;

    return gs::xml::write<gs::uom::QuantityRatio<uomNumerator, uomDenominator>>(path, object, rootName.str());
}

template<typename uomNumerator, typename uomDenominator>
/// <summary>Read the value of the text from the given file.  This assumes that the text is the only element in the file.</summary>
/// <param name="text">The std::tstring object into which the element will be read.</param>
/// <param name="path">The file from which to read the text.</param>
/// <returns>True if the read operation is successful; otherwise, false.</returns>
tinyxml2::XMLError read( gs::uom::QuantityRatio<uomNumerator, uomDenominator>& object, const std::tstring& path )
{
    std::tstring strUomNum = gs::type::ToName<uomNumerator>();
    strUomNum = strUomNum.erase( 0, 6 );// get rid of "UnitOf"

    std::tstring strUomDen = gs::type::ToName<uomDenominator>();
    strUomDen = strUomDen.erase( 0, 6 );// get rid of "UnitOf"

    std::tostringstream rootName;
    rootName << SL( "QuantityRatioOf" ) << strUomNum << SL( "And" ) << strUomDen;

    return gs::xml::read<gs::uom::QuantityRatio<uomNumerator, uomDenominator>>( object, path, rootName.str() );
}

template<typename uomNumerator, typename uomDenominator>
/// <summary>Create an xml output element for the given quantityratio.</summary>
/// <param name="quantityratio">The given quantityratio.</param>
/// <param name="elementName">The name of the quantityratio element.  If empty, then the Length type name is used.</param>
/// <returns>The xml output element.</returns>
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::uom::QuantityRatio<uomNumerator, uomDenominator>& quantityratio, const std::tstring& elementName = SL( "" ) )
{
    std::tstring elementNameLocal = elementName;
    if( elementNameLocal.empty() )
        elementNameLocal = SL( "QuantityRatio" );

    tinyxml2::XMLElement* element = doc.NewElement( str::utf8( elementNameLocal ).c_str() );

    gs::uom::Quantity<uomNumerator> numerator( quantityratio.Numerator, static_cast<double>(quantityratio) );
    gs::uom::Quantity<uomDenominator> denominator( quantityratio.Denominator, 1 );

    tinyxml2::XMLElement* e = nullptr;
    e = gs::xml::make_element( doc, numerator, SL("Numerator") );
    element->LinkEndChild( e );

    e = gs::xml::make_element( doc, denominator, SL( "Denominator" ) );
    element->LinkEndChild( e );


    return element;
}


template<typename uomNumerator, typename uomDenominator>
/// <summary>Read the quantityratio from the xml input handle.</summary>
/// <param name="quantityratio">The Length object into which the element will be read.</param>
/// <param name="hLength">The xml input handle for the quantityratio element.</param>
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
tinyxml2::XMLError from_handle( std::unique_ptr<gs::uom::QuantityRatio<uomNumerator, uomDenominator>>& quantityratio, tinyxml2::XMLHandle handle )
{
    tinyxml2::XMLError error = tinyxml2::XML_NO_ERROR;

    std::unique_ptr<gs::uom::Quantity<uomNumerator>> numerator;
    error = from_parent_handle( numerator, handle, SL( "Numerator" ) );
    if( error != tinyxml2::XML_NO_ERROR )
        return error;

    std::unique_ptr<gs::uom::Quantity<uomDenominator>> denominator;
    error = from_parent_handle( denominator, handle, SL( "Denominator" ) );
    if( error != tinyxml2::XML_NO_ERROR )
        return error;

    // make the quanity
    quantityratio = std::make_unique<gs::uom::QuantityRatio<uomNumerator, uomDenominator>>( *numerator, *denominator, static_cast<double>(*numerator) );

    return tinyxml2::XML_NO_ERROR;
}

template<typename uomNumerator, typename uomDenominator>
tinyxml2::XMLError from_parent_handle( std::unique_ptr<gs::uom::QuantityRatio<uomNumerator, uomDenominator>>& quantityratio, tinyxml2::XMLHandle hParent, const std::tstring& childName = SL( "" ) )
{
    // If no name is provided, then just use the class name as the element name.
    std::tstring elementNameLocal = childName;
    if( elementNameLocal.empty() )
        elementNameLocal = SL( "Quantity" );

    tinyxml2::XMLHandle hChild = hParent.FirstChildElement( str::utf8( elementNameLocal ).c_str() );

    return from_handle( quantityratio, hChild );
}


}
}
