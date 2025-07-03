#include <muepch.h>	
#include <Platform/PlatformAPI.h>

#include <Platform/Windows/WindowsPlatformAPI.h>

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