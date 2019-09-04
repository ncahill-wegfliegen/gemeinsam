///////////////////////////////////////////////////////////////////////
//
// File: nhill\xml\port.h
// Date: 25 Jun 2015 nhill
//
// Definitions for exporting/importing library elements.
// Define GEOSCOUT_XML_STATIC if the module is a static library, 
// or if you want to use the code directly.
// Define GEOSCOUT_XML_EXPORT if the module is dynamic (shared) library.
//
// GS_XML_PORT_CLASS      export/import a class
// GS_XML_PORT_CFUNCTION  export/import a "C" function
// GS_XML_PORT_FUNCTION   export/import a function( which is not a "C" function )
// GS_XML_PORT_TEMPLATE   export/import a template instantiation
// 
// Copyright (c) 2015 geoLOGIC systems, ltd.  All rights reserved.
//
// NONDISCLOSURE
//   This is proprietary software of geoLOGIC systems, ltd.
//   This software is considered to contain trade secret information,
//   the exclusive rights to whom belong to geoLOGIC systems, ltd.
//   Source code may NOT be disclosed to any person without prior
//   written permission of geoLOGIC systems, ltd. Object code may be
//   disclosed or transmitted upon proper licensing.
//
///////////////////////////////////////////////////////////////////////
#pragma once

#ifdef GEOSCOUT_XML_STATIC
#   ifndef GS_XML_PORT_CLASS
#       define GS_XML_PORT_CLASS
#   endif
#   ifndef GS_XML_PORT_CFUNCTION
#       define GS_XML_PORT_CFUNCTION
#   endif
#   ifndef GS_XML_PORT_FUNCTION
#       define GS_XML_PORT_FUNCTION
#   endif
#   ifndef GS_XML_PORT_TEMPLATE
#       define GS_XML_PORT_TEMPLATE
#   endif
#else
#   ifdef GEOSCOUT_XML_EXPORT
#       ifndef GS_XML_PORT_CLASS
#           define GS_XML_PORT_CLASS __declspec(dllexport)
#       endif
#       ifndef GS_XML_PORT_CFUNCTION
#           define GS_XML_PORT_CFUNCTION extern "C" __declspec(dllexport)
#       endif
#       ifndef GS_XML_PORT_FUNCTION
#           define GS_XML_PORT_FUNCTION __declspec(dllexport)
#       endif
#       ifndef GS_XML_PORT_TEMPLATE
#           define GS_XML_PORT_TEMPLATE
#       endif
#   else
#       ifndef GS_XML_PORT_CLASS
#           define GS_XML_PORT_CLASS __declspec(dllimport)
#       endif
#       ifndef GS_XML_PORT_CFUNCTION
#           define GS_XML_PORT_CFUNCTION extern "C" __declspec(dllimport)
#       endif
#       ifndef GS_XML_PORT_FUNCTION
#           define GS_XML_PORT_FUNCTION __declspec(dllimport)
#       endif
#       ifndef GS_XML_PORT_TEMPLATE
#           define GS_XML_PORT_TEMPLATE extern
#       endif
#   endif
#endif
