project(day_03)

set(CMAKE_PREFIX_PATH "/home/adamj/projects/advent-of-code/c++")

# set(Boost_USE_STATIC_LIBS OFF) # Could be linked statically if Boost is compiled for it because this is a standalone app
# set(Boost_USE_MULTITHREADED ON)  
# set(Boost_USE_STATIC_RUNTIME OFF) # Could be linked statically if Boost is compiled for it because this is a standalone app 

# find_package(Boost 1.86.0) 

# if(Boost_FOUND)
    # include_directories(${Boost_INCLUDE_DIR})

# Collect all source files
set(SOURCES
    SolutionThree.cpp
    ../SolutionBase.cpp
)

    add_executable(day_03 day_03.cpp ${SOURCES}) 

    # target_link_libraries(day_01 ${Boost_LIBRARIES})
# else()
    # message(FATAL_ERROR "Boost not found!")
#