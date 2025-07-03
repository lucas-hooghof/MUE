#pragma once

#include <Platform/PlatformAPI.h>
#include <Core/Log.h>

int main(int argc, char* argv)
{
	MUE::PlatformAPI::Initlize();
#ifdef MUE_DEBUG
	MTRACE_CORE("PlatformAPI Initlized");
#endif
	return 0;

}