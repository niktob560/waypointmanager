cmake_minimum_required(VERSION 3.1)
project(waypointmanager DESCRIPTION "Library for holding waypoint way")

include_directories(Inc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDERD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Og -g")

SET(mylibSRCS Src/main.cpp Src/manager.cpp)
SET(myprogSRCS Src/main.cpp Src/manager.cpp)

#ADD_LIBRARY(waypointmanager ${mylibSRCS})
#ADD_EXECUTABLE(main ${myprogSRCS})

#TARGET_LINK_LIBRARIES(main waypointmanager)

#add_executable(main Src/main.cpp Src/manager.cpp)

ADD_LIBRARY(waypointmanager SHARED ${mylibSRCS})
