project(atlRunner)

add_executable(${PROJECT_NAME}
	src/main.cpp
)

target_link_libraries(${PROJECT_NAME} 
	PUBLIC
		libs::atlCore
)

target_link_libraries(${PROJECT_NAME}
	PUBLIC
		libs::allTestDefinition
)
