#include <muepch.h>

#include <Core/Application.h>

namespace MUE
{
	Application* Application::s_Instance;

	Application::Application(const ApplicationSpecs& specs)
	{
		MUE_ASSERT(s_Instance == nullptr);
		s_Instance = this;

		m_window = Window::Create(specs.width, specs.height, specs.Title);
		m_lasttime = PlatformAPI::GetTimeMilliseconds();
	}

	Application::~Application()
	{
	}

	void Application::OnUpdate(Timestep dt)
	{
		m_window->OnUpdate();
	}

	void Application::Run()
	{
		while (m_window->IsWindowOpen())
		{
			float curr = PlatformAPI::GetTimeMilliseconds();
			Timestep dt = curr - m_lasttime;
			m_lasttime = curr;
			this->OnUpdate(dt);
		}
	}
}