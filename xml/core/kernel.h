#pragma once

#include "..\port.h"
#include <string>
#include "../../../../other/TiXml2/tinyxml2.h"

namespace nhill
{
namespace xml
{

#pragma region read
/// <summary>Create an xml document based on the given file path.</summary>
/// <param name="path">The path to the xml file.<\param>
/// <returns>A pointer to the document.</returns>
NHILL_XML_PORT_FUNCTION
tinyxml2::XMLError make_document( tinyxml2::XMLDocument& doc, const std::string& path );

/// <summary>Get the handle for the root element in the document.</summary>
/// <param name="document">The xml document.</param>
/// <param name="rootName">The name of the root element in the document.</param>
/// <returns>The handle to the root element of the document.</returns>
NHILL_XML_PORT_FUNCTION
tinyxml2::XMLHandle make_root_handle( tinyxml2::XMLDocument& document, const std::string& rootName );
#pragma endregion

#pragma region write
NHILL_XML_PORT_FUNCTION
tinyxml2::XMLDeclaration* make_declaration( tinyxml2::XMLDocument& doc );
#pragma endregion

#pragma region error
NHILL_XML_PORT_FUNCTION std::string to_string( tinyxml2::XMLError error );
NHILL_XML_PORT_FUNCTION std::string to_label( tinyxml2::XMLError error );
#pragma endregion
}
}

