#pragma once

#include <Platform/PlatformDetection.h>

#ifdef MUE_PLATFORM_WINDOWS
	#define _WIN32_WINNT 0x0601
	#include <sdkddkver.h>
	
	#define WIN32_LEAN_AND_MEAN
	#define NOMINMAX
	#define STRICT
	
	#include <Windows.h>

	#define MUE_BREAK() __debugbreak()
#else
	#error "MUE Only supports Windows"
#endif

