cmake_minimum_required(VERSION 3.17)
project(uwebsockets)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

include_directories(uWebSockets/src uWebSockets/uSockets/src wrapper)

add_library(uwebsockets SHARED lib.cpp)
