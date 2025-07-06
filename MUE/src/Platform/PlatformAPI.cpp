#include <muepch.h>	
#include <Platform/PlatformAPI.h>

#ifdef MUE_PLATFORM_WINDOWS
#include <Platform/Windows/WindowsPlatformAPI.h>
#endif

namespace MUE
{
	PlatformAPI* PlatformAPI::s_Instance;

	void PlatformAPI::Initlize()
	{
		#ifdef MUE_PLATFORM_WINDOWS
			s_Instance = new WindowsPlatformAPI;
		#endif
	}
}