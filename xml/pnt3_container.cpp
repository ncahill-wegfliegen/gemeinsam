#include "pnt3_container.h"
#include "pnt3.h"

using namespace nhill::geometry;

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Pnt3_container<>& pnts, std::string element_name )
{
   using namespace tinyxml2;

   // Create an element name if none was provided.
   if( element_name.empty() )
      element_name = type::to_name<Pnt3_container<>>();

   XMLElement* element = doc.NewElement( element_name.c_str() );

   XMLElement* child = nullptr;
   for( const auto& pnt : pnts )
   {
      child = make_element( doc, pnt );
      element->LinkEndChild( child );
   }

   return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( Pnt3_container<>& pnts, tinyxml2::XMLHandle handle )
{
   using namespace tinyxml2;

   pnts.clear();

   XMLError retrn = XMLError::XML_NO_ERROR;
   XMLError error = XMLError::XML_NO_ERROR;

   for( XMLNode* node = handle.FirstChild().ToElement(); node != nullptr; node = node->NextSibling() )
   {
      Pnt3 pnt;
      error = from_handle( pnt, node );
      if( error == XMLError::XML_NO_ERROR )
         pnts.push_back( pnt );
      else
         retrn = error;
   }

   return retrn;
}
