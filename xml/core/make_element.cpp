#include "make_element.h"

template<> 
tinyxml2::XMLElement* nhill::xml::make_element<bool>( tinyxml2::XMLDocument& doc, const bool& boolean, std::string element_name )
{
   // Create an element name if none was provided.
   if( element_name.empty() )
      element_name = "Bool";

   std::string text{ boolean ? "true" : "false" };
   return nhill::xml::make_element<std::string>( doc, text, element_name );
}
