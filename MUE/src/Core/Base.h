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
#elif defined(MUE_PLATFORM_LINUX)
	#define MUE_BREAK() __builtin_trap()
#else
	#error "MUE Only supports Windows and linux"
#endif

#include <cstdint>