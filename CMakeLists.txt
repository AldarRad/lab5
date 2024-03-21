cmake_minimum_required(VERSION 3.0.0)
project(lab5 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(lab5 main.cpp)
add_library(d data.h)

target_link_libraries(lab5 d)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
