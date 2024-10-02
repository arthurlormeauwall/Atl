project(allTestDefinition)

add_library(${PROJECT_NAME} STATIC
	src/AllTests.h
)

add_library(libs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME} 
	PUBLIC 
		libs::atl)

target_link_libraries(${PROJECT_NAME}
	PUBLIC
		libs::someLibTest
)
