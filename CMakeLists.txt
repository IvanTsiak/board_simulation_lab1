cmake_minimum_required(VERSION 3.8)
project(practic LANGUAGES C CXX)
add_compile_options(/W3)
add_compile_options(/std:c++20)
add_compile_options(/EHsc)
add_executable(out
main.cpp
board.cpp
)