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
	#if __has_include("X11/Xlib.h")
	#define MUE_X11_WAYLAND
	#elif __has_include("wayland-client.h")
	#define MUE_DWM_WAYLAND
	#endif
#else
	#error "Unknown platform!"
#endif 
