#include <muepch.h>

#include <Platform/Windows/WindowsWindow.h>

namespace MUE
{
	std::wstring StringToWString(const std::string& str) {
		if (str.empty()) return std::wstring();

		int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), NULL, 0);
		std::wstring wstr(size_needed, 0);
		MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), &wstr[0], size_needed);
		return wstr;
	}


	WindowsWindow::WindowsWindow(uint32_t width, uint32_t height, std::string Title)
	{
		m_windowdata.width = width;
		m_windowdata.height = height;
		m_windowdata.Title = Title;
		m_windowdata.IsRunning = true;

		m_HInstance = GetModuleHandle(nullptr);
		
		this->Initlize();
	}

	WindowsWindow::~WindowsWindow()
	{
		this->Shutdown();
	}

	void WindowsWindow::Initlize()
	{

		WNDCLASSEX wc = { 0 };
		wc.cbSize = sizeof(wc);
		wc.lpszClassName = L"WindowsWindow";
		wc.hInstance = m_HInstance;
		wc.cbWndExtra = sizeof(WindowData);
		wc.hbrBackground = nullptr;
		wc.hCursor = nullptr;
		wc.hIcon = nullptr;
		wc.hIconSm = nullptr;
		wc.lpszMenuName = nullptr;
		wc.lpfnWndProc = HandleMSG;
		wc.style = CS_OWNDC;

		RegisterClassEx(&wc);
		RECT wr;
		wr.left = 100;
		wr.right = m_windowdata.width + wr.left;
		wr.top = 100;
		wr.bottom = m_windowdata.height + wr.top;
		if (AdjustWindowRect(&wr, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, FALSE) == 0)
		{
			MFATAL_CORE("Failed to Adjust window rect");
			exit(1);
		}

		m_HwndHandle = CreateWindow(
			L"WindowsWindow", StringToWString(m_windowdata.Title).c_str() ,
			WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
			CW_USEDEFAULT, CW_USEDEFAULT, wr.right - wr.left, wr.bottom - wr.top,
			nullptr, nullptr, m_HInstance, nullptr
		);

		if (m_HwndHandle == nullptr)
		{
			MFATAL_CORE("Failed to create window");
			exit(1);
		}

		SetWindowLongPtrA(m_HwndHandle, GWLP_USERDATA, (LONG_PTR)(&m_windowdata));

		ShowWindow(m_HwndHandle, SW_SHOW);

		m_HDC = GetDC(m_HwndHandle);


		PIXELFORMATDESCRIPTOR pfd = {};
		pfd.nSize = sizeof(pfd);
		pfd.nVersion = 1;
		pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pfd.iPixelType = PFD_TYPE_RGBA;
		pfd.cColorBits = 32;
		pfd.cDepthBits = 24;
		pfd.cStencilBits = 8;
		pfd.iLayerType = PFD_MAIN_PLANE;

		int pixelformat = ChoosePixelFormat(m_HDC, &pfd);
		SetPixelFormat(m_HDC, pixelformat, &pfd);

		m_HGLRC = wglCreateContext(m_HDC);
		wglMakeCurrent(m_HDC, m_HGLRC);


	}

	void WindowsWindow::Shutdown()
	{
		DestroyWindow(m_HwndHandle);
		UnregisterClassW(L"WindowsWindow", m_HInstance);
	}

	LRESULT WindowsWindow::HandleMSG(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_CLOSE:
			PostQuitMessage(0);
			WindowData& data = *(WindowData*)GetWindowLongPtrA(hWnd, GWLP_USERDATA);
			data.IsRunning = false;
			break;
		}

		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	void WindowsWindow::OnUpdate()
	{
		MSG msg;
		while (PeekMessage(&msg, m_HwndHandle, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}