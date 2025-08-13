#include <MUE.h>

class Sandbox : public MUE::Application
{
public:
	Sandbox(const MUE::ApplicationSpecs& specs)
		:MUE::Application(specs)
	{

	}
};

MUE::Application* MUE::CreateApplication(int argc, char* argv[])
{
	MUE::ApplicationSpecs specs;
	return new Sandbox(specs);
}