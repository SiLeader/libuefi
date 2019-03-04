cmake_minimum_required(VERSION 3.12)
project(libuefi)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

file(GLOB_RECURSE HEADERS include/uefi/*.hpp include/uefi/*.h)
file(GLOB_RECURSE SOURCES src/*.cpp src/*.c)

add_library(uefi ${SOURCES} ${HEADERS})
add_subdirectory(test)