cmake_minimum_required(VERSION 3.25.1) 
project(exampleApp)


# Enforce c++11 standard.
set (CMAKE_CXX_STANDARD 11)

# This project consist of 3 components, each in one directory, so add each of them
add_subdirectory(atlCoreLib)
add_subdirectory(libs)
add_subdirectory(atlApp)
add_subdirectory(app)

