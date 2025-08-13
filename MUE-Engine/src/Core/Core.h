#pragma once

#include <Core/PlatformDetection.h>

#ifdef MUE_PLATFORM_WINDOWS
#include <Windows.h>
#ifdef MUE_DEBUG
#define MUE_BREAK() __debugbreak()
#endif
#endif

#include <cstdint>
