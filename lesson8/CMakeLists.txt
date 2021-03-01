cmake_minimum_required(VERSION 3.18)

project(lesso8 CXX)

add_executable(lesson8 main.cxx)
target_compile_features(lesson8 PUBLIC cxx_std_17)
include(CTest)
add_test(NAME chec_lesson8
        COMMAND lesson3)
