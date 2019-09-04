#pragma once

#include "kernel.h"
#include "../../utility/type.h" 
#include "../../../../other/TiXml2/tinyxml2.h"
#include <sstream>

namespace nhill
{
namespace xml
{

template<typename Object>
/// <summary>Write the given text out to the given file.  The text will be the only element in the file.</summary>
/// <param name="path">The path of the file to which the text is written.</param>
/// <param name="text">The text to be written to the file.</param>
/// <returns>TinyXml error enumeration.</returns>
tinyxml2::XMLError write( const std::string& path, const Object& object, std::string root_name = "" )
{
   using namespace tinyxml2;

   if( root_name.empty() )
      root_name = nhill::type::to_name<Object>();

   tinyxml2::XMLDocument doc;

   doc.LinkEndChild( make_declaration( doc ) );
   doc.LinkEndChild( make_element<Object>( doc, object, root_name ) );

   XMLError error = doc.SaveFile( path.c_str() );
   if( error != XMLError::XML_SUCCESS )
   {
      std::ostringstream msg;
      msg << "nhill::xml::write. Failed to write " << root_name << " to the file " << path << ". " << to_label( error ) << ".";
      LOG_ERROR( msg.str() );
      return error;
   }

   return XMLError::XML_SUCCESS;
}

}
}


