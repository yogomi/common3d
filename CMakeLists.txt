cmake_minimum_required(VERSION 2.8)
project(common3d)

list(APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")

add_subdirectory(src)
