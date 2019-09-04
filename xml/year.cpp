#include "year.h"

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Year& year, std::string element_name )
{
   if( element_name.empty() )
      element_name = type::to_name<Year>();

   return make_element<int>( doc, static_cast<int>(year), element_name );
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Year& year, tinyxml2::XMLHandle handle )
{
   using namespace tinyxml2;

   XMLError retrn = XMLError::XML_NO_ERROR;
   XMLError error = XMLError::XML_NO_ERROR;

   int yr;
   error = from_handle<int>( yr, handle );
   if( error == XMLError::XML_NO_ERROR )
      year = yr;
   else
      retrn = error;

   return retrn;
}