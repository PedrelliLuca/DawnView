#pragma once

#include "Core.h"

namespace DawnView {
	
	class DV_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT, i.e. SandBox application
	Application* CreateApplication();

}

