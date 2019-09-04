#pragma once

#include "..\port.h"
#include "kernel.h"
#include "../../log/log.h"
#include <string>
#include <sstream>
#include "../../utility/type.h" 
#include "../../../../other/TiXml2/tinyxml2.h"

namespace nhill
{
namespace xml
{

/// <summary>Read the value of the text from the given file.  This assumes that the text is the only element in the file.</summary>
/// <param name="text">The std::string object into which the element will be read.</param>
/// <param name="path">The file from which to read the text.</param>
/// <returns>True if the read operation is successful; otherwise, false.</returns>
template<typename Object>
tinyxml2::XMLError read( Object& object, const std::string& path, std::string root_name = "" )
{
   using namespace tinyxml2;

   if( root_name.empty() )
      root_name = type::to_name<Object>();

   XMLDocument doc;
   XMLError error = make_document( doc, path );
   if( error != XMLError::XML_NO_ERROR )
   {
      std::ostringstream msg;
      msg << "nhill::xml::read. Failed to create document for "  << root_name << " in the file " << path << ". "  << to_label( error ) << "." ;
      LOG_ERROR( msg.str() );
      return error;
   }

   XMLHandle hRoot = make_root_handle( doc, root_name );
   error = from_handle<Object>( object, hRoot );
   if( error != XMLError::XML_NO_ERROR )
   {
      std::ostringstream msg;
      msg << "nhill::xml::read. Failed to read " << root_name << " from the file " << path << ". " << to_label( error ) << ".";
      LOG_ERROR( msg.str() );
      return error;
   }

   return XMLError::XML_SUCCESS;
}

template<typename Object>
tinyxml2::XMLError read( std::unique_ptr<Object>& uptr_object, const std::string& path, std::string root_name = "" )
{
   using namespace tinyxml2;

   if( root_name.empty() )
      root_name = type::to_name<Object>();

   XMLDocument doc;
   XMLError error = make_document( doc, path );
   if( error != XMLError::XML_SUCCESS )
   {
      std::ostringstream msg;
      msg << "nhill::xml::read. Failed to create document for " << root_name << " in the file " << path << ". " << to_label( error ) << ".";
      LOG_ERROR( msg.str() );
      return error;
   }

   XMLHandle hRoot = make_root_handle( doc, root_name );
   error = from_handle<Object>( uptr_object, hRoot );
   if( error != XMLError::XML_SUCCESS )
   {
      std::ostringstream msg;
      msg << "nhill::xml::read. Failed to read " << root_name << " from the file " << path << ". " << to_label( error ) << ".";
      LOG_ERROR( msg.str() );
      return error;
   }

   return XMLError::XML_SUCCESS;
}

}
}