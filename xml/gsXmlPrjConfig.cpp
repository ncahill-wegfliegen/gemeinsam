#include "gsXmlPrjConfig.h"
//#include "gsXmlUtility.h"
#include "gsXmlIO.h"

namespace gs
{
namespace xml
{

tinyxml2::XMLError read_cm(double & cm, const std::tstring & pathPrjConfig, const std::tstring & groupName, const std::tstring & gridFileTitle)
{
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLError error = gs::xml::make_document(doc, pathPrjConfig);
	if( error != tinyxml2::XML_NO_ERROR )
		return error;
	
	std::string groupNameA = gs::str::utf8(groupName);
	std::string gridFileTitleA = gs::str::utf8(gridFileTitle);

	tinyxml2::XMLHandle hGsProject = gs::xml::make_root_handle(doc, SL("gsProject"));
	tinyxml2::XMLHandle hOvlSettings = hGsProject.FirstChildElement("ovlsettings");

	tinyxml2::XMLHandle hUserGroup = hOvlSettings.FirstChildElement("usergroup");
	for( ; hUserGroup.ToNode() != nullptr; hUserGroup = hUserGroup.NextSiblingElement("usergroup") )
	{
		tinyxml2::XMLElement* elmUserGroup = hUserGroup.ToElement();
		if( elmUserGroup == nullptr )
			continue;

		// The group name attribute of this element
		const char* groupNameElm = elmUserGroup->Attribute("groupname");
		if( groupNameElm == nullptr )
			continue;

		// Is this the group we are looking for?
		if( strcmp(groupNameElm, groupNameA.c_str()) == 0 )
			break;
	}

	if( hUserGroup.ToNode() == nullptr )
		return tinyxml2::XMLError::XML_ERROR_PARSING_ATTRIBUTE;

	// Search all of the "gridgroup" elements until we find the one
	// that matches the given grid file title.
	tinyxml2::XMLHandle hGridGroup = hUserGroup.FirstChildElement("gridgroup");
	for( ; hGridGroup.ToNode() != nullptr; hGridGroup = hGridGroup.NextSiblingElement("gridgroup") )
	{
		tinyxml2::XMLElement* elmGridGroup = hGridGroup.ToElement();
		if( elmGridGroup == nullptr )
			continue; 

		// The grid file attribute of this element
		std::string gridFileTitleElm = elmGridGroup->Attribute("gridfile");
		
		// Strip the extension
		size_t pos = gridFileTitleElm.find_last_of(".");
		if( pos == std::tstring::npos )
			continue;	// something is wrong with the path.  It doesn't have an extension.
		gridFileTitleElm = gridFileTitleElm.substr(0, pos);

		// Strip the directory
		pos = gridFileTitleElm.find_last_of("\\");
		if( pos == std::tstring::npos )
			continue;	// something is wrong with the path.  It doesn't have an directory.
		gridFileTitleElm = gridFileTitleElm.substr(pos + 1);

		// Is this the grid file title we are looking for?
		if( strcmp(gridFileTitleElm.c_str(), gridFileTitleA.c_str()) == 0 )
			break;
	}

	if( hGridGroup.ToNode() == nullptr )
		return tinyxml2::XMLError::XML_ERROR_FILE_NOT_FOUND;

	// The central meridian string
	const char* cms = hGridGroup.ToElement()->Attribute("cm");
	if( cms == nullptr )
		return tinyxml2::XMLError::XML_NO_ATTRIBUTE;

	// Convert the central meridian to a double
	cm = std::stod(cms);

	return tinyxml2::XMLError::XML_SUCCESS;
}

tinyxml2::XMLError read_cm(double & cm, const std::tstring & pathGrid)
{
	size_t posPeriod = pathGrid.find_last_of(SL("."));
	if( posPeriod == std::tstring::npos )
		return tinyxml2::XMLError::XML_ERROR_PARSING;	// something is wrong with the path.  It doesn't have an extension.

	size_t posSlash = pathGrid.find_last_of(SL("\\"));
	if( posPeriod == std::tstring::npos )
		return tinyxml2::XMLError::XML_ERROR_PARSING;	// something is wrong with the path.  It doesn't have an directory.

	std::tstring gridFileTitle = pathGrid.substr(posSlash + 1, posPeriod - posSlash - 1);
	std::tstring pathPrjConfig = pathGrid.substr(0, posSlash);

	posSlash = pathPrjConfig.find_last_of(SL("\\"));
	if( posPeriod == std::tstring::npos )
		return tinyxml2::XMLError::XML_ERROR_PARSING;	// something is wrong with the path.  It doesn't have an directory.

	std::tstring groupName = pathPrjConfig.substr(posSlash + 1);

	pathPrjConfig = pathPrjConfig.substr(0, posSlash + 1) + SL("Project.gscfg8");
														   
	return read_cm( cm, pathPrjConfig, groupName, gridFileTitle);
}

}
}