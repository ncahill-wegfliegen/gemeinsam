#pragma once

#include "gsXmlPort.h"
#include "tixml/tixml2.h"
#include "gs/bll/field.h"
#include "gs/tstring.h"

namespace gs
{
namespace xml
{

/// <summary>Create an xml output element for the given field.</summary>
/// <param name="field">The given field.</param>
/// <param
/// <returns>The xml output element.</returns>
gsXmlPortFunction tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::Field& field, const std::tstring& elementName = SL( "" ) );

/// <summary>Read the field value from the xml input handle.</summary>
/// <param name="field">The gs::Field object into which the element will be read.</param>
/// <param name="hField">The xml input handle for the field element.</param>
/// <returns>True if the read operation is successful; otherwise, false.</returns>
/// <example>
/// The handle should refer to an xml element that looks like 
///   <code>
///     &lt;Field&gt;
///         &lt;Code&gt;1580&lt;/Code&gt;
///         &lt;Name&gt;UPPER MANNVILLE&lt;/Name&gt;
///     &lt;/Field&gt;
///   </code>
/// </example>
gsXmlPortFunction tinyxml2::XMLError from_handle( gs::Field& field, tinyxml2::XMLHandle hField );

}
}

