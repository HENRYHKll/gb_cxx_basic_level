cmake_minimum_required(VERSION 3.18)

project(lesson3 CXX)

add_executable(lesson3 main.cxx)
target_compile_features(lesson3 PUBLIC cxx_std_17)
include(CTest)
add_test(NAME chec_lesson3
        COMMAND lesson3)