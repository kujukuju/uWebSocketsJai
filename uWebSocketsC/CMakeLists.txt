cmake_minimum_required(VERSION 3.17)
project(uwebsockets)

add_compile_definitions(LIBUS_NO_SSL)
add_compile_definitions(UWS_NO_ZLIB)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

#if(MSVC)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -Wpedantic -Wall -Wextra -Wsign-conversion -Wconversion -std=c++20")
#    target_compile_options(${TARGET_NAME} PRIVATE /W4 /WX)
#else()
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread -Wpedantic -Wall -Wextra -Wsign-conversion -Wconversion -std=c++20")
#    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
#endif()

include_directories(uWebSockets/src uWebSockets/uSockets/src wrapper)

add_library(uwebsockets SHARED lib.cpp)
