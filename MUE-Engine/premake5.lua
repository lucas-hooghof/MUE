project "MUE-Engine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("bin/%{prj.name}/%{cfg.buildcfg}")
    objdir ("bin-int/%{prj.name}/%{cfg.buildcfg}")

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "src"
    }


    filter "configurations:MUE_DEBUG"
        defines "MUE_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:MUE_RELEASE"
        defines "MUE_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:MUE_DIST"
        defines "MUE_DIST"
        runtime "Release"
        optimize "Full"
