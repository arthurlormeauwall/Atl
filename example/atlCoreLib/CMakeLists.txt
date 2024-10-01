project(atlCore)

add_library(${PROJECT_NAME}
	STATIC IMPORTED)


target_include_directories(${PROJECT_NAME}
	INTERFACE
		"/home/alorme/dev/cpp/Atl/atl_core/src"
)

target_compile_features(${PROJECT_NAME}
	INTERFACE
		cxx_std_11
)

