#include "pnt.h"

using namespace nhill::geometry;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Pnt<>& pnt, std::string element_name )
{
   using namespace tinyxml2;

   // Create an element name if none was provided.
   if( element_name.empty() )
      element_name = type::to_name<Pnt<>>();

   XMLElement* element = doc.NewElement( element_name.c_str() );

   XMLElement* child = nullptr;

   child = make_element( doc, pnt.x, "x" );
   element->LinkEndChild( child );

   child = make_element( doc, pnt.y, "y" );
   element->LinkEndChild( child );

   return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Pnt<>& pnt, tinyxml2::XMLHandle handle )
{
   using namespace tinyxml2;

   XMLError retrn = XMLError::XML_NO_ERROR;
   XMLError error = XMLError::XML_NO_ERROR;

   double x;
   error = from_parent_handle( x, handle, "x" );
   if( error == XMLError::XML_NO_ERROR )
      pnt.x = x;
   else
      retrn = error;

   double y;
   error = from_parent_handle( y, handle, "y" );
   if( error == XMLError::XML_NO_ERROR )
      pnt.y = y;
   else
      retrn = error;

   return retrn;
}