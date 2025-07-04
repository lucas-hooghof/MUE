#pragma once

#include <Core/Assert.h>
#include <Core/Base.h>

#include <Core/Timestep.h>
#include <Core/Window.h>

namespace MUE
{
	struct ApplicationSpecs
	{
		std::string Title;
		uint32_t width;
		uint32_t height;
	};

	class Application
	{
	public:
		Application(const ApplicationSpecs& specs);
		virtual ~Application();

		virtual void OnUpdate(Timestep dt);
		virtual void Run();

		static Application* GetInstance() {
			MUE_ASSERT(s_Instance != nullptr);
			return s_Instance;
		}

	private:
		static Application* s_Instance;
		float m_lasttime;
		Window* m_window;
	};

	Application* CreateApplication(int argc, char* argv[]);
}