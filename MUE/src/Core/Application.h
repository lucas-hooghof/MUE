#pragma once

#include <Core/Assert.h>
#include <Core/Base.h>

#include <Core/Timestep.h>

namespace MUE
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void OnUpdate(Timestep dt) = 0;
		virtual void Run() = 0;
	private:
		static Application* s_Instance;
	};
}