#pragma once

#include <Core/Core.h>

namespace MUE
{
	struct ApplicationSpecs
	{

	};
	class Application
	{
	public:
		Application(const ApplicationSpecs& specs);
		~Application() = default;

		void Run();
	};

	extern Application* CreateApplication(int argc,char* argv[]);
}