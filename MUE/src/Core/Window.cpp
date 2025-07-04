#include <muepch.h>
#include <Core/Window.h>

#include <Platform/Windows/WindowsWindow.h>

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