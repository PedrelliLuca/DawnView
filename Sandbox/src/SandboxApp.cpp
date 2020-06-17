#include <DawnView.h>

class SandBox : public DawnView::Application
{
public:
	SandBox()
	{

	}

	~SandBox()
	{

	}
};

DawnView::Application* DawnView::CreateApplication()
{
	return new SandBox();
}