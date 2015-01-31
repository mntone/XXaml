#pragma once

#ifdef WIN32
#ifdef XXAML_EXPORTS
#define XXAML_IMPORT __declspec( dllexport )
#else
#define XXAML_IMPORT __declspec( dllimport )
#endif
#else
#define XXAML_IMPORT
#endif

#ifdef USE_INTERNAL
#define INTERNAL 1
#endif

#define CPP_METHODS