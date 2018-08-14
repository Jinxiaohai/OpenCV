cmake_minimum_required(VERSION 3.8)

project(OpenCVProject)

find_package(OpenCV)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
