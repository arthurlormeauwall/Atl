cmake_minimum_required(VERSION 3.25.1) 

project(atlLib)

add_subdirectory(atl)
add_subdirectory(example)

set_target_properties(atl PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/atl)
set_target_properties(atlRunner PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/test)
set_target_properties(app PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/app)