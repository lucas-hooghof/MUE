#pragma once

#include <Platform/PlatformAPI.h>
#include <Core/Log.h>

#include <Core/Application.h>

int main(int argc, char* argv[])
{
	MUE::PlatformAPI::Initlize();
#ifdef MUE_DEBUG
	MTRACE_CORE("PlatformAPI Initlized");
#endif
	auto app = MUE::CreateApplication(argc, argv);
	app->Run();
	delete app;
	return 0;

}