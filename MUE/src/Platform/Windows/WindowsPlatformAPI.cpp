#include <muepch.h>
#include <Platform/Windows/WindowsPlatformAPI.h>

namespace MUE
{

	void WindowsPlatformAPI::WriteToConsole_Impl(std::string text)
	{
		HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD word = 0;
		WriteConsoleA(out, text.c_str(), text.size(), &word, nullptr);
	}
	uint32_t WindowsPlatformAPI::GetTimeMilliseconds_Impl()
	{
		static LARGE_INTEGER s_frequency;
		static BOOL s_use_qpc = QueryPerformanceFrequency(&s_frequency);
		if (s_use_qpc) {
			LARGE_INTEGER now;
			QueryPerformanceCounter(&now);
			return (1000LL * now.QuadPart) / s_frequency.QuadPart;
		}
		else {
			return GetTickCount64();
		}
	}
	void* WindowsPlatformAPI::GetProcAddress_Impl(const char* procname)
	{
		void* proc = wglGetProcAddress(procname);
		return proc;
	}
}