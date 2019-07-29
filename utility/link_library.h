#pragma once

#if defined(_UNICODE)
    #if defined(_DEBUG)
        #define GEOSCOUT_LINK_LIBRARY(LIBRARY_TITLE) __pragma(comment(lib, LIBRARY_TITLE##"UD" ))
    #else
        #define GEOSCOUT_LINK_LIBRARY(LIBRARY_TITLE) __pragma(comment(lib, LIBRARY_TITLE##"U" ))
    #endif
    #else
    #if defined(_DEBUG)
        #define GEOSCOUT_LINK_LIBRARY(LIBRARY_TITLE) __pragma(comment(lib, LIBRARY_TITLE##"D" ))
    #else
        #define GEOSCOUT_LINK_LIBRARY(LIBRARY_TITLE) __pragma(comment(lib, LIBRARY_TITLE ))
    #endif
#endif
