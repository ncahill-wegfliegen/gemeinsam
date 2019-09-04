#pragma once

#include "../../utility/type.h" 
#include <string>
#include "../../../../other/TiXml2/tinyxml2.h"

namespace nhill
{
namespace xml
{

template<typename Object>
tinyxml2::XMLError from_parent_handle( Object& object, tinyxml2::XMLHandle hParent, std::string child_name = "") 
{
   // If no name is provided, then just use the class name as the element name.
   if( child_name.empty() )
      child_name = type::to_name<Object>();

   tinyxml2::XMLHandle handle = hParent.FirstChildElement( child_name.c_str() );

   return from_handle<Object>( object, handle );
}

template<typename Object>
tinyxml2::XMLError from_parent_handle( std::unique_ptr<Object>& uptr_object, tinyxml2::XMLHandle hParent, std::string child_name = "" )
{
   // If no name is provided, then just use the class name as the element name.
   if( child_name.empty() )
      child_name = type::to_name<Object>();

   tinyxml2::XMLHandle handle = hParent.FirstChildElement( child_name.c_str() );

   return from_handle<Object>( uptr_object, handle );
}


}
}
