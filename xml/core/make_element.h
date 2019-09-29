#pragma once

#include "..\port.h"
#include <string>
#include <sstream>
#include "../../utility/type.h" 
#include "../../utility/enable_if.h"
#include "../../log/log.h"
#include "../../../../other/TiXml2/tinyxml2.h"

namespace nhill
{
namespace xml
{

/// <summary>Create an xml output element for the given object.
/// <para>If no element name is provided, then the object's type name is used as the xml element name.</para>
/// <para>The object must overload the output stream operator (&lt;&lt;).</para>
/// </summary>
/// <param name="value">The given object.</param>
/// <returns>The xml output element.</returns>
template<typename Object>
tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const Object& obj, std::string element_name = "" )
{
   // Create an element name if none was provided.
   if( element_name.empty() )
      element_name = nhill::type::to_name<Object>();

   // Create the element
   tinyxml2::XMLElement* element = doc.NewElement( element_name.c_str() );
   if( element == nullptr )
   {
      std::ostringstream msg;
      msg << "nhill::xml::make_element.  The tinyxml2::XMLDocument for " << type::to_name<Object>() << " failed to create a tinyxml2::XMLElement with the name " << element_name << ".";
      LOG_ERROR( msg.str() );
      return nullptr;
   }

   // Convert the object into text
   std::ostringstream text;
   text.exceptions( std::ostringstream::failbit | std::ostringstream::badbit );
   try 
   {
      text << obj;
   }
   catch( std::ostringstream::failure ex )
   {
      std::ostringstream msg;
      msg << "nhill::xml::make_element. Failed to stream " << type::to_name<Object>() << " into the stringstream. " << ex.what();
      LOG_ERROR( msg.str() );
      throw std::exception( msg.str().c_str() );
   }

   // Set the text of the element
   element->SetText( text.str().c_str() );

   // Return the element
   return element;
}

/// <summary>Specialization for boolean.</summary>
template<> NHILL_XML_PORT_FUNCTION
tinyxml2::XMLElement* make_element<bool>( tinyxml2::XMLDocument& doc, const bool& boolean, std::string element_name );

template<> NHILL_XML_PORT_FUNCTION
tinyxml2::XMLElement* make_element<std::wstring>( tinyxml2::XMLDocument& doc, const std::wstring& wstr, std::string element_name );

}
}

