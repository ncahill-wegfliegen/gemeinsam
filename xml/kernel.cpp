#include "core\kernel.h"
#include <sstream>
#include "../log/log.h"

#pragma region read
/// <summary>Create an xml document based on the given file path.</summary>
/// <param name="path">The path to the xml file.<\param>
/// <returns>A pointer to the document.</returns>
tinyxml2::XMLError nhill::xml::make_document( tinyxml2::XMLDocument& doc, const std::string& path )
{
   std::locale locale( "" );

   tinyxml2::XMLError error = doc.LoadFile( path.c_str() );
   if( error != tinyxml2::XML_NO_ERROR )
   {
      std::ostringstream message;
      message << "Path=\"" << path << "\" could not be loaded into the tinyxml2::XMLDocument";
      const char* errorStr1 = doc.GetErrorStr1();
      if( errorStr1 != nullptr )
         message << "; Error Description=" << errorStr1;
      const char* errorStr2 = doc.GetErrorStr2();
      if( errorStr2 != nullptr )
         message << "; Diagnostic=" << errorStr2;
      LOG_ERROR( message.str() );
   }

   return error;
}

/// <summary>Get the handle for the root element in the document.</summary>
/// <param name="document">The xml document.</param>
/// <param name="rootName">The name of the root element in the document.</param>
/// <returns>The handle to the root element of the document.</returns>
tinyxml2::XMLHandle nhill::xml::make_root_handle( tinyxml2::XMLDocument& document, const std::string& rootName )
{
   tinyxml2::XMLHandle hRoot = document.FirstChildElement( rootName.c_str() );
   if( hRoot.ToElement() == nullptr )
   {
      std::ostringstream message;
      message << "Document does not contain a root element called \"" << rootName << "\".";
      LOG_ERROR( message.str() );
      throw std::invalid_argument( message.str() );
   }
   return hRoot;
}
#pragma endregion

#pragma region write
tinyxml2::XMLDeclaration* nhill::xml::make_declaration( tinyxml2::XMLDocument& doc )
{
   tinyxml2::XMLDeclaration* declaration = doc.NewDeclaration( nullptr );
   return declaration;
}
#pragma endregion

#pragma region error
std::string nhill::xml::to_string( tinyxml2::XMLError error )
{
   switch( error )
   {
   case tinyxml2::XML_SUCCESS: return "XML_SUCCESS";
   case tinyxml2::XML_NO_ATTRIBUTE: return "XML_NO_ATTRIBUTE";
   case tinyxml2::XML_WRONG_ATTRIBUTE_TYPE: return "XML_WRONG_ATTRIBUTE_TYPE";
   case tinyxml2::XML_ERROR_FILE_NOT_FOUND: return "XML_ERROR_FILE_NOT_FOUND";
   case tinyxml2::XML_ERROR_FILE_COULD_NOT_BE_OPENED: return "XML_ERROR_FILE_COULD_NOT_BE_OPENED";
   case tinyxml2::XML_ERROR_FILE_READ_ERROR: return "XML_ERROR_FILE_READ_ERROR";
   case tinyxml2::XML_ERROR_ELEMENT_MISMATCH: return "XML_ERROR_ELEMENT_MISMATCH";
   case tinyxml2::XML_ERROR_PARSING_ELEMENT: return "XML_ERROR_PARSING_ELEMENT";
   case tinyxml2::XML_ERROR_PARSING_ATTRIBUTE: return "XML_ERROR_PARSING_ATTRIBUTE";
   case tinyxml2::XML_ERROR_IDENTIFYING_TAG: return "XML_ERROR_IDENTIFYING_TAG";
   case tinyxml2::XML_ERROR_PARSING_TEXT: return "XML_ERROR_PARSING_TEXT";
   case tinyxml2::XML_ERROR_PARSING_CDATA: return "XML_ERROR_PARSING_CDATA";
   case tinyxml2::XML_ERROR_PARSING_COMMENT: return "XML_ERROR_PARSING_COMMENT";
   case tinyxml2::XML_ERROR_PARSING_DECLARATION: return "XML_ERROR_PARSING_DECLARATION";
   case tinyxml2::XML_ERROR_PARSING_UNKNOWN: return "XML_ERROR_PARSING_UNKNOWN";
   case tinyxml2::XML_ERROR_EMPTY_DOCUMENT: return "XML_ERROR_EMPTY_DOCUMENT";
   case tinyxml2::XML_ERROR_MISMATCHED_ELEMENT: return "XML_ERROR_MISMATCHED_ELEMENT";
   case tinyxml2::XML_ERROR_PARSING: return "XML_ERROR_PARSING";
   case tinyxml2::XML_CAN_NOT_CONVERT_TEXT: return "XML_CAN_NOT_CONVERT_TEXT";
   case tinyxml2::XML_NO_TEXT_NODE: return "XML_NO_TEXT_NODE";
   case tinyxml2::XML_ERROR_COUNT: return "XML_ERROR_COUNT";
   default: return "";
   }
}

std::string nhill::xml::to_label( tinyxml2::XMLError error )
{
   switch( error )
   {
   case tinyxml2::XML_SUCCESS: return "Success";
   case tinyxml2::XML_NO_ATTRIBUTE: return "No Attribute";
   case tinyxml2::XML_WRONG_ATTRIBUTE_TYPE: return "Wrong Attribute Type";
   case tinyxml2::XML_ERROR_FILE_NOT_FOUND: return "File Not Found";
   case tinyxml2::XML_ERROR_FILE_COULD_NOT_BE_OPENED: return "File Could Not Be Opened";
   case tinyxml2::XML_ERROR_FILE_READ_ERROR: return "File Read Error";
   case tinyxml2::XML_ERROR_ELEMENT_MISMATCH: return "Element Mismatch";
   case tinyxml2::XML_ERROR_PARSING_ELEMENT: return "Error Parsing Element";
   case tinyxml2::XML_ERROR_PARSING_ATTRIBUTE: return "Error Parsing Attribute";
   case tinyxml2::XML_ERROR_IDENTIFYING_TAG: return "Error Identifying Tag";
   case tinyxml2::XML_ERROR_PARSING_TEXT: return "Error Parsing Text";
   case tinyxml2::XML_ERROR_PARSING_CDATA: return "Error Parsing CData";
   case tinyxml2::XML_ERROR_PARSING_COMMENT: return "Error Parsing Comment";
   case tinyxml2::XML_ERROR_PARSING_DECLARATION: return "Error Parsing Declaration";
   case tinyxml2::XML_ERROR_PARSING_UNKNOWN: return "Unknown Parsing Error";
   case tinyxml2::XML_ERROR_EMPTY_DOCUMENT: return "Empty Document";
   case tinyxml2::XML_ERROR_MISMATCHED_ELEMENT: return "Mismatched Element";
   case tinyxml2::XML_ERROR_PARSING: return "Parsing Error";
   case tinyxml2::XML_CAN_NOT_CONVERT_TEXT: return "Cannot Convert Text";
   case tinyxml2::XML_NO_TEXT_NODE: return "No Text Node";
   case tinyxml2::XML_ERROR_COUNT: return "Error Count";
   default: return "";
   }
}
#pragma endregion
