workspace "DawnView"
	architecture "x64"

	configurations
	{
		"Debug", 
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "DawnView"
	location "DawnView"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src"
	}

	 -- Everything below only applies to windows 
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On" -- Linking the runtime libraries statically 
		systemversion "latest"

		defines
		{
			"DV_PLATFORM_WINDOWS",
			"DV_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "DV_DEBUG"
		symbols "On" -- Debug symbols turned on 

	filter "configurations:Release"
		defines "DV_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DV_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"DawnView/vendor/spdlog/include",
		"DawnView/src"
	}

	 
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DV_PLATFORM_WINDOWS"
		}

		links
		{
			"DawnView"
		}

	filter "configurations:Debug"
		defines "DV_DEBUG"
		symbols "On" -- Debug symbols turned on 

	filter "configurations:Release"
		defines "DV_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DV_DIST"
		optimize "On"