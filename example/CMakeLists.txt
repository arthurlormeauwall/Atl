cmake_minimum_required(VERSION 3.25.1) 
project(exampleApp)

set (CMAKE_CXX_STANDARD 11)

add_subdirectory(atlCoreLib)
add_subdirectory(libs)
add_subdirectory(atlApp)
add_subdirectory(app)

