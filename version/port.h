///////////////////////////////////////////////////////////////////////
//
// File: nhill\version\port.h
// Date: 25 Jun 2015 nhill
//
// Definitions for exporting/importing library elements.
// Define NHILL_VERSION_STATIC if the module is a static library, 
// or if you want to use the code directly.
// Define NHILL_VERSION_EXPORT if the module is dynamic (shared) library.
//
// NHILL_VERSION_PORT_CLASS      export/import a class
// NHILL_VERSION_PORT_CFUNCTION  export/import a "C" function
// NHILL_VERSION_PORT_FUNCTION   export/import a function( which is not a "C" function )
// NHILL_VERSION_PORT_OPTION     export/import a template instantiation
// NHILL_VERSION_PORT_FIELD      export/import a field 
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

#ifdef NHILL_VERSION_STATIC
#   ifndef NHILL_VERSION_PORT_CLASS
#       define NHILL_VERSION_PORT_CLASS
#   endif
#   ifndef NHILL_VERSION_PORT_CFUNCTION
#       define NHILL_VERSION_PORT_CFUNCTION
#   endif
#   ifndef NHILL_VERSION_PORT_FUNCTION
#       define NHILL_VERSION_PORT_FUNCTION
#   endif
#   ifndef NHILL_VERSION_PORT_OPTION
#       define NHILL_VERSION_PORT_OPTION
#   endif
#   ifndef NHILL_VERSION_PORT_FIELD
#       define NHILL_VERSION_PORT_FIELD
#   endif
#else
#   ifdef NHILL_VERSION_EXPORT
#       ifndef NHILL_VERSION_PORT_CLASS
#           define NHILL_VERSION_PORT_CLASS __declspec(dllexport)
#       endif
#       ifndef NHILL_VERSION_PORT_CFUNCTION
#           define NHILL_VERSION_PORT_CFUNCTION extern "C" __declspec(dllexport)
#       endif
#       ifndef NHILL_VERSION_PORT_FUNCTION
#           define NHILL_VERSION_PORT_FUNCTION __declspec(dllexport)
#       endif
#       ifndef NHILL_VERSION_PORT_OPTION
#           define NHILL_VERSION_PORT_OPTION
#       endif
#       ifndef NHILL_VERSION_PORT_FIELD
#           define NHILL_VERSION_PORT_FIELD __declspec(dllexport)
#       endif
#   else
#       ifndef NHILL_VERSION_PORT_CLASS
#           define NHILL_VERSION_PORT_CLASS __declspec(dllimport)
#       endif
#       ifndef NHILL_VERSION_PORT_CFUNCTION
#           define NHILL_VERSION_PORT_CFUNCTION extern "C" __declspec(dllimport)
#       endif
#       ifndef NHILL_VERSION_PORT_FUNCTION
#           define NHILL_VERSION_PORT_FUNCTION __declspec(dllimport)
#       endif
#       ifndef NHILL_VERSION_PORT_OPTION
#           define NHILL_VERSION_PORT_OPTION extern
#       endif
#       ifndef NHILL_VERSION_PORT_FIELD
#           define NHILL_VERSION_PORT_FIELD __declspec(dllimport)
#       endif
#   endif
#endif
