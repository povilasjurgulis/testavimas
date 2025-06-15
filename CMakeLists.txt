cmake_minimum_required(VERSION 3.10)
project(ManoPrograma)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "-O3")

# Įtraukiami header failų katalogai
include_directories(${CMAKE_SOURCE_DIR})

add_executable(main main.cpp)

