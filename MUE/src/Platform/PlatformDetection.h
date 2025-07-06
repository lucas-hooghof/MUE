#pragma once

#if defined(_WIN32) or defined(_WIN64)
#endif

#ifdef _WIN32
	#ifdef _WIN64
		#define MUE_PLATFORM_WINDOWS
	#else
		#error "x86 Builds are not supported!"
	#endif
#elif defined(__ANDROID__)
	#define MUE_PLATFORM_ANDROID
	#error "Android is not supported!"
#elif defined(__linux__)
	#define MUE_PLATFORM_LINUX
#endif