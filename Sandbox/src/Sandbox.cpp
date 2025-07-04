#include <MUE.h>

class Sandbox : public MUE::Application
{
public:
	Sandbox(const MUE::ApplicationSpecs& spec)
		:Application(spec)
	{

	}
private:
};

MUE::Application* MUE::CreateApplication(int argc,char* argv[])
{
	MUE::ApplicationSpecs spec;
	spec.Title = "Sandbox";
	spec.width = 1280;
	spec.height = 720;
	return new Sandbox(spec);
}