#pragma once

#include "gsXmlPort.h"
#include "tixml/tixml2.h"
#include "gs/bll/pool.h"
#include "gs/tstring.h"

namespace gs
{
namespace xml
{

/// <summary>Create an xml output element for the given pool.</summary>
/// <param name="pool">The given pool.</param>
/// <param
/// <returns>The xml output element.</returns>
gsXmlPortFunction tinyxml2::XMLElement* make_element( tinyxml2::XMLDocument& doc, const gs::Pool& pool, const std::tstring& elementName = SL( "" ) );

/// <summary>Read the pool value from the xml input handle.</summary>
/// <param name="pool">The gs::Pool object into which the element will be read.</param>
/// <param name="hPool">The xml input handle for the pool element.</param>
/// <returns>True if the read operation is successful; otherwise, false.</returns>
/// <example>
/// The handle should refer to an xml element that looks like 
///   <code>
///     &lt;Pool&gt;
///         &lt;Code&gt;1580&lt;/Code&gt;
///         &lt;Name&gt;UPPER MANNVILLE&lt;/Name&gt;
///     &lt;/Pool&gt;
///   </code>
/// </example>
gsXmlPortFunction tinyxml2::XMLError from_handle( gs::Pool& pool, tinyxml2::XMLHandle hPool );

}
}

