cmake_minimum_required(VERSION 3.25.1) 
project(exampleApp)

set (CMAKE_CXX_STANDARD 11)

add_subdirectory(aLib)
add_subdirectory(atlRunner)
add_subdirectory(app)

