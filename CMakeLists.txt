cmake_minimum_required(VERSION 3.25)
project(complex_numbers)

set(CMAKE_CXX_STANDARD 17)

add_executable(complex_numbers main.cpp Complex.h)


add_subdirectory(googletest)


include_directories(googletest/googletest/include)


add_executable(ComplexTest test1.cpp)


target_link_libraries(ComplexTest gtest gtest_main)