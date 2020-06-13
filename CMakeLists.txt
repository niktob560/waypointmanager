cmake_minimum_required(VERSION 3.1)
project(waypointmanager DESCRIPTION "Library for holding waypoint way")

include_directories(Inc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDERD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fanalyzer -Wall -Wextra -Werror -Og -g -Wparentheses -Wsequence-point -Wreturn-type -Wswitch -Wuninitialized -Wno-write-strings -Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wduplicated-branches -Wduplicated-cond -Wextra-semi -Wfloat-equal -Wlogical-op -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Werror -IInclude -Wall -Wextra -Wpedantic -pedantic-errors -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -fno-devirtualize -fno-use-cxa-atexit")

SET(mylibSRCS Src/main.cpp Src/manager.cpp)
SET(myprogSRCS Src/main.cpp Src/manager.cpp)

#ADD_LIBRARY(waypointmanager ${mylibSRCS})
#ADD_EXECUTABLE(main ${myprogSRCS})

#TARGET_LINK_LIBRARIES(main waypointmanager)

#add_executable(main Src/main.cpp Src/manager.cpp)

ADD_LIBRARY(waypointmanager SHARED ${mylibSRCS})
