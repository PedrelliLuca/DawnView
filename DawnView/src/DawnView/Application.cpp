#include "dvpch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace DawnView {

	Application::Application()
	{
		// You need to wrap Window::Create() because unique_ptr constructor is explicit
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();  
		}
	}
}