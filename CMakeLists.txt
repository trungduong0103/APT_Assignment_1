cmake_minimum_required(VERSION 3.17)
project(APT_Assignment_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(APT_Assignment_1 main.cpp headers/descriptive_statistics.h headers/file.h headers/helpers.h headers/inferential_statistics.h headers/merge_sort.h headers/validation.h source/descriptive_statistics.cpp source/file.cpp source/helpers.cpp source/inferential_statistics.cpp source/merge_sort.cpp headers/validation.h source/validation.cpp source/validation.cpp)