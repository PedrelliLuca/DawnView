#pragma once

#ifdef DV_PLATFORM_WINDOWS
	#if DV_BUILD_DLL
		#define DV_API __declspec(dllexport)
	#else
		# define DV_API __declspec(dllimport)
	#endif // DV_BUILD_DLL	
#else
	#error DawnView only supports Windows!
#endif // DV_PLATFORM_WINDOWS

#define BIT(x) (1 << x)