#include "rect.h"

using namespace nhill::geometry;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Rect<>& rect, std::string element_name )
{
   using namespace tinyxml2;

   // Create an element name if none was provided.
   if( element_name.empty() )
      element_name = type::to_name<Rect<>>();

   XMLElement* element = doc.NewElement( element_name.c_str() );

   XMLElement* child = nullptr;

   child = make_element( doc, rect.left, "left" );
   element->LinkEndChild( child );

   child = make_element( doc, rect.bottom, "bottom" );
   element->LinkEndChild( child );

   child = make_element( doc, rect.right, "right" );
   element->LinkEndChild( child );

   child = make_element( doc, rect.top, "top" );
   element->LinkEndChild( child );

   return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Rect<>& rect, tinyxml2::XMLHandle handle )
{
   using namespace tinyxml2;

   XMLError retrn = XMLError::XML_NO_ERROR;
   XMLError error = XMLError::XML_NO_ERROR;

   double value{ 0 };
   error = from_parent_handle( value, handle, "left" );
   if( error == XMLError::XML_NO_ERROR )
      rect.left = value;
   else
      retrn = error;

   value = 0;
   error = from_parent_handle( value, handle, "bottom" );
   if( error == XMLError::XML_NO_ERROR )
      rect.bottom = value;
   else
      retrn = error;

   value = 0;
   error = from_parent_handle( value, handle, "right" );
   if( error == XMLError::XML_NO_ERROR )
      rect.right = value;
   else
      retrn = error;

   value = 0;
   error = from_parent_handle( value, handle, "top" );
   if( error == XMLError::XML_NO_ERROR )
      rect.top = value;
   else
      retrn = error;

   return retrn;
}