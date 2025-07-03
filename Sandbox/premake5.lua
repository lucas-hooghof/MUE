project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/MUE/src"
	}

	links
	{
		"MUE"
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