#include "rect_container.h"
#include "rect.h"

using namespace nhill::geometry;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Rect_container& rects, std::string element_name )
{
   using namespace tinyxml2;

   // Create an element name if none was provided.
   if( element_name.empty() )
      element_name = type::to_name<Rect_container>();

   XMLElement* element = doc.NewElement( element_name.c_str() );

   XMLElement* child = nullptr;
   for( const auto& rect : rects )
   {
      child = make_element( doc, rect );
      element->LinkEndChild( child );
   }

   return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Rect_container& rects, tinyxml2::XMLHandle handle )
{
   using namespace tinyxml2;
   
   rects.clear();

   XMLError retrn = XMLError::XML_NO_ERROR;
   XMLError error = XMLError::XML_NO_ERROR;

   for( XMLNode* node = handle.FirstChild().ToElement(); node != nullptr; node = node->NextSibling() )
   {
      Rect rect;
      error = from_handle( rect, node );
      if( error == XMLError::XML_NO_ERROR )
         rects.push_back( rect );
      else
         retrn = error;
   }

   return retrn;
}
