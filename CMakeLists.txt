cmake_minimum_required(VERSION 3.12)
project(libuefi)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

file(GLOB_RECURSE HEADERS *.hpp *.h)
file(GLOB_RECURSE SOURCES *.cpp *.c)

add_library(libuefi ${SOURCES} ${HEADERS})
