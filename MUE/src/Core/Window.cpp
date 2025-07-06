#include <muepch.h>
#include <Core/Window.h>

#ifdef MUE_PLATFORM_WINDOWS
#include <Platform/Windows/WindowsWindow.h>
#endif

namespace MUE
{
	Window* Window::Create(uint32_t width, uint32_t height, std::string Title)
	{
		#ifdef MUE_PLATFORM_WINDOWS
		return new WindowsWindow(width,height,Title);
		#else
		return nullptr;
		#endif

	}
}