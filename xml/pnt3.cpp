#include "pnt3.h"

using namespace nhill::geometry;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Pnt3<>& pnt, std::string element_name )
{
   using namespace tinyxml2;

   // Create an element name if none was provided.
   if( element_name.empty() )
      element_name = type::to_name<Pnt3<>>();

   XMLElement* element = doc.NewElement( element_name.c_str() );

   XMLElement* child = nullptr;

   child = make_element( doc, pnt.x, "x" );
   element->LinkEndChild( child );

   child = make_element( doc, pnt.y, "y" );
   element->LinkEndChild( child );

   child = make_element( doc, pnt.z, "z" );
   element->LinkEndChild( child );

   return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Pnt3<>& pnt, tinyxml2::XMLHandle handle )
{
   using namespace tinyxml2;

   XMLError retrn = XMLError::XML_NO_ERROR;
   XMLError error = XMLError::XML_NO_ERROR;

   double value{ 0 };
   error = from_parent_handle( value, handle, "x" );
   if( error == XMLError::XML_NO_ERROR )
      pnt.x = value;
   else
      retrn = error;

   value = 0;
   error = from_parent_handle( value, handle, "y" );
   if( error == XMLError::XML_NO_ERROR )
      pnt.y = value;
   else
      retrn = error;

   value = 0;
   error = from_parent_handle( value, handle, "z" );
   if( error == XMLError::XML_NO_ERROR )
      pnt.z = value;
   else
      retrn = error;

   return retrn;
}