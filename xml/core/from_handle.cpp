#include "from_handle.h"
#include "../../log/log.h"
#include <sstream>

using namespace std;

/// <summary>Specialization for string.</summary>
template<>
tinyxml2::XMLError nhill::xml::from_handle<std::string>( std::string& str, tinyxml2::XMLHandle handle )
{
   using namespace tinyxml2;

   XMLElement* element = handle.ToElement();
   if( element == nullptr )
   {
      std::ostringstream msg;
      msg << "nhill::xml::from_handle specialized for std::string. The tinyxml2::XMLHandle has no tinyxml2::XMLElement.";
      LOG_ERROR( msg.str() );
      return XMLError::XML_ERROR_PARSING_ELEMENT;
   }

   const char* text_value = element->GetText();
   if( text_value == nullptr )
   {
      std::ostringstream msg;
      msg << "nhill::xml::from_handle specialized for std::string. The tinyxml2::XMLElement has no text.";
      LOG_ERROR( msg.str() );
      return XMLError::XML_NO_TEXT_NODE;
   }

   str = text_value;

   return XMLError::XML_SUCCESS;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle<std::wstring>( std::wstring& wstr, tinyxml2::XMLHandle handle )
{
	string str;
	tinyxml2::XMLError error{ from_handle<std::string>( str, handle ) };
	if( error == tinyxml2::XML_NO_ERROR )
	{
		wstr = { str.cbegin(), str.cend() };
	}
	return error;
}

/// <summary>Specialization for boolean.</summary>
template<>
tinyxml2::XMLError nhill::xml::from_handle<bool>( bool& boolean, tinyxml2::XMLHandle handle )
{
   using namespace tinyxml2;
   
   std::string text;
   XMLError error = nhill::xml::from_handle<std::string>( text, handle );
   if( error != XMLError::XML_SUCCESS )
   {
      std::ostringstream msg;
      msg << "nhill::xml::from_handle specialized for boolean. The tinyxml2::XMLHandle for a string has no text.";
      LOG_ERROR( msg.str() );
      return XMLError::XML_NO_TEXT_NODE;
   }

   std::string strue{ "true" };
   boolean = (text.compare( 0, strue.length(), strue ) == 0);

   return XMLError::XML_SUCCESS;
}
