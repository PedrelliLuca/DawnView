#pragma once

#ifdef DV_PLATFORM_WINDOWS

extern DawnView::Application* DawnView::CreateApplication();

// windows specific main, to retrieve infos about how the program was run
int main(int argc, char** argv)
{
	// heap allocate because sandboxes can be very large
	auto application = DawnView::CreateApplication();
	application->Run();
	delete application;
}

#endif