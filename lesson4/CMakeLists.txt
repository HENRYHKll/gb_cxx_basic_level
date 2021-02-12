cmake_minimum_required(VERSION 3.18)

project(lesso4 CXX)

add_executable(lesson4 main.cxx)
target_compile_features(lesson4 PUBLIC cxx_std_17)
include(CTest)
add_test(NAME chec_lesson4
        COMMAND lesson4)
