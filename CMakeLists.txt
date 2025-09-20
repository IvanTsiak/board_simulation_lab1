cmake_minimum_required(VERSION 3.29)
project(board_simulation_lab1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(board_simulation_lab1
    board.cpp
    board.h
    main.cpp)
