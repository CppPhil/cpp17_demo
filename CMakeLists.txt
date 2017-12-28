cmake_minimum_required(VERSION 3.1)

if(MSVC)
    if(MSVC_VERSION GREATER_EQUAL "1911")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
    endif()
endif()

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")
endif()

if(CMAKE_CXX_COMPILER MATCHES ".*clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")
endif()

project(cpp17_demo)

file(GLOB APPLICATION_HEADERS
     ./include/*.hpp)

file(GLOB APPLICATION_SOURCES
     ./src/*.cpp)

add_executable(${PROJECT_NAME}
               "${APPLICATION_HEADERS}"
               "${APPLICATION_SOURCES}")
