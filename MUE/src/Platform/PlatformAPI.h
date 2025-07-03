#pragma once

#include <Core/Base.h>

#include <string>
namespace MUE
{
	class PlatformAPI
	{
	public:
		static void Initlize();

		static void WriteToConsole(std::string text) { s_Instance->WriteToConsole_Impl(text); }

		static float GetTimeMilliseconds() {return (float) s_Instance->GetTimeMilliseconds_Impl(); }
	protected:
		virtual void WriteToConsole_Impl(std::string text) = 0;
		virtual uint32_t GetTimeMilliseconds_Impl() = 0;
	private:
		static PlatformAPI* s_Instance;
	};
}