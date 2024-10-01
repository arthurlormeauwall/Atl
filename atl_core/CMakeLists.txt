project(atlCore)

file(GLOB atlCore_SRC
     "src/*.cpp"
)

add_library(${PROJECT_NAME}
    atlCore_SRC
)

add_library(libs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/>
)

target_compile_features(${PROJECT_NAME}
	PRIVATE
		cxx_std_11
)