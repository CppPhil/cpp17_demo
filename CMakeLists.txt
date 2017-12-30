cmake_minimum_required(VERSION 3.1)

add_compile_options("-std=c++1z")

project(cpp17_demo)

file(GLOB APPLICATION_HEADERS
     ./include/*.hpp
     ./include/core_language/*.hpp
     ./include/library/*.hpp)

file(GLOB APPLICATION_SOURCES
     ./src/*.cpp
     ./src/core_language/*.cpp
     ./src/library/*.cpp)

add_executable(${PROJECT_NAME}
               "${APPLICATION_HEADERS}"
               "${APPLICATION_SOURCES}")
