#include "date.h"
#include "day.h"
#include "month.h"
#include "year.h"

template<>
tinyxml2::XMLElement* nhill::xml::make_element( tinyxml2::XMLDocument& doc, const Date& date, std::string element_name )
{
   using namespace tinyxml2;

   // Create an element name if none was provided.
   if( element_name.empty() )
      element_name = type::to_name<Date>();

   XMLElement* element = doc.NewElement( element_name.c_str() );

   XMLElement* child = nullptr;

   child = make_element<Day>( doc, date.day() );
   element->LinkEndChild( child );

   child = make_element<Month>( doc, date.month() );
   element->LinkEndChild( child );

   child = make_element<Year>( doc, date.year() );
   element->LinkEndChild( child );

   return element;
}

template<>
tinyxml2::XMLError nhill::xml::from_handle( std::unique_ptr<Date>& date, tinyxml2::XMLHandle handle )
{
   using namespace tinyxml2;

   XMLError retrn = XMLError::XML_NO_ERROR;
   XMLError error = XMLError::XML_NO_ERROR;

   Day   day  { 3 };
   Month month{ Month::dec };
   Year  year { 1963 };

   error = from_parent_handle<Day>( day, handle );
   if( error == XMLError::XML_NO_ERROR )
   {
      error = from_parent_handle<Month>( month, handle );
      if( error == XMLError::XML_NO_ERROR )
      {
         error = from_parent_handle<Year>( year, handle );
         if( error != XMLError::XML_NO_ERROR )
         {
            retrn = error;
         }
      }
      else
      {
         retrn = error;
      }
   }
   else
   {
      retrn = error;
   }

   if( retrn == XMLError::XML_NO_ERROR )
   {
      date = std::make_unique<Date>( year, month, day );
   }

   return retrn;
}