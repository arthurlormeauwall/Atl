cmake_minimum_required(VERSION 3.25.1) 
project(exampleApp)

set (CMAKE_CXX_STANDARD 11)

add_subdirectory(someLib)
add_subdirectory(app)
add_subdirectory(test)
