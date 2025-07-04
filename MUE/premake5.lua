project "MUE"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "muepch.h"
	pchsource "src/muepch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
	}
    removefiles {
        "src/MUE/Platform/Windows/**"
    }

	includedirs
	{
		"src",
	}

	links
	{
		"opengl32.lib"
	}
	
	defines 
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	filter "system:windows"
		systemversion "latest"
		
		files {
			"src/MUE/Platform/Windows/**.h",
			"src/MUE/Platform/Windows/**.cpp"
		}


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