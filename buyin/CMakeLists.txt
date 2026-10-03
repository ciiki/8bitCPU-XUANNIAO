cmake_minimum_required(VERSION 3.10)

project(buyin)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/instructions)

aux_source_directory(. src)
aux_source_directory(instructions src)
add_executable(buyin ${src})
