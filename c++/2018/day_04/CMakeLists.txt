project(day_04)
set(CMAKE_PREFIX_PATH "/home/adamj/projects/advent-of-code/c++")

set(SOURCES
    DayFour.cpp
    ../SolutionBase.cpp
)

add_executable(day_04 day_04.cpp ${SOURCES}) 