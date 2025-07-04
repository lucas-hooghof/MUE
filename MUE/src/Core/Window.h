#pragma once

#include <Core/Base.h>
#include <Core/Assert.h>


namespace MUE
{

	class Window
	{
	public:

		virtual void* GetNativeWindow() = 0;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void OnUpdate() = 0;

		virtual bool IsWindowOpen() const = 0;

		static Window* Create(uint32_t width, uint32_t height, std::string Title);
	};
}