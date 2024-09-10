cmake_minimum_required(VERSION 3.22)

project(day_01)

set(CMAKE_PREFIX_PATH "/home/adamj/projects/advent-of-code/c++")

set(Boost_USE_STATIC_LIBS OFF) # Could be linked statically if Boost is compiled for it because this is a standalone app
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) # Could be linked statically if Boost is compiled for it because this is a standalone app 

find_package(Boost 1.86.0) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR}) 
    link_libraries(${Boost_LIBRARY_DIR})
    add_executable(day_01 day_01.cpp) 
    target_link_libraries(day_01 ${Boost_LIBRARIES})
else()
    message(FATAL_ERROR "Boost not found!")
endif()