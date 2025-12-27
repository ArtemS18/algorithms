cmake_minimum_required(VERSION 3.16)
project(graphs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main
    main.cpp
    src/list_graph.cpp
    src/matrix_graph.cpp
    src/set_graph.cpp
    src/arc_graph.cpp
)

target_include_directories(main PRIVATE include)
