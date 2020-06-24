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

#ifdef DV_ENABLE_ASSERTS
	#define DV_ASSERT(x, ...) {if(!x) {DV_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
	#define DV_CORE_ASSERT(x, ...) {if(!x) {DV_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
#else
	#define DV_ASSERT(x, ...)
	#define DV_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)