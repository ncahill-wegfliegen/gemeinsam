#include "make_element.h"
#include <codecvt>

template<> 
tinyxml2::XMLElement* nhill::xml::make_element<bool>( tinyxml2::XMLDocument& doc, const bool& boolean, std::string element_name )
{
   // Create an element name if none was provided.
   if( element_name.empty() )
      element_name = "Bool";

   std::string text{ boolean ? "true" : "false" };
   return nhill::xml::make_element<std::string>( doc, text, element_name );
}

template<> 
tinyxml2::XMLElement* nhill::xml::make_element<std::wstring>( tinyxml2::XMLDocument& doc, const std::wstring& wstr, std::string element_name )
{
	// Convert the wstring to a string
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	std::string str{ converterX.to_bytes( wstr ) };
	return make_element<std::string>( doc, str, element_name );
}

