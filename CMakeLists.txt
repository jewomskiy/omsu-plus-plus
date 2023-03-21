cmake_minimum_required(VERSION 3.24)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp cmake-build-debug/class.cpp cmake-build-debug/class.h cmake-build-debug/boxClass.h cmake-build-debug/containerClass.h cmake-build-debug/errorValues.h)
