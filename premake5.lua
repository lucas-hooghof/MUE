workspace "MUE"
    architecture "x64"
    startproject "Sandbox"

    configurations {
        "MUE_DEBUG",
        "MUE_RELEASE",
        "MUE_DIST"
    }


    -- Include sub-projects
    group "Core"
        include "MUE-Engine"
    group ""

    group "Testing"
        include "Sandbox"
    group ""
