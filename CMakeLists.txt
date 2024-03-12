cmake_minimum_required(VERSION 3.27)
project(hrt_task)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,undefined -g")

add_subdirectory(third_party/Catch2)
add_subdirectory(lib)

add_executable(${PROJECT_NAME}_tests tests.cpp)
target_include_directories(${PROJECT_NAME}_tests PRIVATE third_party/FakeIt/single_header/catch)
target_link_libraries(${PROJECT_NAME}_tests PRIVATE ${PROJECT_NAME}_lib Catch2::Catch2WithMain)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)

