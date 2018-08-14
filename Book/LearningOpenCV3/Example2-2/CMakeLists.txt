cmake_minimum_required(VERSION 3.0)

project(OpenCVProject)

find_package(OpenCV)

message(STATUS ${OpenCV_VERSION})

add_subdirectory(src)
