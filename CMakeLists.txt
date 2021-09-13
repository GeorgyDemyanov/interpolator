cmake_minimum_required(VERSION 3.0)
project(interpolator)

set(CMAKE_CXX_STANDARD 14)

add_executable(interpolator main.cpp Lagrange.cpp Lagrange.h Newton.cpp Newton.h)
