cmake_minimum_required(VERSION 3.18)

project(lesso5 CXX)

add_executable(lesson5 main.cxx)
target_compile_features(lesson5 PUBLIC cxx_std_17)
include(CTest)
add_test(NAME chec_lesson5
        COMMAND lesson3)
