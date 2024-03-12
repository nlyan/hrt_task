cmake_minimum_required(VERSION 3.27)
project(hrt_task_lib)

add_library(${PROJECT_NAME} STATIC callback.cpp callback.hpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
