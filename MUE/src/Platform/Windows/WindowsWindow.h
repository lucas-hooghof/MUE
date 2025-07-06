#pragma once

#include <Core/Window.h>

namespace MUE
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(uint32_t width,uint32_t height,std::string Title);
		virtual ~WindowsWindow();

		virtual void* GetNativeWindow() { return m_HwndHandle; }
		virtual uint32_t GetWidth() const { return m_windowdata.width; }
		virtual uint32_t GetHeight() const { return m_windowdata.height; }

		virtual void OnUpdate();
		virtual bool IsWindowOpen() const { return m_windowdata.IsRunning; }
	private:
		void Initlize();
		void Shutdown();

		static LRESULT CALLBACK HandleMSG(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	private:
		struct WindowData
		{
			uint32_t width, height;
			std::string Title;

			bool IsRunning;
		};

		WindowData m_windowdata;
		HWND m_HwndHandle;
		HINSTANCE m_HInstance;

		HDC m_HDC;
		HGLRC m_HGLRC;
	};
}