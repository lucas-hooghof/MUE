#pragma once

#include <Platform/PlatformAPI.h>

namespace MUE
{
	class WindowsPlatformAPI : public PlatformAPI
	{
	protected:
		virtual void WriteToConsole_Impl(std::string text) override;

		virtual uint32_t GetTimeMilliseconds_Impl() override;
	public:
		WindowsPlatformAPI();
	private: 
		DWORD StartTick;
	};
}