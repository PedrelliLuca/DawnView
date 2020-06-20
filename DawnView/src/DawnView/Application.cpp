#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace DawnView {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			DV_TRACE(e); // logging the WindowResizeEvent
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			DV_TRACE(e); // logging the WindowResizeEvent
		}
		while (true);
	}
}