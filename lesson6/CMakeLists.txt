cmake_minimum_required(VERSION 3.18)

project(lesso6 CXX)

add_executable(lesson6 main.cxx)
target_compile_features(lesson6 PUBLIC cxx_std_17)
include(CTest)
add_test(NAME chec_lesson6
        COMMAND lesson3)
