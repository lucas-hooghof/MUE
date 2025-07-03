project "MUE"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "muepch.h"
	pchsource "muepch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
	}


	includedirs
	{
		"src",
	}

	links
	{
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"
		buildoptions { "/utf-8" }


	filter "configurations:Debug"
		defines "MUE_DEBUG"
		runtime "Debug"
		symbols "on"


	filter "configurations:Release"
		defines "MUE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "MUE_DIST"
		runtime "Release"
		optimize "on"