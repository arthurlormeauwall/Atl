-- premake5.lua
workspace "Atl_Lib"
   configurations { "Debug", "Release" }
   startproject "Atl_app"
   architecture("x64")

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Atl_core"
   location "atl_lib_core"
   kind "StaticLib"
   language "C++"
   targetdir ("bin/" .. outputdir .. "%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "%{prj.name}")
   files 
   {
    "atl_lib_core/src/**.h",
    "atl_lib_core/src/**.cpp"
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

project "Atl_app"
   location "atl_lib_app"
   kind "ConsoleApp"
   language "C++"
   targetdir ("bin/" .. outputdir .. "%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "%{prj.name}")
   links{"Atl_core", "A_module", "Another_module"}
   includedirs {
    "Atl_lib_core/src",
    "test_examples/test_module/src",
    "test_examples/another_test_module/src"
   }
   files 
   {
    "atl_lib_app/src/**.h",
    "atl_lib_app/src/**.cpp"
   }
   

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

project "A_module"
   location "test_examples/test_module"
   kind "StaticLib"
   language "C++"
   targetdir ("bin/" .. outputdir .. "%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "%{prj.name}")
   links{"Atl_core"}
   includedirs {
    "Atl_lib_core/src" 
   }
   files 
   {
    "test_examples/test_module/src/**.h",
    "test_examples/test_module/src/**.cpp"
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

project "Another_module"
   location "test_examples/another_test_module"
   kind "StaticLib"
   language "C++"
   targetdir ("bin/" .. outputdir .. "%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "%{prj.name}")
   links{"Atl_core"}
   includedirs {
    "Atl_lib_core/src" 
   }
   files 
   {
    "test_examples/another_test_module/src/**.h",
    "test_examples/another_test_module/src/**.cpp"
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"