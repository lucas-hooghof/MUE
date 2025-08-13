#pragma once

#include <Core/Application.h>

int main(int argc, char* argv[])
{
	MUE::Application* app = MUE::CreateApplication(argc,argv);
	app->Run();
	delete app;

	return 0;
}