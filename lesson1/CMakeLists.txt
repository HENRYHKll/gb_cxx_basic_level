cmake_minimum_required(VERSION 3.18)

project(hello-world CXX)

add_executable(hello-world main.cxx)
target_compile_features(hello-world PUBLIC cxx_std_17)
include(CTest)
add_test(NAME chec_hello_world 
        COMMAND hello-world)