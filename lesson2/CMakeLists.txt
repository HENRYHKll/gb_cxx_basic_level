cmake_minimum_required(VERSION 3.18)

project(lesson2 CXX)

add_executable(lesson2 main.cxx)
target_compile_features(lesson2 PUBLIC cxx_std_17)
include(CTest)
add_test(NAME chec_lesson2
        COMMAND lesson2)