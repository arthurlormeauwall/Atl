project(atlApp)

add_executable(${PROJECT_NAME}
	src/main.cpp
)
add_library(atlcore STATIC IMPORTED)
set_target_properties(atlcore PROPERTIES IMPORTED_LOCATION "/home/alorme/dev/cpp/Atl/example/atlCoreLib/libatl_core.a")
set_target_properties(atlcore PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "/home/alorme/dev/cpp/Atl/atl_core/src")

target_link_libraries(${PROJECT_NAME} 
PUBLIC
atlcore)

target_link_libraries(${PROJECT_NAME}
	PUBLIC
		libs::aLibTest
)

