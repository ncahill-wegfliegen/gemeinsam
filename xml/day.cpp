#include "day.h"

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Day& day, std::string element_name )
{
   if( element_name.empty() )
      element_name = type::to_name<Day>();

   return make_element<int>( doc, day.value(), element_name );
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Day& day, tinyxml2::XMLHandle handle )
{
   using namespace tinyxml2;

   XMLError retrn = XMLError::XML_NO_ERROR;
   XMLError error = XMLError::XML_NO_ERROR;

   int uday;
   error = from_handle<int>( uday, handle );
   if( error == XMLError::XML_NO_ERROR )
      day.value( uday );
   else
      retrn = error;

   return retrn;
}