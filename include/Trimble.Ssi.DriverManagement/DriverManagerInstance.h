#ifndef DRIVERMANAGERINSTANCE_H_
#define DRIVERMANAGERINSTANCE_H_
#if defined(_WIN32) && !defined(STATIC_SSI_DRIVER)
#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)
#else
#define DLLEXPORT
#define DLLIMPORT
#endif

#ifdef DRIVERMANAGERINSTANCE_EXPORT
#define DRIVERMANAGERINSTANCE_API DLLEXPORT
#else
#define DRIVERMANAGERINSTANCE_API DLLIMPORT
#endif

#include "IDriverManager.h"

DRIVERMANAGERINSTANCE_API SSI::IDriverManager& getDriverManagerInstance();

DRIVERMANAGERINSTANCE_API std::string getSsiVersion();

#endif /* DRIVERMANAGERINSTANCE_H_ */

