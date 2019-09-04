#pragma once

#include "..\port.h"
#include "../../log/log.h"
#include "../../utility/enable_if.h"
#include "../../utility/type.h"
#include "../../../../other/TiXml2/tinyxml2.h"
#include "../../../../other/TiXml2/tinyxml2.h"
#include <iostream>

namespace nhill
{
namespace xml
{


/// <summary>Extract the object value from the xml input handle.
/// <para>The object must overload the input stream operator (&gt;&gt;).</para>
/// <para>Use xmlText if the text contains white space.</para>
/// </summary>
/// <param name="e">The object into which the element will be extracted.</param>
/// <param name="handle">The xml input handle for the element.</param>
/// <returns>True if the extraction is successful; otherwise, false.</returns>
template<typename Object, typename nhill::enable_if::is_not_enum_type<Object>* = nullptr>
tinyxml2::XMLError from_handle( Object& obj, tinyxml2::XMLHandle handle )
{
   using namespace tinyxml2;

   XMLElement* element = handle.ToElement();
   if( element == nullptr )
   {
      std::ostringstream msg;
      msg << "nhill::xml::from_handle. The tinyxml2::XMLHandle for " << nhill::type::to_name<Object,char>() << " has no tinyxml2::XMLElement.";
      LOG_ERROR( msg.str() );
      return XMLError::XML_ERROR_PARSING_ELEMENT;
   }

   const char* text = element->GetText();
   if( text == nullptr )
   {
      std::ostringstream msg;
      msg << "nhill::xml::from_handle. The tinyxml2::XMLElement for " << type::to_name<Object>() << " has no text.";
      LOG_ERROR( msg.str() );
      return XMLError::XML_NO_TEXT_NODE;
   }

   try
   {
      std::stringstream ss;
      ss.exceptions( std::ostringstream::failbit | std::ostringstream::badbit );
      ss << text; // stream the text into the string stream
      ss >> obj; // stream the text out to the object
   }
   catch( std::ostringstream::failure ex )
   {
      std::ostringstream msg;
      msg << "nhill::xml::from_handle. Failed to stream the text \"" << text << "\" out to  " << type::to_name<Object>() << ". " << ex.what();
      LOG_ERROR( msg.str() );
      return XMLError::XML_ERROR_PARSING_TEXT;
   }

   return XMLError::XML_SUCCESS;
}

/// <summary>Specialization for string.</summary>
/// <remarks> The stream will stop when it reaches white space. So use this specialization for reading text with whitespace in it.</remarks>
template<> GS_XML_PORT_FUNCTION
tinyxml2::XMLError from_handle<std::string>( std::string& str, tinyxml2::XMLHandle handle );

/// <summary>Specialization for bool.</summary>
template<> GS_XML_PORT_FUNCTION
tinyxml2::XMLError from_handle<bool>( bool& boolean, tinyxml2::XMLHandle handle );

template<typename Object, typename nhill::enable_if::is_not_enum_type<Object>* = nullptr>
tinyxml2::XMLError from_handle( std::unique_ptr<Object>& obj, tinyxml2::XMLHandle handle )
{
   std::ostringstream msg;
   msg << "nhill::xml::from_handle template for unique_ptr must be specialized for " << type::to_name<Object>();
   LOG_ERROR( msg.str() );
   throw nhill::Not_implemented( msg.str() );
}

template<typename Enum, typename nhill::enable_if::is_enum_type<Enum>* = nullptr>
tinyxml2::XMLError from_handle( Enum& e, tinyxml2::XMLHandle handle )
{
   using namespace tinyxml2;

   XMLElement* element = handle.ToElement();
   if( element == nullptr )
   {
      std::ostringstream msg;
      msg << "nhill::xml::from_handle. The tinyxml2::XMLHandle for enumeration " << nhill::to_label<Enum>( e ) << " has no tinyxml2::XMLElement." ;
      LOG_ERROR( msg.str() );
      return XMLError::XML_ERROR_PARSING_ELEMENT;
   }

   const char* text = element->GetText();
   if( text == nullptr )
   {
      std::ostringstream msg;
      msg << "nhill::xml::from_handle. The tinyxml2::XMLElement for enumeration " << nhill::to_label<Enum>( e ) << " has no text.";
      LOG_ERROR( msg.str() );
      return XMLError::XML_NO_TEXT_NODE;
   }

   if( !nhill::from_string<Enum>( e, text ) )
   {
      std::ostringstream msg;
      msg << "nhill::xml::from_handle. The text \"" << text << "\" cannot be converted to enumeration " << nhill::to_label<Enum>( e );
      LOG_ERROR( msg.str() );
      return XMLError::XML_ERROR_PARSING_TEXT;
   }

   return XMLError::XML_SUCCESS;
}

}
}