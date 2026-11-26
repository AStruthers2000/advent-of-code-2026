cmake_minimum_required(VERSION 4.0)
project(aoc_modules CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find external dependencies
find_package(glm CONFIG REQUIRED)

# Define module library
add_library(aoc_modules)
target_sources(aoc_modules
    PUBLIC
        FILE_SET CXX_MODULES FILES
            aoc.ixx
            aoc.graph.ixx
            aoc.grid.ixx
            aoc.io.ixx
            aoc.math.ixx
            aoc.parse.ixx
            aoc.solver.ixx
            aoc.test.ixx
)

target_link_libraries(aoc_modules
    PUBLIC
        glm::glm
)
