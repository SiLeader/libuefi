#   Copyright 2018-2019 SiLeader and Cerussite.
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.

cmake_minimum_required(VERSION 3.10)
project(libuefi)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

file(GLOB_RECURSE HEADERS include/uefi/*.hpp include/uefi/*.h)
file(GLOB_RECURSE SOURCES src/*.cpp src/*.c)

add_library(uefi ${SOURCES} ${HEADERS})
add_subdirectory(app)
