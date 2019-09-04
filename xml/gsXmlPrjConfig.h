#pragma once

#include "gsXmlPort.h"
#include "tixml/tixml2.h"
#include "gs/tstring.h"

namespace gs
{
namespace xml
{

/// <summary>Read the geoSCOUT project configuration file and get the central meridian for the grid file in the user group.</summary>
/// <param name="cm">Out.  The central meridian of the grid file.</param>
/// <param name="pathPrjConfig">The full path of the geoSCOUT configuration file; e.g., "C:\Users\nhill\Documents\geoSCOUT\Projects\13-013W4\Project.gscfg8".</param>
/// <param name="groupName">The name of the group.  A subdirectory of the project directory; e.g., "Working".</param>
/// <param name="gridFileTitle">The file title of a surfer grid file in the group; e.g., "Fmtn(Elev)-Kbfs".</param>
/// <returns>XML_SUCCESS if the central meridian is obtained successfully; otherwise, an error code.</returns>
gsXmlPortFunction tinyxml2::XMLError read_cm( double& cm, const std::tstring& pathPrjConfig, const std::tstring& groupName, const std::tstring& gridFileTitle);


/// <summary>Read the geoSCOUT project configuration file and get the central meridian for the grid file in the user group.</summary>
/// <param name="cm">Out.  The central meridian of the grid file.</param>
/// <param name="pathGrid">The full path of a surfer grid file.  It must be in a geoSCOUT project directory.
///		<para>e.g., "C:\Users\nhill\Documents\geoSCOUT\Projects\13-013W4\Working\Fmtn(Elev) - Kbfs.grd".</para>
/// </param>
/// <returns>XML_SUCCESS if the central meridian is obtained successfully; otherwise, an error code.</returns>
gsXmlPortFunction tinyxml2::XMLError read_cm(double& cm, const std::tstring& pathGrid);

}
}
