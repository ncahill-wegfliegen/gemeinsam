#pragma once

#include "port.h"
#include "core\make_element.h"
#include "core\from_handle.h"
#include "core\from_parent_handle.h"
#include "core\kernel.h"
#include "nhill\util\enable_if.h"
#include "nhill\uom\quantity_ratio.h"
#include "puom.h"

namespace nhill
{
namespace xml
{

/// <summary>Create an xml output element for the given quantity.</summary>
/// <param name="quantity">The given quantity.</param>
/// <param name="elementName">The name of the quantity element.  If empty, then the Length type name is used.</param>
/// <returns>The xml output element.</returns>
template<typename Uom_numerator, typename Uom_denominator, typename enable_if::is_enum_type<Uom_numerator>* = nullptr, typename enable_if::is_enum_type<Uom_denominator>* = nullptr>
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const uom::Quantity_ratio<Uom_numerator, Uom_denominator>& quantity_ratio, std::string element_name )
{
   using namespace tinyxml2;

   if( element_name.empty() )
      element_name = SL("Quantity_") + type::to_name<Uom_numerator>() + SL("_per_") + type::to_name<Uom_denominator>();

   XMLElement* element = doc.NewElement( element_name.c_str() );

   XMLElement* child = nullptr;

   child = make_element( doc, static_cast<double>(quantity_ratio), SL( "Value" ) );
   element->LinkEndChild( child );

   child = make_element<Uom_numerator>( doc, quantity_ratio.numerator() );
   element->LinkEndChild( child );

   child = make_element<Uom_denominator>( doc, quantity_ratio.denominator() );
   element->LinkEndChild( child );

   return element;
}

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
template<typename Uom_numerator, typename Uom_denominator, typename enable_if::is_enum_type<Uom_numerator>* = nullptr, typename enable_if::is_enum_type<Uom_denominator>* = nullptr>
tinyxml2::XMLError from_handle( std::unique_ptr<uom::Quantity_ratio<Uom_numerator, Uom_denominator>>& quantity_ratio, tinyxml2::XMLHandle handle )
{
   using namespace tinyxml2;

   XMLError error = XMLError::XML_NO_ERROR;

   // Value
   double value{};
   error = from_parent_handle( value, handle, SL( "Value" ) );
   if( error != XMLError::XML_NO_ERROR )
      return error;

   // Numerator
   std::unique_ptr<uom::Prefixed_uom<Uom_numerator>> puom_numerator;
   error = from_parent_handle<Uom_numerator>( puom_numerator, handle );
   if( error != XMLError::XML_NO_ERROR )
      return error;

   // Denominator
   std::unique_ptr<uom::Prefixed_uom<Uom_denominator>> puom_denominator;
   error = from_parent_handle<Uom_denominator>( puom_denominator, handle );
   if( error != XMLError::XML_NO_ERROR )
      return error;

   // make the ratio quanity
   quantity_ratio = std::make_unique<uom::Quantity_ratio<Uom_numerator, Uom_denominator>>( *puom_numerator, *puom_denominator, value );

   return XMLError::XML_SUCCESS;
}

template<typename Uom_numerator, typename Uom_denominator, typename enable_if::is_enum_type<Uom_numerator>* = nullptr, typename enable_if::is_enum_type<Uom_denominator>* = nullptr>
tinyxml2::XMLError from_parent_handle( std::unique_ptr<uom::Quantity_ratio<Uom_numerator, Uom_denominator>>& quantity_ratio, tinyxml2::XMLHandle hParent, std::string child_name = SL( "" ) )
{
   using namespace tinyxml2;

   // If no name is provided, then just use the class name as the element name.
   if( child_name.empty() )
      child_name = "Quantity_" + type::to_name<Uom_numerator>() + "_per_" + type::to_name<Uom_denominator>();

   XMLHandle handle = hParent.FirstChildElement( child_name.c_str() );

   return from_handle<Uom_numerator, Uom_denominator>( quantity_ratio, handle );
}

/// <summary>Write the given text out to the given file.  The text will be the only element in the file.</summary>
/// <param name="path">The path of the file to which the text is written.</param>
/// <param name="text">The text to be written to the file.</param>
/// <returns>True if the write is successful; otherwise, false.</returns>
template<typename Uom_numerator, typename Uom_denominator, typename enable_if::is_enum_type<Uom_numerator>* = nullptr, typename enable_if::is_enum_type<Uom_denominator>* = nullptr>
tinyxml2::XMLError write( const std::string& path, const uom::Quantity_ratio<Uom_numerator, Uom_denominator>& quantity_ratio, std::string root_name = SL( "" ) )
{
   using namespace tinyxml2;

   if( root_name.empty() )
      root_name = SL("Quantity_") + type::to_name<Uom_numerator>() + SL("_per_") + type::to_name<Uom_denominator>();

   XMLDocument doc;

   doc.LinkEndChild( make_declaration( doc ) );
   doc.LinkEndChild( make_element<Uom_numerator, Uom_denominator>( doc, quantity_ratio, root_name ) );

   XMLError error = doc.SaveFile( str::utf8( path ).c_str() );
   if( error != XMLError::XML_SUCCESS )
   {
      std::tostringstream msg;
      msg << SL( "nhill::xml::write for quantity ratio. Failed to write " ) << root_name << SL( " to the file " ) << path << SL( ". " ) << to_label( error ) << SL( "." );
      LOG_ERROR( msg.str() );
      return error;
   }

   return XMLError::XML_SUCCESS;
}

/// <summary>Read the value of the text from the given file.  This assumes that the text is the only element in the file.</summary>
/// <param name="text">The std::string object into which the element will be read.</param>
/// <param name="path">The file from which to read the text.</param>
/// <returns>True if the read operation is successful; otherwise, false.</returns>
template<typename Uom_numerator, typename Uom_denominator, typename enable_if::is_enum_type<Uom_numerator>* = nullptr, typename enable_if::is_enum_type<Uom_denominator>* = nullptr>
tinyxml2::XMLError read( std::unique_ptr<uom::Quantity_ratio<Uom_numerator, Uom_denominator>>& quantity_ratio, const std::string& path, std::string root_name = SL( "" ) )
{
   using namespace tinyxml2;

   if( root_name.empty() )
      root_name = SL("Quantity_") + type::to_name<Uom_numerator>() + SL("_per_") + type::to_name<Uom_denominator>();

   XMLDocument doc;
   XMLError error = make_document( doc, path );
   if( error != XMLError::XML_NO_ERROR )
      if( error != XMLError::XML_NO_ERROR )
      {
         std::tostringstream msg;
         msg << SL( "nhill::xml::read for quantity ratio. Failed to create document for " ) << root_name << SL( " in the file " ) << path << SL( ". " ) << to_label( error ) << SL( "." );
         LOG_ERROR( msg.str() );
         return error;
      }

   tinyxml2::XMLHandle hRoot = make_root_handle( doc, root_name );
   error = from_handle<Uom_numerator, Uom_denominator>( quantity_ratio, hRoot );
   if( error != XMLError::XML_NO_ERROR )
   {
      std::tostringstream msg;
      msg << SL( "nhill::xml::read for quantity ratio. Failed to read " ) << root_name << SL( " from the file " ) << path << SL( ". " ) << to_label( error ) << SL( "." );
      LOG_ERROR( msg.str() );
      return error;
   }

   return XMLError::XML_SUCCESS;
}

}
}
